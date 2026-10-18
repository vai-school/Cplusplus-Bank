#include "account.h"
#include <iostream>
#include <iomanip>

int Account::nextId = 0;

Account::Account() {
    id = 0;
    name = "";
    balance = 0.0f;
}

void Account::getInfo() {
    std::cout << "Enter the name: ";
    std::cin >> name;

    std::cout << "Enter the balance: ";
    std::cin >> balance;

    id = nextId;
    nextId++;
}

void Account::display() const {
    std::cout << "Account ID: " << id << "  Name: " << name << "  Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
}

void Account::deposit(float amount) {
    balance = balance + amount;
}

void Account::withdraw(float amount) {
    balance = balance - amount;
}


int Account::getID() const {
    return id;
}

std::list<Account>::iterator findAccount(std::list<Account>& accounts, int id) {
    for (std::list<Account>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getID() == id) {
            return it;
        }
    }

    return accounts.end();
}

int Account::get_id() const {
    return id;
}

float Account::get_balance() const {
    return balance;
}