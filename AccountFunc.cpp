#include "AccountFunc.h"

// 회원 가입
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

	char output[MAX_STRING * 5];
	sprintf(output, "> %s\t%u\t%s\t%s",
		accountName, accountSSN, accountID, accountPW);

	ui->showResult(output);

	delete ui;
	ui = NULL;
}

// 로그인
void SignIn::startInterface(State& appState)
{
	ui = new SignInUI();
	auto manager = AccountManager::getInstance();
	
	char accountID[MAX_STRING];
	char accountPW[MAX_STRING];

	manager->getInstance();
	ui->startInterface(accountID, accountPW);

	if (manager->signAccount(accountID, accountPW))
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

// 로그 아웃
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

// 회원 탈퇴
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
