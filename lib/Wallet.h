#ifndef MYFINANCE_WALLET_H
#define MYFINANCE_WALLET_H

#include <string>
#include <map>
#include <vector>

#include "Date.h"
#include "Operation.h"

using namespace std;

class Wallet {
private:
    string _name;
    double _balance;
    bool _isDelete;

    multimap<Date*, Operation*>* _listOfDebit;
    multimap<Date*, Operation*>* _listOfCredit;

public:
    Wallet(string name, double balance = 0) {
        _name = name;
        _balance = balance;

        _listOfDebit = new multimap<Date*, Operation*>;
        _listOfCredit = new multimap<Date*, Operation*>;

        _isDelete = false;
    }

    bool Income(TypeOperation type, Date* date, double sum, Category* category) {
        if (category->GetType() != type) {
            return false;
        }

        _listOfDebit->insert(pair<Date*, Operation*>(date, new Operation(type, date, sum, category)));
        return true;
    }

    bool Expense(TypeOperation type, Date* date, double sum, Category* category) {
        if (category->GetType() != type) {
            return false;
        }

        _listOfCredit->insert(pair<Date*, Operation*>(date, new Operation(type, date, sum, category)));
        return true;
    }

    string GetName(){
        return _name;
    }

    double GetBalance() {
        return _balance;
    }

    bool IsDelete() {
        return _isDelete;
    }

    void Delete() {
        _isDelete = true;
    }

    vector<Operation*>* GetListOfDebit() {
        auto* list = new vector<Operation*>;

        for (auto item : *_listOfDebit) {
            list->push_back(item.second);
        }

        return list;
    }

    vector<Operation*>* GetListOfCredit() {
        auto* list = new vector<Operation*>;

        for (auto item : *_listOfCredit) {
            list->push_back(item.second);
        }

        return list;
    }
};


#endif //MYFINANCE_WALLET_H
