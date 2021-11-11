/*
 Filename: FrequencyTable.h
 Description: Declaration of the class FrequencyTable to represent the table where the symbols with their frequencies
                are stored before being put into the huffman tree.
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#ifndef HUFFMAN_LOGANMUNOZ16_FREQUENCYTABLE_H
#define HUFFMAN_LOGANMUNOZ16_FREQUENCYTABLE_H
#include <string>
#include <vector>
#include "Symbol.h"
using std::string;
using std::vector;

class FrequencyTable {
    vector <Symbol*> _table;
public:
    FrequencyTable();
    bool AddElement(string elementToAdd);
    bool AddElement(Symbol* newSymbol);
    bool IsInTable(string elementToFind) const;
    int IndexOf(string elementToFind) const;
    void InsertionSortFrequencyAlphabetical();
    void SelectionSortFrequency();
    Symbol* Remove();
    size_t GetSize() const;
    Symbol* GetPointer(size_t index);
    string ToString();
};


#endif //HUFFMAN_LOGANMUNOZ16_FREQUENCYTABLE_H
