#pragma once
#include <vector>
#include "Product.h"

class ProductManager
{
private:
	ProductManager();
	~ProductManager();

	static ProductManager* instance;

	std::vector<Product> productList;

public:
	static ProductManager* getInstance();

	std::vector<Product> getProductList();
	Product getProduct(const char* name);
	void setProduct(const Product& newProduct);
	void createProduct(const Product& newProduct);
	void createProduct(const char* sellerID, const char* name, const char* production, unsigned int price, unsigned int quantity);
};

