#include "BankAccount.h"

int BankAccount::total = 0;

BankAccount::BankAccount() {
	this->balance = 0;
}

BankAccount::BankAccount(int input) {
	this->balance = input;
	total += input;
}

void BankAccount::withdraw(int output) {
	this->balance -= output;
	total -= output;
}

void BankAccount::save(int input) {
	this->balance += input;
	total += input;
}

int BankAccount::getBalance() {
	return this->balance;
}