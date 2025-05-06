#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{

    int data;
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;

TreeNode* createNode(int value){

    TreeNode* newNode = malloc(sizeof(TreeNode));   
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

void insertNode(TreeNode** root, int value){

    TreeNode* newNode = createNode(value);

    if(*root == NULL){

        *root = newNode;
        return;
    }

    TreeNode* queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = *root;

    while(front < rear){

        TreeNode* current = queue[front++];

        if(current -> left == NULL){

            current -> left = newNode;
            return;
        }

        else{

            queue[rear++] = current -> left;

        }

        if(current -> right == NULL){

            current -> right = newNode; 
            return;
        }

        else{

            queue[rear++] = current -> left;
        }

    }


}

void insertNode(TreeNode** root, int value){

    TreeNode* newNode = malloc(sizeof(TreeNode));

    if(*root == NULL){

        *root = newNode;
        return;
    }

    TreeNode* queue[100];

    int front = 0;
    int rear = 0;

    //initialize the root into the queue

    queue[rear++] = *root;

    //level-order completeness principle

    while(front < rear){

        TreeNode* current = queue[front++];

        if(current -> left == NULL){

            current -> left = newNode;
            return;
        }

        else{

            queue[rear++] = current -> left;

        }

        if(current -> right == NULL){

            current -> right = newNode;
            return;
        }

        else{

            queue[rear++] = current -> right;

        }

    }

}

//Left -> Root -> Right

void inorderTraversal(TreeNode* root){

    if(root == NULL) return ;

    inorderTraversal(root -> left);
    printf("%d ", root -> data);
    inorderTraversal(root -> right);

}

// Root -> Left -> Right

void preorderTraversal(TreeNode* root){

    if (root == NULL) return;

    printf("%d ", root -> data);
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);

} 

// Left -> Right -> Root

void postorderTraversal(TreeNode* root){

    if(root == NULL) return;

    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    printf("%d ", root -> data);

}


//BST Insertion 

TreeNode* insertBST(TreeNode* root, int value){

    if(root == NULL) return createNode(value);

    if(value < root -> data){

        root -> left = insertBST(root -> left, value);
    }

    else if(value > root -> data){

        root -> right = insertBST(root -> right, value);
    }

    return root;
}

// BST Search

TreeNode* searchBST(TreeNode* root, int key){

    if(root == NULL || root -> data == key) return root;

    if(key < root -> data) return searchBST(root -> left, key);

    else if(key > root -> data) return searchBST(root -> right, key);
}

