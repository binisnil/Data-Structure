//
// Created by 박윤빈 on 2022/05/16.
//

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
public:
    Node* head=NULL;
    Node* tail=NULL;
    void Append(int data);
    void Prepend(int data);
    int Length();
    void Print();
    void PrintReverse();
};

#endif //LINKEDLIST_LIST_H
