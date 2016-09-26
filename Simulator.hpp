//
//  Simulator.hpp
//  OrderBook
//
//  Created by 贾豫 on 3/15/16.
//  Copyright © 2016 贾豫. All rights reserved.
//

#ifndef Simulator_hpp
#define Simulator_hpp

#include "Buy.hpp"
#include "Sell.hpp"
#include <string>

class Simulator{
public:
    Simulator(Buy* buy, Sell* sell);
    void addOrder(double price, int quantity, std::string type);
    void printOrder(double price, int quantity, std::string type);
    void printMarket();
    void printFill(double price, int quantity);
    void transaction();
    void simulate(double price, int quantity, std::string type);
    ~Simulator();
    
private:
    Buy* m_buy;
    Sell* m_sell;
};

#endif /* Simulator_hpp */
