#include <iostream>
#include "Que.h"
using namespace std;

int main()
{
    Que<int> q(4);
    int *x;
    int y[5]= {2,3,4,5,6};
    q.Insert(y[0]);
    q.Insert(y[1]);
    q.Insert(y[2]);
    q.Insert(y[3]);
    q.Insert(y[4]);
    x=q.Delete();

    // q.Insert(7);
    q.print();
    return 0;
}

