#include "AccountFunc.h"

// ȸ�� ����
void SignUp::startInterface(State& appState)
{
	ui = new SignUpUI();
	auto manager = AccountManager::getInstance();

	char accountName[MAX_STRING];
	char accountID[MAX_STRING];
	char accountPW[MAX_STRING];
	unsigned int accountSSN;

	ui->startInterface(accountName, accountSSN, accountID, accountPW);
	manager->createAccount(accountName, accountSSN, accountID, accountPW);
	
	Account account = manager->getAccount(accountID);

	char output[MAX_STRING * 5];
	sprintf(output, "> %s\t%u\t%s\t%s",
		accountName, accountSSN, accountID, accountPW);

	ui->showResult(output);

	delete ui;
	ui = NULL;
}

// �α���
void SignIn::startInterface(State& appState)
{
	ui = new SignInUI();
	auto manager = AccountManager::getInstance();
	
	char accountID[MAX_STRING];
	char accountPW[MAX_STRING];

	manager->getInstance();
	ui->startInterface(accountID, accountPW);

	Account account = manager->getAccount(accountID);
	if (account.ID || strcmp(account.password,accountPW) != 0)
	{
		ui->showResult("");
	}
	else
	{
		strcpy(appState.userID, accountID);

		FileIO* fio = FileIO::getInstance();
		fio->printf("%s %s \n", accountID, accountPW);
	}

	delete ui;
	ui = NULL;
}

// �α� �ƿ�
void SignOut::startInterface(State& appState)
{
	ui = new SignOutUI();
	ui->startInterface();

	FileIO* fio = FileIO::getInstance();
	fio->printf("%s \n", appState.userID);

	memset(appState.userID, NULL, MAX_STRING);

	delete ui;
	ui = NULL;
}

// ȸ�� Ż��
void WithdrawAccount::startInterface(State& appState)
{
	ui = new WithdrawAccountUI();
	auto manager = AccountManager::getInstance();

	ui->startInterface();

	manager->deleteAccount(appState.userID);

	FileIO* fio = FileIO::getInstance();
	fio->printf("%s \n", appState.userID);

	memset(appState.userID, NULL, MAX_STRING);

	delete ui;
	ui = NULL;
}
