// Inspired by Ankush Singla @codingNinjas Code.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node * addNode(int data) {
 struct node *head = (struct node *)malloc(sizeof(struct node *));
 head->data = data;
 head->left = NULL;
 head->right = NULL;
 return head;
}

int maximum(int a, int b) {
	return a > b ? a : b;
}

int height(struct node *root) {
	if (!root) {
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	return 1 + maximum(lh,rh);
}

int diameterBinaryTree(struct node *root) {
	if (!root) {
		return 0;
	}

   int option1 = height(root->left) + height(root->right);
   int option2 = diameterBinaryTree(root->left);
   int option3 = diameterBinaryTree(root->right);

   return maximum(option1, maximum(option2, option3));
}

int main() {
	struct node *head, *temp;
	head = addNode(10);
	temp = head;
	temp->left = addNode(20);
	temp->right = addNode(30);
	temp->left->left = addNode(40);
	temp->left->right = addNode(50);
	temp->left->left->left = addNode(60);
	temp->left->left->right = addNode(70);
	temp->left->right->left = addNode(80);
	temp->left->right->right = addNode(90);

	printf("diameter of Binary Tree is = %d",diameterBinaryTree(head));

	getchar();
	return 0;
}