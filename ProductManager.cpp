#include "ProductManager.h"

ProductManager::ProductManager() {}
ProductManager::~ProductManager() {}

ProductManager* ProductManager::instance = nullptr;

ProductManager* ProductManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ProductManager();
	}
	return instance;
}

std::vector<Product> ProductManager::getProductList()
{
	return productList;
}

Product ProductManager::getProduct(const char* name)
{
	for (const Product& product : productList)
	{
		if (strcmp(name, product.name) == 0)
		{
			return product;
		}
	}

	return Product();
}

void ProductManager::setProduct(const Product& newProduct)
{
	for (Product& product : productList)
	{
		if (strcmp(newProduct.name, product.name) == 0)
		{
			product = newProduct;
			return;
		}
	}

	createProduct(newProduct);
}

void ProductManager::createProduct(const Product& newProduct)
{
	productList.push_back(newProduct);
}

void ProductManager::createProduct(const char* sellerID, const char* name, const char* production, unsigned int price, unsigned int quantity)
{
	Product product;
	strcpy(product.sellerID, sellerID);
	strcpy(product.name, name);
	strcpy(product.production, production);
	product.price = price;
	product.quantity = quantity;

	createProduct(product);
}

void ProductManager::close()
{
	delete instance;
	instance = nullptr;
}