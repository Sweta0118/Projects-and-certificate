#include <stdio.h>
#include <stdlib.h>

int length = 0, *number, k;

void delete (int *number, int startpos) // deleting by shifting it to the last
{
    int i;
    for (i = startpos; i < length; i++)
    {
        number[i] = number[i + 1];
    }
}
void play(int *number, int startpos) // O()
{
    if (length == 1)
    {
        printf("The winner is %d \n", number[0]);
        return;
    }
    else
    {
        startpos = ((startpos + k - 1) % length); // updating position
        printf("Eliminated player is %d \n", number[startpos]);
        length--;
        delete (number, startpos);
    }

    play(number, startpos);
}

void create(int n) // creating dynamically array
{
    int i;
    number = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        number[i] = i + 1;
    }
    printf("Players Playing : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", number[i]);
        length++;
    }
    printf("\n");
    printf("Press Enter to continue\n");
    getchar();
}

int main()
{
    int n;
    printf("WELCOME TO HOT-POTATO GAME\n");
    printf("Play With Friends And Enjoy The Time Spent\n");
    printf("Press Enter to continue\n");
    getchar();
    printf("Enter the number of participants for the game : ");
    scanf("%d", &n);
    printf("Enter the value of k : ");
    scanf("%d", &k);
    printf("Thank you for your response.\n");
    printf("Press Enter key to begin the game\n");
    getchar();
    create(n);
    int startpos = 0;
    play(number, startpos);
    return 0;
}
