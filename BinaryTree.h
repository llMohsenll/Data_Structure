#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <stdio.h>
using std namespace;

template <class T>
class BinaryTree
{
private:

public:
    Binary_node <T> *root;
    BinaryTree()
    {
        this-> root= nullptr;
    }
    BinaryTree(T root_vlaue)
    {
        this->root = new Binary_node<T>(root_vlaue);
    }
    int getsize()
    {
        return size(this->root);
    }
    int size(Binary_node <T> *node)
    {
        // if( node->is_leaf())return 1;
        if(node->left()==nullptr)
        {
            return (node->right ()==nullptr)?1:1+size(node->right());

        }
        else
        {
            return (node->right ()== nullptr)? 1+ size(node->left()):1+size(node->left())+size(node->right());
        }

    }

    int getheight()
    {
        return height(this->root);
    }
    int height(Binary_node<T> *node)
    {
        if(node->left()==nullptr)
        {
            return (node->right ()==nullptr)?0:1+height(node->right());

        }
        else
        {
            return (node->right ()== nullptr)? 1+ height(node->left()):1+ (height(node->left())>height(node->right()))?height(node->left()):height(node->right());
        }
    }



    void getLVR(Binary_node<T> *node, T* &lvr)
    {
        if (node->left() != nullptr)
        {
            getLVR(node->left(), lvr);
        }

        cout << node->value() << "-";
        *lvr = node->vlaue();
        lvr ++;

        if (node->right() != nullptr)
        {
            getLVR(node->right(), lvr);
        }
    }

    T * LVR()
    {
        T *lvr = new T[this->size()];
        T *Array_lvr = lvr;
        getLVR(this->root, Array_lvr);
        return lvr;
    }
    void getVLR(Binary_node<T> *node, T* &vlr)
    {
        cout << node->value() << "-";
        *vlr = node->vlaue();
        vlr ++;
        if (node->left() != nullptr)
        {
            getVLR(node->left(), vlr);
        }

        cout << node->value() << "-";

        if (node->right() != nullptr)
        {
            getVLR(node->right(), vlr);
        }
    }

    T * VLR()
    {
        T *vlr = new T[this->size()];
        T *Array_vlr = vlr;
        getVLR(this->root, Array_vlr);
        return vlr;
    }

    void getLRV(Binary_node<T> *node, T* &lrv)
    {

        if (node->left() != nullptr)
        {
            getLRV(node->left(), lrv);
        }



        if (node->right() != nullptr)
        {
            getLRV(node->right(), lrv);
        }
        cout << node->value() << "-";
        *lrv = node->vlaue();
        lrv ++;
    }

    T * LRV()
    {
        T *lrv = new T[this->size()];
        T *Array_lrv = lrv;
        getLRV(this->root, Array_lrv);
        return lrv;
    }











    static BinaryTree<T> makeBinaryTreeOf(T *lvr, T *vlr, int len_of_nodes)
    {
        BinaryTree<T> result_tree(*vlr);

        if (len_of_nodes == 1) return result_tree;

        int index_of_root_in_lvr = 0;
        for (; index_of_root_in_lvr < len_of_nodes ; index_of_root_in_lvr++)
        {
            if (lvr[index_of_root_in_lvr] == *vlr) break;
        }

        setChildRecursive(result_tree.root, 0, index_of_root_in_lvr - 1,
                          lvr, vlr, true);


        setChildRecursive(result_tree.root, index_of_root_in_lvr + 1, len_of_nodes,
                          lvr, vlr, false);

        return result_tree;
    }

    static void setChildRecursive(Binary_node<T> *root, int low, int high, T* lvr, T* &vlr, bool is_left)
    {
        if (*(vlr + 1) == '\0' || low > high) return;
        char* child = ++vlr;
        (is_left)? root->setleft(*child) : root->setright(*child);

        if (low == high)
        {
            return;
        }
        else
        {

            int index_of_child_in_lvr = low;
            for (; index_of_child_in_lvr <= high; ++index_of_child_in_lvr)
            {
                if (lvr[index_of_child_in_lvr] == *child) break;
            }
            Binary_node<T> * new_root = (is_left)? root->getleft(): root->getright();
            setChildRecursive(new_root, low, index_of_child_in_lvr -1,
                              lvr, vlr, true);

            setChildRecursive(new_root, index_of_child_in_lvr + 1, high,
                              lvr, vlr, false);
        }
    }




};




#endif // BINARYTREE_H
