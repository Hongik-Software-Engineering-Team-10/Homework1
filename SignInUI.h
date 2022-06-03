#pragma once
#include "BaseBoundary.h"
class SignInUI : public BaseBoundary
{
public:
	virtual void startInterface(const char* inputID, const char* inputPW);
	virtual void showResult(const char* resultUI);
};
