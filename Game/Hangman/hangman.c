#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void man(int chance);
void display(char arr[], int len);

int main()
{
    srand(time(NULL));
    char words[][15] = {"apple", "orange", "cucumber", "watermelon", "hangman", "programmer", "keyboard"};
    char word[15];
    strcpy(word, words[rand()%7]);
    int len = strlen(word), chance=9, i;
    char wordcpy[len];
    strcpy(wordcpy, word);
    char arr[len];
    for(int i=0; i<len; i++)
        arr[i] = '-';

    while(1)
    {
        printf("\x1b[H\x1b[J");
        printf("Chance left: %d\n",chance);
        display(arr, len);
        man(chance);
        if(strncmp(wordcpy, arr, len) == 0) 
        {
            printf("\n-----You Won!!!------");
            break;
        }
        else if(chance == 0)
        {
            printf("\n----The man Hanged. You Lose----");
            break;    
        }
        char guess;
        printf("\n\aEnter your guess: ");
        scanf(" %c", &guess);
        for(i=0; i<len; i++)
        {
            if(guess == word[i]){
                arr[i] = word[i];
                word[i] = '*';
                break;
            }
        }
        if(i==len) chance--;
    }
}


void man(int chance)
{
    switch (chance)
    {
    case 9:
        printf("\n                \n                \n                \n                \n                \n                \n                \n                \n                \n");
        break;
    case 8:
        printf("\n                \n                \n                \n                \n                \n                \n                \n                \n####################\n");
        break;
    case 7:
        printf("\n||              \n||              \n||              \n||              \n||              \n||              \n||              \n||              \n####################\n");
        break;
    case 6:
        printf("\n||=========     \n||              \n||              \n||              \n||              \n||              \n||              \n||              \n####################\n");
        break;    
    case 5:
        printf("\n||=========     \n||        |     \n||              \n||              \n||              \n||              \n||              \n||              \n####################\n");
        break;
    case 4:
        printf("\n||=========     \n||        |     \n||        |     \n||              \n||              \n||              \n||              \n||              \n####################\n");
        break;
    case 3:
        printf("\n||=========     \n||        |     \n||        |     \n||       ( )    \n||              \n||              \n||              \n||              \n####################\n");
        break;
    case 2:
        printf("\n||=========     \n||        |     \n||        |     \n||       ( )    \n||      /| |\\  \n||       / \\   \n||              \n||              \n####################\n");
        break;
    case 1:
        printf("\n||=========     \n||        |     \n||        |     \n||       ( )    \n||      /| |\\  \n||       / \\   \n||      /   \\  \n||              \n####################\n");
        break;
    case 0:
        printf("\n||=========     \n||        |     \n||        |     \n||        |     \n||      /\x1b[31m( )\x1b[0m\\  \n||       / \\   \n||      /   \\  \n||              \n####################\n");
    }
}

void display(char arr[], int len)
{
    for(int i=0; i<len*4+1; i++){printf("-");}
        printf("\n");
        for(int i=0; i<len; i++)
        {
            printf("| %c ", arr[i]);
        }
        printf("|\n");
        for(int i=0; i<len*4+1; i++){printf("-");}
}