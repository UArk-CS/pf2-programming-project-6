#include <iostream>
#include "BinaryTree.h"
using namespace std;

void insertAddress(BinaryTree tree_);

int main() {

    string inputFile, outputFile;
    string search;
    int userInput = 0;

    BinaryTree tree;

    cout << "---- Binary Search Trees ----" << endl;
    cout << endl;

    cout << "Enter file to read into tree (with .txt): > ";
    cin >> inputFile;
    cout << endl;

    cout << "Enter file name for output (with .txt): > ";
    cin >> outputFile;
    cout << endl;

    tree.ReadFile(inputFile);
    tree.WriteSortedFile(outputFile);

    int quit = 1;
    while (quit == 1) {

        cout << "BST Menu" << endl;
        cout << "1.\t Insert New Address" << endl;
        cout << "2.\t Search and Output Addresses" << endl;
        cout << "3.\t Calculate Height of Tree" << endl;
        cout << endl;

        cout << "Enter 1, 2, or 3 (0 to Quit): > ";
        cin >> userInput;

        cin.ignore();

        switch (userInput) {
            case 0:
                quit = 0;
                break;
            case 1:
                //insert
                insertAddress(tree);
                cout << "New address added!" << endl;
                cout << endl;
                break;
            case 2:
                //search
                cout << "Enter address to lookup: " << endl;
                cout << "Example: 778 N Readable Lane, Jonesboro" << endl;
                cout << "> ";
                getline(cin, search);
                tree.Search(search);
                break;
            case 3:
                //height
                cout << tree.Height() << endl;
                break;
            default:
                break;
        }

    }

    return 0;

}

void insertAddress(BinaryTree tree_) {

    string houseNumber, streetName, city, state, zipcode;

    cout << "House Number: ";
    getline(cin, houseNumber);
    cout << "Street Name: ";
    getline(cin, streetName);
    cout << "City: ";
    getline(cin, city);
    cout << "State: ";
    getline(cin, state);
    cout << "Zipcode: ";
    getline(cin, zipcode);

    tree_.Insert(houseNumber, streetName, city, state, zipcode);

}
