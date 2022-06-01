#pragma once

class BaseControl
{
public:
	BaseControl();
	~BaseControl();

	virtual void startInterface() = 0;
};

