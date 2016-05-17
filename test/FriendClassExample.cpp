//
//  main.cpp
//  Friend Class Example. Also demonstrates scope resolution operator and passing object as an argument.
//
//  Created by Gautam on 1/10/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

#include <iostream>


class TwoValues
{
private:
    int a;
    int b;
public:
    TwoValues(int i, int j) //default constructer
    {
        a = i;
        b = j;
    }
    friend class Min;
};

class Min
{
public:
    int min(TwoValues x);
    void display(TwoValues x);
};

void Min::display(TwoValues x)
{
    std::cout<<"two numbers are "<<x.a<<" & "<<x.b<<"\n";
}
int Min::min(TwoValues x)
{
    return x.a < x.b ? x.a : x.b;
}

int main()
{
    int p,q;
    std::cout<<"enter two numbers\n";
    std::cin>>p>>q;
    TwoValues ob(p,q);
    Min m;
    m.display(ob);
    std::cout<<"smaller of them is "<< m.min(ob)<<"\n";
    return 0;
}
