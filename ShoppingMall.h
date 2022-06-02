#pragma once
#include "BaseControl.h"
#include "AccountFunc.h"
#include "SellerFunc.h"
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

	MenuItem menuItems[12] = {
		{1, 1, new SignUp()}, 
		{1, 2, new WithdrawAccount()},
		{2, 1, new SignIn()},
		{2, 2, new SignOut()},
		{3, 1, new PostNewProductInfo()},
		{3, 2, new SellList()},
		{3, 3, new SellDoneList()},
		{4, 1, new SearchProductInfo()},
		{4, 2, new PurchaseProduct()},
		{4, 3, new PurchaseHistory()},
		{4, 4, new RateSatisfactionScore()},
		{5, 1, new Stats()}
	};
	State appState;

public:
	ShoppingMall();
	~ShoppingMall();
	
	void run(int menuLevel1, int menuLevel2);
};
