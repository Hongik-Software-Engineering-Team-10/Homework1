#pragma once
#include "BaseControl.h"
#include "AccountManager.h"
#include "SignUpUI.h"
#include "WithdrawAccountUI.h"
#include "SignInUI.h"
#include "SignOutUI.h"

class SignUp :
    public BaseControl
{
private:
    SignUpUI* ui;

public:
    void startInterface(State& appState);
};

class SignOut :
    public BaseControl
{
private:
    SignOutUI* ui;

public:
    void startInterface(State& appState);
};

class SignIn :
    public BaseControl
{
private:
    SignInUI* ui;

public:
    void startInterface(State& appState);
};

class WithdrawAccount :
    public BaseControl
{
private:
    WithdrawAccountUI* ui;

public:
    void startInterface(State& appState);
};
