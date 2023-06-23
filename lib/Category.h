#ifndef MYFINANCE_CATEGORY_H
#define MYFINANCE_CATEGORY_H

#include <string>

#include "TypeOperation.h"

using namespace std;

class Category {
private:
    string _name;
    TypeOperation _type;
    bool _isDelete;

public:
    Category(string name, TypeOperation type) {
        _name = name;
        _type = type;
        _isDelete = false;
    }

    string GetName() {
        return _name;
    }

    TypeOperation GetType() {
        return _type;
    }

    void Delete() {
        _isDelete = true;
    }

    bool IsDelete() {
        return _isDelete;
    }
};


#endif //MYFINANCE_CATEGORY_H
