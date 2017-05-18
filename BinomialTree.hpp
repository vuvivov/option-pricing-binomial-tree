//
//  BinomialTree.hpp
//  tree_ShangweiXie
//
//  Created by Shangwei Xie on 3/28/17.
//  Copyright © 2017 Shangwei Xie. All rights reserved.
//

#ifndef BinomialTree_hpp
#define BinomialTree_hpp

#include <stdio.h>
#include "PayOffBridge.hpp"
#include <vector>


class BinomialTree{
public:
    BinomialTree(double _S0,double _Sigma,unsigned int _N,double _T);
    double GetPrice(const PayOffBridge& PayOff);
    void PrintParameters();
    void PrintTree();
    
private:
    bool Built;
    std::vector<std::vector<std::pair<double, double>>> Tree;
    
    virtual void SetTreeParameter()=0;
    void BuildTree();

protected:
    double S0;
    double Sigma;
    int N;
    double T;
    double SigmaSq_DeltaT;
    double Sigma_SqrtDeltaT;
    
    double p;
    double q;
    double u;
    double d;
    
    
};

class BinomialTreeUD1 :public BinomialTree{
public:
    BinomialTreeUD1(double _S0,double _Sigma,unsigned int _N,double _T);
private:
    virtual void SetTreeParameter();
};

class BinomialTreePQ05 :public BinomialTree{
public:
    BinomialTreePQ05(double _S0,double _Sigma,unsigned int _N,double _T);
private:
    virtual void SetTreeParameter();
};


#endif /* BinomialTree_hpp */
