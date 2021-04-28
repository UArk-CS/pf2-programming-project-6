#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {

    string file = "addresses.txt";

    BinaryTree treeTest;
    treeTest.ReadFile(file);

    return 0;

}
