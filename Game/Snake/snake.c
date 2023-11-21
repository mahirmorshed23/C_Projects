#include <stdio.h>
#include <conio.h>
#include <windows.h>

int pre_x[100] = {1,1,1}, pre_y[100] = {1,2,3}, p, q, collision=1, n = 3, points=0;

void display(char arr[12][12], int x, int y)
{
    printf("\n\n\t\x1b[32mPoints:\x1b[0m \x1b[33m%d\x1b[0m\n\n", points);
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(i==0 || i==11 || j==0 || j==11) arr[i][j] = '#';
            else arr[i][j] = '-';
        }
    }
    int z;
    for(z=0; z<n-2; z++)
    {
        if(pre_x[z] == x && pre_y[z] == y || arr[x][y] == '#')
        {
            printf("\x1b[H");
            printf("\n\n\n\n\n\n\n \x1b[33m#\x1b[0m      \x1b[41mGame Over\x1b[0m\n\n\n\n\n\n\n\n\n\n");
            exit(1);
        }
    } 
    
    for(int i=0; i<n-1; i++)
    {
        pre_x[i] = pre_x[i+1];
        pre_y[i] = pre_y[i+1];
    }
    pre_x[n-1] = x;
    pre_y[n-1] = y;

    for(int i=0; i<n-1; i++)
    {
        arr[pre_x[i]][pre_y[i]] = 'o';
    }
    arr[pre_x[n-1]][pre_y[n-1]] = 'O';

    if(collision == 1)
    {
        do {
            p = rand()%10 + 1;
            q = rand()%10 + 1;
            int i;
            for(i=0; i<n; i++)
            {
                if(pre_x[i] == p && pre_y[i] == q) break;
            }
            if(i == n) break;
        } while(1);
        collision = 0;
    }

    arr[p][q] = '$';

    if(pre_x[n-1] == p && pre_y[n-1] == q) 
    {
        Beep(300, 100);
        collision = 1;
        arr[p][q] = 'O';
        points++;
        n++;
        for(int i=n-1; i>=0; i--)
        {
            pre_x[i] = pre_x[i-1];
            pre_y[i] = pre_y[i-1];
        }
        pre_x[0] = p;
        pre_y[0] = q;
    }

    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(arr[i][j]=='#') printf("\x1b[33m #\x1b[0m");
            else if (arr[i][j]=='-') printf("\x1b[32m .\x1b[0m");
            else if (arr[i][j]=='o') printf("\x1b[1m\x1b[36m o\x1b[0m");
            else if (arr[i][j]=='O') printf("\x1b[1m\x1b[34m O\x1b[0m");
            else if (arr[i][j]=='$') printf("\x1b[1m\x1b[35m $\x1b[0m");
        }
        printf("\n");
    }
}

int main()
{
    system("color");
    char arr[12][12], d = 'd', ch = 'd';
    int x=1, y=3;
    srand(time(NULL));
    while(1)
    {
        printf("\x1b[H");
        if(_kbhit())
        {
            d = getch();
            if(ch == 'd' && d == 'a') d = 'd';
            else if(ch == 'a' && d == 'd') d = 'a';
            else if(ch == 's' && d == 'w') d = 's';
            else if(ch == 'w' && d == 's') d = 'w';
        }
        switch (d)
        {
        case 'd':
            y++;
            break;
        case 's':
            x++;
            break;
        case 'a':
            y--;
            break;
        case 'w':
            x--;
            break;
        }
        ch = d;
        display(arr, x, y);
        
        Sleep(400);
    }
}
