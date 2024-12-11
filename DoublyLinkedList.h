
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

// Шаблонный класс для элемента двунаправленного списка
template <typename T>
class Node1 {
public:
    T data;        // данные элемента
    Node1* prev;    // указатель на предыдущий элемент
    Node1* next;    // указатель на следующий элемент

    Node1(T val) : data(val), prev(nullptr), next(nullptr) {}  // Конструктор с параметром
};

// Шаблонный класс для двунаправленного списка
template <typename T>
class DoublyLinkedList {
private:
    Node1<T>* head;  // указатель на первый элемент списка
    Node1<T>* tail;  // указатель на последний элемент списка

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}  // Конструктор

    // Метод для добавления элемента в конец списка
    void addElement(T data) {
        Node1<T>* newNode = new Node1<T>(data);
        if (!head) {  // Если список пуст
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Метод для удаления элемента из списка
    void removeElement(T data) {
        Node1<T>* current = head;
        while (current) {
            if (current->data == data) {
                if (current->prev) {  // Если это не первый элемент
                    current->prev->next = current->next;
                }
                else {  // Если это первый элемент
                    head = current->next;
                }

                if (current->next) {  // Если это не последний элемент
                    current->next->prev = current->prev;
                }
                else {  // Если это последний элемент
                    tail = current->prev;
                }

                delete current;  // Освобождаем память
                return;
            }
            current = current->next;
        }
        cout << "Элемент не найден!" << endl;
    }

    // Метод для удаления первого вхождения элемента
    void removeFirstOccurrence(T data) {
        removeElement(data);
    }

    // Метод для вывода всех элементов списка
    void printList() const {
        Node1<T>* current = head;
        if (!current) {
            cout << "Список пуст!" << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Метод для вывода соседей элемента
    void printNeighbors(T data) {
        Node1<T>* current = head;
        while (current) {
            if (current->data == data) {
                if (current->prev)
                    cout << "Предыдущий элемент: " << current->prev->data << endl;
                else
                    cout << "Предыдущего элемента нет." << endl;

                if (current->next)
                    cout << "Следующий элемент: " << current->next->data << endl;
                else
                    cout << "Следующего элемента нет." << endl;

                return;
            }
            current = current->next;
        }
        cout << "Элемент не найден!" << endl;
    }

    // Деструктор для освобождения памяти
    ~DoublyLinkedList() {
        Node1<T>* current = head;
        while (current) {
            Node1<T>* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
};

#endif // DOUBLY_LINKED_LIST_H

