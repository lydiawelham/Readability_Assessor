#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

double count_letters(string text);
int count_words(string text);
double count_sentences(string text);

int main(void)
{

    //Prompts user for text

    string text = get_string("Text: \n");

    //Calculates no. of letters, words and sentences

    double letters = count_letters(text);
    int words = count_words(text);
    double sentences = count_sentences(text);

    //Calculate average letters per 100 words

    double l;
    l = (letters / words) * 100.00;

    //Calculate average sentences per 100 words

    double s;
    s = (sentences / words) * 100.00;

    //Calculates reading grade per Colman-Liau formula

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    //Prints reading grade

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index >= 1 && index <= 15)
    {
        printf("Grade %i\n", index);
    }

}

double count_letters(string text)
{
    //Counts total characters in text

    int total_chars = strlen(text);

    double letters = 0;

    //Counts number of upper and lowercase letters in string

    for (int i = 0; i < total_chars; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters += 1;
        }
    }

    return letters;
}

int count_words(string text)
{
    int total_chars = strlen(text);

    //Sets initial value of words to 1 and counts words as every subsequent space

    int words = 1;

    //Counts no. of spaces in text

    for (int i = 0; i < total_chars; i++)
    {
        if (text[i] == 32)
        {
            words += 1;
        }
    }

    return words;
}

double count_sentences(string text)
{
    int total_chars = strlen(text);
    double sentences = 0;

    //Counts no. of . ! ? in text to determine no. of sentences

    for (int i = 0; i < total_chars; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences += 1;
        }
    }

    return sentences;
}