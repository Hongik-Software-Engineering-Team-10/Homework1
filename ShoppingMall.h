#pragma once
#include "BaseControl.h"
// blablabla
#include "SearchProductInfo.h"
// blablabla

class ShoppingMall
{
private:
	struct MenuItem
	{
		int menuLevel1;
		int menuLevel2;
		BaseControl* control;
	} menuItems[11] = {
		{1, 1, nullptr}, 
		{1, 2, nullptr},
		{2, 1, nullptr},
		{2, 2, nullptr},
		{3, 1, nullptr},
		{3, 2, nullptr},
		{3, 3, nullptr},
		{4, 1, new SearchProductInfo()},
		{4, 2, nullptr},
		{4, 3, nullptr},
		{4, 4, nullptr}
	};

public:
	ShoppingMall();
	~ShoppingMall();
	
	void run(int menuLevel1, int menuLevel2);
};
