#ifndef NODE1_H
#define NODE1_H


#include <iostream>

using namespace std;
template <class T>
class Node1{
private :
    Node1 *next_node;
    int node_value;
public :
    Node1(T value= 0 , Node1* next= nullptr){
    node_value = value;
    next_node = next;
    };
    ~Node1 (){
    node_value = nullptr;
    next_node = nullptr;
    }

    T value()const;
    Node1 *next() const{
    return this->next_node;
    };

};
template<class T>T Node1<T>:: value()const{
  return this->node_value;
}


#endif // NODE1_H
