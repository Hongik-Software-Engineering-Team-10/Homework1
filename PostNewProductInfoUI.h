#pragma once
#include "BaseBoundary.h"

class PostNewProductInfoUI : 
	public BaseBoundary 
{
public:
	virtual void startInterface(const char* char1, const char* char2, unsigned int& int1, unsigned int& int2);
	virtual void showResult(const char* outputString);
};
