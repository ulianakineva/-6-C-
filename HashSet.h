#ifndef HASHSET_H
#define HASHSET_H

#include <unordered_set>
#include <iostream>

template <typename T>
class HashSet {
private:
    std::unordered_set<T> elements;

public:
    // ���������� ��������
    void Add(const T& element);

    // �������� ��������
    void Remove(const T& element);

    // ����������� ���� ���������
    HashSet<T> Union(const HashSet<T>& other) const;

    // �������� ���� ���������
    HashSet<T> Except(const HashSet<T>& other) const;

    // ����������� ���� ���������
    HashSet<T> Intersect(const HashSet<T>& other) const;

    // �������� �� ������� ��������
    bool Contains(const T& element) const;

    // ����� ���� ��������� (��� �������)
    void Print() const;
};

// ���������� ��������
template <typename T>
void HashSet<T>::Add(const T& element) {
    elements.insert(element);
}

// �������� ��������
template <typename T>
void HashSet<T>::Remove(const T& element) {
    elements.erase(element);
}

// ����������� ���� ���������
template <typename T>
HashSet<T> HashSet<T>::Union(const HashSet<T>& other) const {
    HashSet<T> result = *this;
    for (const auto& element : other.elements) {
        result.Add(element);
    }
    return result;
}

// �������� ���� ���������
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

// ����������� ���� ���������
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

// �������� �� ������� ��������
template <typename T>
bool HashSet<T>::Contains(const T& element) const {
    return elements.find(element) != elements.end();
}

// ����� ���� ���������
template <typename T>
void HashSet<T>::Print() const {
    for (const auto& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#endif // HASHSET_H
