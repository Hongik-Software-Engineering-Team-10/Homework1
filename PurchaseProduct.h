#pragma once
#include "BaseControl.h"
#include "PurchaseProductUI.h"

class PurchaseProduct :
    public BaseControl
{
private:
    PurchaseProductUI* ui;

public:
    void startInterface(State& appState);
};

