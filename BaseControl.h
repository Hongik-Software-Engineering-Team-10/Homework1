#pragma once
#include "ShoppingMall.h"

class BaseControl
{
public:
	BaseControl();
	~BaseControl();

	virtual void startInterface(State& appState) = 0;
};

