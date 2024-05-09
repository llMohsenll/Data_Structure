#ifndef BINARYNODE_H
#define BINARYNODE_H


#include <iostream>

using namespace std;
    template<typename T>

class Binary_node
{
protected:
    T node_value;
    Binary_node<T> *p_left_child;
    Binary_node<T> *p_right_child;

public:
    Binary_node <T> *parent;
    Binary_node(T value,
                Binary_node<T> *parent = nullptr,
                Binary_node<T> *left= nullptr,
                Binary_node<T> *right = nullptr)
    {

        this->node_value = value;
        this->p_left_child= left;
        this->p_right_child= right;
        this->parent= parent;
    }
    ~Binary_node()
    {
        node_value = NULL;
        p_left_child= nullptr;
        p_right_child = nullptr;
        parent = nullptr;
    }
    T vlaue()
    {
        return node_value;
    }
    void setValue(T x)
    {
        this -> node_value = x;
    }
    Binary_node *left() const
    {
        return p_left_child;
    }
    void setleft(T value)
    {
        if(this->p_left_child ->vlaue()!= NULL)
        {
            this-> p_left_child-> setValue(value);
        }
        else
        {
            this->p_left_child=new Binary_node<T>(value,this);

        }
    }
    Binary_node *right() const
    {
        return p_right_child;
    }
    void setright(T value)
    {
        if(this->p_right_child ->vlaue()!= NULL)
        {
            this-> p_right_child-> setValue(value);
        }
        else
        {
            this->p_right_child=new Binary_node<T>(value,this);

        }
    }
        bool is_leaf() const
        {
            return (left()==nullptr )&&(right== nullptr);
        }
bool mainRoot(Binary_node<T> *root)const{
return(root->parent == nullptr);
}

    };

#endif // BINARYNODE_H
