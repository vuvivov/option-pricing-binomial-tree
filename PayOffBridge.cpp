//
//  PayOffBridge.cpp
//  tree_ShangweiXie
//
//  Created by Shangwei Xie on 3/28/17.
//  Copyright © 2017 Shangwei Xie. All rights reserved.
//

#include "PayOffBridge.hpp"

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
    ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
    ThePayOffPtr = innerPayOff.clone();
}

PayOffBridge::~PayOffBridge()
{
    delete ThePayOffPtr;
}

PayOffBridge& PayOffBridge::operator=
(const PayOffBridge& original)
{
    if (this != &original)
    {
        delete ThePayOffPtr;
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    return *this;
}