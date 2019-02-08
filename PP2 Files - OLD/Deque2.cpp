#include<string>
#include "Deque2.hpp"
// using namespace std;

void Deque::create_node(const std::string &s){
    node* newnode = new node();
    newnode->next = NULL;
    newnode->prev = NULL;
}

void Deque::init(const std::string &s){
    head = NULL;
    tail = NULL;
    create_node(s);
    head = newnode;
    tail = newnode;
}

void Deque::insertFront(const std::string &s){
    create_node(s);
    newnode->next = head;
    head->prev= newnode;
    head = head->prev;
}

void Deque::insertBack(const std::string &s){
    create_node(s);
    newnode->prev = tail;
    tail->next = newnode;
    tail = tail->next;
}

const std::string Deque::removeFront(){
    std::string ret = head->str;
    head = head->next;
    return ret;
}

const std::string Deque::removeBack(){
    std::string ret = tail->str;
    tail = tail->prev;
    tail->next = NULL;
    return ret;
}

void Deque::printList()
{
    temp = head;
    while(temp != tail){
        cout<<temp->str<<" ";
        temp = temp->next;
    }
}