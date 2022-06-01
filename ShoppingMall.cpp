#include "ShoppingMall.h"

ShoppingMall::ShoppingMall()
{
	appState.selectedProduct[0] = appState.userID[0] = '\0';
}

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