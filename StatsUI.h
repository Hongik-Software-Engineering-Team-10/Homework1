#pragma once
#include "BaseBoundary.h"

class StatsUI : 
    public BaseBoundary
{
public:
    virtual void startInterface();
    virtual void showResult(const char* output);
};
