#pragma once
#include "BaseBoundary.h"

class RateSatisfactionScoreUI :
    public BaseBoundary
{
public:
    void startInterface(const char* inputString, int& inputInteger);
    void updateInterface(const char* outputString);
};
