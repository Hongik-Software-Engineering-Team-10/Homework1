#include "Account.h"

Account::Account()
{
	ID[0] = password[0] = name[0] = '\0';
	SSN = 0;
}
Account::Account(const Account& account)
{
	operator=(account);
}

Account::~Account() {}

Account& Account::operator=(const Account& account)
{
	strcpy(name, account.name);
	strcpy(password, account.password);
	strcpy(ID, account.ID);
	SSN = account.SSN;

	return (*this);
}