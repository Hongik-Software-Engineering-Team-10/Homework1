#pragma once
#include "BaseControl.h"
#include "RateSatisfactionScoreUI.h"

class RateSatisfactionScore :
    public BaseControl
{
private:
    RateSatisfactionScoreUI* ui;
    
public:
    void startInterface(State& appState);
};

