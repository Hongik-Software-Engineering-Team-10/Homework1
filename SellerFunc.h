#pragma once
#include <cstring>
#include <iostream>
#include "BaseControl.h"
#include "ProductManager.h"
#include "State.h"
#include "Product.h"
#include "PostNewProductInfoUI.h"
#include "SellListUI.h"
#include "SellDoneListUI.h"
#include "StatsUI.h"

class PostNewProductInfo :
    public BaseControl
{
private:
    PostNewProductInfoUI* ui;

public:
    void startInterface(State& appState);
};

class SellList :
    public BaseControl
{
private: 
    SellListUI* ui;

public:
    void startInterface(State& appState);
};

class SellDoneList :
    public BaseControl
{
private:
    SellDoneListUI* ui;

public:
    void startInterface(State& appState);
};

class Stats :
    public BaseControl
{
private:
    StatsUI* ui;

public:
    void startInterface(State& appState);
};
