/*
 Filename: FrequencyTable.cpp
 Description: Implementation of the class FrequencyTable to add, remove, sort, etc. elements in the frequency table
                to prepare them for being put in the huffman tree.
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#include "FrequencyTable.h"
#include "Symbol.h"
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using std::string;
using std::stringstream;
using std::setw;

/**
 * Constructor
 * Nothing needed here - just placed for consistency
 */
FrequencyTable::FrequencyTable() {

}

/**
 * Add Element
 * Attempts to add a Symbol to the table based on the element string associated with it
 * First checks if the element is already in the table, if so it will increase its frequency and sort the table
 * Otherwise it will create a pointer to a new Symbol* and then add it to the table, and then sort it.
 * @param elementToAdd - the string representing the new element to add to the table
 * @return false if the element was already there, and true if not
 */
bool FrequencyTable::AddElement(string elementToAdd) {
    if(IsInTable(elementToAdd)) {
        GetPointer(IndexOf(elementToAdd))->IncrementFrequency();
        InsertionSortFrequencyAlphabetical();
        return false;
    }
    else {
        Symbol* toAdd = new Symbol;
        toAdd->SetElement(elementToAdd);
        _table.push_back(toAdd);
    }
    InsertionSortFrequencyAlphabetical();
    return true;
}

/**
 * Add Element
 * Attempts to add a Symbol to the table based on a Symbol*
 * When this method is being used, there will be no duplicates, so the only case to check is to ensure the Symbol*
 * is not null. Then it will add it to the table - sorting is done manually from outside this method due to the
 * sorting being done differently when creating the table and when creating the tree
 * @param newSymbol - a Symbol* to add to the table
 * @return false if the Symbol* was null and true if not and it was added
 */
bool FrequencyTable::AddElement(Symbol *newSymbol) {
    if(newSymbol == nullptr) {
        return false;
    }
    _table.push_back(newSymbol);
    return true;
}

/**
 * Is In Table
 * Searches the table to see if the element passed is in it
 * @param elementToFind - the element you are searhcing for
 * @return true if the element is found, false if not
 */
bool FrequencyTable::IsInTable(string elementToFind) const{
    for(size_t i = 0; i < _table.size(); i++) {
        if(_table.at(i)->GetElement() == elementToFind)
            return true;
    }
    return false;
}

/**
 * Index Of
 * Gets the index of the passed element
 * @param elementToFind - the element which the user is searching for
 * @return an integer with the index of the element, -1 if the element is not found
 */
int FrequencyTable::IndexOf(string elementToFind) const{
    for(size_t i = 0; i < _table.size(); i++) {
        if(_table.at(i)->GetElement() == elementToFind) {
            return i;
        }
    }
    return -1;
}

/**
 * Insertion Sort for Frequency and Alphabetical
 * Uses an insertion sort to sort the table by frequency and then sorts it alphabetically - both in descending order
 * This is used when creating the table, but not when creating the tree, because to get the result given to us
 * we were not able to sort alphabetically when creating the tree and get the same thing
 * @return void
 */
void FrequencyTable::InsertionSortFrequencyAlphabetical() {
    Symbol* temp;
    int j;
    //This first loop is the insertion sort
    for(size_t i = 1; i < _table.size(); i++) {
        j = i;
        while(j > 0 && _table.at(j - 1)->GetFrequency() < _table.at(j)->GetFrequency()) {
                temp = _table.at(j);
                _table.at(j) = _table.at(j - 1);
                _table.at(j - 1) = temp;
                j--;
        }
    }
    //This second part goes through and changes things alphabetically
    for(size_t k = 0; k < _table.size() - 1; k++) {
        if (_table.at(k)->GetFrequency() == _table.at(k + 1)->GetFrequency()) {
            if (_table.at(k)->GetElement() < _table.at(k + 1)->GetElement()) {
                temp = _table.at(k + 1);
                _table.at(k + 1) = _table.at(k);
                _table.at(k) = temp;
            }
        }
    }
}

/**
 * Selection Sort for Frequency
 * Uses a selection sort to sort the table by frequency in descending order - done only when in the process of
 * creating the huffman tree
 * @return void
 */
void FrequencyTable::SelectionSortFrequency() {
    size_t maxFrequencyIndex = 0;
    Symbol* temp;
    for(size_t i = _table.size() - 1; i > 0; i--) {
        maxFrequencyIndex = i;
        for(int j = i - 1; j >= 0; j--) {
            if(_table.at(j)->GetFrequency() < _table.at(maxFrequencyIndex)->GetFrequency()) {
                maxFrequencyIndex = j;
            }
        }
        if(maxFrequencyIndex != i) {
            temp = _table.at(maxFrequencyIndex);
            _table.at(maxFrequencyIndex) = _table.at(i);
            _table.at(i) = temp;
        }
    }
}

/**
 * Remove
 * Removes the element at the end of the table - thus with the smalled frequency - but does not delete the Symbol
 * @return Symbol* - a pointer to the element that was removed from the table
 */
Symbol* FrequencyTable::Remove() {
    Symbol* temp = _table.at(_table.size() - 1);
    _table.pop_back();
    return temp;
}

/**
 * Get Size
 * Getter for the size of the table
 * @return size_t of the table size
 */
size_t FrequencyTable::GetSize() const{
    return _table.size();
}

/**
 * Get Pointer
 * Gets the pointer at a certain index - checks to ensure a valid index
 * @return Symbol* of the pointer at that index
 */
Symbol* FrequencyTable::GetPointer(size_t index) {
    if(index >= _table.size()) {
        return nullptr;
    }
    return _table.at(index);
}

/**
 * To String
 * Returns a string representation of the entire table in the format:
 * {key:  a, code: 11}
 * @return a string of the entire table
 */
string FrequencyTable::ToString() {
    stringstream result;
    for(size_t i = 0; i < _table.size(); i++) {
        result << "{key:" << setw(3) << _table.at(i)->GetElement() << ", code: " << _table.at(i)->GetKey() << "}\n";
    }
    return result.str();
}








