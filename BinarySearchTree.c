#include <stdio.h>
#include <stdlib.h>

char a=' ';

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int val)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
        root = create(val);
    else if (root->data > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void inorder(struct node *root,int indent)
{
    if (root == NULL)
        return;
    inorder(root->left,indent+4);
    if(indent){
        for(int i=0;i<indent;i++){
            printf("%c",a);
        }
    }
    printf("%d \n", root->data);
    inorder(root->right,indent+4);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void binarySearch(struct node *root,int key){
    if(root==NULL){
        printf("Not found\n");
        return;
    }
    if(root->data==key){
        printf("Found\n");
        return;
    }
    else if(root->data<key)
        binarySearch(root->right,key);
    else
        binarySearch(root->left,key);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 45);
    root = insert(root, 15);
    root = insert(root, 79);
    root = insert(root, 90);
    root = insert(root, 10);
    root = insert(root, 55);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 50);

    printf("Inorder: \n");
    inorder(root,0);
    // printf("Preorder: ");
    // preorder(root);
    // printf("Postorder: ");
    // postorder(root);
    binarySearch(root,13);
    return 0;
}