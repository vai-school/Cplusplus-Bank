
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <list>

#include <string>

class Account {
private:
    int id;
    std::string name;
    float balance;
    static int nextId;

public:
    Account();
    void getInfo();
    void display() const;
    void deposit(float amount);
    void withdraw(float amount);
    int getID() const;
    int get_id() const;
    float get_balance() const;

};

std::list<Account>::iterator findAccount(std::list<Account>& accounts, int id);

#endif