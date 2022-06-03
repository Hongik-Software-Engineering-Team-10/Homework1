#pragma once
#include "BaseBoundary.h"

class SellListUI : 
    public BaseBoundary 
{
public:
	virtual void startInterface();
	virtual void showResult(const char* output);
};
