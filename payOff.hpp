//
//  PayOff.hpp
//  tree_ShangweiXie
//
//  Created by Shangwei Xie on 3/28/17.
//  Copyright © 2017 Shangwei Xie. All rights reserved.
//

#ifndef PayOff_hpp
#define PayOff_hpp

#include <stdio.h>

class PayOff
{
public:
    PayOff(){};
    virtual double operator()(double S0) const=0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const=0;
};

class PayOffCall : public PayOff
{
public:
    PayOffCall(double Strike_);
    virtual double operator()(double S0) const;
    virtual ~PayOffCall(){}
    virtual PayOff* clone() const;
private:
    double K;
};



#endif /* PayOff_hpp */
