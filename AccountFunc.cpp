#include "AccountFunc.h"

// È¸¿ø °¡ÀÔ
void SignUp::startInterface(State& appState)
{
	ui = new SignUpUI();
	auto DB = AccountManager::getInstance();

	char accountName[MAX_STRING];
	char accountID[MAX_STRING];
	char accountPW[MAX_STRING];
	unsigned int accountSSN;

	ui->startInterface(accountName, accountSSN, accountID, accountPW);
	DB->createAccount(accountName, accountSSN, accountID, accountPW);

	char output[MAX_STRING * 5];
	sprintf(output, "> %s %u %s %s\n",
		accountName, accountSSN, accountID, accountPW);

	ui->showResult(output);

	delete ui;
	ui = NULL;
}

// ·Î±×ÀÎ
void SignIn::startInterface(State& appState)
{
	ui = new SignInUI();
	auto DB = AccountManager::getInstance();
	
	char accountID[MAX_STRING];
	char accountPW[MAX_STRING];

	DB->getInstance();
	ui->startInterface(accountID, accountPW);

	if (!DB->signAccount(accountID, accountPW))
	{
		ui->showResult("");
	}
	else
	{
		strcpy(appState.userID, accountID);

		char output[MAX_STRING * 5];
		sprintf(output, "> %s %s\n", accountID, accountPW);

		ui->showResult(output);
	}

	delete ui;
	ui = NULL;
}

// ·Î±× ¾Æ¿ô
void SignOut::startInterface(State& appState)
{
	ui = new SignOutUI();
	ui->startInterface();

	char output[MAX_STRING * 5];
	sprintf(output, "> %s\n", appState.userID);

	ui->showResult(output);

	memset(appState.userID, NULL, MAX_STRING);

	delete ui;
	ui = NULL;
}

// È¸¿ø Å»Åð
void WithdrawAccount::startInterface(State& appState)
{
	ui = new WithdrawAccountUI();
	auto DB = AccountManager::getInstance();

	ui->startInterface();

	DB->deleteAccount(appState.userID);

	char output[MAX_STRING * 5];
	sprintf(output, ">%s\n", appState.userID);

	ui->showResult(output);

	memset(appState.userID, NULL, MAX_STRING);

	delete ui;
	ui = NULL;
}
