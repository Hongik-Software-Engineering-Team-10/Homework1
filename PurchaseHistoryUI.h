#pragma once
#include "BaseBoundary.h"
#include <string> // TODO: remove it.

class PurchaseHistoryUI :
    public BaseBoundary
{
public:
    void startInterface();
    void updateInterface(const char* outputString);
};

