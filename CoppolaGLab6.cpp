//----------------------------------------------------------------------------------------------------------------------
//Lab 6 Grading Block
//Name:  Giovanni Coppola
//Lab Grade: 
//----------------------------------------------------------------------------------------------------------------------
//Total Possible Points -------------------------------------------------------------------------------------------> 200
//Total Points lost ----------------------------------------------------------------------------------------------->
//Lab Grade -------------------------------------------------------------------------------------------------------> 
//----------------------------------------------------------------------------------------------------------------------
//General Comments:
//  
//  
//  
//  
//----------------------------------------------------------------------------------------------------------------------
//Standard Requirements
//  Requirements met as specified for the
//  Which includes but not limited to:
//    Program Creation
//    File Requirements
//    Documentation
//    Documentation as required for Class Objects
//    Constants
//    Variables 
//    Code
//Comments:
//  
//  
//  
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//Program Specifications
//-Standards.h included with the preprocessor directives
//-Course Required header & CPP file
//Comments:
//
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//----------------------------------------------------------------------------------------------------------------------
//
//Class Object DEFINITION
//nodeStructType defined
//node defined
//nodePtr type def
//Object defined using UML
//
//Methods
// Accomplish the required tasks EFFICIENTLY
// Methods placed in header and cpp file in the order 
//  listed in the instructions with the constructor first and the destructor last
// Constructor
//  Calls CreateTree
// CreateTree
//  Set root to NULL & isAlpha to true
// IsEmpty 
//  returns a bool
// GetRoot
//  returns a pointer to the root
// GetANode
//  Creates a nodePtr with letter,count and 2 pointers set to NULL// Insert
//   Inserts a node into the ordered ascending tree, either alpha or int tree
// BuildAlphaTree
//  Inputs letters, creating an alphabet ordered tree with counts set to 0
//  Recursively, Inorder
// BuildCountTree
//  From the updated Alpha tree, creates a count tree in ascending order, recursively
// ProcessText
//  Inputs the letters created a binary search tree from the order of the letters in the input file
// Insert
//  Inserts a node into tree based on the type of the newNode
// Inorder,Preorder,Postorder
//  Outputs the output file, in aligned columns the letter and the counts in the correct order, 
//    one per line
// UpdateTree
//  Using the input data from the text file, updates the count based on the occurrence of the
//   letter, recursively, Inorder
// FindLargestCount
//  Using the count tree & taking advantage of the order, efficiently finds the largest count
//   in the tree
// SumCounts
//  Calculates the sum of the counts in the count tree, recursively
// SearchTree
//  Non-recursive solution returns a bool, current and parent based on the type of tree
// DeleteLeafNode, DeleteNodeLeftChildOnly, DeleteNodeRightChildOnly, DeleteNodeWithTwoChildren,
//  Deletes and updates the pointers as needed
// DeleteNode
// Delete
//  Call one of 4 deletion methods to actually delete the specific type of node
// DestroyTree
// Print
//  Outputs the tree in the specified order to the output file
// Destructor
//Friend Functions
//  PrintDivider
//
//Comments:
// 
// 
// 
// 
//Points Lost --------------------------------------------------------------------------------------------------->
//
//Main - follow this order and accomplish these tasks
// Files open
// Alpha tree built
// Alpha tree output inorder, no counts updated with sum of counts
// Process Text, counts updated based on text
// Output Alpha tree inorder with letters, counts & sum of counts
// Output Alpha tree preorder with letters, counts & sum of counts
// Output Alpha tree postorder with letters, counts & sum of counts
// Build the count tree, ordered in ascending order based on the counts
// Output Count tree inorder with letters, counts & sum of counts
// Output Count tree postorder with letters, counts & sum of counts
// Find the largest in the Count tree and output the largest clearly labeled in the main
// Search for the letter, t in the Alpha tree and output message with letter and count or
//  message that it was not found
// Search for the letter, * in the Alpha tree and output message with letter and count or
//  message that it was not found
// Search for the letter, q in the Alpha tree and output message with letter and count or
//  message that it was not found
// Attempt to delete a node with letter, u to search and delete the node if found - leaf node
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, u - search and delete the node if found - node with 2 children
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, h - search and delete the node if found - node with 1 right child
// Output deletion message in the main based on found
// Attempt to delete a node with a letter, z - search and delete the node if found - node with 1 left child
// Output deletion message in the main based on found
// Attempt to delete a node with letter, x - search and delete the node if found - node not found
// Output deletion message in the main based on found
// Output the alpha tree to the output file, message "After 4 Deletions"
// Output the count tree to the output file, message "After 4 Deletions"
// Files Closed
//----------------------------------------------------------------------------------------------------------------------
//Miscellaneous Errors not anticipated by your professor
//
//
//
//Comments:
// 
//
// 
//----------------------------------------------------------------------------------------------------------------------
//

