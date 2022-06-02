#pragma once
#include <algorithm>
#include "BaseControl.h"
#include "AccountManager.h"
#include "PurchaseHistoryUI.h"

class PurchaseHistory :
    public BaseControl
{
private:
    PurchaseHistoryUI* ui;

public:
    void startInterface(State& appState);
};

