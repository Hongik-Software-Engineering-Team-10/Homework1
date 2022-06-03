#pragma once
#include "BaseBoundary.h"

class SearchProductInfoUI :
    public BaseBoundary
{
public:
    virtual void startInterface(const char* inputString);
    virtual void showResult(const char* outputString);
};
