#pragma once
#include <string> // TODO: remove it.
#include <algorithm>
#include "BaseControl.h"
#include "PurchaseHistoryUI.h"

class PurchaseHistory :
    public BaseControl
{
private:
    PurchaseHistoryUI* ui;

public:
    void startInterface(State& appState);
};

