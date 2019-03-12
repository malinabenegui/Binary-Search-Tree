#include <iostream>

using namespace std;

struct Arb
{
    int key;
    Arb *left;
    Arb *right;
};

Arb* insertNode(Arb* node, int value)
{
    if (node == NULL)
    {
        node = new Arb;
        node -> left = node -> right = NULL;
        node -> key = value;
        return node;
    }
    if (value < node -> key)
        node -> left = insertNode(node -> left, value);
    else if (value > node -> key)
        node -> right = insertNode(node -> right, value);
    else
        return node;
}

int searchNode(Arb* node, int value)
{
    if (node -> key == value)
        return node -> key;

    if(node == NULL)
        return -1;

    if (value < node -> key)
        return searchNode(node -> left, value);

    return searchNode(node -> right, value);
}

int findMax(Arb* node)
{
    if (node == NULL)
        return -1;

    else
    {
        Arb* current = node;
        while(current -> right != NULL)
            current = current -> right;
        return current -> key;
    }
}

Arb* findMinNode(Arb* node)
{
    if (node == NULL)
        return node;

    else
    {
        Arb* current = node;
        while(current -> left != NULL)
            current = current -> left;
        return current;
    }
}

Arb* deleteNode(Arb* node, int value)
{
    if (node == NULL)
        return NULL;

    if (value < node -> key)
        node -> left = deleteNode(node -> left, value);

    else if (value > node -> key)
        node -> right = deleteNode(node -> right, value);

    else
    {
        if (node -> left == NULL)
        {
            Arb* toReturnNode = node -> right;
            return toReturnNode ;
        }

        else if (node -> right == NULL)
        {
            Arb* toReturnNode = node -> left;
            return toReturnNode;
        }

        Arb* temporaryNode = findMinNode(node -> right);

        node -> key = temporaryNode -> key;

        node -> right = deleteNode(node -> right, temporaryNode -> key);
    }
    return node;
}

void PostOrder(Arb* node)
{
    if (node == NULL)
        return;

    PostOrder(node -> left);
    PostOrder (node -> right);
    cout << node -> key << " ";
}

void InOrder(Arb* node)
{
    if (node == NULL)
        return;

    InOrder(node -> left);
    cout << node -> key << " ";
    InOrder(node -> right);
}

void PreOrder(Arb* node)
{
    if (node == NULL)
        return;

    cout << node -> key << " ";
    PreOrder(node -> left);
    PreOrder(node -> right);
}

int main()
{
    Arb *root = NULL;
    root = insertNode(root, 15);
    root = insertNode(root, 9);
    root = insertNode(root, 20);
    root = insertNode(root, 7);
    root = insertNode(root, 11);
    root = insertNode(root, 18);
    root = insertNode(root, 24);

    PreOrder(root);
    cout << '\n';
    PostOrder(root);
    cout << '\n';
    InOrder(root);
    cout << '\n';

}
