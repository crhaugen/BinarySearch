#include "stdafx.h"
#include "CppUnitTest.h"
#include "TomHanksMovieRoles.h"
#include "../BinarySearchTree/BSTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestForBinaryTreeProject
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		
		TEST_METHOD(TestMethod1)
		{
			BSTree<string, TomHanksMovieRoles> tree;
		}

	};
}