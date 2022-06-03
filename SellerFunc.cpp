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

    char output[MAX_STRING * 5];
    sprintf(output, "> %s %s %d %d\n", name, production, price, quantity);

    ui->showResult(output);

    delete ui;
    ui = NULL;
}

void SellList::startInterface(State& appState)
{
    ui = new SellListUI();
    auto manager = ProductManager::getInstance();

    ui->startInterface();

    char output[MAX_STRING * 10], cursor[2][3] = { "  ", "> " };
    bool first = true;
    for (auto i : manager->getProductList())
    {
        if (strcmp(i.sellerID, appState.userID) == 0)
        {
            sprintf(output, "%s%s %s %d %d\n", cursor[first], i.name, i.production, i.price, i.leftQuantity);
            ui->showResult(output);

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

    char output[MAX_STRING * 10], cursor[2][3] = { "  ", "> " };
    bool first = true;
    for (auto i : manager->getProductList())
    {
        if (strcmp(i.sellerID, appState.userID) == 0 && i.leftQuantity == 0)
        {
            sprintf(output, "%s%s %s %d %d %.0lf\n",
                cursor[first], i.name, i.production,
                i.price, (i.quantity - i.leftQuantity), i.satisfactionScore);
            ui->showResult(output);

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

    char output[MAX_STRING * 10], cursor[2][3] = { "  ", "> " };
    bool first = true;
    for (auto i : manager->getProductList())
    {
        if (strcmp(i.sellerID, appState.userID) == 0)
        {
            totalSales = i.price * (i.quantity - i.leftQuantity);
            sprintf(output, "%s%s %d %.0lf\n", cursor[first], i.name, totalSales, i.satisfactionScore);
            ui->showResult(output);

            first = false;
        }
    }

    delete ui;
    ui = NULL;
}