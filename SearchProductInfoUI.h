#pragma once
#include "BaseBoundary.h"

class SearchProductInfoUI :
    public BaseBoundary
{
public:
    void startInterface(const char* terminalInput);
    void updateInterface(const char* terminalOutput);
};

