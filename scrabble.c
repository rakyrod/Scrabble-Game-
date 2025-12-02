#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int winner(string word);

int main(void)
{
    // user prompt
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // compute scores
    int score1 = winner(word1);
    int score2 = winner(word2);

    // print winner
    if (score1 > score2)
    {
        printf("PLAYER 1 WINS!\n");
    }
    else if (score2 > score1)
    {
        printf("PLAYER 2 WINS!\n");
    }
    else
    {
        printf("ITS A TIE!\n");
    }
}

// compute score function
int winner(string word)
{
    int score = 0;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
