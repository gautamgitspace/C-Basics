//
//  main.cpp
//  Queue
//
//  Created by Gautam on 11/2/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
}*head, *tail;

class Queue
{
    int size = 0;
public:Queue()
    {
        head = tail = NULL;
    }
public:void enqueue(int value)
    {
        size++;
        node *temp = new(struct node);
        temp->data = value;
        if(head == NULL)
        {
            /*FIRST ENQUEUE*/
            head = temp;
            tail = head;
            tail->link = NULL;
            cout<<"ADDED: "<<temp->data<<endl;
        }
        else
        {
            /*ENQUEUE TO EXISTING*/
            tail->link = temp;
            tail = temp;
            tail->link = NULL;
            cout<<"ADDED: "<<temp->data<<endl;
        }
        
    }
public:int dequeue()
    {
        size--;
        node *temp;
        int return_data;
        if(head == NULL)
        {
            cout<<"QUEUE EMPTY"<<endl;
        }
        else
        {
            return_data = head->data;
            temp = head;
            head = head->link;
            free(temp);
        }
        return return_data;
    }
public:int peak()
    {
        int return_data = head->data;
        return  return_data;
    }
public:int sizeOfQueue()
    {
        return size;
    }
    
};
int main(int argc, const char * argv[])
{
    Queue queue = *new Queue();
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    cout<<"NOW SERVING: "<<queue.dequeue()<<endl;
    cout<<"NEXT IN LINE: "<<queue.peak()<<endl;
    cout<<"NOW SERVING: "<<queue.dequeue()<<endl;
    cout<<"NEXT IN LINE: "<<queue.peak()<<endl;
    return 0;
}
