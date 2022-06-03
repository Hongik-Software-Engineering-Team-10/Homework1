#pragma once
#include "BaseBoundary.h"

class SignUpUI : public BaseBoundary
{
public:
	virtual void startInterface(const char* inputName, unsigned int& inputSSN, const char* inputID, const char* inputPW);
	virtual void showResult(const char* resultUI);
};
