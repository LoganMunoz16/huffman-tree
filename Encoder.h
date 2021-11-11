/*
 Filename: Encoder.h
 Description: Declaration of the class Encoder to represent the class which works with the frequency table and
                huffman tree to actually read and then encode the file given.
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/

#ifndef HUFFMAN_LOGANMUNOZ16_ENCODER_H
#define HUFFMAN_LOGANMUNOZ16_ENCODER_H
#include "FrequencyTable.h"
#include "HuffmanTree.h"
#include <string>
#include <fstream>
#include <iostream>
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::string;

class Encoder {

public:
    Encoder();
    void CreateTable(FrequencyTable& table, istream& input);
    string Encode(FrequencyTable& table, HuffmanTree& tree, istream& input);
};


#endif //HUFFMAN_LOGANMUNOZ16_ENCODER_H
