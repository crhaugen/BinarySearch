// Author: Chyanne Haugen
//Definition and Declaration of the BinKeyedNode class
#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class K, class T>

class BinKeyedNode
{
private:

	K key;
	T data;
	BinKeyedNode *left;
	BinKeyedNode *right;

public:
	BinKeyedNode()
	{
		left = nullptr;
		right = nullptr;
	}

	BinKeyedNode(K newKey, T newData, BinKeyedNode *newLeft, BinKeyedNode *newRight) : key(newKey), data(newData), left(newLeft), right(newRight)
	{
		
	}

	//accessors
	T getData() const
	{
		return data;
	}

	K getKey() const
	{
		return key;
	}

	BinKeyedNode *getLeftNode() const
	{
		return left;
	}

	BinKeyedNode *getRightNode() const
	{
		return right;
	}

	//mutators
	void setData(const T newData)
	{
		data = newData;
	}

	void setKey(const K newKey)
	{
		key = newKey;
	}

	void setLeftNode(BinKeyedNode* newLeft)
	{
		left = newLeft;
	}

	void setRightNode(BinKeyedNode* newRight)
	{
		right = newRight;
	}

	//function that overloads << method with cout
	friend ostream& operator <<(ostream& outStream, const BinKeyedNode& node)
	{
		outStream << node.data;
		return outStream;
	}

};