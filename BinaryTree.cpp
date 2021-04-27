//
// Created by Ben Worthington on 4/26/21.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree() {

    Root = NULL;

}

BinaryTree::~BinaryTree() {}

bool BinaryTree::SearchHelper(int Value, Node * Tree) {

    // Data value not found
    if (Tree == NULL)
        return false;

        // Data value found
    else if (Tree->Value == Value)
        return true;

        // Recursively search for data value
    else if (Tree->Value > Value)
        return (SearchHelper(Value, Tree->Left));
    else if (Tree->Value < Value)
        return (SearchHelper(Value, Tree->Right));

}

bool BinaryTree::Search(int Value) {

    // Call tree searching function
    return (SearchHelper(Value, Root));

}

bool BinaryTree::InsertHelper(int Value, Node * &Tree) {

    // Insert data into the tree
    if (Tree == NULL)
    {
        Tree = new Node;
        Tree->Value = Value;
        Tree->Left = NULL;
        Tree->Right = NULL;
        return true;
    }

        // Data value already inserted
    else if (Tree->Value == Value)
        return false;

        // Recursively search for insertion position
    else if (Tree->Value > Value)
        return (InsertHelper(Value, Tree->Left));
    else if (Tree->Value < Value)
        return (InsertHelper(Value, Tree->Right));

}

bool BinaryTree::Insert(int Value) {

    // Call tree insertion function
    return (InsertHelper(Value, Root));

}

void BinaryTree::PrintHelper(Node * Tree) {

    // Check terminating condition
    if (Tree != NULL)
    {
        // Print left subtree
        PrintHelper(Tree->Left);

        // Print node value
        cout << " " << Tree->Value << " ";

        // Print right subtree
        PrintHelper(Tree->Right);
    }

}

void BinaryTree::Print() {

    // Call tree printing function
    PrintHelper(Root);
    cout << endl;

}