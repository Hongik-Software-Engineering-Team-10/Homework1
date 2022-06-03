#pragma once
#include "BaseBoundary.h"

class SignOutUI : public BaseBoundary
{
public:
	virtual void startInterface();
	virtual void showResult(const char* resultUI);
};
