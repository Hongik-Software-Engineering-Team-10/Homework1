#pragma once
#include "BaseBoundary.h"
class SignUpUI : public BaseBoundary
{
public:
	void startInterface(const char* inputName, unsigned int& inputSSN, const char* inputID, const char* inputPW);
	void showResult(const char* resultUI);
};
