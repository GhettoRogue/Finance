#ifndef MYFINANCE_USER_H
#define MYFINANCE_USER_H

#include <string>
#include <map>

#include "Wallet.h"

using namespace std;

class User {
private:
    string _name;
    map<string, Wallet*>* _wallets;
    bool _isDelete;

public:
    User(string name) {
        _name = name;
        _wallets = new map<string, Wallet*>;
        _isDelete = false;
    }

    bool AddWallet(string name, double balance = 0) {
        if (!_wallets->count(name)) {
            return false;
        }

        _wallets->insert(pair<string, Wallet*>(name, new Wallet(name, balance)));

        return true;
    }

    bool DelWallet(string name, double balance = 0) {
        if (!_wallets->count(name)) {
            return false;
        }

        _wallets->at(name)->Delete();

        return true;
    }

    vector<Wallet*>* GetAll() {
        auto* wallets = new vector<Wallet*>;

        for (auto item : *_wallets) {
            wallets->push_back(item.second);
        }

        return wallets;
    }

    Wallet* Find(string name) {
        for (auto item : *_wallets) {
            if (item.first == name) {
                return item.second;
            }
        }

        return nullptr;
    }

    void Delete() {
        _isDelete = true;
    }

    bool IsDelete() {
        return _isDelete;
    }
};


#endif //MYFINANCE_USER_H
