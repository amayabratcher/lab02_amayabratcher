// intlist.cpp
// Implements class IntList
// Amaya Bratcher 4/14/2025

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if(source.head == NULL){
        this -> head = nullptr;
        
    }
    else{
        Node* p = source.head;
        this -> head =  new Node;
        this -> head -> info = p -> info;
        this -> head -> next = nullptr;
        this -> tail =  this -> head;

        p = p -> next;
        while(p !=  nullptr){
            this -> tail -> next = new Node; 
            this -> tail  = this -> tail -> next;
            this -> tail -> info =  p -> info;
            this -> tail -> next = nullptr;
            p = p -> next;
        }
        
      
    }

}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    while(this -> head != nullptr){
        Node* p =  this -> head -> next;
        delete this -> head;
        this -> head = p;
    }
}



// return sum of values in list
int IntList::sum() const {
    Node* p =  this -> head;
    int sum = 0;
    while(p != nullptr){
        sum += p -> info;
        p = p-> next; 
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* p  =  this -> head;
    while(p != nullptr){
        if(p -> info  == value){
            return true;
        }
        p = p -> next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    
    if(this -> head  == nullptr){
        return 0;
    }
    
    int max =  this -> head -> info;
    Node* p = this -> head;
    while(p != nullptr){
        if(p -> info > max){
            max = p -> info;
        }
        p = p -> next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(this -> head == nullptr){
        return 0;
    }
    double average =  double(this -> sum()) / double(this -> count());
   return average;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* p = new Node;
    p -> info = value;
    p -> next = this -> head;
    this -> head = p;

    if(this -> tail  == nullptr){
        this -> tail = this -> head -> next;
    }
    
}

// append value at end of list
void IntList::push_back(int value) {
    if(this -> head == nullptr){
        this -> head = new Node;
        this -> head -> info = value;
        this -> tail = this -> head;
    }
    else{
    this -> tail -> next  = new Node;
    this -> tail =  this -> tail -> next;
    this -> tail -> info = value;
    this -> tail -> next  = nullptr;
    }
}

// return count of values
int IntList::count() const {
   int count = 0;
   if(this -> head == nullptr){
    return count;
   }
   else{
    Node* p = this -> head;
    while(p != nullptr){
        count += 1;
        p = p -> next;
    }
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    while(this -> head != nullptr){
        Node* p =  this -> head -> next;
        delete this -> head;
        this -> head = p;
    }
    if(source.head == NULL){
        this -> head = nullptr;
        
    }
    else{
        Node* p = source.head;
        this -> head =  new Node;
        this -> head -> info = p -> info;
        this -> head -> next = nullptr;
        this -> tail =  this -> head;

        p = p -> next;
        while(p !=  nullptr){
            this -> tail -> next = new Node; 
            this -> tail  = this -> tail -> next;
            this -> tail -> info =  p -> info;
            this -> tail -> next = nullptr;
            p = p -> next;
        }
        
      
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){
    this -> head = nullptr;
    this -> tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

