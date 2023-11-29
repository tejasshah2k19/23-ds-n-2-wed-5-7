#include<stdio.h>
#include<stdlib.h>

struct node{
    int data; 
    struct node *left,*right;
    int height; 
    int bf; 
}*root=NULL;


int calculateHeight(struct node *root){//100 
    int lh = 0 ;
    int rh = 0 ; 

    if(root->left == NULL){
        lh =0;
    }else{
        lh = root->left->height; 
    }

    if(root->right == NULL){
        rh =0;
    }else{
        rh = root->right->height; 
    }
    return lh>rh?lh:rh; 
}



struct node* leftRotate(struct node *root){
    struct node *rootRight = root->right; 
    struct node *rootRightLeft  = rootRight->left;  
    
    root->right = rootRightLeft;
    rootRight -> left = root; 


    root->height = 1 + calculateHeight(root);
    rootRight->height = 1 + calculateHeight(rootRight);
    return rootRight; 
}

struct node* rightRotate(struct node *root){

    struct node *rootLeft = root->left; 
    struct node *rootLeftRight = rootLeft->right; 

    root->left = rootLeftRight;
    rootLeft->right = root; 


    root->height = 1 + calculateHeight(root);
    rootLeft->height = 1 + calculateHeight(rootLeft); 
    return rootLeft;  

}



int calculateBF(struct node *root){//100 
    int lh = 0 ;
    int rh = 0 ; 

    if(root->left == NULL){
        lh =0;
    }else{
        lh = root->left->height; 
    }

    if(root->right == NULL){
        rh =0;
    }else{
        rh = root->right->height; 
    }
    return lh-rh; 
}
    
void inOrder(struct node *root)
{
    if(root != NULL){ 
        inOrder(root->left);
        printf(" |%d{%d}| ",root->data,root->height);
        inOrder(root->right); 
    }
}

struct node* addNode(struct node *root,int data){
    int bf; 
    if(root == NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root->data  = data; 
        root->height=1; 
        root->bf=0; 
        root->left = NULL;
        root->right = NULL;
        return root;
    }else{

        if(data < root->data){
            //left 
            root->left = addNode(root->left,data); 
        }else{
            //right 
            root->right = addNode(root->right,data);
        }

        //height calculate 
        root->height = 1 + calculateHeight(root);        

        root->bf =  calculateBF(root); 

        if(root->bf < -1){
             if(root->right->data > data ){
                 printf("\nRight Left Imbalance => %d\n",root->data);
                 //right {root->right}
                 root->right = rightRotate(root->right);
                 //left  {root}
                 return leftRotate(root); 
            }else{
                 printf("\nRight Right Imbalance => %d\n",root->data);
                return leftRotate(root);//rootRight 
            }
        
        }
        if(root->bf > 1 ){
             if(root->left->data > data ){ 
                printf("\nLeft Left Imbalance => %d\n",root->data);
                //right -> root  
                return rightRotate(root); 
             }else{
                 printf("\nLeft Right Imbalance => %d\n",root->data);
                //left  {root->left}
                root->left = leftRotate(root->left);
                //right {root}
                return rightRotate(root);
             }

        }

     

        return root; 
    }
}

int main(){

    //root = addNode(root,600);//2 
    //root = addNode(root,400);//1
    //root = addNode(root,350); //1
 root=addNode(root,100);
 root=addNode(root,2);
 root=addNode(root,9);
 root=addNode(root,55); 
 root=addNode(root,66); 
 root=addNode(root,54);
 root=addNode(root, 23);
 root=addNode(root, 40);
 root=addNode(root, 20);
 root=addNode(root, 10); 


// printf("\n %d %d %d",root->data,root->right->data,root->right->right->data);
    inOrder(root);
     printf("\nEND");
     return 0;
}
