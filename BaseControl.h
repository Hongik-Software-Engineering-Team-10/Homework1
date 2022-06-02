#pragma once
#include "State.h"
#include "ProductManager.h"

class BaseControl
{
public:
	BaseControl();
	~BaseControl();

	virtual void startInterface(State& appState) = 0;
};

