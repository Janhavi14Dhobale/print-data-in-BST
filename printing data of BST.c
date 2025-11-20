#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void printInRange(struct Node* root, int L, int R) {
    if (root == NULL)
        return;

    if (L < root->data)
        printInRange(root->left, L, R);

    if (root->data >= L && root->data <= R)
        printf("%d ", root->data);

    if (R > root->data)
        printInRange(root->right, L, R);
}

int main() {
    struct Node* root = NULL;
    int n, val, L, R;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter range L and R: ");
    scanf("%d %d", &L, &R);

    printf("Values in the range [%d, %d]: ", L, R);
    printInRange(root, L, R);

    return 0;
}

