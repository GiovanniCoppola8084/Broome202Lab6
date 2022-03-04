//-------------------------------------------------------------------------------------------------
//File Name: TreeClass.cpp
//Associated File: TreeClass.h
//Contains:
//  All methods definitions from the TreeClass.h file
//
//-------------------------------------------------------------------------------------------------

//Include the header file for the tree class
#include "TreeClass.h"

//-------------------------------------------------------------------------------------------------
//CreateTree - sets the root of the tree to null and the isAlpha variable to true
//-------------------------------------------------------------------------------------------------
void treeClassType::CreateTree()
{
    //Set the root to NULL
    root = nullptr;

    //Set the isAlpha to true
    isAlpha = true;
}

//-------------------------------------------------------------------------------------------------
//IsEmpty - returns if the root is null
//-------------------------------------------------------------------------------------------------
bool treeClassType::IsEmpty()
{
    //Return if the root is null or not
    return root == nullptr;
}

//-------------------------------------------------------------------------------------------------
//GetRoot - returns the root from the top of the tree
//-------------------------------------------------------------------------------------------------
nodeptr treeClassType::GetRoot()
{
    //Returns the root from the top of the tree
    return root;
}

//-------------------------------------------------------------------------------------------------
//GetANode - creates a new node for a letter and stores that letter and count
//-------------------------------------------------------------------------------------------------
nodeptr treeClassType::GetANode(char aLetter, int letterCount)
{
    //Create a temporary new node pointer
    nodeptr aNode = new Node;

    //Store the new letter of the node
    aNode->data.letter = aLetter;
    //Store the new letter count of the node
    aNode->data.count = letterCount;

    //Set the left link to null
    aNode->leftLink = nullptr;
    //Set the right link to null
    aNode->rightLink = nullptr;

    //Return the node
    return aNode;
}

//-------------------------------------------------------------------------------------------------
//BuildAlphaTree - read the data from the input file and stores the letters in a BST
//-------------------------------------------------------------------------------------------------
void treeClassType::BuildAlphaTree(ifstream& fin)
{
    //Create a temporary node to input the data
    nodeptr aNode = new Node;

    //Set the isAlpha flag to true
    isAlpha = true;

    //Read in the first character of the input file (primer)
    fin.get(aNode->data.letter);

    //While loop to loop through the rest of the nodes and input the letters
    while (fin)
    {
        //Call insert to insert the character into the BST with a new node
        Insert(GetANode(aNode->data.letter, 0));

        //Read in the next character of the input file (changer)
        fin.get(aNode->data.letter);
    }
}

