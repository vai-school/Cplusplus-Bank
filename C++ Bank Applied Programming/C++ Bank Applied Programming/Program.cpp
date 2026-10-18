#include <iostream>
#include <list>
#include <algorithm>
#include <limits>
#include "account.h"


void managerMenu(std::list<Account>& accounts) {
    bool done = false;
    int choice;
    int id;

    while (!done) {
        std::cout << "\nManager Menu:\n";
        std::cout << "0. Back\n";
        std::cout << "1. Show all accounts\n";
        std::cout << "2. Add new account\n";
        std::cout << "3. Remove account\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (!std::cin) { //Error Handling for if its not a number
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That wasn't a number.\n";
            continue;
        }

        if (choice == 0) {
            done = true;
        }
        else if (choice == 1) {
            if (accounts.empty()) {
                std::cout << "No accounts yet.\n";
            }
            std::for_each(accounts.begin(), accounts.end(), [](const Account& a) {
                a.display();
                });
        }
        else if (choice == 2) {
            Account newAccount;
            newAccount.getInfo();
            accounts.push_back(newAccount);
        }
        else if (choice == 3) {
            std::cout << "Enter account ID to remove: ";
            std::cin >> id;

            if (!std::cin) { //Error Handling for if its not a number
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That wasn't a number.\n";
                continue;
            }

            auto it = findAccount(accounts, id);
            if (it == accounts.end()) {
                std::cout << "Account not found.\n";
            }
            else {
                accounts.erase(it);
                std::cout << "Account removed.\n";
            }
        }
        else {
            std::cout << "Invalid choice. Please enter 0-3.\n";
        }
    }
}

void customerMenu(std::list<Account>& accounts) {
    int id;
    std::cout << "Enter your account ID: ";
    std::cin >> id;

    if (!std::cin) { //Error Handling for if its not a number
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That wasn't a number.\n";
        return;
    }

    auto it = findAccount(accounts, id);
    if (it == accounts.end()) {
        std::cout << "Account not found.\n";
        return;
    }

    bool done = false;
    int choice;
    float amount;

    while (!done) {
        std::cout << "\nCustomer Menu:\n";
        std::cout << "0. Back\n";
        std::cout << "1. View my account\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Desposit\n";
        std::cout << "4. Remove my account\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (!std::cin) { //Error Handling for if its not a number
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That wasn't a number.\n";
            continue;
        }

        if (choice == 0) {
            done = true;
        }
        else if (choice == 1) {
            it->display();
        }
        else if (choice == 2) {
            std::cout << "Amount to withdraw: ";
            std::cin >> amount;

            if (!std::cin) { //Error Handling for if its not a number
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That wasn't a number.\n";
                continue;
            }

            it->withdraw(amount);
        }
        else if (choice == 3) {
            std::cout << "Amount to deposit: ";
            std::cin >> amount;

            it->deposit(amount);
            std::cout << "Deposit successful.\n";
        }
        else if (choice == 4) {
            accounts.erase(it);
            std::cout << "Account removed.\n";
            done = true;   // 'it' is invalid after erase, so we must leave :/
        }
        else {
            std::cout << "Invalid choice. Please enter 0-3.\n";
        }
    }
}

int main() {
    std::list<Account> accounts;
    bool done = false;
    int choice;

    while (!done) {
        std::cout << "\nWelcome:\n";
        std::cout << "0. Quit Program\n";
        std::cout << "1. Customer\n";
        std::cout << "2. Manager\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (!std::cin) { //Error Handling for if its not a number
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "That wasn't a number.\n";
            continue;
        }

        if (choice == 0) {
            done = true;
        }
        else if (choice == 1) {
            customerMenu(accounts);
        }
        else if (choice == 2) {
            managerMenu(accounts);
        }
        else { // "Error Handling" for when its not 1 of the 2 options
            std::cout << "Invalid choice. Please enter 0-2.\n";
        }
    }
    return 0;
}
