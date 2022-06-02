#include "PurchaseProduct.h"

void PurchaseProduct::startInterface(State& appState)
{
	ui = new PurchaseProductUI();
	auto manager = ProductManager::getInstance();
	//auto DB = AccountDB::getInstance();

	ui->startInterface();

	Product selectedProduct = manager->getProduct(appState.selectedProduct);
	if (selectedProduct.name[0] == '\0' || selectedProduct.quantity == 0)
	{
		ui->updateInterface("");
		appState.selectedProduct[0] = '\0';
	}
	else
	{
		char output[MAX_STRING * 10];
		sprintf(output, "> %s\t%s", selectedProduct.sellerID, selectedProduct.name);
		ui->updateInterface(output);

		// TODO: Do purchase.
		//DB->purchaseProduct(appState.userID, selectedProduct.name);
		selectedProduct.quantity--;
		manager->setProduct(selectedProduct);

		appState.selectedProduct[0] = '\0';
	}

	delete ui;
	ui = NULL;
}