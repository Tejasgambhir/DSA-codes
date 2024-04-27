#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};


struct Stack {
	int size;
	int top;
	struct Node** array;
};


struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

struct Stack* createStack(int size)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (struct Node**)malloc(
		stack->size * sizeof(struct Node*));
	return stack;
}


int isFull(struct Stack* stack)
{
	return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, struct node* node)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = node;
}

struct node* pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return NULL;
	return stack->array[stack->top--];
}

struct node* peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return NULL;
	return stack->array[stack->top];
}

void postOrderIterative(struct node* root)
{
	if (root == NULL)
		return;

	struct Stack* stack = createStack(50);
	do {
		while (root) {

			if (root->right)
				push(stack, root->right);
			push(stack, root);

			
			root = root->left;
		}

		
		root = pop(stack);

		
		if (root->right && peek(stack) == root->right) {
			pop(stack); 
			push(stack, root); 
			root = root->right; 
		}
		else 
		{
			printf("%d ", root->data);
			root = NULL;
		}
	} while (!isEmpty(stack));
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
void InOrder(struct node * root){
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
int main()
{
    int a,b,c=1;;
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
                    while (c!=3)
                    {
                        printf("1.Recursive");
                        printf("2.Iterative");
                        scanf("%d",&c);
                        if (c==1)
                        {
                            InOrder(root);
                        }
                        if (c==2)
                        {
                           
                        }
                        
                        
                    }
                    
                }
                if (b==2)
                {
                    while (c!=3)
                    {
                        printf("1.Recursive");
                        printf("2.Iterative");
                        scanf("%d",&c);
                        if (c==1)
                        {
                            preOrder(root);
                        }
                        if (c==2)
                        {
                           
                        }
                        
                        
                    }
                    
                }
                if (b==3)
                {
                    while (c!=3)
                    {
                        printf("1.Recursive");
                        printf("2.Iterative");
                        scanf("%d",&c);
                        if (c==1)
                        {
                            postOrder(root);
                        }
                        if (c==2)
                        {
                           postOrderIterative(root);
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