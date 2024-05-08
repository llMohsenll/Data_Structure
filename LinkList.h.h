#ifndef LINKLIST_H_H
#define LINKLIST_H_H

#include <iostream>
#include "Node2.h"
using namespace std;
template <class T>
class List2
{
private :
    Node2<T> *list_head;
public :

    list2(Node2<T> *head =nullptr)
    {
        list_head = head;
    };
    ~List2()
    {
        list_head = nullptr;
    };

    bool empty()
    {
        return list_head == nullptr;
    };
    Node2<T>* begin()
    {
        return this->list_head;
    };

    Node2<T>* end()
    {
        if (empty())
        {
            return nullptr;
        }
        else
        {
            Node2<T> *ptr = begin();
            while (ptr->next()!= nullptr)
            {
                ptr = ptr->next();
            }
            return ptr;
        }
    };
    T front ()
    {

        if (empty())
        {
            return NULL;
        }
        else
        {
            return this ->begin()->value;
        }


    };
    void push_front(T value);
    T pop_front(){
    if (empty())
    {
        return NULL;
    }
    T x = begin()->value();
    Node2 <T> * ptr = begin();
    list_head = begin()->next();
//begin ()->
    begin()->setPre(nullptr);
    delete ptr;
    return x;};
    T erase(T x);
    int size();
    int count(T x);
    void print();

};
template <class T> void List2<T>:: push_front(T value)
{
    //cout << "push";

    if(empty())
    {
        list_head = new Node2<T>(value,nullptr,nullptr);
    }
    else
    {
        list_head= new Node2<T> {value,begin(),nullptr};
        Node2<T> *next_node = this->begin()->next();
     if(next_node!=nullptr){
    next_node->setPre(list_head);
    }

}
template<class T>T List2<T>:: pop_front()
{
    if (empty())
    {
        return NULL;
    }
    T x = begin()->value();
    Node2 <T> * ptr = begin();
    list_head = begin()->next();
//begin ()->
    begin()->setPre(nullptr);
    delete ptr;
    return x;

}
template <class T> T List2<T>::erase(T x)
{
    if(empty())
    {
        return NULL;
    }
    for (Node2<T> *ptr = begin(); ptr!= nullptr; ptr= ptr->next())
    {

        if(ptr->value() == x)
        {
            ptr->setnext(ptr->next()->next());
            ptr-> next()->setpre(ptr);
        }
    }

}
template <class T> int List2<T>::size()
{
    if(empty())
    {
        return NULL;
    }
    int node_counter=0;
    for (Node2<T> *ptr = begin(); ptr!= nullptr; ptr= ptr->next())
    {
        node_counter++;
    }
    return node_counter;
}
template <class T> int List2<T>::count(T x)
{
    if(empty())
    {
        return NULL;
    }
    int node_counter=0;
    for (Node2<T> *ptr = begin(); ptr!= nullptr; ptr= ptr->next())
    {
        if(ptr->value()== x)
        {
            node_counter++;
        }
    }
    return node_counter;
}
template<class T> void List2<T>::print()
{
    //cout<<" miao";
    for (Node2<T> *ptr = begin(); ptr!= nullptr; ptr= ptr->next())
    {
        cout<<" "<<ptr->value()<<endl;
        cout<< " | ^"<<endl;
        cout <<" ~ |"<<endl;
    }
}

#endif // LINKLIST_H_H
