#include "RateSatisfactionScore.h"

void RateSatisfactionScore::startInterface(State& appState)
{
	ui = new RateSatisfactionScoreUI();
	auto manager = ProductManager::getInstance();

	char productName[MAX_STRING];
	int score = 0;
	ui->startInterface(productName, score);

	Product product = manager->getProduct(productName);
	if (product.name[0] == '\0')
	{
		ui->updateInterface("");
	}
	else
	{
		product.addSatisfactionScore(score);

		char output[MAX_STRING * 10];
		sprintf(output, "> %s\t%s\t%.1lf", product.sellerID, product.name, product.satisfactionScore);
		ui->updateInterface(output);

		manager->setProduct(product);
	}

	delete ui;
	ui = NULL;
}
