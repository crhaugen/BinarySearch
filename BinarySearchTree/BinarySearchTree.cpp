// BinarySearchTreeHaugen.cpp : Defines the entry point for the console application.
//Author: Chyanne Haugen
//Description: Program uses a binary search tree to store Tom Hanks movie role in a database that then allows the movie titles to be found, removed, and added.

#include "stdafx.h" 
#include <iostream>
#include <fstream>
#include <string>
#include "TomHanksMovieRoles.h"
#include "BSTree.h"

using namespace std;

int main()
{
	string fileName = "TomHanksMovieRoles.txt";
	string title = "Splash";
	string title2 = "Toy Story 99";
	string title3 = "Big";

	TomHanksMovieRoles tomHanksRole;
	BSTree<string, TomHanksMovieRoles> tree;


	ifstream infile;

	infile.open(fileName);

	assert(!infile.fail());

	while (!infile.eof()) //reading data from file to the tree as tomHanksMoiveRoles objects
	{
		infile >> tomHanksRole;
		if (!infile.eof())
		{
			tree.insert(tomHanksRole.getMovieTitle(), tomHanksRole);
		}

	}

	/*
	  Code below test the find, print and remove functions of the binary search tree.
	*/

	//cout << tree; //should print tree in sorted order
	//BSTree<string, TomHanksMovieRoles> tree2(tree); //copying tree one to tree two
	//cout << "*****DOING DEEP COPY TREE TWO SHOULD LOOK THE SAME.********" << endl;
	//cout << tree2; //should be same as tree one
	//tree2.remove("Toy Story 4"); //removing a title
	//cout << "*****TOY STORY 4 SHOULD NOT BE FOUND.********" << endl;
	//tree2.find("Toy Story 4"); //should not be found
	//cout << "*****TOY STORY 4 SHOULD BE FOUND.********" << endl;
	//tree.find("Toy Story 4"); //still should be found

	//string title4 = "A Hologram for the King"; //testing end of tree, this is the left most node
	//tree.find(title4); //should be found
	//tree.remove(title4); //should be found and removed
	//tree.find(title4); //should not be found

	//string title5 = "He Knows You're Alone"; //testing root tree this is the root node
	//tree.find(title5); //should be found
	//tree.remove(title5); //should be found and removed
	//tree.find(title5); //should not be found

	//string title7 = "Bachelor Party"; //testing node that is some what in the middle of the tree
	//tree.find(title7); //should be found
	//tree.remove(title7); //should be found and removed
	//tree.find(title7); //should not be found

	//string title6 = "Cast Away"; //testing node that is some what in the middle of the tree
	//tree.find(title6); //should be found
	//tree.remove(title6); //should be found and removed
	//tree.find(title6); //should not be found


	cout << tree << endl;

	cout << "Looking for " << title << "...." << endl;
	tree.find(title);
	cout << endl;

	cout << "Looing for " << title2 << "...." << endl;
	tree.find(title2);
	cout << endl;

	cout << "Trying to delete " << title3 << "...." << endl;
	tree.remove(title3);
	cout << endl;

	cout << "Trying to delete " << title2 << "...." << endl;
	tree.remove(title2);

	system("pause");
}
