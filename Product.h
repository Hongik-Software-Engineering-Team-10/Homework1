#pragma once
#include <cstring>
#define MAX_STRING	32

class Product
{
private:
	unsigned int ratedCount;

public:
	Product();
	Product(const Product& product);
	~Product();

	char name[MAX_STRING];
	char production[MAX_STRING];
	unsigned int price;
	unsigned int quantity;
	unsigned int leftQuantity;
	char sellerID[MAX_STRING];
	double satisfactionScore;

	void addSatisfactionScore(unsigned int score);
	Product& operator=(const Product& product);
};

