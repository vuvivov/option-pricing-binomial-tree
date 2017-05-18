//
//  PayOffBridge.hpp
//  tree_ShangweiXie
//
//  Created by Shangwei Xie on 3/28/17.
//  Copyright © 2017 Shangwei Xie. All rights reserved.
//

#ifndef PayOffBridge_hpp
#define PayOffBridge_hpp

#include <stdio.h>
#include "PayOff.hpp"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    inline double operator()(double S0) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
private:
    PayOff* ThePayOffPtr;
};

inline double PayOffBridge::operator()(double S0) const
{
    return ThePayOffPtr->operator ()(S0);
}

#endif /* PayOffBridge_hpp */
