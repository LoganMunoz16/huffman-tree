# Huffman Tree

This was the final project in my Data Structures II course, CSC 2431. April 2020 - June 2020.

We were tasked with creating a C++ implementation of a Huffman Tree that would be used to encode any text document input to the program. The implementation takes the text document and first creates a Frequency Table, which holds how many times each character appears throughout the document. Then, using the Frequency Table, the Huffman Tree is constructed, and then used to encode the document. This was tested with small scale documents containing a few paragraphs, and text documents as large as the entire King James Bible. 

This project was given to us with very minimal directions, so it taught me a lot about working with the concepts that I knew and finding my own way to implement those concepts to achieve the goal. It is one of the most complex projects from an algorithm and data structure stand point that I have done thus far, and made me a lot more confident in using larger and complex data structures such as these. I plan to try and refine my implementation even further, and implement a way to work back through the Huffman Tree and decode an encoded document.

The following is an example of what the Encoding Table would look like after the Huffman Tree is created. Each character is assigned a combination of 0's and 1's based on its position in the tree, with the most common characters having the shortest encoded value.

```
{key:   , code: 11}
{key:  a, code: 010}
{key:  e, code: 0010}
{key:  o, code: 0110}
{key:  u, code: 0111}
{key:  r, code: 1000}
{key:  n, code: 1010}
{key:  i, code: 1011}
{key:  l, code: 00001}
{key:  s, code: 00010}
{key:  d, code: 00110}
{key:  m, code: 10011}
{key:  p, code: 000000}
{key:  c, code: 000001}
{key: CR, code: 000110}
{key:  t, code: 000111}
{key:  g, code: 001111}
{key:  q, code: 100100}
{key:  b, code: 100101}
{key:  h, code: 0011100}
{key:  f, code: 00111010}
{key:  z, code: 00111011}
```
