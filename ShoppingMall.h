#pragma once
#include "BaseControl.h"
// blablabla
#include "SearchProductInfo.h"
#include "PurchaseProduct.h"
#include "PurchaseHistory.h"
#include "RateSatisfactionScore.h"

class ShoppingMall
{
private:
	class MenuItem
	{
	public:
		int menuLevel1;
		int menuLevel2;
		BaseControl* control;
	};

	MenuItem menuItems[11] = {
		{1, 1, nullptr}, 
		{1, 2, nullptr},
		{2, 1, nullptr},
		{2, 2, nullptr},
		{3, 1, nullptr},
		{3, 2, nullptr},
		{3, 3, nullptr},
		{4, 1, new SearchProductInfo()},
		{4, 2, new PurchaseProduct()},
		{4, 3, new PurchaseHistory()},
		{4, 4, new RateSatisfactionScore()}
	};
	State appState;

public:
	ShoppingMall();
	~ShoppingMall();
	
	void run(int menuLevel1, int menuLevel2);
};
