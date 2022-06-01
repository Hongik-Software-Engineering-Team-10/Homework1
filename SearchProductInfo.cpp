#include "SearchProductInfo.h"

void SearchProductInfo::startInterface()
{
	ui = new SearchProductInfoUI();
	auto manager = ProductManager::getInstance();

	char productName[MAX_STRING];
	ui->startInterface(productName);

	Product product = manager->getProduct(productName);
	if (product.name[0] == '\0')
	{
		ui->updateInterface("");
	}
	else
	{
		char output[MAX_STRING * 10];
		sprintf(output, "> %s\t%s\t%s\t%u\t%u\t%.1lf",
			product.sellerID, product.name, product.production,
			product.price, product.quantity, product.satisfactionScore);

		ui->updateInterface(output);
	}
}