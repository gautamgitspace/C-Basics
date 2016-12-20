//
//  main.cpp
//  Priority Queue
//
//  Created by Gautam on 11/2/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct node
{
    int priority;
    char info[10];
    struct node *link;
};

class Priority_Queue
{
private:
    node *front;
public:
    Priority_Queue()
    {
        front = NULL;
    }

    void insert(char *info, int priority)
    {
        node *tmp, *q;
        tmp = new node;
        strcpy(tmp->info, info);
        tmp->priority = priority;
        if (front == NULL || priority > front->priority)
        {
            tmp->link = front;
            front = tmp;
        }
        else
        {
            q = front;
            while (q->link != NULL && q->link->priority >= priority)
                q=q->link;
            tmp->link = q->link;
            q->link = tmp;
        }
    }

    void allocateToCPU()
    {
        node *tmp;
        if(front == NULL)
            cout<<"========Queue Underflow========\n";
        else
        {
            tmp = front;
            cout<<"Allocated to CPU: "<<tmp->info<<endl;
            front = front->link;
            free(tmp);
        }
    }

    void displayJobs()
    {
        node *ptr;
        ptr = front;
        if (front == NULL)
            cout<<"Queue is empty\n";
        else
        {	cout<<"Queue is :\n";
            cout<<"Priority       Item\n";
            while(ptr != NULL)
            {
                cout<<ptr->priority<<"                 "<<ptr->info<<endl;
                ptr = ptr->link;
            }
        }
    }
};

int main()
{
    int choice, priority;
    char item[10];
    Priority_Queue pq;
    do
    {
        cout<<"1.Add a Job\n";
        cout<<"2.Allocate To CPU\n";
        cout<<"3.Display Jobs in Queue\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Input the item value to be added in the queue : ";
                cin>>item;
                cout<<"Enter its priority : ";
                cin>>priority;
                pq.insert(item, priority);
                break;
            case 2:
                pq.allocateToCPU();
                break;
            case 3:
                pq.displayJobs();
                break;
            case 4:
                break;
        }
    }
    while(choice != 4);
    return 0;
}
