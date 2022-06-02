#include "PurchaseHistory.h"

void PurchaseHistory::startInterface(State& appState)
{
	ui = new PurchaseHistoryUI();
	auto manager = ProductManager::getInstance();
	//auto DB = AccountDB::getInstance();

	ui->startInterface();

	std::vector<std::string> purchasedList; //= DB->getPurchasedList(appState.userID);
	std::sort(purchasedList.begin(), purchasedList.end());

	char output[MAX_STRING * 10], cursor[2][3] = { "  ", "> " };
	bool first = true;
	for (std::string productName : purchasedList)
	{
		Product product = manager->getProduct(productName.c_str());
		if (product.name[0] == '\0')
		{
			continue;
		}

		sprintf(output, "%s%s\t%s\t%s\t%u\t%u\t%.1lf", cursor[first],
			product.sellerID, product.name, product.production,
			product.price, product.leftQuantity, product.satisfactionScore);
		ui->updateInterface(output);

		first = false;
	}

	delete ui;
	ui = NULL;
}