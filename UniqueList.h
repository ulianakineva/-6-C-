#ifndef UNIQUE_LIST_H
#define UNIQUE_LIST_H

#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

template <typename T>
class UniqueList {  // Открытие класса
private:
    set<T> elements; // Используем std::set для хранения уникальных элементов

public:
    // Метод для добавления элемента
    void Add(const T& value) {
        elements.insert(value);
    }

    // Метод для удаления элемента
    void Remove(const T& value) {
        elements.erase(value);
    }

    // Метод Union (объединяет две коллекции)
    UniqueList Union(const UniqueList& other) const {
        UniqueList result;
        result.elements.insert(elements.begin(), elements.end());
        result.elements.insert(other.elements.begin(), other.elements.end());
        return result;
    }

    // Метод Except (удаляет из первой коллекции элементы второй)
    UniqueList Except(const UniqueList& other) const {
        UniqueList result;
        set_difference(elements.begin(), elements.end(),
            other.elements.begin(), other.elements.end(),
            inserter(result.elements, result.elements.begin()));
        return result;
    }

    // Метод Intersect (общие элементы двух коллекций)
    UniqueList Intersect(const UniqueList& other) const {
        UniqueList result;
        set_intersection(elements.begin(), elements.end(),
            other.elements.begin(), other.elements.end(),
            inserter(result.elements, result.elements.begin()));
        return result;
    }

    // Метод Contains (проверяет наличие элемента)
    bool Contains(const T& value) const {
        return elements.find(value) != elements.end();
    }

    // Метод для печати элементов списка
    void Print() const {
        // Устанавливаем локаль для корректного вывода символов
        setlocale(LC_ALL, "ru_RU.UTF-8");
        wcout.imbue(locale("ru_RU.UTF-8"));

        for (const auto& el : elements) {
            // Преобразуем код в символ через функцию rucode
            wchar_t symbol = static_cast<wchar_t>(el);
            wcout << symbol << L" ";  // Выводим символ с пробелом между ними
        }
        wcout << endl;  // Переход на новую строку после вывода всех элементов
    }

    // Метод для получения всех элементов списка
    const set<T>& GetElements() const {
        return elements;
    }

};

#endif // UNIQUE_LIST_H
