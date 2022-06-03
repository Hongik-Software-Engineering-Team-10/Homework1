#pragma once
#include "BaseBoundary.h"
class WithdrawAccountUI : public BaseBoundary
{
public:
	virtual void startInterface();
	virtual void showResult(const char* resultUI);
};
