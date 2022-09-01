//
// (다) 분반의 20211799 유진 학생과 함께 의논하여 코드를 작성하였습니다.
//
#include <sstream>
#include "list.h"

void LinkedList::Append(int data) { //List의 마지막에 새로운 data에 대한 Node추가

    Node* newnode=new Node;

    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(head==NULL&&tail==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        Node* cur=head;
        while (cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=newnode;
        newnode->prev=cur;
        tail=newnode;
    }
}

void LinkedList::Prepend(int data) {
    Node* newnode=new Node;
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL&&tail==NULL) {
        head = newnode;
        tail = newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

int LinkedList::Length() {
    int count = 0;
    Node* cur=head;
    while (cur!=NULL){
        count++;
        cur = cur->next;
    }
    cout<<endl;
    return count;
}

void LinkedList::Print() {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << ' ';
        cur = cur->next;
    }
}

void LinkedList::PrintReverse() {
    Node* cur=tail;
     while (cur != NULL){
         cout << cur->data << ' ';
         cur=cur->prev;
    }
}