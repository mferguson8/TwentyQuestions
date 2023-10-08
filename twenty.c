#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

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
