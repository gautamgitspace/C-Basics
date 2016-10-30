//
//  main.cpp
//  CircularLinkedList
//
//  Created by Gautam on 10/29/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

#include <iostream>


using namespace std;

struct node
{
    int data;
    struct node* next;
}*last;

class CircularLinkedList
{
    
public:
    void createNode(int value);
    void addToBeginning(int value);
    void addAfter(int value, int pos);
    void deleteElement(int value);
    bool searchElement(int value);
    void displayList();
    void sortList();
    
    CircularLinkedList()
    {
        last = NULL;
    }
    
};



int main(int argc, const char * argv[])
{
    // insert code here...
    return 0;
}

void CircularLinkedList::createNode(int value)
{
    struct node *newNode;
    newNode = new(struct node);
    newNode->data = value;
    if(last == NULL)
    {
        last = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void CircularLinkedList::addToBeginning(int value)
{
    struct node *newNode;
    newNode = new(struct node);
    newNode->data = value;
    newNode->next = last->next;
    last->next = newNode;
}

void CircularLinkedList::addAfter(int value, int pos)
{
    struct node *newNode, *head;
    newNode = new(struct node);
    head = last->next;
    for(int i=0; i<pos-1;i++)
    {
        head=head->next;
        if(head == last->next)
        {
            cout<<"Number of elements less than"<<pos<<endl;
        }
    }
    newNode->next = head->next;
    head->next = newNode;
    newNode->data = value;
    
    /*element inserted at the last*/
    if(head == last)
    {
        last = newNode;
    }
}

void CircularLinkedList::deleteElement(int value)
{
    struct node *newNode, *ptr;
    ptr = last->next;
    /*CASE - only one element in the list*/
    if(last->next == last && last->data == value)
    {
        newNode = last;
        last = NULL;
        free(newNode);
        return;
    }
    /*CASE - first element in the list*/
    if(ptr->data == value)
    {
        newNode = ptr;
        ptr = ptr->next;
        last->next = ptr;
        free(newNode);
        return;
    }
    /*CASE - element in the list*/
    while (ptr->next!=last)
    {
        if(ptr->next->data == value)
        {
            newNode = ptr->next;
            ptr->next = newNode->next;
            free(newNode);
            return;
        }
        ptr = ptr->next;
    }
    /*CASE - last element in the list*/
    if(ptr->next->data == value)
    {
        newNode = ptr->next;
        ptr->next = last->next;
        free(newNode);
        last = ptr;
        return;
    }
    /*when not found*/
    cout<<"Element not found in the list"<<endl;
    
}

bool CircularLinkedList::searchElement(int value)
{
    struct node *ptr;
    ptr = last->next;
    while(ptr!=last)
    {
        if(ptr->data == value)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

void CircularLinkedList::displayList()
{
    if(last == NULL)
    {
        cout<<"EMPTY LIST"<<endl;
    }
    struct node *ptr;
    ptr = last->next;
    while(ptr!=last)
    {
        cout<<ptr->data<<endl;
    }
    ptr = ptr->next;
}

void CircularLinkedList::sortList()
{
    struct node *ptr, *compare;
    int temp;
    ptr = last->next;
    if(last == NULL)
    {
        cout<<"EMPTY LIST"<<endl;
    }
    while(ptr!=last)
    {
        compare = ptr->next;
        while (compare!=last->next)
        {
            if(compare!=last->next)
            {
                if(ptr->data > compare->data)
                {
                    temp = ptr->data;
                    ptr->data = compare->data;
                    compare->data = temp;
                }
            }
            else
            {
                break;
            }
            compare=compare->next;
        }
        ptr=ptr->next;
    }
}
