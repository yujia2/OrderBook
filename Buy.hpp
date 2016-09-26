//
//  Buy.h
//  OrderBook
//
//  Created by 贾豫 on 3/14/16.
//  Copyright © 2016 贾豫. All rights reserved.
//

#ifndef Buy_h
#define Buy_h

#include <unordered_map>
#include <queue>

class Buy{
public:
    Buy();
    double getHighPrice(); // return the current high price
    void addOrder(double price, int quantity); // add new order to map, and new price(if any) to queue
    void deleteOrder(double price, int quantity); // delete order from map after a successful fill
    int quantityOnPrice(double price);
    
private:
    std::unordered_map<double, int> m_map; // map from price to quality
    std::priority_queue<double> m_prices; // price low->high(top)
};

#endif /* Buy_h */
