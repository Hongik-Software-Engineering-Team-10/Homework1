#pragma once
#include "BaseBoundary.h"
class SignInUI : public BaseBoundary
{
public:
	void startInterface(const char* inputID, const char* inputPW);
	void showResult(const char* resultUI);
};