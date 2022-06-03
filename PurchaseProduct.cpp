#include "PurchaseProduct.h"

void PurchaseProduct::startInterface(State& appState)
{
	ui = new PurchaseProductUI();
	auto manager = ProductManager::getInstance();
	auto DB = AccountManager::getInstance();

	ui->startInterface();

	Product selectedProduct = manager->getProduct(appState.selectedProduct);
	if (selectedProduct.name[0] == '\0' || selectedProduct.leftQuantity == 0)
	{
		ui->showResult("");
		appState.selectedProduct[0] = '\0';
	}
	else
	{
		char output[MAX_STRING * 10];
		sprintf(output, "> %s %s\n", selectedProduct.sellerID, selectedProduct.name);
		ui->showResult(output);

		DB->purchaseProduct(appState.userID, selectedProduct.name);
		selectedProduct.leftQuantity--;
		manager->setProduct(selectedProduct);

		appState.selectedProduct[0] = '\0';
	}

	delete ui;
	ui = NULL;
}
