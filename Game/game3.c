#include <stdio.h>
#include <stdlib.h>

void  update_screen(char arr[10][10], int x, int y)
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			arr[i][j] = '-';
		}
	}
	arr[x][y] = '@';
	arr[4][4] = '#';
	for(int i=0; i<20; i++)
	{
		int a,b;
		a = rand() % 10;
		b = rand() % 10;
		if(arr[a][b] != 'X' && arr[a][b] != '@' && arr[a][b] != '#') arr[a][b] = 'X';
		else i--;
	}

	for(int i=0; i<10; i++)
	{
		printf("              \n");
		printf("               ");
		for(int j=0; j<10; j++)
		{
			if(arr[i][j] == '@') printf("\x1b[44m %c \x1b[0m ", arr[i][j]);	
			else if(arr[i][j] == '#') printf("\x1b[43m %c \x1b[0m ", arr[i][j]);
			else if(arr[i][j] == 'X') printf("\x1b[41m %c \x1b[0m ", arr[i][j]);
			else printf("\x1b[42m %c \x1b[0m ",arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int x=0, y=0;
	char arr[10][10], move;

	while(1)
	{
		printf("\x1b[H\x1b[J");
		printf("\n\n\a\x1b[36mpress w,s,a,d and ENTER to move up,down,right,left: \x1b[0m\n");
		update_screen(arr, x ,y);
		printf("Enter key: ");
		scanf("%c", &move);
		if(move == 'w' && x!=0)x--;
		else if(move == 's' && x!=9)x++;
		else if(move == 'a' && y!=0)y--;
		else if(move == 'd' && y!=9)y++;
	
		if(arr[x][y]=='#')
		{
			printf("\n\n                   \x1b[42mCongrats!!!You Won the game.\x1b[0m\n");
			break;
		}
		else if(arr[x][y]=='X')
		{
			printf("\n\n                      \x1b[41mGame Over.You lose :(\x1b[0m\n");
			break;
		}

	}
	return 0;
}

