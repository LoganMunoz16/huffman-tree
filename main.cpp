/*
 Filename: main.cpp
 Description: The driver for this program, checks for various issues with the user and then uses primarily the
                encoder class to do the operations
 Author: Logan Munoz
 Date: 06/05/2020
 Course: Data Structures II
*/
#include "FrequencyTable.h"
#include "HuffmanTree.h"
#include "Encoder.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using std::cerr;
using std::endl;
using std::cout;

int main(int argc, char* argv[]) {
    ifstream inFile;
    ofstream outFile;
    if(argc != 4) {
        cerr << "Not enough or too many arguments. Please try again." << endl;
        return 1;
    }
    string action = argv[1];
    if(action != "-encode") {
        cerr << "Wrong operation, use -encode." << endl;
        return 1;
    }
    string inputName = argv[2];
    string outputName = argv[3];
    if(inputName == outputName) {
        cerr << "Error: Files have the same name, please try again." << endl;
        return 1;
    }
    else {
        inFile.open(inputName);
        if(!inFile.is_open()) {
            cerr << "Could not open file: " << inputName << ", please try again" << endl;
            return 1;
        }
        outFile.open(outputName);
        if(!outFile.is_open()) {
            cerr << "Could not open file: " << outputName << ", please try again" << endl;
            return 1;
        }
    }
    FrequencyTable table;
    HuffmanTree tree;
    Encoder encoder;
    encoder.CreateTable(table, inFile);
    inFile.close();
    inFile.open(inputName); //Reopens the file so that it can be read once more to substitute in the codes
    if(!inFile.is_open()) {
        cerr << "Could not open file: " << inputName << ", please try again" << endl;
        return 1;
    }
    outFile << encoder.Encode(table, tree, inFile);
    cout << table.ToString();
    return 0;
}