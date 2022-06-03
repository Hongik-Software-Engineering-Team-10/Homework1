#pragma once
#include "BaseBoundary.h"

class SellDoneListUI : 
    public BaseBoundary 
{
public:
	void startInterface();
	void showResult(const char* output);
};
