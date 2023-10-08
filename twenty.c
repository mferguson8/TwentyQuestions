#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    char *question;
    char *guess;
    struct node *left;
    struct node *right;
};

// Function to insert a new node into the binary tree
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

void play_game(struct node *root)
{
    char input;
    printf("You think of a fruit or vegetable, and I will try to guess it!\n");

    while (1)
    {
        if (root->question[0] == '\0')
        {
            printf("Is it %s?\n", root->guess);
            printf("y/n: ");
            scanf(" %c", &input);

            if (input == 'y')
            {
                printf("I win!\n");
            }
            else
            {
                printf("I give up. What's your answer? ");
                char userGuess[100];
                scanf(" %[^\n]", userGuess);
                printf("Please enter a question to distinguish %s from %s: ", userGuess, root->guess);
                char newQuestion[100];
                scanf(" %[^\n]", newQuestion);

                root->question = strdup(newQuestion);
                root->left = insert(root->left, 0, "", userGuess);
                root->right = insert(root->right, 0, "", root->guess);
                printf("Thanks for teaching me!\n");
            }

            printf("Play again? (q to quit, any other key to continue): ");
            scanf(" %c", &input);
            if (input == 'q')
            {
                break;
            }
            else
            {
                root = create_game_tree();
                printf("You think of a fruit or vegetable, and I will try to guess it!\n");
            }
        }
        else
        {
            printf("%s\n", root->question);
            printf("y/n: ");
            scanf(" %c", &input);

            if (input == 'y')
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }
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

int main()
{
    struct node *game_tree = create_game_tree();
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char c, game_over = 0;

    while (1)
    {
        scanf(" %c", &c);
        if (c == 'q')
        {
            break;
        }
        else
        {
            play_game(game_tree);
            printf("Press 'q' to quit or any other key to continue:\n");
        }
    }

    printf("Bye Bye!\n");
    return 0;
}
