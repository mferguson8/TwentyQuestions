#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct node *insert(struct node *root, int data, const char *question, const char *guess)
{
    if (root == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->question = strdup(question);
        newNode->guess = strdup(guess);
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data, question, guess);
    }
    else
    {
        root->right = insert(root->right, data, question, guess);
    }

    return root;
}

struct node *create_game_tree()
{
    struct node *root = NULL;

    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");

    return root;
}
