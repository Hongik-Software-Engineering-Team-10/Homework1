#include "SearchProductInfo.h"

void SearchProductInfo::startInterface(State& appState)
{
	ui = new SearchProductInfoUI();
	auto manager = ProductManager::getInstance();

	char productName[MAX_STRING];
	ui->startInterface(productName);

	Product product = manager->getProduct(productName);
	if (product.name[0] == '\0' || product.leftQuantity == 0)
	{
		ui->updateInterface("");
	}
	else
	{
		char output[MAX_STRING * 10];
		sprintf(output, "> %s %s %s %u %u %.0lf\n",
			product.sellerID, product.name, product.production,
			product.price, product.leftQuantity, product.satisfactionScore);

		ui->updateInterface(output);
		strcpy(appState.selectedProduct, product.name);
	}

	delete ui;
	ui = NULL;
}
