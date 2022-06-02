#include "SellerFunc.h"
using namespace std;

void PostNewProductInfo::startInterface(State& appState)
{
    ui = new PostNewProductInfoUI();
    auto manager = ProductManager::getInstance();

    char* name; 
    char* production;
    unsigned int price, quantity;

    ui->startInterface(name, production, price, quantity);
    manager->createProduct(appState.userID, name, production, price, quantity);

    delete ui;
    ui = NULL;
}

void SellList::startInterface(State& appState)
{
    ui = new SellListUI();
    auto manager = ProductManager::getInstance();

    ui->startInterface();
    for (auto i : manager->getProductList()) 
    {
        if (strcmp(i.sellerID, appState.userID) == 0)
        {
        	FileIO* fio = FileIO::getInstance();
	        fio->printf("%s %s %d %d \n", i.name, i.production, i.price, i.leftQuantity);
        }
    }
    delete ui;
    ui = NULL;
}

void SellDoneList::startInterface(State& appState)
{
    ui = new SellDoneListUI();
    auto manager = ProductManager::getInstance();

    ui->startInterface();

    for (auto i : manager->getProductList())

    {
        if (strcmp(i.sellerID, appState.userID) == 0 && i.leftQuantity == 0)
        {
            FileIO* fio = FileIO::getInstance();
	        fio->printf("%s %s %d %d %d \n", i.name, i.production, i.price, (i.quantity - i.leftQuantity), i.satisfactionScore);
        }
    }
    delete ui;
    ui = NULL;
}

void Stats::startInterface(State& appState)
{
    ui = new StatsUI();
    auto manager = ProductManager::getInstance();

    ui->startInterface();

    int TotalSales;

    for (auto i : manager->getProductList())
    {
        if (strcmp(i.sellerID, appState.userID) == 0)
        {
            TotalSales = i.price * (i.quantity - i.leftQuantity);
            FileIO* fio = FileIO::getInstance();
            fio->printf("%s %d %d \n", i.name, TotalSales, i.satisfactionScore);
        }
    }
     

    delete ui;
    ui = NULL;
}