//-------------------------------------------------------------------------------------------------
//Insert - this function will determine if the letter will be added to the left or right of a node
//-------------------------------------------------------------------------------------------------
void treeClassType::Insert(nodeptr newNode)
{
    //Create a temporary node for the current node
    nodeptr current;

    //Create a temporary node for the parent node
    nodeptr parent;

    //If the list is an alphabetical list
    if (isAlpha)
    {
        //If it is the first node in the tree
        if (root == nullptr)
        {
            //Set the current node to the new root
            current = newNode;

            //The root becomes the new node
            root = current;
        }
        else
        {
            //Set the current to the root
            current = root;
            //Set the parent to the root
            parent = root;

            //While the parent is not the null pointer
            while (current != nullptr)
            {
                //Set the parent to the current
                parent = current;

                //If the new node is less than the root
                if (current->data.letter > newNode->data.letter)
                {
                    //Set the current's left link node to the new node
                    current = current->leftLink;
                }
                else
                {
                    //Set the current's right link node to the new node
                    current = current->rightLink;
                }
            }
            //If the parent's node is greater than the new node
            if (parent->data.letter > newNode->data.letter)
            {
                //Set the left child of the parent to the new node
                parent->leftLink = newNode;
            }
            else
            {
                //Set the right child of the parent to the new node
                parent->rightLink = newNode;
            }
        }
    }
    //If the list is a count list
    else
    {
        //If it is the first node in the tree
        if (root == nullptr)
        {
            //Set the current node to the new root
            current = newNode;

            //The root becomes the new node
            root = current;
        }
        else
        {
            //Set the current to the root
            current = root;
            //Set the parent to the root
            parent = root;

            //While the parent is not the null pointer
            while (current != nullptr)
            {
                //Set the parent to the current
                parent = current;

                //If the new node is less than the root
                if (current->data.count > newNode->data.count)
                {
                    //Set the current's left link node to the new node
                    current = current->leftLink;
                }
                else
                {
                    //Set the current's right link node to the new node
                    current = current->rightLink;
                }
            }
            //If the parent's node is greater than the new node
            if (parent->data.count > newNode->data.count)
            {
                //Set the left child of the parent to the new node
                parent->leftLink = newNode;
            }
            else
            {
                //Set the right child of the parent to the new node
                parent->rightLink = newNode;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
//BuildCountTree - Traverses the tree and updates the count of the tree
//-------------------------------------------------------------------------------------------------
void treeClassType::BuildCountTree(nodeptr parentPtr)
{
    //Create a temporary node for the copied tree
    nodeptr copiedTree = new Node;

    //Set the IsAlpha flag to false
    isAlpha = false;

    //Set the current to the root
    copiedTree = parentPtr;

    //If the parentPtr is not the null pointer
    if (parentPtr != nullptr)
    {
        //Call the BuildCountTree recursively with the copiedTree's left link
        BuildCountTree(copiedTree->leftLink);

        //Insert the new node into the copied tree in order of the count
        Insert(GetANode(parentPtr->data.letter, parentPtr->data.count));
        
        //Call the BuildCountTree recursively with the copiedTree's right link
        BuildCountTree(copiedTree->rightLink);
    }
}

//-------------------------------------------------------------------------------------------------
//ProcessText - reads in an input file and will process the data that is taken in
//-------------------------------------------------------------------------------------------------
void treeClassType::ProcessText(ifstream& fin)
{
    //Create a temporary character
    char tempChar;

    //Read in the first character from the input file (primer)
    fin.get(tempChar);

    //While loop to loop through the rest of the input file stream
    while (fin)
    {
        //Lower case the tempChar
        tempChar = tolower(tempChar);

        //If the lowercased character is in the alphabet
        if (tempChar >= 'a' && tempChar <= 'z')
        {
            //Call the UpdateTree method
            UpdateTree(tempChar, root);
        }

		//Read in the next character from the input file (changer)
		fin.get(tempChar);
    }
}

//-------------------------------------------------------------------------------------------------
//Inorder - output the tree in an inorder way, recursively
//-------------------------------------------------------------------------------------------------
void treeClassType::Inorder(ofstream& fout, nodeptr currentPtr)
{
    //If the currentPtr is not equal to the null pointer
    if (currentPtr != nullptr)
    {
        //Call the Inorder function recursively for the left link
        Inorder(fout, currentPtr->leftLink);

        //Print the character and the count of that character
        fout << right << setw(15) << currentPtr->data.letter << setw(15)
            << currentPtr->data.count << endl;

        //Call the Inorder function recursively for the right link
        Inorder(fout, currentPtr->rightLink);
    }
}

//-------------------------------------------------------------------------------------------------
//Preorder - output the tree in a preorder way, recursively
//-------------------------------------------------------------------------------------------------
void treeClassType::Preorder(ofstream& fout, nodeptr currentPtr)
{
    //If the currentPtr is not equal to the null pointer
    if (currentPtr != nullptr)
    {
        //Print the character and the count of that character
        fout << right << setw(15) << currentPtr->data.letter << setw(15)
            << currentPtr->data.count << endl;

        //Call the Preorder function recursively for the left link
        Preorder(fout, currentPtr->leftLink);

        //Call the Preorder function recursively for the right link
        Preorder(fout, currentPtr->rightLink);
    }
}

//-------------------------------------------------------------------------------------------------
//Postorder - output the tree in a postorder way, recursively
//-------------------------------------------------------------------------------------------------
void treeClassType::Postorder(ofstream& fout, nodeptr currentPtr)
{
    //If the currentPtr is not equal to the null pointer
    if (currentPtr != nullptr)
    {
        //Call the Postorder function recursively for the left link
        Postorder(fout, currentPtr->leftLink);

        //Call the Postorder function recursively for the right link
        Postorder(fout, currentPtr->rightLink);

        //Print the character and the count of that character
        fout << right << setw(15) << currentPtr->data.letter << setw(15)
            << currentPtr->data.count << endl;
    }
}

//-------------------------------------------------------------------------------------------------
//UpdateTree - searches for a letter and updates the count of that letter
//-------------------------------------------------------------------------------------------------
void treeClassType::UpdateTree(char aLetter, nodeptr currentPtr)
{
    //If the tree is not equal to the null pointer
    if (currentPtr != nullptr)
    {
        //If the letter passed in is less than the current character of the tree
        if (aLetter < currentPtr->data.letter)
        {
            //Move the tree to the left child of the currentPtr by calling the UpdateTree method
            UpdateTree(aLetter, currentPtr->leftLink);
        }
        else if (aLetter > currentPtr->data.letter)
        {
            //Move the tree to the right child of the currentPtr by calling the UpdateTree method
            UpdateTree(aLetter, currentPtr->rightLink);
        }
        else
        {
            //Update the count of the tree
            currentPtr->data.count++;
        }
    }
}

//-------------------------------------------------------------------------------------------------
//FindLargestCount - finds the largest count in the tree
//-------------------------------------------------------------------------------------------------
int treeClassType::FindLargestCount()
{
    //Create a temporary current node
    nodeptr current = new Node;
    //Create a temporary parent node
    nodeptr parent = new Node;

    //Set a temporary highest count
    int highestCount = 0;

    //Set the current to the root
    current = root;

    //While current is not equal to the null pointer
    while (current != nullptr)
    {
        //Set the parent to the current
        parent = current;

        //If the highest count is less than the current count
        if (current->data.count > highestCount)
        {
            //Set the new highest count
            highestCount = current->data.count;
        }

        //Move the current count to the right
        current = current->rightLink;
    }
    //Return the highest count
    return highestCount;
}

//-------------------------------------------------------------------------------------------------
//SumCounts - totals all of the counts from the tree
//-------------------------------------------------------------------------------------------------
int treeClassType::SumCounts(nodeptr currentNode)
{
	//If the current node is not the null pointer
	if (currentNode != nullptr)
	{
		//Return the count by recursively calling until the null pointer is reached
		return currentNode->data.count + SumCounts(currentNode->leftLink) + SumCounts(currentNode->rightLink);
	}
	else
	{
		//Otherwise, return 0
		return 0;
	}
}

//-------------------------------------------------------------------------------------------------
//SearchTree - Searches the tree for a value and returns if that value is found
//-------------------------------------------------------------------------------------------------
void treeClassType::SearchTree(NodeStructType searchNode, bool& found, nodeptr& currentPtr, 
    nodeptr& parentPtr)
{
    //If the tree is an alphabet tree
    if (isAlpha)
    {
        //If the root is null
        if (root == nullptr)
        {
            //Set the current to the null pointer
            currentPtr = nullptr;
        }
        else
        {
            //Set the current to the root
            currentPtr = root;

            //Set the parent to null
            parentPtr = nullptr;

            //While the current tree is not empty
            while (currentPtr != nullptr && !found)
            {
                //If the letter is less than the current letter
                if (currentPtr->data.letter > searchNode.letter)
                {
                    //Set the parent equal to the current
                    parentPtr = currentPtr;

                    //Move to the left link of the current
                    currentPtr = currentPtr->leftLink;
                }
                else if (currentPtr->data.letter < searchNode.letter)
                {
                    //Set the parent equal to the current
                    parentPtr = currentPtr;

                    //Move to the right link of the current
                    currentPtr = currentPtr->rightLink;
                }
                else if (currentPtr->data.letter == searchNode.letter)
                {
                    //Set found equal to true
                    found = true;
                }
            }
        }
    }
    else
    {
        //If the root is null
        if (root == nullptr)
        {
            //Set the current to the null pointer
            currentPtr = nullptr;
        }
        else
        {
            //Set the current to the root
            currentPtr = root;

            //Set the parent to null
            parentPtr = nullptr;

            //While the current tree is not empty
            while (currentPtr != nullptr && !found)
            {
                //If the letter is less than the current letter
                if (currentPtr->data.count > searchNode.count)
                {
                    //Set the parent equal to the current
                    parentPtr = currentPtr;

                    //Move to the left link of the current
                    currentPtr = currentPtr->leftLink;
                }
                else if (currentPtr->data.count < searchNode.count)
                {
                    //Set the parent equal to the current
                    parentPtr = currentPtr;

                    //Move to the right link of the current
                    currentPtr = currentPtr->rightLink;
                }
                else if (currentPtr->data.count == searchNode.count)
                {
                    //Set found equal to true
                    found = true;
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
//DeleteNode - searches the tree for a node and then deletes it
//-------------------------------------------------------------------------------------------------
void treeClassType::DeleteNode(NodeStructType searchNode, bool& found)
{
    //Create a node for the current
    nodeptr current;
    //Create a node for the parent
    nodeptr parent;

    //Set found to false
    found = false;

    //Search the tree for the node passed in
    SearchTree(searchNode, found, current, parent);

    //If found is true
    if (found == true)
    {
        //Call the delete function
        Delete(current, parent);
    }
}

//-------------------------------------------------------------------------------------------------
//Delete - call one of the 4 methods based on the node passed in
//-------------------------------------------------------------------------------------------------
void treeClassType::Delete(nodeptr& currentPtr, nodeptr& parentPtr)
{
    //If the current node has no children
    if (currentPtr->leftLink == nullptr && currentPtr->rightLink == nullptr)
    {
        //Call the delete leaf node method
        DeleteLeafNode(currentPtr, parentPtr);
    }
    else if (currentPtr->leftLink != nullptr && currentPtr->rightLink == nullptr)
    {
        //Call the delete left child only method
        DeleteNodeLeftChildOnly(currentPtr, parentPtr);
    }
    else if (currentPtr->leftLink == nullptr && currentPtr->rightLink != nullptr)
    {
        //Call the delete right child only method
        DeleteNodeRightChildOnly(currentPtr, parentPtr);
    }
    else if (currentPtr->leftLink != nullptr && currentPtr->rightLink != nullptr)
    {
        //Call the delete node with two children method
        DeleteNodeWithTwoChildren(currentPtr, parentPtr);
    }
}

//-------------------------------------------------------------------------------------------------
//DeleteLeafNode - delete the node with no children
//-------------------------------------------------------------------------------------------------
void treeClassType::DeleteLeafNode(nodeptr& currentPtr, nodeptr& parentPtr)
{
    //If the parent is not the null pointer
    if (parentPtr != nullptr)
    {
        //If the parent's left child is pointing to the current
        if (parentPtr->leftLink == currentPtr)
        {
            //Set the parent's left child to null
            parentPtr->leftLink = nullptr;
        }
        else if (parentPtr->rightLink == currentPtr)
        {
            //Set the parent's right link to null
            parentPtr->rightLink = nullptr;
        }
    }
    else if (root == currentPtr)
    {
        //Set the root to null
        root = nullptr;
    }

    //Set the current pointer to the null pointer
    currentPtr = nullptr;

    //Delete current
    delete currentPtr;
}

//-------------------------------------------------------------------------------------------------
//DeleteNodeWithLeftChild - delete the node with a left child
//-------------------------------------------------------------------------------------------------
void treeClassType::DeleteNodeLeftChildOnly(nodeptr& currentPtr, nodeptr& parentPtr)
{
    //If the parent is not null
    if (parentPtr != nullptr)
    {
        //Set the parent's left child to the current's left child
        parentPtr->rightLink = currentPtr->leftLink;
    }
    else if (root == currentPtr)
    {
        //Set the root to null
        root = nullptr;
    }

    //Set the current pointer to the null pointer
    currentPtr->leftLink = nullptr;

    //Delete current
    delete currentPtr;
}

//-------------------------------------------------------------------------------------------------
//DeleteNodeWithRightChild - delete the node with a right child
//-------------------------------------------------------------------------------------------------
void treeClassType::DeleteNodeRightChildOnly(nodeptr& currentPtr, nodeptr& parentPtr)
{
    //If the parent is not null
    if (parentPtr != nullptr)
    {
        //Set the parent's right child to the current's right child
        parentPtr->leftLink = currentPtr->rightLink;
    }
    else if (root == currentPtr)
    {
        //Set the root to null
        root = nullptr;
    }

    //Set the current pointer to the null pointer
    currentPtr->rightLink = nullptr;

    //Delete current
    delete currentPtr;
}

//-------------------------------------------------------------------------------------------------
//DeleteNodeWithTwoChildren - delete the node with both children
//-------------------------------------------------------------------------------------------------
void treeClassType::DeleteNodeWithTwoChildren(nodeptr& currentPtr, nodeptr& parentPtr)
{
    //Create a temp pointer
    nodeptr tempPtr;

    //Create a temp swap pointer
    nodeptr tempSwapPtr = new Node;

    //Set the parent to current
    parentPtr = currentPtr;

    //Set tempPtr to the current's left child
    tempPtr = currentPtr->leftLink;

    //While tempPtr is not equal to the null pointer
    while (tempPtr != nullptr)
    {
        //If the tempPtr right child is the null pointer
        if (tempPtr->rightLink != nullptr)
        {
            //Set the parent equal to the tempPtr
            parentPtr = tempPtr;

            //Move the tempPtr to the right
            tempPtr = tempPtr->rightLink;
        }
        else
        {
            //Break the loop if the right link is null
            break;
        }
    }

    //If the parent is the same as current
    if (parentPtr == currentPtr)
    {
        //Set the parent's left child to the tempPtr's left child
        parentPtr->leftLink = tempPtr->leftLink;
    }
    else
    {
        //Set the parent's right child to the tempPtr's left child
        parentPtr->rightLink = tempPtr->leftLink;
    }

    //Swap current and tempPtr
    tempSwapPtr->data = currentPtr->data;
    currentPtr->data = tempPtr->data;
    tempPtr->data = tempSwapPtr->data;

    //Set the tempPtr's left child to the null pointer
    tempPtr->leftLink = nullptr;

    //Delete tempPtr
    delete tempPtr;
}

//-------------------------------------------------------------------------------------------------
//DestoryTree - delete the entire tree by calling the DeleteNode method
//-------------------------------------------------------------------------------------------------
void treeClassType::DestroyTree()
{
    //Create a static integer count
    int count = 0;

    //Create a boolean variable for found
    bool found = false;

    //If this is a letter tree
    if (isAlpha)
    {
        //Output that this set of deletions will be for the letter tree
        cout << "Deletions for the letter tree" << endl;
    }
    else
    {
        //Output that this set of deletions will be for the count tree 
        cout << "Deletions for the count tree" << endl;
    }

    //While the root is not null
    while (!IsEmpty())
    {
        //Increment the count
        count++;

        //Output what node is being deleted
        cout << "Destroy #" << count << endl;
        cout << "Deleted Node - Letter: " << GetRoot()->data.letter << " Count: " << GetRoot()->data.count << endl;

        //Call the delete node method with the left link of the tree
        DeleteNode(GetRoot()->data, found);
    }

    //Print the divider to the console
    PrintDivider('-', 100);
}

//-------------------------------------------------------------------------------------------------
//Print - print the entire tree with 
//-------------------------------------------------------------------------------------------------
void treeClassType::Print(ofstream& fout, string traversalType, string treeType, string taskType)
{
    //Create a temporary node
	nodeptr aNode;

    //Set the node to the root
    aNode = root;

    //Print the output divider to the output file
    PrintDivider(fout, '-', 100);

    //Set the setw to be on the right
    fout << right;

    //Print if this is an alpha tree or not
    fout << setw(3) << "This is the " << treeType << " Tree" << endl;

    //Print the traversal type
    fout << setw(2) << traversalType << " traversal of the tree" << endl;

    //Print the task performed
    fout << "Task Performed:" << taskType << endl;

    //Print the header for the letters and counts
    fout << setw(15) << "Letter" << setw(15) << "Count" << endl;

    //Print the divider to the output file
    PrintDivider(fout, '-', 100);

    //If the traversal type is Inorder
    if (traversalType.compare("Inorder") == 0)
    {
        //Call the Inorder print method
        Inorder(fout, aNode);
    }
    else if (traversalType.compare("Preorder") == 0)
    {
        //Call the Preorder print method
        Preorder(fout, aNode);
    }
    else if (traversalType.compare("Postorder") == 0)
    {
        //Call the Postorder print method
        Postorder(fout, aNode);
    }
    //Output the divider to the output file
    PrintDivider(fout, '-', 100);

    //Print the sum of the counts
    fout << left << setw(27) << "Sum of counts" << SumCounts(aNode) << endl;

    //Output the divider to the output file
    PrintDivider(fout, '-', 100);
}