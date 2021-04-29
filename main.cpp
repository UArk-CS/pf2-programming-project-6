#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {

    string file = "addresses_copy.txt";
    string outputFile = "sorted_addresses.txt";

    BinaryTree treeTest;
    treeTest.ReadFile(file);
    treeTest.WriteSortedFile(outputFile);

    return 0;

}
