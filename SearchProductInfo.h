#pragma once
#include "BaseControl.h"
#include "SearchProductInfoUI.h"
#include "ProductManager.h"

class SearchProductInfo :
    public BaseControl
{
private:
    SearchProductInfoUI* ui;

public:
    void startInterface(State& appState);
};

