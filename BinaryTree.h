//
// Created by Ben Worthington on 4/26/21.
//

#ifndef PF2_PROGRAMMING_PROJECT_6_BINARYTREE_H
#define PF2_PROGRAMMING_PROJECT_6_BINARYTREE_H

#include <iostream>
#include <fstream>
using namespace std;

struct Node {

    string Value;
    int HouseNumber;
    string StreetName;
    string City;
    string State;
    int Zipcode;
    Node *Left;
    Node *Right;

};

class BinaryTree {
public:

    // Constructor functions
    BinaryTree();
    ~BinaryTree();

    // General binary tree operations
    bool Search(string value_);
    string CreateKey(Node *&Tree_);
    bool Insert(Node *&Tree_);
    bool Delete(string value_);
    void Print();
    int Count();

    int Height();
private:
    // Helper functions
    void DestroyHelper(Node * Tree_);
    bool SearchHelper(string value_, Node *Tree_);
    bool InsertHelper(string value_, int &houseNumber_, string &streetName_, string &city_, string &state_, int &zipcode_, Node *&Tree_);
    bool DeleteNode(Node *&Tree_);
    bool DeleteHelper(string value_, Node *&Tree_);
    void PrintHelper(Node *Tree_);
    int CountHelper(Node *Tree_);
    int HeightHelper(Node *Tree_);

    // Tree pointer
    Node *Root;

};


#endif //PF2_PROGRAMMING_PROJECT_6_BINARYTREE_H
