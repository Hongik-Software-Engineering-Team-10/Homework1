#pragma once
#include "BaseBoundary.h"

class PurchaseProductUI :
    public BaseBoundary
{
public:
    void startInterface();
    void showResult(const char* output);
};
