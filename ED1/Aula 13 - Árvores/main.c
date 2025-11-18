#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max_int(int a, int b)
{
    return (a > b) ? a : b;
}

typedef int T;

typedef enum Side
{
    LEFT,
    RIGHT
} Side;

typedef struct Node
{
    T value;
    Node* left;
    Node* right;
} Node;


Node* NewNode(T value)
{
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->left = NULL;
    novo->right = NULL;
    novo->value = value;
    return novo;
}

Node* NewRoot(Node** root, T value)
{
    *root = NewNode(value);
}

Node* Search(Node* root, T value)
{
    if (root == NULL) return NULL;
    if (root->value == value) return root;

    Node* aux = Search(root->right, value);
    if (aux) return aux;

    return Search(root->left, value);
}

Node* SearchWithPath(Node* root, T value)
{
    if (root == NULL) return NULL;
    if (root->value == value) return root;

    printf("Visitado: %d\n", root->value);

    Node* aux = SearchWithPath(root->right, value);
    if (aux) return aux;

    return SearchWithPath(root->left, value);
}

void SearchPath(Node* root, T value)
{
    printf("Buscando por %d\n", value);

    Node* res = SearchWithPath(root, value);

    if (res) printf("Encontrado.\n");
    else printf("Não encontrado.\n");
}

bool InsertNode(Node* raiz, T value, T parentValue, Side side)
{
    Node* copy = raiz;
    Node* parentNode = Search(raiz, parentValue);
    
    if (parentNode == NULL) return false;

    Node* novo = NewNode(value);

    if (side == LEFT)
    {
        parentNode->left = novo;
    }
    else
    {   
        parentNode->right = novo;
    }

    raiz = copy;
    return true;
}

void CountNodes(Node* root, int *count)
{
    if (root == NULL) return;

    *count++;

    CountNodes(root->left, count);
    CountNodes(root->right, count);
}

int CountNodes(Node* root)
{
    int count = 0;

    CountSearch(root, &count);

    return count;
}

bool IsLeaf(Node* node)
{
    if (node->left == NULL && node->right == NULL)
    {
        return true;
    }
    return false;
}

void HeightSearch(Node* root, int *count, int *max)
{
    if (root == NULL) return 

    *count++;
    HeightSearch(root->right, count, max);
    *count--;
    HeightSearch(root->left, count, max);

    *max = max_int(*max, *count);
}

int Heigth(Node* root)
{
    int count = 0;
    int max = count;

    HeightSearch(root, &count, &max);

    return max;
}

void DestroyTree(Node* root)
{
    if (root == NULL) return;

    Node* left = root->left;
    Node* right = root->right;

    free(root);

    DestroyTree(left);
    DestroyTree(right);
}

int main()
{
    Node *root;
    NewRoot(&root, 40);

    InsertNode(root, 20, 40, LEFT);
    InsertNode(root, 60, 40, RIGHT);
    InsertNode(root, 10, 20, LEFT);
    InsertNode(root, 30, 20, RIGHT);

    SearchPath(root, 10);
}