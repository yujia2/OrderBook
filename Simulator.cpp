//
//  Simulator.cpp
//  OrderBook
//
//  Created by 贾豫 on 3/15/16.
//  Copyright © 2016 贾豫. All rights reserved.
//

#include "Simulator.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Simulator::Simulator(Buy* buy, Sell* sell){
    m_buy = buy;
    m_sell = sell;
}

void Simulator::addOrder(double price, int quantity, string type){
    if (type == "B") {
        m_buy->addOrder(price, quantity);
    }else if (type == "S"){
        m_sell->addOrder(price, quantity);
    }else
        cout<<"addOrder type error!";
}

void Simulator::printOrder(double price, int quantity, string type){
    cout << "Order: " << type << " " << quantity << " @ " << price << endl;
}

void Simulator::printMarket(){
    string buyStatus;
    string sellStatus;
    
    if (m_buy->getHighPrice() == -1) {
        buyStatus = "Empty Buy";
    }else{
        double highPrice = m_buy->getHighPrice();
        buyStatus = to_string(highPrice) + "@" + to_string(m_buy->quantityOnPrice(highPrice));
    }
    
    if(m_sell->getLowPrice() == -1){
        sellStatus = "Empty Sell";
    }else{
        double lowPrice = m_sell->getLowPrice();
        sellStatus = to_string(lowPrice) + "@" + to_string(m_sell->quantityOnPrice(lowPrice));
    }
    
    cout << "Market: " << buyStatus << " - " << sellStatus << endl;
}

void Simulator::printFill(double price, int quantity){
    cout << "FILL: " << quantity << " @ " << price << endl;
}

void Simulator::transaction(){
    while (m_buy->getHighPrice() >= m_sell->getLowPrice() && m_sell->getLowPrice() > 0) {
        double bp = m_buy->getHighPrice();
        double sp = m_sell->getLowPrice();
        int tranQuan = min(m_buy->quantityOnPrice(bp), m_sell->quantityOnPrice(sp)); // transaction quantity
        printFill(bp, tranQuan);
        m_buy->deleteOrder(bp, tranQuan);
        m_sell->deleteOrder(sp, tranQuan);
    }
}

void Simulator::simulate(double price, int quantity, string type){
    addOrder(price, quantity, type);
    printOrder(price, quantity, type);
    transaction();
    printMarket();
}

Simulator::~Simulator(){
    delete m_buy;
    delete m_sell;
}

















