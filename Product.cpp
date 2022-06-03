#include "Product.h"

Product::Product()
{
	name[0] = production[0] = sellerID[0] = '\0';
	price = quantity = leftQuantity = ratedCount = 0;
	satisfactionScore = 0.0;
}
Product::Product(const Product& product)
{
	operator=(product);
}

Product::~Product() {}

void Product::addSatisfactionScore(unsigned int score)
{
	if (score < 1 || score > 5)
	{
		return;
	}

	double sumOfScores = (satisfactionScore * (double)ratedCount) + (double)score;
	ratedCount++;
	satisfactionScore = sumOfScores / (double)ratedCount;
}

Product& Product::operator=(const Product& product)
{
	strcpy(name, product.name);
	strcpy(production, product.production);
	strcpy(sellerID, product.sellerID);
	price = product.price;
	quantity = product.quantity;
	leftQuantity = product.leftQuantity;
	ratedCount = product.ratedCount;
	satisfactionScore = product.satisfactionScore;

	return (*this);
}
