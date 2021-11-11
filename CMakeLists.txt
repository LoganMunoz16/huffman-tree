cmake_minimum_required(VERSION 3.10)
project(huffman_LoganMunoz16)

set(CMAKE_CXX_STANDARD 14)

add_executable(huffman_LoganMunoz16
        .gitignore
        README.md main.cpp HuffmanTree.cpp HuffmanTree.h FrequencyTable.cpp FrequencyTable.h Encoder.cpp Encoder.h Symbol.cpp Symbol.h)
