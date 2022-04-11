/*
 * author: Ryan Zimmerman
 * course: CPSC 2108 - Data Structures - Spring 2021
 * instructor: Dr. Alfredo Perez
 * campus: Columbus State University - TSYS School of Computer Science
*/


#include "InputCollection.hpp"
#include "TreeNode.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {

	char alphabetArray[26];	
	char input1, input2;
	InputCollection collector;

	for(int i=0;i<26;i++){
		alphabetArray[i] = (char)(i+65);//this is such a cool method for filling the array 
	}

	std::vector<char> alphabet(alphabetArray, alphabetArray+sizeof(alphabetArray));

	TreeNode<char>* tree;
	
	std::cout << "Level order Tree (BFS):" << std::endl << std::endl;

      	tree = tree->TreeNode<char>::levelOrderTree(alphabet);

	TreeNode<char>::levelOrder(tree);
	std::cout << std::endl << std::endl;

	input1 = collector.InputCollection::UserInput();
	input2 = collector.InputCollection::UserInput();

	std::cout << std::endl;
	TreeNode<char>* LCA;
	LCA = LCA->TreeNode<char>::leastCommonAncestor(tree,input1,input2);
	
	std::cout << "The least common ancestor is: " << LCA->getData() << std::endl;

	return 0;
}
