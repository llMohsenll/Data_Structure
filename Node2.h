#ifndef NODE2_H
#define NODE2_H


using namespace std;
template <class T>
class Node2
{
private :
    Node2<T> *next_node;
    Node2<T>* pre_node;
    int node_value;
public :
    Node2(T value= 0, Node2<T>* next= nullptr,Node2<T>* pre = nullptr)
    {
        node_value = value;
        next_node = next;
        pre_node= pre;
    };
    ~Node2 ()
    {
        node_value = nullptr;
        next_node = nullptr;
        pre_node = nullptr;
    }

    T value()const;
    Node2<T> *next() const
    {
        return this->next_node;
    };
    Node2<T>* pre()const
    {
        return this -> pre_node;
    }

};
template<class T>T Node2<T>:: value()const
{
    return this->node_value;
}
#endif // NODE2_H
