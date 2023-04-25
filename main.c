#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode {
	int val;

	struct TreeNode *left;
	struct TreeNode *right;
} treenode;

treenode *create_treenode(int val){
	treenode* result = malloc(sizeof(treenode));
	if(result != NULL){
		result->left = NULL;
		result->right = NULL;
		result->val=val;
	}

	return result;
}

void printTabs(int numTabs){
	for(int i=0; i<numTabs; i++){
		printf("\t");
	}
}

void print_treenode_rec(treenode *root, int level){
	if(root == NULL){
		printTabs(level);
		printf("---<empty>---\n");
		return;
	}

	printTabs(level);
	printf("value = %d\n", root->val);

	printTabs(level);
	printf("left\n");
	print_treenode_rec(root->left, level+1);
	printTabs(level);

	printf("right\n");
	print_treenode_rec(root->right, level+1);
	printTabs(level);
	printf("done\n");
}

void print_treenode(treenode *root){
	print_treenode_rec(root, 0);
}

bool insertNumber(treenode **rootPtr, int val){
	treenode* root = *rootPtr;
	if(root == NULL){
		// empty tree
		(*rootPtr) = create_treenode(val);
		return true;
	}

	if(val == root->val){
		// do nothing
		return false;
	}

	if(val < root->val){
		return insertNumber(&(root->left), val);
	}else{
		return insertNumber(&(root->right), val);
	}
}

bool findNode(treenode *root, int val){
	if(root == NULL) return false;

	if(root->val == val){
		return true;
	}

	if(val < root->val){
		return findNode(root->left, val);
	}else{
		return findNode(root->right, val);
	}
}

int main(){
	treenode *root = NULL;

	insertNumber(&root, 9);
	insertNumber(&root, 5);
	insertNumber(&root, 15);
	insertNumber(&root, 10);
	insertNumber(&root, 21);
	insertNumber(&root, 25);
	insertNumber(&root, 18);
	insertNumber(&root, 11);
	insertNumber(&root, 19);
	insertNumber(&root, 17);
	insertNumber(&root, 1);
	insertNumber(&root, 2);
	insertNumber(&root, 28);
	insertNumber(&root, 30);

	// print_treenode(root);

	printf("%d (%d)\n", 15, findNode(root, 15));
	printf("%d (%d)\n", 10, findNode(root, 10));
	printf("%d (%d)\n", 1, findNode(root, 1));
	printf("%d (%d)\n", 3, findNode(root, 3));
	printf("%d (%d)\n", 29, findNode(root, 29));

	return 0;
}