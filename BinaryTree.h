//
// Created by Ben Worthington on 4/26/21.
//

#ifndef PF2_PROGRAMMING_PROJECT_6_BINARYTREE_H
#define PF2_PROGRAMMING_PROJECT_6_BINARYTREE_H

#include <iostream>
#include <fstream>
using namespace std;

struct Node {

    int Value;
    Node *Left;
    Node *Right;

};

class BinaryTree {
public:

    // Constructor functions
    BinaryTree();
    ~BinaryTree();

    // General binary tree operations
    bool Search(int Value);
    bool Insert(int Value);
    bool Delete(int Value);
    void Print();
    int Count();
    int Height();

private:
    // Helper functions
    bool SearchHelper(int Value, Node * Tree);
    bool InsertHelper(int Value, Node * &Tree);
    bool DeleteNode(Node * &Tree);
    bool DeleteHelper(int Value, Node * &Tree);
    void PrintHelper(Node * Tree);
    int CountHelper(Node *Tree);
    int HeightHelper(Node *Tree);

    // Tree pointer
    Node *Root;

};


#endif //PF2_PROGRAMMING_PROJECT_6_BINARYTREE_H
