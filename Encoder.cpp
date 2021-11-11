/*
 Filename: Encoder.cpp
 Description: Implementation of the class Encoder to work with the huffman tree and frequency table to create the table
                and then create the huffman tree, and then put the new encoded elements back into a new text file.
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#include "Encoder.h"
#include "FrequencyTable.h"
#include "HuffmanTree.h"
#include <string>
#include <sstream>
#include <iostream>
using std::stringstream;
using std::istream;
using std::string;

/**
 * Constructor
 * Nothing needed here - just placed for consistency
 */
Encoder::Encoder() {

}

/**
 * Create Table
 * Creates the initial frequency table by going through and attempting to add each new character
 * Note - substitutes some different characters in for things like \n and \r
 * @param table - a reference to the table being made
 * @param input - the istream which is being read from
 * @return void
 */
void Encoder::CreateTable(FrequencyTable &table, istream &input) {
    char c = '\0';
    string element = "";
    while(input.get(c)) {
        if(c == '\n'){
            element = "CR";
        }
        else if(c == '\r') {
            element = "LF";
        }
        else {
            element = c;
        }
        table.AddElement(element);
    }
}

/**
 * Encode
 * Works with teh huffman tree to create the tree and then the resulting table, and then rereads through the istream
 * and based on the character read will insert the code for it into a stringstream to be returned at teh end
 * @param table - a reference to the table being made
 * @param tree - a reference to the huffman tree being used
 * @param input - the istream which is being read from
 * @return a string of 1's and 0's representing the encoded version of the input file
 */
string Encoder::Encode(FrequencyTable &table, HuffmanTree& tree, istream &input) {
    tree.AllOperations(table);
    stringstream result;
    char c = '\0';
    string element = "";
    while(input.get(c)) {
        if(c == '\n'){
            element = "CR";
        }
        else if(c == '\r') {
            element = "LF";
        }
        else {
            element = c;
        }
        result << table.GetPointer(table.IndexOf(element))->GetKey();
    }
    return result.str();
}
