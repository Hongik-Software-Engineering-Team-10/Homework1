#pragma once
#include "BaseControl.h"
#include "SearchProductInfoUI.h"

class SearchProductInfo :
    public BaseControl
{
private:
    SearchProductInfoUI* ui;

public:
    void startInterface(State& appState);
};
