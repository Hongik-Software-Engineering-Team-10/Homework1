#pragma once
#include "FileIO.h"

class BaseBoundary
{
public:
	BaseBoundary();
	~BaseBoundary();

	virtual void showResult(const char* output) = 0;
};
