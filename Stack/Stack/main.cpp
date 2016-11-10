//
//  main.cpp
//  Stack
//
//  Created by Gautam on 11/2/16.
//  Copyright © 2016 Gautam. All rights reserved.
//
//  Stack using Linked List

#include <iostream>

using namespace std;

struct node
{
    node *link;
    int data;
}*top;

class Stack
{

    public:Stack()
    {
        top = NULL;
    }
    public:void push(int value)
    {
        node *temp = new (struct node);
        temp->data = value;
        temp->link = top;
        top = temp;
        cout<<"PUSHED: "<<value<<endl;
    }

    
    public:node* pop()
    {
        if(top == NULL)
            cout<<"EMPTY STACK"<<endl;
    
            node *temp = new node();
            temp = top;
            //cout<<"TOP IS"<<top->data<<endl;
            top = top->link;
            //free(temp);
            return temp;
    }
    public:node* peak()
    {
        return top;
    }
    
    public:void print()
    {
        if(top == NULL)
        {
            cout<<"EMPTY STACK"<<endl;
        }
        else
        {
            node *ptr;
            ptr = top;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<endl;
                ptr = ptr->link;
            }
        }
    }

    
};



int main(int argc, const char * argv[])
{
    Stack stack = *new Stack();
    stack.push(100);
    cout<<"PEAK@TOP: "<<stack.peak()->data<<endl;
    stack.push(90);
    cout<<"PEAK@TOP: "<<stack.peak()->data<<endl;
    stack.push(80);
    cout<<"PEAK@TOP: "<<stack.peak()->data<<endl;
    stack.push(70);
    cout<<"PEAK@TOP: "<<stack.peak()->data<<endl;
    cout<<"POPPING CHERRY: "<<stack.pop()->data<<endl;
    cout<<"PEAK@TOP"<<stack.peak()->data<<endl;
    stack.print();
    cout<<"POPPING CHERRY: "<<stack.pop()->data<<endl;
    stack.print();
    return 0;
}
