#pragma once
#include "BaseBoundary.h"

class PurchaseHistoryUI :
    public BaseBoundary
{
public:
    void startInterface();
    void showResult(const char* output);
};
