#ifndef HASHSET_H
#define HASHSET_H

#include <unordered_set>
#include <iostream>

template <typename T>
class HashSet {
private:
    std::unordered_set<T> elements;

public:
    // Добавление элемента
    void Add(const T& element);

    // Удаление элемента
    void Remove(const T& element);

    // Объединение двух коллекций
    HashSet<T> Union(const HashSet<T>& other) const;

    // Разность двух коллекций
    HashSet<T> Except(const HashSet<T>& other) const;

    // Пересечение двух коллекций
    HashSet<T> Intersect(const HashSet<T>& other) const;

    // Проверка на наличие элемента
    bool Contains(const T& element) const;

    // Вывод всех элементов (для отладки)
    void Print() const;
};

// Добавление элемента
template <typename T>
void HashSet<T>::Add(const T& element) {
    elements.insert(element);
}

// Удаление элемента
template <typename T>
void HashSet<T>::Remove(const T& element) {
    elements.erase(element);
}

// Объединение двух коллекций
template <typename T>
HashSet<T> HashSet<T>::Union(const HashSet<T>& other) const {
    HashSet<T> result = *this;
    for (const auto& element : other.elements) {
        result.Add(element);
    }
    return result;
}

// Разность двух коллекций
template <typename T>
HashSet<T> HashSet<T>::Except(const HashSet<T>& other) const {
    HashSet<T> result;
    for (const auto& element : elements) {
        if (other.elements.find(element) == other.elements.end()) {
            result.Add(element);
        }
    }
    return result;
}

// Пересечение двух коллекций
template <typename T>
HashSet<T> HashSet<T>::Intersect(const HashSet<T>& other) const {
    HashSet<T> result;
    for (const auto& element : elements) {
        if (other.elements.find(element) != other.elements.end()) {
            result.Add(element);
        }
    }
    return result;
}

// Проверка на наличие элемента
template <typename T>
bool HashSet<T>::Contains(const T& element) const {
    return elements.find(element) != elements.end();
}

// Вывод всех элементов
template <typename T>
void HashSet<T>::Print() const {
    for (const auto& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#endif // HASHSET_H
