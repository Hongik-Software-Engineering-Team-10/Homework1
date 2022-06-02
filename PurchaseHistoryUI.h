#pragma once
#include "BaseBoundary.h"

class PurchaseHistoryUI :
    public BaseBoundary
{
public:
    void startInterface();
    void updateInterface(const char* outputString);
};

