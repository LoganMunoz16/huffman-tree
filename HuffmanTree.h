/*
 Filename: HuffmanTree.h
 Description: Declaration of the class HuffmanTree to represent the binary Huffman Tree used to encode
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#ifndef HUFFMAN_LOGANMUNOZ16_HUFFMANTREE_H
#define HUFFMAN_LOGANMUNOZ16_HUFFMANTREE_H
#include <string>
#include "FrequencyTable.h"
#include "Symbol.h"
using std::string;

class HuffmanTree {
    Symbol* _root;
public:
    HuffmanTree();
    ~HuffmanTree();
    void AllOperations(FrequencyTable& refTable);
    void BuildTree(FrequencyTable& refTable);
    void BuildCode(Symbol* treeNode, string& code, FrequencyTable& refTable);
    Symbol* CreateNewSymbol(Symbol* element1, Symbol* element2);
};


#endif //HUFFMAN_LOGANMUNOZ16_HUFFMANTREE_H
