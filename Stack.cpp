#include <iostream>
int main()
{
    Stack<int> s(10);
    int x = 20,y=10;
    s.push(x);
    s.push(y);
    s.push(8);
    s.pop();
    s.push(31);
    s.print();
}
/*
|31|
 --
|10|
 --
|20|
 --
  */
