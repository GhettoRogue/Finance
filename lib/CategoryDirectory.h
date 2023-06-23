#ifndef MYFINANCE_CATEGORYDIRECTORY_H
#define MYFINANCE_CATEGORYDIRECTORY_H

#include <map>
#include <vector>
#include <string>

#include "Category.h"

using namespace std;

class CategoryDirectory {
private:
    map<string, Category*>* _categories;

public:
    CategoryDirectory() {
        _categories = new map<string, Category *>;
    }

    vector<Category*>* GetAll() {
        auto* categories = new vector<Category *>;

        for (auto item : *_categories) {
            categories->push_back(item.second);
        }

        return categories;
    }

    Category* Find(string name) {
        for (auto item : *_categories) {
            if (item.first == name) {
                return item.second;
            }
        }

        return nullptr;
    }

    bool Add(string name, TypeOperation type) {
        if (!_categories->count(name)) {
            return false;
        }

        _categories->insert(pair<string, Category*>(name, new Category(name, type)));

        return true;
    }

    bool Del(string name) {
        if (!_categories->count(name)) {
            return false;
        }

        _categories->at(name)->Delete();

        return true;
    }
};


#endif //MYFINANCE_CATEGORYDIRECTORY_H
