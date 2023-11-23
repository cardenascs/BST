#include<stdlib.h>
#include<stdio.h>

void loop();
int *valor;


struct node{
    int key;
    struct node *left, *right;
};

struct node* newNode(int item){
    struct node* temp
    = (struct node*)malloc(
        sizeof(struct node));
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
}

struct node* insert(struct node* node, int key){
    if (node==NULL){
        return newNode(key);
    }
    if(key < node->key){
        node->left = insert(node->left, key);
    }
    else if(key > node->key){
        node->right = insert(node->right, key);
    }

    return node;
}

void Inorden(struct node* root){
    if(root!=NULL){
        Inorden(root->left);
        printf("Node %d\n", root->key);
        if(root->left !=NULL){
            printf("  Child Left %d\n", root->left->key);
        }
        if(root->right != NULL){
            printf("  Right Child %d\n", root->right->key);
        }
        Inorden(root->right);
    }
}

void displayRight(struct node *root){
    printf(" Right %d", root->key);
}

void displayLeft(struct node *root){
    printf(" Left %d", root->key);
}

void displayNode(struct node *node){
    printf("Nodo %d", node->key);
    if(node->left != NULL){
        displayLeft(node->left);
    }
    if(node->right != NULL){
        displayRight(node->right);
    }
    printf("\n");
}

void Search(struct node *node, int val){
    if(val==node->key){
        displayNode(node);
    }
    else{
        if(val < node->left){
            Search(node->left, val);
        }
        else{
            Search(node->right, val);
        }
    }
}

struct node *prev = NULL;

int isBST(struct node* root){
	if(root){
		if(!isBST(root->left)){
			return 0;
		}
		if(prev != NULL && root->key <= prev->key){
			return 0;
		}
		prev = root;
		return isBST(root->right);
	}
	return 1;
}

//char *op;
//struct node* root = NULL;

int main(){
	
	struct node *root = newNode(50);
	root->left = newNode(20);
    root->right = newNode(60);
    root->left->left = newNode(10);
    root->left->right = newNode(30);
    root->right->right = newNode(80);
    
    if(isBST(root)){
    	printf("En efecto es un BST");
	}
	else{
		printf("No es BST");
	}
    
    printf("\n");
    prev = NULL;
    
    struct node *root1 = newNode(50);
    root1->left = newNode(20);
    root1->right = newNode(30);
    root1->left->left = newNode(70);
    root1->left->right = newNode(80);
    root1->left->left->right = newNode(40);
    root1->left->left->left = newNode(90);
    
	if(isBST(root1)){
		printf("En efecto es un BST");
	}
	else{
		printf("No es BST\n");
	}

//    printf("Ingresa el nodo raiz\n");
//    scanf("%i", &valor);
//    root = insert(root, valor);
//    printf("Agregar nodo? S/N\n");
//    scanf("%s", &op);
//    op = toupper(op);
//    if(op == 'S'){
//        loop();
//    }
//    system("clear");
//    Inorden(root);
//
//    printf("\n \n \n");
//    Search(root, 50);

    return 0;
}

//void loop(){
//    printf("Ingresa el nodo\n");
//    scanf("%i", &valor);
//    insert(root, valor);
//    printf("Agregar otro nodo?\n");
//    scanf("%s", &op);
//    op = toupper(op);
//    if(op=='S'){
//        loop();
//    }
//    else{
//        printf("Bye\n");
//    }
//}

