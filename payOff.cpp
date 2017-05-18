//
//  PayOff.cpp
//  tree_ShangweiXie
//
//  Created by Shangwei Xie on 3/28/17.
//  Copyright © 2017 Shangwei Xie. All rights reserved.
//

#include "PayOff.hpp"
#include <math.h>

PayOffCall::PayOffCall(double _K) : K(_K)
{
}

double PayOffCall::operator () (double S0) const
{
    return fmax(S0-K,0);
}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}
