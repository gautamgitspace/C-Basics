//
//  main.cpp
//  Queue
//
//  Created by Gautam on 11/2/16.
//  Copyright © 2016 Gautam. All rights reserved.
//  Queue and circular queue (job replacement)

#include <iostream>
#define MAX 5

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
        if(size < MAX)
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
                cout<<"HEAD IS:"<<head->data<<endl;
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
        else
        {
            cout<<"QUEUE FULL. AGING IN ACTION..."<<endl;
            cout<<"ADDED: "<<value<<endl;
            cout<<"AGED SERVING: "<<head->data<<endl;;
            dequeue();
            
            node *temp = new(struct node);
            temp->data = value;
            tail->link = temp;
            tail = temp;
            tail->link = NULL;
            size++;
            
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
    cout<<"SIZE OF Queue after 2 served: "<<queue.sizeOfQueue()<<endl;
    queue.enqueue(100);
    queue.enqueue(200);
    cout<<"SIZE OF Queue: "<<queue.sizeOfQueue()<<endl;
    cout<<"TRYING TO ADD"<<endl;
    queue.enqueue(300);
    cout<<"SIZE OF Queue: "<<queue.sizeOfQueue()<<endl;
    cout<<"NEXT IN LINE: "<<queue.peak()<<endl;
    cout<<"======================="<<endl;
    cout<<"NOW SERVING: "<<queue.dequeue()<<endl;
    cout<<"NOW SERVING: "<<queue.dequeue()<<endl;
    cout<<"NOW SERVING: "<<queue.dequeue()<<endl;
    cout<<"NOW SERVING: "<<queue.dequeue()<<endl;
    cout<<"NOW SERVING: "<<queue.dequeue()<<endl;
    
    return 0;
}
