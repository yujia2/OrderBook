//
//  Sell.hpp
//  OrderBook
//
//  Created by 贾豫 on 3/15/16.
//  Copyright © 2016 贾豫. All rights reserved.
//

#ifndef Sell_hpp
#define Sell_hpp

#include <unordered_map>
#include <queue>

class Sell{
public:
    Sell();
    double getLowPrice();
    void addOrder(double price, int quantity);
    void deleteOrder(double price, int quantity);
    int quantityOnPrice(double price);
    
private:
    std::unordered_map<double, int> m_map; // map from price to quantity
    std::priority_queue<double, std::vector<double>, std::greater<double>> m_prices; //high->low(top)
};



#endif /* Sell_hpp */
