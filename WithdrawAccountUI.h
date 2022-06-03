#pragma once
#include "BaseBoundary.h"
class WithdrawAccountUI : public BaseBoundary
{
public:
	void startInterface();
	void showResult(const char* output);
};
