#pragma once
#include "BaseBoundary.h"

class PurchaseProductUI :
    public BaseBoundary
{
public:
    void startInterface();
    void updateInterface(const char* outputString);
};
