#pragma once
#include "BaseBoundary.h"

class SellListUI : 
    public BaseBoundary 
{
public:
	void startInterface();
	void showResult(const char* output);
};
