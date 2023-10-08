#ifndef BST_H
#define BST_H

struct node
{
    int data;
    char *question;
    char *guess;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root, int data, const char *question, const char *guess);

struct node *create_game_tree();

#endif
