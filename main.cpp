//
//  main.cpp
//  tree_ShangweiXie
//
//  Created by Shangwei Xie on 3/28/17.
//  Copyright © 2017 Shangwei Xie. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "BinomialTree.hpp"

int main(int argc, const char * argv[]) {
    double S0=100;
    double Sigma=.2;
    double K=100;
    double T=1;
    
    std::fstream fs;
    fs.open ("/Users/shangweixie/Dropbox/fincad/tree_ShangweiXie/binomialTree.csv", std::fstream::in | std::fstream::out | std::fstream::app);
    
    PayOffCall ThePayOff(K);
    for (int N=1; N<=100; N++)
    {
        BinomialTreePQ05 Tree1=BinomialTreePQ05(S0, Sigma, N, T);
        BinomialTreeUD1 Tree2=BinomialTreeUD1(S0, Sigma, N, T);
        fs<<Tree1.GetPrice(ThePayOff)<<","<<Tree2.GetPrice(ThePayOff)<<"\n";
    }
    fs.close();
    
    return 0;
}
