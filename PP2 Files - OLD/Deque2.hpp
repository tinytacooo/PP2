#ifndef DEQUE2_H
#define DEQUE2_h

#include <sstream>
#include <iostream>

class node
{
    public:
        std::string str;
        node* next;
        node* prev;
};

class Deque {
public:
    node* newnode;
    node* temp;
    node* head;
    node* tail;

    void create_node(const std::string &s);
    void init(const std::string &s);
    void insertFront(const std::string &s);
    void insertBack(const std::string &s);
    const std::string removeFront();
    const std::string removeBack();
    void printList();
};

#endif