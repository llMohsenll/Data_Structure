#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T >
class Stack
{
private:
    int top;
    T *stack;
    int max;
public :
    ~Stack();


    Stack(int maxSize);
    void print();
    bool IsEmpty();
    bool IsFull();
    void  push(T& x);
    T pop();
};
template <class T > Stack<T>::Stack(int maxSize) :max(maxSize)
{
    stack = new T[max];
    top = -1;
}
template <class T > Stack<T>:: ~Stack()
{
    delete []stack;
    top = -1;
}
template <class T > bool Stack<T>::IsEmpty()
{
    return (top == -1);
}
template <class T > bool Stack<T>::IsFull()
{
    return (top == max);
}
template <class T > T Stack<T>::pop()
{
    T x;
    if (!IsEmpty())
    {
        x = stack[top--];
    }
    return x;
}
template <class T > void Stack<T>::push(T& x)
{
    if (!IsFull())
    {
        stack[++top] = x;
    }

}
template <class T > void Stack<T>::print()
{
    int x=top;
    while (x >= 0 && !IsEmpty())
    {
        std::cout <<"|"<< stack[x] << "|"<<"\n"<<" --"<<"\n";
        x--;
    }
}

#endif // STACK_H
