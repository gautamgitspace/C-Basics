//
//  main.cpp
//  LargestBST
//
//  Created by Gautam on 7/19/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

#include <iostream>

class BinarySearchTree
{

    public: struct node
    {
        int data;
        node* left;
        node* right;
    };
    node* root;
    
    node* insert(node* t, int data)
    {
        if (t==NULL)
        {
            t = new node;
            t->data = data;
            t->left=NULL;
            t->right=NULL;
        }
        else if(data <= t->data)
        {
            t->left = insert(t->left, data);
        }
        else if(data > t->data)
        {
            t->right = insert(t->right, data);
        }
        return t;
    }
    
    int findMax(node* t)
    {
        if(t==NULL)
            return -1;
        while(t->right!=NULL)
        {
            t=t->right;
        }
        return t->data;
    }
    public: BinarySearchTree()
    {
        root = NULL;
    }
    void insert(int x)
    {
        root = insert(root, x);
    }
    int findMax()
    {
        int a = findMax(root);
        return a;
    }
};

int main(int argc, char * argv[])
{

    BinarySearchTree obj;
    obj.insert(20);
    obj.insert(22);
    obj.insert(28);
    obj.insert(10);
    obj.insert(27);
    obj.insert(21);
    int res = obj.findMax();
    printf("%d\n",res);
    
    return 0;
    
}

