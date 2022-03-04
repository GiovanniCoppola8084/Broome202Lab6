//-------------------------------------------------------------------------------------------------
//File Name: TreeClass.h
//Associated File: TreeClass.cpp and NodeStructure.h
//Contains:
//  Class for the tree with the function prototypes and inline constructor and destructor
//
//-------------------------------------------------------------------------------------------------

#ifndef TreeClass_h
#define TreeClass_h

//Include the header file for the node structure
#include "NodeStructure.h"

//Create the class for the tree class type
class treeClassType
{
public:

    //Constructor - inline method to call CreateTree
    treeClassType() { CreateTree(); };

    //Prototypes for other public methods:
    void CreateTree();
    bool IsEmpty();
    nodeptr GetRoot();
    nodeptr GetANode(char aLetter, int letterCount);
    void BuildAlphaTree(ifstream& fin);
    void BuildCountTree(nodeptr parentPtr);
    void ProcessText(ifstream& fin);
    void Inorder(ofstream& fout, nodeptr currentPtr);
    void Preorder(ofstream& fout, nodeptr currentPtr);
    void Postorder(ofstream& fout, nodeptr currentPtr);
    void UpdateTree(char aLetter, nodeptr currentPtr);
    int FindLargestCount();
    int SumCounts(nodeptr currentNode);
    void SearchTree(NodeStructType searchNode, bool& found, nodeptr& currentPtr, 
        nodeptr& parentPtr);
    void DeleteNode(NodeStructType searchNode, bool& found);
    void DestroyTree();
    void Print(ofstream& fout, string traversalType, string treeType, string taskType);

    //Destructor - inline method to call DestroyTree
    ~treeClassType() { DestroyTree(); };

    //Friend function for the PrintDivider method
    friend void PrintDivider(ofstream& fout, char symbol, int width);

private:

    //Prototypes for private methods
    void Insert(nodeptr newNode);
    void DeleteLeafNode(nodeptr& currentPtr, nodeptr& parentPtr);
    void DeleteNodeLeftChildOnly(nodeptr& currentPtr, nodeptr& parentPtr);
    void DeleteNodeRightChildOnly(nodeptr& currentPtr, nodeptr& parentPtr);
    void DeleteNodeWithTwoChildren(nodeptr& currentPtr, nodeptr& parentPtr);
    void Delete(nodeptr& currentPtr, nodeptr& parentPtr);

    //Pointer for the root of the tree
    nodeptr root;

    //Boolean for if the tree is the alphabet tree
    bool isAlpha;
};

#endif // !TreeClass_h