#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <unordered_set>
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    // ����������� ����
    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;  // ������ ������

    bool containsDuplicatesHelper(Node<T>* node, std::unordered_set<T>& seen);

public:
    LinkedList();   // �����������
    ~LinkedList();  // ����������

    void add(T data);    // ����� ��� ���������� ��������
    void remove(T data); // ����� ��� �������� ��������
    bool containsDuplicates(); // ����� ��� �������� �� ���������
    void print();         // ����� ��� ������ ������
};

// ���������� ������������ � ����������� ����� ����� � ������������ �����
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

// ���������� ������ ���������� ��������
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

// ���������� ������ �������� ��������
template <typename T>
void LinkedList<T>::remove(T data) {
    if (head == nullptr) {
        std::cout << "������ ����. �������� ����������.\n";
        return;
    }

    // ���� ������� ��� �������� � ��� ������ ������
    if (head->data == data) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        std::cout << "������� " << data << " ����� �� ������.\n";
        return;
    }

    Node<T>* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    // ���� ������� �� ������
    if (current->next == nullptr) {
        std::cout << "������� " << data << " �� ������ � ������.\n";
        return;
    }

    // �������� ���������� ��������
    Node<T>* temp = current->next;
    current->next = current->next->next;
    delete temp;
    std::cout << "������� " << data << " ����� �� ������.\n";
}


// ���������� ������ ��� �������� �� ���������
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
        return true; // �������� ������
    }
    seen.insert(node->data);
    return containsDuplicatesHelper(node->next, seen);
}

// ���������� ������ ��� ������ ������
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
