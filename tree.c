#include <stdio.h>
#include <stdlib.h>

struct abc{
	int data;
	struct abc *left,*right;
};

struct abc *create(int d){
	struct abc *temp=(struct abc*)malloc(sizeof(struct abc));
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder(struct abc *p){
	if(p==NULL)
		return;
	inorder(p->left);
	printf("%d ",p->data);
	inorder(p->right);
}

void preorder(struct abc *p){
	if(p==NULL)
		return;
	printf("%d ",p->data);
	preorder(p->left);
	preorder(p->right);
}

void postorder(struct abc *p){
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf("%d ",p->data);
}

int main(){
	struct abc *root;
	root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	printf("Inorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\n");
}
