#pragma once
#include "BaseBoundary.h"

class RateSatisfactionScoreUI :
    public BaseBoundary
{
public:
    virtual void startInterface(const char* inputString, int& inputInteger);
    virtual void showResult(const char* outputString);
};