//Include the header for the tree class
#include "TreeClass.h"

//Prototype for the PrintLetterIsFound function
void PrintLetterIsFound(NodeStructType aNode, bool found, nodeptr current, nodeptr parent, 
	ofstream& fout);

//Prototype for the DeleteLetterIfFound function
void DeleteLetterIfFound(ofstream& fout, NodeStructType aNode, bool& found, nodeptr& current,
    nodeptr& parent, treeClassType& binarySearchTree);

int main(void)
{
    //Create an input file stream
    ifstream fin;
	ifstream fin2;
    //Create an output file stream
    ofstream fout;

    //15 - Create a boolean value to be the found variable
    bool found15 = false;

    //3 - Open the first input file stream
    fin.open("Letters.txt");
	//3 - Open the second input file stream
	fin2.open("info.txt");
    //4 - Open the output file stream
    fout.open("results.txt");

    //Output the heading to the screen
	PrintDivider('-', 100);
	PrintCourseHeading(COLLEGE, PROGRAM, NAME, 100);
	PrintDivider('-', 100);

	//Output the heading to the output file
	PrintDivider(fout, '-', 100);
	PrintCourseHeading(fout, COLLEGE, PROGRAM, NAME, 100);
	PrintDivider(fout, '-', 100);

    //5 - Create a new alpha tree
    treeClassType binarySearchTree;
	//5 - Create a new count tree
	treeClassType binaryCountTree;

	//15 - Create a new node structure type
	NodeStructType aNode;
	//15 - Create a new node pointer for the current node
	nodeptr current15;
	//15 - Create a new node pointer for the parent node
	nodeptr parent15;

    //5 - Build the BST
    binarySearchTree.BuildAlphaTree(fin);

    //6 - Output the BST, inorder, with no counts
    binarySearchTree.Print(fout, "Inorder", "ALPHA", "Updated With Letters");

    //7 - Process the text
    binarySearchTree.ProcessText(fin2);

    //8 - Output the BST, inorder, with updated counts
    binarySearchTree.Print(fout, "Inorder", "ALPHA", "Updated Counts");

    //9 - Output the BST, inorder, with letters and counts
    binarySearchTree.Print(fout, "Preorder", "ALPHA", "Letters & Counts");

    //10 - Output the BST, inorder, with updated counts
    binarySearchTree.Print(fout, "Postorder", "ALPHA", "Updated Counts");

    //11 - Build the count tree from lowest to highest
	binaryCountTree.BuildCountTree(binarySearchTree.GetRoot());

    //12 - Output the count tree inorder with the letter and counts
	binaryCountTree.Print(fout, "Inorder", "COUNT", "Letters & Counts");

    //13 - Output the count tree postorder with the letter and counts
	binaryCountTree.Print(fout, "Postorder", "COUNT", "Letters & Counts");

    //14 - Print the divider to the output file
    PrintDivider(fout, '-', 100);

    //14 - Find the largest count of the BST and output it to the output file
    fout << "The largest count of the BST is: " << binaryCountTree.FindLargestCount() << endl;

    //14 - Print the divider to the output file
    PrintDivider(fout, '-', 100);

	//15 - Set the letter of node structure type to a 't'
	aNode.letter = 't';
    //15 - Search for the letter 't'
    binarySearchTree.SearchTree(aNode, found15, current15, parent15);
	//15 - Call the PrintLetterIsFound function
	PrintLetterIsFound(aNode, found15, current15, parent15, fout);
    //15 - Set found to false
    found15 = false;

	//16 - Set the letter of the node structure type to a '*'
	aNode.letter = '*';
	//16 - Search for the character '*'
	binarySearchTree.SearchTree(aNode, found15, current15, parent15);
	//16 - Call the PrintLetterIsFound function
	PrintLetterIsFound(aNode, found15, current15, parent15, fout);
    //16 - Set found to false
    found15 = false;

	//17 - Set the letter of the node structure type to a 'q'
	aNode.letter = 'q';
	//17 - Search for the character 'q'
	binarySearchTree.SearchTree(aNode, found15, current15, parent15);
	//17 - Call the PrintLetterIsFound function
	PrintLetterIsFound(aNode, found15, current15, parent15, fout);
    //17 - Set found to false
    found15 = false;

	//18 - Set the letter of the node structure type to a 'u'
	aNode.letter = 'u';
	//18 - Search for the character 'u'
	binarySearchTree.SearchTree(aNode, found15, current15, parent15);
    //18 - Delete the letter if found
    DeleteLetterIfFound(fout, aNode, found15, current15, parent15, binarySearchTree);
    //18 - Set found to false
    found15 = false;

	//19 - Set the letter of the node structure type to a 'x'
	aNode.letter = 'x';
	//19 - Search for the character 'x'
	binarySearchTree.SearchTree(aNode, found15, current15, parent15);
	//19 - Delete the letter if found
    DeleteLetterIfFound(fout, aNode, found15, current15, parent15, binarySearchTree);
    //19 - Set found to false
    found15 = false;

	//20 - Set the letter of the node structure type to a 'h'
	aNode.letter = 'h';
	//20 - Search for the character 'h'
	binarySearchTree.SearchTree(aNode, found15, current15, parent15);
	//20 - Delete the letter if found
    DeleteLetterIfFound(fout, aNode, found15, current15, parent15, binarySearchTree);
    //20 - Set found to false
    found15 = false;

	//21 - Set the letter of the node structure type to a 'z'
	aNode.letter = 'z';
	//21 - Search for the character 'z'
	binarySearchTree.SearchTree(aNode, found15, current15, parent15);
	//21 - Delete the letter if found
    DeleteLetterIfFound(fout, aNode, found15, current15, parent15, binarySearchTree);
    //21 - Set found to false
    found15 = false;

	//22 - Set the letter of the node structure type to a 'x'
	aNode.letter = 'x';
	//22 - Search for the character 'x'
	binarySearchTree.SearchTree(aNode, found15, current15, parent15);
	//22 - Delete the letter if found
    DeleteLetterIfFound(fout, aNode, found15, current15, parent15, binarySearchTree);

    //23 - Output the alpha tree inorder
    binarySearchTree.Print(fout, "Inorder", "ALPHA", "After 4 Deletions");

    //24 - Output the count tree inorder
    binaryCountTree.Print(fout, "Inorder", "COUNT", "Updated Counts");

    //Close the first input file
    fin.close();
    //Close the second input file
    fin2.close();
    //Close the output file
    fout.close();

    return 0;
}

