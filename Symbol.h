/*
 Filename: Symbol.h
 Description: Declaration of the class Symbol to represent the individual symbols which will be sorted and encoded
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#ifndef HUFFMAN_LOGANMUNOZ16_SYMBOL_H
#define HUFFMAN_LOGANMUNOZ16_SYMBOL_H
#include <string>
using std::string;

class Symbol {
    string _element;
    int _frequency;
    string _key;
    Symbol* _leftChild;
    Symbol* _rightChild;
public:
    Symbol();
    ~Symbol();
    string GetElement();
    void SetElement(string element);
    void SetFrequency(int frequency);
    void SetLeftChild(Symbol *leftChild);
    void SetRightChild(Symbol *rightChild);
    int GetFrequency();
    Symbol* GetLeftChild();
    Symbol* GetRightChild();
    string GetKey() ;
    void SetKey(string key);
    void IncrementFrequency();
};


#endif //HUFFMAN_LOGANMUNOZ16_SYMBOL_H
