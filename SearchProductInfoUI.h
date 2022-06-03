#pragma once
#include "BaseBoundary.h"

class SearchProductInfoUI :
    public BaseBoundary
{
public:
    void startInterface(const char* inputString);
    void showResult(const char* output);
};
