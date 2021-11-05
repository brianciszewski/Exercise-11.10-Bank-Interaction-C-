#include<iostream>
#include<iomanip>
#include<vector>
#include<memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;


int main()
{
	/*
Account Brian;
Brian.setBalance(100);
Brian.credit(15);
Brian.debit(10);

SavingsAccount Brian1;
Brian1.setBalance(Brian.getBalance());
Brian1.setIntrestRate(.02);
std::cout << "You have earned $" << Brian1.calculateIntrest() << " in intrest.\n" << std::endl;
std::cout << "Your new balance is $" << Brian1.balance + Brian1.intrest << "\n" << std::endl;

CheckingAccount Brian2;
Brian2.setFee(3.25);
Brian2.setBalance(Brian.getBalance());
Brian2.credit(5);
Brian2.debit(4.67);

Account account{ 500 };
//account.setBalance(500);
SavingsAccount savingsAccount;
savingsAccount.setBalance(1000);
CheckingAccount checkingAccount;
checkingAccount.setBalance(2000);
*/

///////////////////////////////////////////////////////////////////////////////////////
	int choice;
	int counter = 0;
	double balance, debit, credit, rate;
	bool accountOpened[3] = { false, false, false };  // tracks which accounts have been opened for "check balances of all accounts" function
	vector<Account*> accountVector{ 0,0,0 };
	Account account(0);

	bool sStatement = true;
	while (sStatement == true) {

		cout << fixed << setprecision(2);
		cout << "What type of account would you like to open?\n1) Basic Account\n2) Savings Account\n3) Checking Account\n"
			"4) Check balances of all Accounts\n5) Exit\n\n: ";
		// filters input other than numbers
		while (!(cin >> choice)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please choose a number selection.\n";
		}

		cout << "\n";
		switch (choice) {

		case 1:
		{
			account.message1();
			cout << "Account: $ ";
			balance = account.getInput();
			account.setBalance(balance);
			Account* accountPtr{ &account };
			accountVector[0] = accountPtr;

			account.message2();
			cout << "Account?\n: $ ";
			debit = account.getInput();
			account.debit(debit);

			account.message3();
			cout << "Account?\n: $ ";
			credit = account.getInput();
			account.credit(credit);
			accountOpened[0] = true;
			break;
		}
		case 2:
		{
			account.message1();
			cout << "Savings Account: $ ";
			balance = account.getInput();
			SavingsAccount savingsAccount(0);
			savingsAccount.setBalance(balance);
			Account* savingsAccountPtr{ &savingsAccount };
			accountVector[1] = savingsAccountPtr;

			cout << "\nWhat is the intrest rate of your Savings Account?\n: % ";
			rate = account.getInput();
			savingsAccount.setIntrestRate(rate);

			account.message2();
			cout << "Savings Account?\n: $ ";
			debit = account.getInput();
			savingsAccount.debit(debit);

			account.message3();
			cout << "Account?\n: $ ";
			credit = account.getInput();
			savingsAccount.credit(credit);
			
			cout << "\nYou have earned $" << savingsAccount.calculateIntrest() << " in intrest at a rate of %" << rate <<
				"\nYour new balance is $ " << savingsAccount.getBalance() + savingsAccount.calculateIntrest() << "\n" << endl;
			savingsAccount.setBalance(savingsAccount.getBalance() + savingsAccount.calculateIntrest());
			accountOpened[1] = true;
			break;
		}
		case 3:
		{
			account.message1();
			cout << "Checking Account: $ ";
			balance = account.getInput();
			CheckingAccount checkingAccount(0);
			checkingAccount.setBalance(balance);
			Account* checkingAccountPtr{ &checkingAccount };
			accountVector[2] = checkingAccountPtr;

			account.message2();
			cout << "Checking Account?\n: $ ";
			debit = account.getInput();
			checkingAccount.debit(debit);

			account.message3();
			cout << "Checking Account?\n: $ ";
			credit = account.getInput();
			checkingAccount.credit(credit);
			accountOpened[2] = true;
			break;
		}
		case 4:
		{
				string accountNames[3] = { "Basic Account","Savings Account", "Checking Account" };

				for (int i = 0; i < 3; i++) {
					if (accountOpened[i] == true) {
						cout << setw(0) << accountNames[i] << setw(20) << "$" << accountVector[i]->getBalance() << "\n";
					}
					else {
						counter++;
					}
				}
				if (counter == 3) {
					cout << "No Accounts have been opened.\n" << endl;
				}
				cout << "\n";
				counter = 0;
				break;
		}
		case 5:
		{
			sStatement = false;
			return sStatement;
		}
		default:
		{
			cout << "Invalid input. Please choose a number from the above choices.\n\n" << endl;
		}
		} // end switch
	}	 // end while 

}



