#ifndef MYFINANCE_OPERATION_H
#define MYFINANCE_OPERATION_H

#include "Date.h"
#include "TypeOperation.h"
#include "Category.h"

class Operation {
private:
    TypeOperation _type;
    Date* _date;
    double _sum;
    Category* _category;
    bool _isDelete;

public:
    Operation(TypeOperation type, Date* date, double sum, Category* category) {
        _type = type;
        _category = category;
        _date = date;
        _sum = sum;

        _isDelete = false;
    }

    TypeOperation GetType() {
        return _type;
    }

    Date* GetDate() {
        return _date;
    }

    double GetSum() {
        return _sum;
    }

    Category* GetCategory() {
        return _category;
    }

    bool IsDelete() {
        return _isDelete;
    }
    void Delete() {
        _isDelete = true;
    }
};


#endif //MYFINANCE_OPERATION_H
