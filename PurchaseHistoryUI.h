#pragma once
#include "BaseBoundary.h"

class PurchaseHistoryUI :
    public BaseBoundary
{
public:
    virtual void startInterface();
    virtual void showResult(const char* output);
};