//-------------------------------------------------------------------------------------------------
//PrintLetterIsFound - function to print if a letter was found or not
//-------------------------------------------------------------------------------------------------
void PrintLetterIsFound(NodeStructType aNode, bool found, nodeptr current, nodeptr parent, 
	ofstream& fout)
{
	//Print the divider to the output file
	PrintDivider(fout, '-', 100);
	//If the tree was found
	if (found == true)
	{
		//Print that the letter was found and the count of that letter
		fout << "The letter " << aNode.letter << " count is: " << parent->data.count << endl;
	}
	else
	{
		//Print that the letter was not found
		fout << "The letter " << aNode.letter << " was not found in the tree" << endl;
	}
	//Print the divider to the output file
	PrintDivider(fout, '-', 100);
}

//-------------------------------------------------------------------------------------------------
//DeleteLetterIfFound - function to delete the letter if found with a message following, or just
//  a message if the letter was not found in the tree
//-------------------------------------------------------------------------------------------------
void DeleteLetterIfFound(ofstream& fout, NodeStructType aNode, bool& found, nodeptr& current,
    nodeptr& parent, treeClassType& binarySearchTree)
{
    //Print the divider to the output file
	PrintDivider(fout, '-', 100);
	//If the character was found
    if (found == true)
    {
        //Call the DeleteNode method
        binarySearchTree.DeleteNode(aNode, found);

        //Output that the letter was found and deleted
        fout << "The letter " << aNode.letter << " was found in the binary search tree and deleted" << endl;
    }
    else
    {
        //Output that the letter was not found otherwise
        fout << "The letter was not found in the binary search tree" << endl;
    }
    //Print the divider to the output file
	PrintDivider(fout, '-', 100);
}