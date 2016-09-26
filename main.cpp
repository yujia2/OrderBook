//
//  main.cpp
//  OrderBook
//
//  Created by 贾豫 on 3/14/16.
//  Copyright © 2016 贾豫. All rights reserved.
//

#include <iostream>
//#include "Buy.hpp"
//#include "Sell.hpp"
#include "Simulator.hpp"
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Buy* buy = new Buy();
    Sell* sell = new Sell();
    Simulator simulator(buy, sell);
 
    ///////////////////////////////////////////////////////
    // 1.you can either check orders through a file input
    ///////////////////////////////////////////////////////
    ifstream file("orders.txt");
    string line;
    getline(file, line);
    while(getline(file, line)){
        vector<string> arr;
        string tmp;
        for(int i = 0; i < line.size(); i++){
            if(line[i] == ',' || i == line.size() - 1){
                arr.push_back(tmp);
                tmp.erase(tmp.begin(), tmp.end());
                continue;
            }
            tmp += line[i];
        } // end for
        string type = arr[0];
        int quantity = stoi(arr[1]);
        double price = stod(arr[2]);
        simulator.simulate(price, quantity, type);
    }
    
        //////////////////////////////////////////////////////
        // 2. or check manually when the file is not so large
        //////////////////////////////////////////////////////
//    simulator.simulate(15.20, 100, "B");
//    simulator.simulate(15.10, 200, "B");
//    simulator.simulate(15.60, 100, "S");
//    simulator.simulate(15.50, 100, "S");
//    simulator.simulate(15.20, 100, "B");
//    
//    simulator.simulate(15.20, 100, "S");
//    simulator.simulate(15.30, 100, "S");
//    simulator.simulate(15.40, 100, "S");
//    simulator.simulate(15.50, 500, "B");
//    simulator.simulate(15.40, 400, "S");









    
}
