#pragma once
#include "BaseBoundary.h"

class SellDoneListUI : 
    public BaseBoundary 
{
public:
	virtual void startInterface();
	virtual void showResult(const char* output);
};
