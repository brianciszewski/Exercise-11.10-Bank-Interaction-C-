#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_h

class Account {
public:

	// default constructor
	Account();

	Account(double newBalance);

	double balance = 0.0;

	void setBalance(double newBalance);

	double getBalance() const;

	void credit(double creditAmount) ;

	void debit(double debitAmount) ;

	void message1();
	void message2();
	void message3();

	double getInput();
};

#endif