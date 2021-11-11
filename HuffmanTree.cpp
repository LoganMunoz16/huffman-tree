/*
 Filename: HuffmanTree.cpp
 Description: Implementation of the class HuffmanTree to create the tree from the frequency table which allows
                the codes to be assigned to each element and then reinserted back into a table
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#include "HuffmanTree.h"
#include "FrequencyTable.h"
#include "Symbol.h"
#include <string>
using std::string;

/**
 * Constructor
 * Prepares the tree to be built by setting the root to nullptr
 */
HuffmanTree::HuffmanTree(): _root(nullptr) {

}

/**
 * Destructor
 * Deletes all the allocated memory in the tree - this will subsequently delete everything in the table as well
 * by deleting the root which will call the destructor of the Symbol class - therefore cascading the deletion
 * all the way down the tree.
 */
HuffmanTree::~HuffmanTree() {
    delete _root;
}

/**
 * Build Tree
 * Builds the Huffman Tree by removing the last two elements, creating a new element which is a combination of
 * them both, and then reincerting into the table - done until there is only one element left in the table which
 * then becomes the root of the tree.
 * I use just the simple left and right child pointer method of creating this
 * @param refTable - the frequency table which the tree is being built from
 * @return void
 */
void HuffmanTree::BuildTree(FrequencyTable& refTable) {
    while(refTable.GetSize() > 1) {
            Symbol* element1 = refTable.Remove();
            Symbol* element2 = refTable.Remove();
            Symbol* newSymbol = CreateNewSymbol(element1, element2);
            refTable.AddElement(newSymbol);
            refTable.SelectionSortFrequency();
    }
    _root = refTable.Remove();
    return;
}

/**
 * Build Code
 * Creates the code for each of the original elements by traversing down the tree in a postorder fashion and
 * building the code as the program traverses, adding the elements back into the table to create the table
 * containing each element and its code to be used when encoding the file.
 * Node - this is a recursive function
 * @param refTable - the frequency table which the tree is being built from
 * @param treeNode - the node which is being look at - is originally called with the root node
 * @param code - the string representation of the code which is changed during each run through the function
 * @return void
 */
void HuffmanTree::BuildCode(Symbol* treeNode, string& code, FrequencyTable& refTable) {
    if(_root == treeNode) {
        code = "";
    }
    if(treeNode != nullptr) {
        code += "1";
        BuildCode(treeNode->GetLeftChild(), code, refTable);
        code += "0";
        BuildCode(treeNode->GetRightChild(), code, refTable);
        if(treeNode->GetRightChild() == nullptr && treeNode->GetLeftChild() ==  nullptr) {
            treeNode->SetKey(code);
            refTable.AddElement(treeNode);
            refTable.InsertionSortFrequencyAlphabetical();
        }
        code = code.substr(0, code.length() - 1);
    }
    else {
        code = code.substr(0, code.length() - 1);
    }
    return;
}

/**
 * Create New Symbol
 * A helper function used when building the tree - takes in two elements and creates a new element which is the
 * parent of both the one inputted - combining both the element strings and their frequencies.
 * @param element1 - the first element which is the smallest
 * @param element2 - the second element which is the larger one
 * @return A  Symbol* which points to the newly created Symbol
 */
Symbol *HuffmanTree::CreateNewSymbol(Symbol *element1, Symbol *element2) {
    Symbol* temp = new Symbol;
    temp->SetElement(element1->GetElement() + element2->GetElement());
    temp->SetFrequency(element1->GetFrequency() + element2->GetFrequency());
    temp->SetLeftChild(element1);
    temp->SetRightChild(element2);
    temp->SetKey("2");

    return temp;
}

/**
 * All Operations
 * Something I created for convenience - essentially just calls all the other methods in this class so that there
 * only need to be one method called to complete all operations
 * @param refTable - the frequency table which the tree is being built from
 * @return void
 */
void HuffmanTree::AllOperations(FrequencyTable &refTable) {
    BuildTree(refTable);
    string code = "";
    BuildCode(_root, code, refTable);
}



