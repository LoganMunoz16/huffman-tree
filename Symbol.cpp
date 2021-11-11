/*
 Filename: Symbol.cpp
 Description: Implementation of the class Symbol to represent the object which is stored in both the table and the
                tree - allows for access from all classes - included the necessary elements to create the tree
                and store the data needed.
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#include "Symbol.h"
#include <string>
using std::string;

/**
 * Constructor
 * Sets the default values of all the different elements of a Symbol
 */
Symbol::Symbol() : _element("-1"), _frequency(1), _key("2"),  _leftChild(nullptr), _rightChild(nullptr) {

}

/**
 * Get Element
 * The Getter for the _element value in the Symbol
 * @return _element - string
 */
string Symbol::GetElement() {
    return _element;
}

/**
 * Get Frequency
 * The Getter for the _frequency value in the Symbol
 * @return _frequency - int
 */
int Symbol::GetFrequency() {
    return _frequency;
}

/**
 * Get Left Child
 * The Getter for the _leftChild value in the Symbol
 * @return _leftchild - Symbol*
 */
Symbol *Symbol::GetLeftChild() {
    return _leftChild;
}

/**
 * Get Right Child
 * The Getter for the _rightchild value in the Symbol
 * @return _rightchild - Sybmol*
 */
Symbol *Symbol::GetRightChild() {
    return _rightChild;
}

/**
 * Set Element
 * The Setter for the _element value in the Symbol - sets it as the string passed
 * @return void
 */
void Symbol::SetElement(string element) {
    _element = element;
}

/**
 * Set Frequency
 * The Setter for the _frequency value in the Symbol - sets it as the int passed
 * @return void
 */
void Symbol::SetFrequency(int frequency) {
    _frequency = frequency;
}

/**
 * Set Left Child
 * The Setter for the _leftChild value in the Symbol - sets it as the Symbol* passed
 * @return void
 */
void Symbol::SetLeftChild(Symbol *leftChild) {
    _leftChild = leftChild;
}

/**
 * Set Right Child
 * The Setter for the _righCChild value in the Symbol - sets it as the Symbol* passed
 * @return void
 */
void Symbol::SetRightChild(Symbol *rightChild) {
    _rightChild = rightChild;
}

/**
 * Increment Frequency
 * Increases the frequency of this by one
 * @return void
 */
void Symbol::IncrementFrequency() {
    _frequency++;
}

/**
 * Get Get Key
 * The Getter for the _key value in the Symbol
 * @return _key - string
 */
string Symbol::GetKey()  {
    return _key;
}

/**
 * Set Key
 * The Setter for the _key value in the Symbol - sets it as the string passed
 * @return void
 */
void Symbol::SetKey(string key) {
    _key = key;
}

/**
 * Destructor
 * Deletes the allocated memory in the left and right children - because they are both Symbols, this will be
 * called many times in terms of the tree created and thus will delete everything
 */
Symbol::~Symbol() {
        delete _leftChild;
        delete _rightChild;
}
