
#include<stdio.h>
#include<malloc.h>

struct node{
int data;
struct node* left;
struct node* right;
};

struct node* createnode(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inorder(struct node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

int isBST(struct node* root){
    static struct node *prev=NULL; //root's parent is NULL
    if(root!= NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node* search_iter(struct node* root,int key){
    while(root!=NULL){

        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else {
            root=root->right;
        }
        }
    return NULL;
}

void Insertion(struct node* root,int key){
    struct node *prev,*ptr;
    prev=NULL;

    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("Can not inset %d, already exists in BST.",key);
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else {
            root=root->right;
        }
        }
    ptr= createnode(key);
    if(key<prev->data){
        prev->left=ptr;
    }
    else{
        prev->right=ptr;
    }
}
struct node* inorderPredecessor(struct node* root){
    root=root->left;
    while(root->right != NULL){
        root=root->right;
    }
    return root;
}

struct node* delete_node(struct node* root,int key){
    struct node* iPre;
    //search for the node to be deleted

    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(key<root->data){
        delete_node(root->left,key);
    }
    else if(key>root->data) {
        root->right = delete_node(root->right,key);
    }
    //deletion strategy(in this point we have got the node)
    else{
        iPre = inorderPredecessor(root);
        root->data = iPre->data;
        root->left = delete_node(root->left,iPre->data);
    }
    return root;
}

int main(){
    struct node *p=createnode(5);
    struct node *p1=createnode(3);
    struct node *p2=createnode(6);
    struct node *p3=createnode(1);
    struct node *p4=createnode(4);

    //tree looks like

    //       5
     //     / \
     //    3   6
     //   / \
      // 1   4

    //linking
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    delete_node(p,3);
    printf("\n");
    inorder(p);
return 0;
}



