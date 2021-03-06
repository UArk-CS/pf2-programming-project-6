//
// Created by Ben Worthington on 4/26/21.
//

#include "BinaryTree.h"
#include <fstream>

BinaryTree::BinaryTree() {

    Root = NULL;

}

void BinaryTree::DestroyHelper(Node *Tree_) {

    // Delete node and it's children
    if (Tree_ != NULL)
    {
        DestroyHelper(Tree_->Left);
        DestroyHelper(Tree_->Right);
        delete Tree_;
    }

}

BinaryTree::~BinaryTree() {

    // Call tree destroy function
//    DestroyHelper(Root);

}

void BinaryTree::ReadFile(string &fileName_) {

    string houseNumber;
    string streetName;
    string city;
    string state;
    string zipcode;
    string blank;
    ifstream din;
    din.open(fileName_);
    if (din.fail()) {
        return;
    }

    if (din.is_open()) {

        while (!din.eof()) {

            getline(din, houseNumber);
            getline(din, streetName);
            getline(din, city);
            getline(din, state);
            getline(din, zipcode);

            Insert(houseNumber, streetName, city, state, zipcode);

            // Discard new line
            getline(din, blank);

        }

    }

}

void BinaryTree::WriteSortedFileHelper( ofstream &dout_, Node *Tree_) {

    if (dout_.is_open()) {

        // Check terminating condition
        if (Tree_ != NULL)
        {
            // Print left subtree
            WriteSortedFileHelper(dout_, Tree_->Left);

            dout_ << Tree_->HouseNumber << " " << Tree_->StreetName << ", " << Tree_->City << " " << Tree_->State + " " + Tree_->Zipcode << endl;
            dout_ << endl;

            // Print right subtree
            WriteSortedFileHelper(dout_, Tree_->Right);
        }
    }
}

void BinaryTree::WriteSortedFile(string &outputFileName_) {

    ofstream dout;
    dout.open(outputFileName_, fstream::app);
    if (dout.fail()) {
        return;
    }

    if (dout.is_open()) {
        WriteSortedFileHelper(dout, Root);

        dout.close();
    }
}

bool BinaryTree::SearchHelper(string value_, Node *Tree_) {

    while (Tree_ != NULL) {


        // Data value found
        if (Tree_->Value == value_) {

            cout << Tree_->HouseNumber << endl;
            cout << Tree_->StreetName << endl;
            cout << Tree_->City << endl;
            cout << Tree_->State << endl;
            cout << Tree_->Zipcode << endl;

            return true;

        }

            // Recursively search for data value
        else if (Tree_->Value > value_)
            return (SearchHelper(value_, Tree_->Left));
        else if (Tree_->Value < value_)
            return (SearchHelper(value_, Tree_->Right));

    }



}

bool BinaryTree::Search(string value_) {

    // Call tree searching function
    return (SearchHelper(value_, Root));

}

string BinaryTree::CreateKey(string houseNumber_, string streetName_, string city_) {

    return (houseNumber_ + " " + streetName_ + ", " + city_);

}

bool BinaryTree::InsertHelper(string value_, string &houseNumber_, string &streetName_, string &city_, string &state_, string &zipcode_, Node *&Tree_) {

    // Insert data into the Tree_
    if (Tree_ == NULL)
    {
        Tree_ = new Node;
        Tree_->Value = value_;
        Tree_->HouseNumber = houseNumber_;
        Tree_->StreetName = streetName_;
        Tree_->City = city_;
        Tree_->State = state_;
        Tree_->Zipcode = zipcode_;
        Tree_->Left = NULL;
        Tree_->Right = NULL;
        return true;
    }

        // Data value_ already inserted
    else if (Tree_->Value == value_)
        return false;

        // Recursively search for insertion position
    else if (Tree_->Value > value_)
        return (InsertHelper(value_, houseNumber_, streetName_, city_, state_, zipcode_, Tree_->Left));
    else if (Tree_->Value < value_)
        return (InsertHelper(value_, houseNumber_, streetName_, city_, state_, zipcode_, Tree_->Right));

}

bool BinaryTree::Insert(string &houseNumber_, string &streetName_, string &city_, string &state_, string &zipcode_) {

    string value = CreateKey(houseNumber_, streetName_,city_);

    return (InsertHelper(value, houseNumber_, streetName_, city_, state_, zipcode_, Root));

}

bool BinaryTree::DeleteNode(Node *&Tree_) {

    Node *Temp = Tree_;

    // Node has 0 children
    if ((Tree_->Left == NULL) && (Tree_->Right == NULL))
        Tree_ = NULL;

        // Node has 1 child
    else if (Tree_->Left == NULL)
        Tree_ = Tree_->Right;
    else if (Tree_->Right == NULL)
        Tree_ = Tree_->Left;


        // Node has 2 children
    else
    {
        // Find leftmost node in right subtree
        Node *Parent = Tree_;
        Temp = Tree_->Right;
        while (Temp->Left != NULL)
        {
            Parent = Temp;
            Temp = Parent->Left;
        }

        // Replace deleted data with leftmost value
        if (Parent == Tree_)
            Parent->Right = Temp->Right;
        else
            Parent->Left = Temp->Right;
        Tree_->Value = Temp->Value;
    }

    // Delete node
    delete Temp;
    return true;

}

bool BinaryTree::DeleteHelper(string value_, Node *&Tree_) {

    // Data value not found
    if (Tree_ == NULL)
        return false;

        // Data value found and deleted
    else if (Tree_->Value == value_)
        return (DeleteNode(Tree_));

        // Recursively search for node to delete
    else if (Tree_->Value > value_)
        return (DeleteHelper(value_, Tree_->Left));
    else
        return (DeleteHelper(value_, Tree_->Right));

}

bool BinaryTree::Delete(string value_) {

    // Call tree deletion function
    return (DeleteHelper(value_, Root));

}

void BinaryTree::PrintHelper(Node *Tree_) {

    // Check terminating condition
    if (Tree_ != NULL)
    {
        // Print left subtree
        PrintHelper(Tree_->Left);

        // Print node value
        cout << " " << Tree_->Value << " ";

        // Print right subtree
        PrintHelper(Tree_->Right);
    }

}

void BinaryTree::Print() {

    // Call tree printing function
    PrintHelper(Root);
    cout << endl;

}

int BinaryTree::CountHelper(Node *Tree_) {

    int count = 1;

    if (Tree_ == NULL) {

        return 0;

    }

    if (Tree_->Left != NULL) {

        count += CountHelper(Tree_->Left);

    }

    if (Tree_->Right != NULL) {

        count += CountHelper(Tree_->Right);

    }

    return count;

}

int BinaryTree::Count() {

    return CountHelper(Root);

}

int BinaryTree::HeightHelper(Node *Tree_) {

    if (Tree_ == NULL) {

        return 0;

    }

    return (1 + max(HeightHelper(Tree_->Left), HeightHelper(Tree_->Right)));

}

int BinaryTree::Height() {

    return HeightHelper(Root);

}