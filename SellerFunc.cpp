#include "SellerFunc.h"
using namespace std;

void PostNewProductInfo::startInterface(State& appState)
{
    ui = new PostNewProductInfoUI();
    auto manager = ProductManager::getInstance();

    char name[MAX_STRING]; 
    char production[MAX_STRING];
    unsigned int price, quantity;

    ui->startInterface(name, production, price, quantity);
    manager->createProduct(appState.userID, name, production, price, quantity);

    FileIO* fio = FileIO::getInstance();
    fio->printf("> %s %s %d %d\n\n", name, production, price, quantity);

    delete ui;
    ui = NULL;
}

void SellList::startInterface(State& appState)
{
    ui = new SellListUI();
    auto manager = ProductManager::getInstance();

    ui->startInterface();

    FileIO* fio = FileIO::getInstance();
    char cursor[2][3] = { "  ", "> " };
    bool first = true;
    for (auto i : manager->getProductList()) 
    {
        if (strcmp(i.sellerID, appState.userID) == 0)
        {
	        fio->printf("%s%s %s %d %d\n\n", cursor[first], i.name, i.production, i.price, i.leftQuantity);
            first = false;
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

    FileIO* fio = FileIO::getInstance();
    char cursor[2][3] = { "  ", "> " };
    bool first = true;
    for (auto i : manager->getProductList())
    {
        if (strcmp(i.sellerID, appState.userID) == 0 && i.leftQuantity == 0)
        {
	        fio->printf("%s%s %s %d %d %.0lf\n\n",
                cursor[first], i.name, i.production,
                i.price, (i.quantity - i.leftQuantity), i.satisfactionScore);
            first = false;
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

    int totalSales;

    FileIO* fio = FileIO::getInstance();
    char cursor[2][3] = { "  ", "> " };
    bool first = true;
    for (auto i : manager->getProductList())
    {
        if (strcmp(i.sellerID, appState.userID) == 0)
        {
            totalSales = i.price * (i.quantity - i.leftQuantity);
            fio->printf("%s%s %d %.0lf\n\n", cursor[first], i.name, totalSales, i.satisfactionScore);
            first = false;
        }
    }
     
    delete ui;
    ui = NULL;
}
