#ifndef OLIMPIAD_H
#define OLIMPIAD_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class Olimpiad {
public:
    void addElement(const Key& key, const Value& value) {
        olympiad[key] = value;
    }

    void removeElement(const Key& key) {
        olympiad.erase(key);
    }

    Value getElement(const Key& key) const {
        auto it = olympiad.find(key);
        if (it != olympiad.end()) {
            return it->second;
        }
        throw out_of_range("Ёлемент не найден");
    }

    bool containsKey(const Key& key) const {
        return olympiad.find(key) != olympiad.end();
    }

    vector<Key> getAllKeys() const {
        vector<Key> keys;
        for (const auto& pair : olympiad) {
            keys.push_back(pair.first);
        }
        return keys;
    }

    vector<Value> getAllValues() const {
        vector<Value> values;
        for (const auto& pair : olympiad) {
            values.push_back(pair.second);
        }
        return values;
    }

    vector<pair<Key, Value>> getAllElements() const {
        std::vector<pair<Key, Value>> elements;
        for (const auto& pair : olympiad) {
            elements.push_back(pair);
        }
        return elements;
    }

private:
    map<Key, Value> olympiad;
};

#endif
