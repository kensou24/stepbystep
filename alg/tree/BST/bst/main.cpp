#include <iostream>
#include "BinarySearchTree.h"

void testSearch()
{
    BitNode<int> *node_7 = new BitNode<int>(7);

    BitNode<int> *node_6 = new BitNode<int>(6);
    BitNode<int> *node_3 = new BitNode<int>(3);
    BitNode<int> *node_5 = new BitNode<int>(5);
    node_6->bitLeftNode = node_3;
    node_6->bitRightNode = node_5;

    BitNode<int> *node_9 = new BitNode<int>(9);
    BitNode<int> *node_13 = new BitNode<int>(13);
    BitNode<int> *node_12 = new BitNode<int>(12);
    node_12->bitLeftNode = node_9;
    node_12->bitRightNode = node_13;

    node_7->bitLeftNode = node_6;
    node_7->bitRightNode = node_12;

    BitNode<int> *root = node_7;
    BitNode<int> *pre = nullptr;
    BitNode<int> *result = nullptr;

    int searchInt = 13;

    //test BST
    BinarySearchTree<int> bst;
    bool searchResult = bst.Search(root, searchInt, pre, result);
    if(searchResult)
    {
        std::cout << "find " << searchInt << " in BST" << std::endl;
    }else
        {
        std::cout << "not find " << searchInt << " in BST" << std::endl;
    }
}

void testAdd()
{
    BitNode<int> *root = nullptr;

    BinarySearchTree<int> bst;
    bst.Add(root, 7);
    std::cout << "current root ==" << root << std::endl;

    bst.Add(root, 6);
    bst.Add(root, 12);

    bst.Add(root, 3);
    bst.Add(root, 5);

    bst.Add(root, 9);
    bst.Add(root, 13);

    std::cout << "root data" << root->node << std::endl;
    std::cout << "root left" << root->bitLeftNode->node << std::endl;
    std::cout << "root right" << root->bitRightNode->node << std::endl;
}

void testDel()
{
    BitNode<int> *root = nullptr;

    BinarySearchTree<int> bst;
    bst.Add(root, 7);
    std::cout << "current root ==" << root << std::endl;

    bst.Add(root, 6);
    bst.Add(root, 12);

    bst.Add(root, 3);
    bst.Add(root, 5);

    bst.Add(root, 9);
    bst.Add(root, 13);

    bst.InorderReverse(root);

    bst.DeleElement(root, 6);

    bst.InorderReverse(root);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    testSearch();

    testAdd();

    testDel();

    return 0;
}