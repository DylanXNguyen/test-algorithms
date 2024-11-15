#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

  /*  printf("%f\n", letters);
    printf("%f\n", words);
    printf("%f\n", sentences);*/

    float L = (float) letters/words * 100;
   // printf("L: %f\n",L);
    float S = (float) sentences/words * 100;
   // printf("S: %f\n",S);

    int index = (int) round(0.0588 * L -0.296 *S -15.8);



    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",index);
    }



}

int count_letters(string text)
{
    int letters = 0;

    for(int i =0, len = strlen(text); i < len; i++)
    {
        if(text[i] != ' ' && text[i] != '!' && text[i] != '.' && text[i] != '?' && text[i] != ',' && text[i] != '\'')
        {

        letters++;
      //   printf("%i\n", letters);
      //  printf("%c\n", text[i]);
        }
    }

    return letters;
}

int count_words(string text)
{
    int spaces = 0;


    for(int i =0, len = strlen(text); i < len; i++)
    {
        if(text[i] == ' ')
        {
        spaces++;
        }
    }

    return spaces +1;
}

int count_sentences(string text)
{

    int periods = 0;

      for(int i =0, len = strlen(text); i < len; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {

        periods++;
        }
    }

    return periods;
}
