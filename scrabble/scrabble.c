#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_update(string user, int len);

int main(void)
{

    string user1 = get_string("Player 1: ");
    string user2 = get_string("Player 2: ");
    int len1 = strlen(user1);
    int len2 = strlen(user2);
    int count1 = count_update(user1, len1);
    int count2 = count_update(user2, len2);
    if (count1 > count2)
    {
        printf("Player 1 wins!\n");
    }
    else if (count2 > count1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

int count_update(string user, int len)
{

    int count = 0;
    for (int i = 0; i < len; i++)
    {
        user[i] = tolower(user[i]);
        char letter = user[i];

        if (letter == 'b' || letter == 'c' || letter == 'm' || letter == 'p')
        {
            count += 3;
        }
        else if (letter == 'd' || letter == 'g')
        {
            count += 2;
        }
        else if (letter == 'f' || letter == 'h' || letter == 'v' || letter == 'w' || letter == 'y')
        {
            count += 4;
        }
        else if (letter == 'x' || letter == 'j')
        {
            count += 8;
        }
        else if (letter == 'q' || letter == 'z')
        {
            count += 10;
        }
        else if (letter == 'k')
        {
            count += 5;
        }
        else if (ispunct(letter))
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    return count;
}
