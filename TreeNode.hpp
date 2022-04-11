/*
 * author: Ryan Zimmerman
 * course: CPSC 2108 - Data Structures - Spring 2021
 * instructor: Dr. Alfredo Perez
 * campus: Columbus State University - TSYS School of Computer Science

This header is based on the provided CSU TreeNode.java file for Project 4. Dr. Perez has allowed me to complete the project in C++ for personal growth, much to my appreciation. The method definitons are included in this .hpp file as is protocol for generic templates in C++. Many of the methods used are based on studied resources including cppreference.com, geeksforgeeks.com, Cracking the Coding Interview by Gayle MCDowell, and the Fifth Edition of the C++ Primer by Lippman, Lajoie, and Moo.
*/


#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include <list>
#include <iostream>
#include <queue>

template <typename T>
class TreeNode {

	private:
		TreeNode<T> *left_child, *right_child, *parent;
		T data;
		int level;	
	public:
		TreeNode(){ }
		TreeNode(T data){ 
			this->data = data;
			this->left_child = this->right_child = nullptr;
		}

		TreeNode(TreeNode* parent, T data) {
			this->data = new T(data);
			this->parent = parent;
		}

		TreeNode(TreeNode* left, TreeNode* right, T data){
			this->left_child = left;
		       	this->right_child = right;
			this->data = data;
		}

		~TreeNode() { 
			delete parent;
			delete left_child;
			delete right_child;
		}
		TreeNode* getRightChild() { return this->right_child; }

		TreeNode* getLeftChild() { return this->left_child; }

		inline bool isDataEqual(T data){ return 0 == getData()(data);	}

		inline void setData(T data) { this->data = data; }

		inline T getData() { return this->data; }

		inline void setParent(TreeNode<T>* node) { this->parent = node; }

		inline void setLevel(int level) { this->level = level; 	}

		inline int getLevel() { return this->level; }

		TreeNode* findNodeOnTree(T dataToFind) {
			std::vector<TreeNode*> nodes = std::list<TreeNode*>();
			nodes.clear();
			nodes.push_back(this);

			while(!nodes.empty()) {
				TreeNode* current = nodes.erase(nodes.begin());
				if (current->isDataEqual(dataToFind)) {
					return current;
				}

				if (current->left_child != nullptr){
					nodes.push_back(current->left_child);
				}

				if (current->right_child != nullptr) {
					nodes.push_back(current->right_child);
				}
			}
			return nullptr;
		}
	
		void createTree(TreeNode* node, int i, std::vector<T>& arr){
			if(node!=nullptr){
				if(2*i+1<arr.size()){
					node->left_child = new TreeNode(arr[2*i+1]);
					createTree(node->left_child,2*i+1,arr);
				}
				if(2+i+2<arr.size()){
			  		node->right_child = new TreeNode(arr[2*i+2]);
					createTree(node->right_child,2*i+2,arr);
				}
			}
		}

		TreeNode* levelOrderTree(std::vector<T>& arr){
			if(arr.size() == 0){
				return nullptr;
			}
			TreeNode* root = new TreeNode((arr[0]));
			createTree(root,0,arr);
			return root;
		}

		static void inOrder(TreeNode* root){
			if(root==nullptr){
				return;
			}
			inOrder(root->left_child);
			std::cout << root->data << " ";
			inOrder(root->right_child);
		}

		static void levelOrder(TreeNode* root){
			if(root==nullptr){
				return;
			}
			std::queue<TreeNode<T>*> treeQueue;

			treeQueue.push(root);

			while(!treeQueue.empty()){
				TreeNode* node = treeQueue.front();
				std::cout << node->data << " ";
				treeQueue.pop();
				
				if(node->left_child != nullptr){
					treeQueue.push(node->left_child);
				}if(node->right_child != nullptr){
					treeQueue.push(node->right_child);
				}
			}
		}

		TreeNode* leastCommonAncestor(TreeNode* root, T inputA, T inputB){
			if(root==nullptr){
				return root;
			}
			if(root->data == inputA || root->data == inputB){
				return root;
			}

			TreeNode* left_lca = leastCommonAncestor(root->left_child, inputA, inputB);
			TreeNode* right_lca = leastCommonAncestor(root->right_child, inputA, inputB);
			if(left_lca && right_lca) { return root; };

			return (left_lca != nullptr)? left_lca : right_lca;
		}
};
#endif
