#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
    struct node*next;
};

struct node *top = NULL;
void printArray(int *a, int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}


void push(struct node*value) {
    struct node *newNode;
    newNode = value;// assign value to the node
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; // Make the node as top
    }
    top = newNode; // top always points to the newly created node
}

struct node* pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct node*temp = top;
        top= top->next;
        return temp;
    }
}


void preOrder(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}
void postOrder(struct node * root){
    if(root!= NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }

}
void InOrder(struct node *link){
    struct node* root  =link;
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }

}
struct node* buildTree(struct node * root){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    root = (struct node*)malloc(sizeof(struct node));
    root->data =data;
    if (data == -1)
    {
        return NULL;
    }
    printf("Enter data  for inserting in left of %d\n",data);
    root->left = buildTree(root->left);
    printf("Enter data  for inserting in right of %d\n",data);
    root->right= buildTree(root->right);
    return root;
}
void inorderIterative(struct node*root){
    struct node* currentNode = root;
    while(1)
    {
        while(currentNode!=NULL){
            push(currentNode);
            currentNode = currentNode->left;
        
        }
        if (top==NULL)
        {
            break;
        }
        currentNode = pop();
        printf("%d ", currentNode->data);
        currentNode = currentNode->right;
    }
    
    
}
void preorderIterative(struct node*root){
    struct node * currentNode =root;
    push(currentNode);
    if (root==NULL){
        return ;
    }
    do
    {
        currentNode = pop();
        printf("%d ",currentNode->data);
        if (currentNode->right!=NULL)
        {
            push(currentNode->right);
        }
        
        if (currentNode->left!=NULL)
        {
            push(currentNode->left);
        }
        
    } while (top!=NULL);
    printf("\n");
    
}
void postOrderIterative(struct node * root){
    struct node * currentNode = root;
    int arr[20],count=0;
    push(currentNode);
    while (top!=NULL)
    {
        currentNode = pop();
        arr[count]=currentNode->data;
        if (currentNode->left!=NULL)
        {
        push(currentNode->left);
        }
        if(currentNode->right!=NULL)
            push(currentNode->right);
        count++;
    }
    for (int i = count-1; i >= 0; i--)
    {
        printf("%d ",arr[i]);
    }
    
    
}
int main()
{
    int a,b;
    struct node * root = NULL;
   
    root = buildTree(root);
    do
    {
        
        printf("1.Traversal\n");
        printf("2.Deletion\n");
        printf("3.exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&a);
        if (a==1)
        {
            do
            {
                
                printf("1.Inorder Traversal\n");
                printf("2.preorder Traversal\n");
                printf("3.postorder Traversal\n");
                printf("4.exit\n");
                printf("Enter your choice: \n");
                scanf("%d",&b);
                if (b==1)
                {
                    int c=-1;
                    while (c!=3)
                    {
                        printf("1.Recursive\n");
                        printf("2.Iterative\n");
                        printf("3.exit\n");
                        scanf("%d",&c);
                        if (c==1)
                        {
                            InOrder(root);
                            printf("\n");
                        }
                        if (c==2)
                        {
                           inorderIterative(root);
                           printf("\n");
                        }
                        
                        
                    }
                    
                }
                if (b==2)
                {
                    int c=-1;

                    while (c!=3)
                    {
                        printf("1.Recursive\n");
                        printf("2.Iterative\n");
                        printf("3.exit\n");
                        scanf("%d",&c);
                        if (c==1)
                        {
                            preOrder(root);
                            printf("\n");
                        }
                        if (c==2)
                        {
                           preorderIterative(root);
                           
                        }
                        
                        
                    }
                    
                }
                if (b==3)
                {
                    int c=-1;
                    while (c!=3)
                    {
                        printf("1.Recursive\n");
                        printf("2.Iterative\n");
                        printf("3.exit\n");
                        scanf("%d",&c);
                        if (c==1)
                        {
                            postOrder(root);
                            printf("\n");
                        }
                        if (c==2)
                        {
                            postOrderIterative(root);
                            printf("\n");
                        }
                        
                        
                    }
                    
                }
                
                

            
            } while (b!=4);
            
        }
        if (a==2)
        {

        }
        
        
    } while (a!=3);
    
    return 0;
}