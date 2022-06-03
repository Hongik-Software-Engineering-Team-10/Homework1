#pragma once
#include "BaseBoundary.h"

class StatsUI : 
    public BaseBoundary
{
public:
    void startInterface();
    void showResult(const char* output);
};
