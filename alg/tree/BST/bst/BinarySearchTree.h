//
// Created by kenso on 2018/10/8.
//

#ifndef BST_BINARYSEARCHTREE_H
#define BST_BINARYSEARCHTREE_H

#include <iostream>

template <typename T>
struct BitNode
{
    T node;
    BitNode *bitLeftNode;
    BitNode *bitRightNode;

    BitNode():bitLeftNode(nullptr),bitRightNode(nullptr){ }

    BitNode(T _node):node(_node), bitLeftNode(nullptr),bitRightNode(nullptr){  }

    BitNode( T _node,
    BitNode *_bitLeftNode,
    BitNode *_bitRightNode):node(_node),bitLeftNode(_bitLeftNode),bitRightNode(_bitRightNode){ }
};


template  <typename T>
class BinarySearchTree {
public:

    //BST search function
    bool Search(BitNode<T> *parentNode, T t, BitNode<T> * preNode, BitNode<T> * &findNode)
    {
        //root is empty
        if(parentNode == nullptr)
        {
            findNode = preNode;
            std::cout << "root is null " << t << std::endl;
            return false;
        }
        else if(t == parentNode->node)
        {
            findNode = parentNode;
            std::cout << "find  " << t << std::endl;
            return true;
        }else if(t < parentNode->node)
        {
            std::cout << "to search left  " << parentNode->node << std::endl;
            return Search(parentNode->bitLeftNode, t, parentNode, findNode);
        }else if(t > parentNode->node)
        {
            std::cout << "to search right  " << parentNode->node << std::endl;
            return Search(parentNode->bitRightNode, t, parentNode, findNode);
        }
        return false;
    }

    //Add node in BST
    bool Add(BitNode<T>* &parentNode, T t)
    {
        BitNode<T> *findNode = nullptr;
        if(Search(parentNode, t, nullptr, findNode))
        {
            std::cout << "already exist in BST data = " << t << std::endl;
            return false;
        }
        else
        {
            std::cout << "to insert in BST data = " << t << std::endl;
            if(nullptr == findNode)
            {
                parentNode = new BitNode<T>(t);
            }
            else
            {
                if( t < findNode->node)
                {
                    findNode->bitLeftNode = new BitNode<T>(t);
                }else
                {
                    findNode->bitRightNode = new BitNode<T>(t);
                }
            }
            return true;
        }

    }


    bool DeleElement(BitNode<T>* &parentNode, T key)
    {
        if(!parentNode)
        {
            return false;   //树是空树的话就返回假
        }
        if(parentNode->node == key)
        {
            BitNode<T>*  s;
            BitNode<T>*  p;
            if(parentNode->bitRightNode == nullptr)   //只有右子树，情况2
            {
                s = parentNode;
                parentNode = parentNode->bitLeftNode;
                delete s;
            }
            else if(parentNode->bitLeftNode == nullptr)
            {
                s = parentNode;               //只有左子树，情况1
                parentNode = parentNode->bitRightNode;
                delete s;
            }
            else
            {                      //情况3，左右子树都有
                p = parentNode;
                s = parentNode->bitRightNode;
                while (s->bitLeftNode)
                {
                    p = s;           //找到所要删除节点的后继，那就是他的右孩子的
                    s = s->bitLeftNode;
                }
                parentNode->node = s->node;    //用删除节点的后继替换所删除的节点
                if(p != parentNode)
                {
                    p->bitLeftNode = nullptr;   //所删除的节点的右孩子不是叶结点
                }
                else
                    p->bitRightNode = nullptr;   //所删除的节点的右孩子是叶节点
                delete s;
            }
            return true;
        }
        else if(key < parentNode->node)
            DeleElement(parentNode->bitLeftNode,key);    //去和他的左子树根去比较
        else
            DeleElement(parentNode->bitRightNode, key);   //去和他的右子树根去比较

    }

    //中序遍历并输出元素
    void InorderReverse(BitNode<T> *root)
    {
        if(nullptr != root)
        {
            InorderReverse(root->bitLeftNode);
            std::cout<< " " << root->node << std::endl;
            InorderReverse(root->bitRightNode);
        }
    }

};


#endif //BST_BINARYSEARCHTREE_H
