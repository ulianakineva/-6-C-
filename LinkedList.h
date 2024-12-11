#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <unordered_set>
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Конструктор узла
    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Голова списка

    bool containsDuplicatesHelper(Node<T>* node, std::unordered_set<T>& seen);

public:
    LinkedList();   // Конструктор
    ~LinkedList();  // Деструктор

    void add(T data);    // Метод для добавления элемента
    void remove(T data); // Метод для удаления элемента
    bool containsDuplicates(); // Метод для проверки на дубликаты
    void print();         // Метод для печати списка
};

// Реализация конструктора и деструктора прямо здесь в заголовочном файле
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Реализация метода добавления элемента
template <typename T>
void LinkedList<T>::add(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Реализация метода удаления элемента
template <typename T>
void LinkedList<T>::remove(T data) {
    if (head == nullptr) {
        std::cout << "Список пуст. Удаление невозможно.\n";
        return;
    }

    // Если элемент для удаления — это голова списка
    if (head->data == data) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        std::cout << "Элемент " << data << " удалён из списка.\n";
        return;
    }

    Node<T>* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    // Если элемент не найден
    if (current->next == nullptr) {
        std::cout << "Элемент " << data << " не найден в списке.\n";
        return;
    }

    // Удаление найденного элемента
    Node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
    std::cout << "Элемент " << data << " удалён из списка.\n";
}


// Реализация метода для проверки на дубликаты
template <typename T>
bool LinkedList<T>::containsDuplicates() {
    std::unordered_set<T> seen;
    return containsDuplicatesHelper(head, seen);
}

template <typename T>
bool LinkedList<T>::containsDuplicatesHelper(Node<T>* node, std::unordered_set<T>& seen) {
    if (node == nullptr) {
        return false;
    }
    if (seen.find(node->data) != seen.end()) {
        return true; // Дубликат найден
    }
    seen.insert(node->data);
    return containsDuplicatesHelper(node->next, seen);
}

// Реализация метода для печати списка
template <typename T>
void LinkedList<T>::print() {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // LINKEDLIST_H
