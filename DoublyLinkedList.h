
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

// ��������� ����� ��� �������� ���������������� ������
template <typename T>
class Node1 {
public:
    T data;        // ������ ��������
    Node1* prev;    // ��������� �� ���������� �������
    Node1* next;    // ��������� �� ��������� �������

    Node1(T val) : data(val), prev(nullptr), next(nullptr) {}  // ����������� � ����������
};

// ��������� ����� ��� ���������������� ������
template <typename T>
class DoublyLinkedList {
private:
    Node1<T>* head;  // ��������� �� ������ ������� ������
    Node1<T>* tail;  // ��������� �� ��������� ������� ������

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}  // �����������

    // ����� ��� ���������� �������� � ����� ������
    void addElement(T data) {
        Node1<T>* newNode = new Node1<T>(data);
        if (!head) {  // ���� ������ ����
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // ����� ��� �������� �������� �� ������
    void removeElement(T data) {
        Node1<T>* current = head;
        while (current) {
            if (current->data == data) {
                if (current->prev) {  // ���� ��� �� ������ �������
                    current->prev->next = current->next;
                }
                else {  // ���� ��� ������ �������
                    head = current->next;
                }

                if (current->next) {  // ���� ��� �� ��������� �������
                    current->next->prev = current->prev;
                }
                else {  // ���� ��� ��������� �������
                    tail = current->prev;
                }

                delete current;  // ����������� ������
                return;
            }
            current = current->next;
        }
        cout << "������� �� ������!" << endl;
    }

    // ����� ��� �������� ������� ��������� ��������
    void removeFirstOccurrence(T data) {
        removeElement(data);
    }

    // ����� ��� ������ ���� ��������� ������
    void printList() const {
        Node1<T>* current = head;
        if (!current) {
            cout << "������ ����!" << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // ����� ��� ������ ������� ��������
    void printNeighbors(T data) {
        Node1<T>* current = head;
        while (current) {
            if (current->data == data) {
                if (current->prev)
                    cout << "���������� �������: " << current->prev->data << endl;
                else
                    cout << "����������� �������� ���." << endl;

                if (current->next)
                    cout << "��������� �������: " << current->next->data << endl;
                else
                    cout << "���������� �������� ���." << endl;

                return;
            }
            current = current->next;
        }
        cout << "������� �� ������!" << endl;
    }

    // ���������� ��� ������������ ������
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

