//
//  BinomialTree.cpp
//  tree_ShangweiXie
//
//  Created by Shangwei Xie on 3/28/17.
//  Copyright © 2017 Shangwei Xie. All rights reserved.
//

#include "BinomialTree.hpp"
#include <math.h>
#include <iostream>

BinomialTree::BinomialTree(double _S0,double _Sigma,unsigned int _N,double _T):S0(_S0),Sigma(_Sigma),N(_N),T(_T){
    Built=0;
    double DeltaT=T/N;
    SigmaSq_DeltaT=pow(Sigma,2)*DeltaT;
    Sigma_SqrtDeltaT=Sigma*sqrt(DeltaT);
}

void BinomialTree::BuildTree(){
    SetTreeParameter();
    Built=1;
    //step=0
    Tree.resize(N+1);
    Tree[0].resize(1);
    Tree[0][0].first=S0;
    //step>=1
    for (int i=1; i<=N; i++) {
        Tree[i].resize(i+1);
        //set price
        for (int j=0; j<=i-1; j++) {
            Tree[i][j].first=Tree[i-1][j].first*u;
        }
        Tree[i][i].first=Tree[i-1][i-1].first*d;
    }
}


BinomialTreeUD1::BinomialTreeUD1(double _S0,double _Sigma,unsigned int _N,double _T):BinomialTree( _S0, _Sigma,  _N, _T){}

BinomialTreePQ05::BinomialTreePQ05(double _S0,double _Sigma,unsigned int _N,double _T):BinomialTree( _S0, _Sigma,  _N, _T){}

void BinomialTreeUD1::SetTreeParameter(){
    u=1+.5*SigmaSq_DeltaT+.5*sqrt(pow(SigmaSq_DeltaT,2)+4*SigmaSq_DeltaT);
    d=1/u;
    p=1/(u+1);
    q=u/(u+1);
}

void BinomialTreePQ05::SetTreeParameter(){
    p=.5;
    q=.5;
    d=1-Sigma_SqrtDeltaT;
    u=1+Sigma_SqrtDeltaT;
}

double BinomialTree::GetPrice(const PayOffBridge &PayOff){
    if (Built==0) {
        BuildTree();
    }
    //step N
    for (int i=0; i<=N; i++) {
        Tree[N][i].second=PayOff(Tree[N][i].first);
    }
    //step N-1 to 0
    for (int i=N-1; i>=0; i--) {
        for (int j=0; j<=i; j++) {
            Tree[i][j].second=(Tree[i+1][j].second*p+Tree[i+1][j+1].second*q);
        }
    }
    return Tree[0][0].second;
}

void BinomialTree::PrintTree(){
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=i; j++) {
            std::cout<<Tree[i][j].first<<","<<Tree[i][j].second<<"_";
        }
        std::cout<<std::endl;
    }
}

void BinomialTree::PrintParameters(){
    std::cout<<"p="<<p<<"\n"
    <<"q="<<q<<"\n"
    <<"u="<<u<<"\n"
    <<"d="<<d<<"\n";
}