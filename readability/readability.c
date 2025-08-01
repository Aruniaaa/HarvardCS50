#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    int size = strlen(text);
    int words = 0, lines = 0, letters = 0;
    int avg = 0;
    for(int i = 0; i < size; i++){

        if(text[i] ==  ' ')
        {
            words++;
        } else if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            lines++;
        } else
        {
            letters++;
        }


    }

    words++;
   float L = (float)letters / words * 100;
   float S = (float)lines / words * 100;
   avg = round(0.0588 * L - 0.296 * S - 15.8);
    if (avg >= 16){
        printf("Grade 16+\n");

    }
    else if (avg < 1){
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %i\n", avg);
    }


    // Compute the Coleman-Liau index

    // Print the grade level
}
