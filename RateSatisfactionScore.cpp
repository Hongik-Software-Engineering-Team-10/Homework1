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
		ui->showResult("");
	}
	else
	{
		product.addSatisfactionScore(score);

		char output[MAX_STRING * 10];
		sprintf(output, "> %s %s %.0lf\n", product.sellerID, product.name, product.satisfactionScore);
		ui->showResult(output);

		manager->setProduct(product);
	}

	delete ui;
	ui = NULL;
}
