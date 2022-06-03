#pragma once
#include "BaseBoundary.h"

class PurchaseProductUI :
    public BaseBoundary
{
public:
    virtual void startInterface();
    virtual void showResult(const char* output);
};
