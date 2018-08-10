#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *addNode(int data) {
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data = data;
	head->left = NULL;
	head->right = NULL;
	return head;
}

struct node * convertBinaryTreeToDLL(struct node *temp) {
	if (temp->left) {
		struct node *lTree = convertBinaryTreeToDLL(temp->left);
		for (; lTree->right; lTree = lTree->right);
		lTree->right = temp;
		temp->left = lTree;
	}
	if (temp->right) {
		struct node *rTree = convertBinaryTreeToDLL(temp->right);
		for (; rTree->left; rTree = rTree->left);
		rTree->left = temp;
		temp->right = rTree;
	}
	return temp;
}

void print(struct node *temp) {
	while (temp->right != NULL) {
		printf("%d ",temp->data);
		temp = temp->left;
	}
}

int main() {
	struct node *head, *temp;
	head = addNode(10);
	temp = head;
	temp->left = addNode(20);
	temp->right = addNode(30);
	temp->left->left = addNode(40);
	temp->left->right = addNode(50);
	temp->right->left = addNode(60);
	temp->right->right = addNode(70);

    struct node *temp1 = convertBinaryTreeToDLL(head);
	print(temp1);
	getchar();
	return 0;
}