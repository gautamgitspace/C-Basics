//
//  main.cpp
//  DoublyLinkedList
//
//  Created by Gautam on 10/30/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node * next;
    struct node* prev;
}*start;

class DoublyLinkedList
{
    public:
    
        void create(int value);
        void addBeginning(int value);
        void addAfter(int value, int post);
        void deleteElement(int value);
        bool searchElement(int value);
        void displayList();
        void reverse();
        DoublyLinkedList()
        {
            start = NULL;
        }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

void DoublyLinkedList::create(int value)
{
    struct node *newNode, *ptr;
    newNode = new (struct node);
    newNode->data = value;
    newNode->next = NULL;
    
    if(start == NULL)
    {
        newNode->prev = NULL;
        start = newNode;
    }
    else
    {   /*ITERATE THE LIST AND REACH THE LAST*/
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        /*LINK FWD TO LAST*/
        ptr->next = newNode;
        /*LINK BACK FROM LAST*/
        newNode->prev = ptr;
    }
}

void DoublyLinkedList::addAfter(int value, int pos)
{
    struct node *ptr, *newNode;
    ptr = start;
    for(int i=0; i<pos-1; i++)
    {
        ptr=ptr->next;
    }
    newNode = new (struct node);
    newNode->data = value;
    
    /*CASE: INSERT AFTER LAST ELEMENT*/
    if(ptr->next == NULL)
    {
        ptr->next = newNode;
        newNode->prev = ptr;
        newNode->next = NULL;
    }
    /*CASE: OTHER*/
    else
    {
        ptr->next = newNode;
        newNode->next = ptr->next;
        newNode->prev = ptr;
        newNode->next->prev = newNode;
    }
}

void DoublyLinkedList::addBeginning(int value)
{
    struct node *newNode;
    newNode = new (struct node);
    newNode->data = value;
    
    newNode->next = start;
    newNode->prev = NULL;
    start->prev=newNode;
    start = newNode;
}

void DoublyLinkedList::deleteElement(int value)
{
    struct node *temp, *ptr;
    /*CASE DELETE FIRST ELEMENT*/
    if(start->data == value)
    {
        temp = start;
        start->next->prev = NULL;
        start = start->next;
        free(temp);
        return;
    }
    
    /*CASE ELEMENT IN THE LIST*/
    ptr = start;
    while (ptr->next->next != NULL)
    {
        if(ptr->next->data == value)
        {
            temp = ptr->next;
            ptr->next->next->prev = ptr;
            ptr->next = ptr->next->next;
            free(temp);
            return;
        }
        ptr=ptr->next;
    }
    /*CASE LAST ELEMENT*/
    if(ptr->next->data == value)
    {
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);
        return;
    }
    
}

bool DoublyLinkedList::searchElement(int value)
{
    struct node *ptr;
    ptr = start;
    while(ptr!=NULL)
    {
        if(ptr->data == value)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

void DoublyLinkedList::reverse()
{
    struct node *ptr1, *ptr2;
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    
    while (ptr2!=NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    start = ptr1;
}
