#ifndef QUE_H
#define QUE_H


#include <iostream>
//#include "Que.h"
using namespace std;
template <class T>
class Que
{
private :
    T *que;
    int maxSize;
    int first,last;

public:
    Que(int max);
    ~Que();
    bool IsFull();
    bool IsEmpty();
    void Insert(T& x);
    T* Delete();
    void print();
};

template <class T> Que<T>::Que(int max)
{
    maxSize = max;
    que = new T[maxSize];
    first=last=0;
}
template <class T> Que<T>::~Que()
{
    delete [] que;
    first = last =0;
}
template <class T> bool Que<T>::IsFull()
{
    return(last==maxSize+1);
}
template <class T>bool Que<T>:: IsEmpty()
{
    return (last==first);
}
template <class T> void Que<T>::Insert(T &x)
{
    if(!IsFull())
        que[last++]=x;
    else cout << "sorry the the Que is FUll!"<<endl;
}
template <class T> T* Que<T>::Delete()
{
    if(!IsEmpty())
    {
        T x= que[first];
        first++;
        return &x;
    }
    else
    {
        cout << "Your Que is empty my Lord!"<<endl;
        return NULL;
    }

}
template <class T> void Que<T>::print()
{
    int i;
    for(i=first; i<last && !IsEmpty(); i++)
    {
        cout<<" |"<<que[i]<<"| ";
    }
}

#endif // QUE_H
