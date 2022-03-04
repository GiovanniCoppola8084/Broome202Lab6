//-------------------------------------------------------------------------------------------------
//File Name: NodeStructure.h
//Associated File: Standards.h
//Contains:
//  The structure for the node structure type and a structure for the node itself
//  Also, a typedef for a node pointer called nodeptr
//
//-------------------------------------------------------------------------------------------------

#ifndef NodeStructure_h
#define NodeStructure_h

//Include the header file for the standards
#include "Standards.h"

//Create a structure for the node type
struct NodeStructType
{
    //Create a variable for a char letter
    char letter;

    //Create a variable for an integer count
    int count;
};

//Create a structure for the node
struct Node
{
    //Create data for the node structure type
    NodeStructType data;

    //Create a left link for a node
    Node* leftLink;

    //Create a right link for a node
    Node* rightLink;
};

//Typedef for a node pointer
typedef Node* nodeptr;

#endif // !NodeStructure_h