// Author: Chyanne Haugen
//Definition and Declaration of the BSTree class

#pragma once
#include"BinKeyedNode.h"
#include <iostream>
#include <string>
//#define NDEBUG
#include <cassert>

using namespace std;

template <class K, class T>

class BSTree
{
private:
	BinKeyedNode<K, T> *root;

	BinKeyedNode<K, T>* copyHelper(BinKeyedNode<K, T> *root)
	{
		BinKeyedNode<K, T> *temp = nullptr;
		if (root != nullptr)
		{
			temp = new BinKeyedNode<K, T>(root->getKey(), root->getData(), copyHelper(root->getLeftNode()), copyHelper(root->getRightNode()));
		}
		return temp;
	}

	void clearHelper(BinKeyedNode<K, T> *root)
	{
		if (root != nullptr)
		{
			clearHelper(root->getLeftNode());
			clearHelper(root->getRightNode());
			delete root;
		}
	}

	//return pointer to left most node in tree
	BinKeyedNode<K, T>* gettingMinNode(BinKeyedNode<K, T> *root)
	{
		assert(root != nullptr);

		BinKeyedNode<K, T> *temp = nullptr;

		if (root->getLeftNode() == nullptr)
		{
			temp = root;
		}
		else
		{
			temp = gettingMinNode(root->getLeftNode());
		}

		return temp;
	}

	//Removes left most node in tree and returns pointer to that new sub tree
	BinKeyedNode<K, T>* deleteMinNode(BinKeyedNode<K, T> *root)
	{
		assert(root != nullptr);

		BinKeyedNode<K, T> *temp = root;

		if (root->getLeftNode() == nullptr)
		{
			temp = root->getRightNode();
		}
		else
		{
			root->setLeftNode(deleteMinNode(root->getLeftNode()));
		}

		return temp;
	}

	//helper method to insert nodes using recursion
	BinKeyedNode<K, T>* insertNode(BinKeyedNode<K, T>* nodePtr, const K &newKey, const T &newData)
	{
		if (nodePtr == nullptr)
		{
			try
			{
				nodePtr = new BinKeyedNode<K, T>(newKey, newData, nullptr, nullptr); //setting root to the new data
			}
			catch (exception &e)
			{
				e; //stops compiler warnings
			}
		}
		else if (newKey < nodePtr->getKey())
		{
			nodePtr->setLeftNode(insertNode(nodePtr->getLeftNode(), newKey, newData));
		}
		else
		{
			nodePtr->setRightNode(insertNode(nodePtr->getRightNode(), newKey, newData));
		}

		return nodePtr;
	}

	//helper method to find node using recursion with a key
	BinKeyedNode<K, T>* findNode(BinKeyedNode<K, T> *nodePtr, const K &searchKey, int &numComparisons)
	{
		if (nodePtr != nullptr) //if there is a tree to check 
		{
			cout << "Comparing " << searchKey << " with " << nodePtr->getKey() << endl;

			if (searchKey == nodePtr->getKey()) 
			{
				numComparisons++;
			}
			else if (searchKey < nodePtr->getKey())
			{
				nodePtr = findNode(nodePtr->getLeftNode(), searchKey, numComparisons);
				numComparisons++;
			}
			else
			{
				nodePtr = findNode(nodePtr->getRightNode(), searchKey, numComparisons);
				numComparisons++;
			}
		}
		return nodePtr;
	}

	//helper method to remove a node using recursion with a key
	BinKeyedNode<K, T>* removeNode(BinKeyedNode<K, T> *nodePtr, const K &searchKey)
	{
		if (nodePtr != nullptr)
		{
			if (searchKey < nodePtr->getKey())
			{
				nodePtr->setLeftNode(removeNode(nodePtr->getLeftNode(), searchKey));
			}
			else if (searchKey > nodePtr->getKey())
			{
				nodePtr->setRightNode(removeNode(nodePtr->getRightNode(), searchKey));
			}
			else //found it!
			{
				BinKeyedNode<K, T> *temp = nodePtr;

				if (nodePtr->getLeftNode() == nullptr) //only a right child 
				{
					nodePtr = nodePtr->getRightNode(); //point to right 
					delete temp; //removing node
				}
				else if (nodePtr->getRightNode() == nullptr) // only a left child
				{
					nodePtr = nodePtr->getLeftNode(); //point to left 
					delete temp; //removing node
				}
				else //must have two children
				{
					BinKeyedNode<K, T> *temp = gettingMinNode(nodePtr->getRightNode()); //having temp point to smallest node on right side of subtree

					//swaping data
					nodePtr->setData(temp->getData());
					nodePtr->setKey(temp->getKey());

					//deleting the smallest node in right subtree and will return new subtree for right child to point to
					nodePtr->setRightNode(deleteMinNode(nodePtr->getRightNode()));
					delete temp;
				}
			}
		}

		return nodePtr;
	}

public:

	BSTree()
	{
		root = nullptr;
	}

	//copy constructor
	BSTree(const BSTree<K, T>& fromTree)
	{
		root = copyHelper(fromTree.root); //deep copy
	}


	BinKeyedNode<K, T>* getRootNode() const
	{
		return root;
	}

	void setRootNode(BinKeyedNode<K, T>* newRoot)
	{
		root = newRoot;
	}

	bool isEmpty() const
	{
		return (root == nullptr);
	}

	//inserts a node by calling a helper method
	void insert(const K &newKey, const T &newData)
	{
		root = insertNode(root, newKey, newData);
	}

	//finds a node by calling a helper method
	bool find(const K &searchKey)
	{
		assert(root != nullptr);

		int numComparisons = 0;
		bool foundNode = false;

		BinKeyedNode<K, T> *temp = findNode(root, searchKey, numComparisons);

		if (temp != nullptr) //if temp does not equal null then node must of been found
		{
			cout << searchKey << " Was found in the database." << endl;
			foundNode = true;
		}
		else
		{
			cout << searchKey << " Was not found in the database." << endl;
		}
		cout << "Number of comparisons made: " << numComparisons << endl;

		return foundNode;
	}

	//calls helper function that will remove node if found
	void remove(const K &searchKey)
	{
		assert(root != nullptr);
		int numRemoveComparisons = 0;

		BinKeyedNode<K, T> *temp = findNode(root, searchKey, numRemoveComparisons);

		if (temp != nullptr) //if found we should be able to remove it
		{
			root = removeNode(root, searchKey);
			cout << searchKey << " Was removed from the database." << endl;
		}
		else
		{
			cout << searchKey << " Was not removed from the database. (could not be found)" << endl;
		}
		cout << "Number of comparisons made: " << numRemoveComparisons << endl;

	}

	void printInOrder(ostream& outStream, BinKeyedNode<K, T> *root) const
	{
		if (root != nullptr)
		{
			printInOrder(outStream, root->getLeftNode());
			outStream << *root;
			printInOrder(outStream, root->getRightNode());
		}
	}

	//assigning one tree to another 
	BSTree& operator=(const BSTree &fromTree)
	{
		if (this != &fromTree) //check to make sure trees aren't already the same
		{
			clearHelper(root); //removing elements in receiving tree

			if (!fromTree.isEmpty()) //adding element from the from tree to the receiving tree
			{
				this->root = copyHelper(fromTree.getRootNode());
			}
		}
		return *this;
	}

	//function that overloads << method with cout
	friend ostream& operator <<(ostream& outStream, const BSTree& tree)
	{
		tree.printInOrder(outStream, tree.getRootNode()); //calls method that will print nodes
		return(outStream);
	}

	~BSTree()
	{
		clearHelper(root);
	}
};