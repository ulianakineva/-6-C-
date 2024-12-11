#ifndef UNIQUE_LIST_H
#define UNIQUE_LIST_H

#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

template <typename T>
class UniqueList {  // �������� ������
private:
    set<T> elements; // ���������� std::set ��� �������� ���������� ���������

public:
    // ����� ��� ���������� ��������
    void Add(const T& value) {
        elements.insert(value);
    }

    // ����� ��� �������� ��������
    void Remove(const T& value) {
        elements.erase(value);
    }

    // ����� Union (���������� ��� ���������)
    UniqueList Union(const UniqueList& other) const {
        UniqueList result;
        result.elements.insert(elements.begin(), elements.end());
        result.elements.insert(other.elements.begin(), other.elements.end());
        return result;
    }

    // ����� Except (������� �� ������ ��������� �������� ������)
    UniqueList Except(const UniqueList& other) const {
        UniqueList result;
        set_difference(elements.begin(), elements.end(),
            other.elements.begin(), other.elements.end(),
            inserter(result.elements, result.elements.begin()));
        return result;
    }

    // ����� Intersect (����� �������� ���� ���������)
    UniqueList Intersect(const UniqueList& other) const {
        UniqueList result;
        set_intersection(elements.begin(), elements.end(),
            other.elements.begin(), other.elements.end(),
            inserter(result.elements, result.elements.begin()));
        return result;
    }

    // ����� Contains (��������� ������� ��������)
    bool Contains(const T& value) const {
        return elements.find(value) != elements.end();
    }

    // ����� ��� ������ ��������� ������
    void Print() const {
        // ������������� ������ ��� ����������� ������ ��������
        setlocale(LC_ALL, "ru_RU.UTF-8");
        wcout.imbue(locale("ru_RU.UTF-8"));

        for (const auto& el : elements) {
            // ����������� ��� � ������ ����� ������� rucode
            wchar_t symbol = static_cast<wchar_t>(el);
            wcout << symbol << L" ";  // ������� ������ � �������� ����� ����
        }
        wcout << endl;  // ������� �� ����� ������ ����� ������ ���� ���������
    }

    // ����� ��� ��������� ���� ��������� ������
    const set<T>& GetElements() const {
        return elements;
    }

};

#endif // UNIQUE_LIST_H
