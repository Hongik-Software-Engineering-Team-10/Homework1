#include "ShoppingMall.h"

State::State()
{
	userID[0] = selectedProduct[0] = '\0';
}
State::~State() {}

ShoppingMall::ShoppingMall() {}
ShoppingMall::~ShoppingMall()
{
	for (MenuItem& item : menuItems)
	{
		delete item.control;
		item.control = NULL;
	}
}

void ShoppingMall::run(int menuLevel1, int menuLevel2)
{
	for (MenuItem& item : menuItems)
	{
		if (item.menuLevel1 == menuLevel1 && item.menuLevel2 == menuLevel2)
		{
			item.control->startInterface(appState);
		}
	}
}