//
//  main.cpp
//  Object Passing, Return and Assignment
//
//  Created by Gautam on 1/12/16.
//  Copyright © 2016 Gautam. All rights reserved.
//

// Returning objects from a function.
/*
#include <iostream>
using namespace std;
class myclass {
    int i;
public:
    void set_i(int n) { i=n; }
    int get_i() { return i; }
};
myclass f();  // return object of type myclass
int main()
{
    myclass o;
    o = f();
    cout << o.get_i() << "\n";
    return 0; }
myclass f() {
    myclass x;
    x.set_i(1);
    return x;
}
*/
/*
 // Assigning objects.
 #include <iostream>
 using namespace std;
 class myclass {
 int i;
 public:
 void set_i(int n) { i=n; }
 int get_i() { return i; }
 };
 int main() {
 myclass ob1, ob2;
 ob1.set_i(99);
 ob2 = ob1; // assign data from ob1 to ob2
 cout << "This is ob2's i: " << ob2.get_i();
 return 0; }
*/


 // Passing an object to a function.
 #include <iostream>
 using namespace std;
 class myclass {
 int i;
 public:
 myclass(int n);
 ~myclass();
 void set_i(int n) { i=n; }
 int get_i() { return i; }
 };
 myclass::myclass(int n)
 {
 i = n;
 cout << "Constructing " << i << "\n";
 }
 myclass::~myclass()
 {
 cout << "Destroying " << i << "\n";
 }
 void f(myclass ob);
 int main() {
 myclass o(1);
 f(o);
 cout << "This is i in main: ";
 cout << o.get_i() << "\n";
 return 0; }
 void f(myclass ob)
 {
 ob.set_i(2);
 cout << "This is local i: " << ob.get_i();
 cout << "\n";
 }