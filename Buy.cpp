//
//  Buy.cpp
//  OrderBook
//
//  Created by 贾豫 on 3/15/16.
//  Copyright © 2016 贾豫. All rights reserved.
//

#include <iostream>
#include "Buy.hpp"

using namespace std;

Buy::Buy(){}

double Buy::getHighPrice(){
    if(m_prices.empty())
        return -1;
    return m_prices.top();
}

void Buy::addOrder(double price, int quantity){
    if (m_map.find(price) != m_map.end()) {
        m_map[price] = m_map[price] + quantity;
    }else{ // price not exist
        m_prices.push(price);
        m_map[price] = quantity;
    }
}

void Buy::deleteOrder(double price, int quantity){
    if (quantity >= m_map[price]) {
        m_map.erase(price);
        m_prices.pop();
    }else{
        m_map[price] -= quantity;
    }
    
}

int Buy::quantityOnPrice(double price){
    return m_map[price];
}