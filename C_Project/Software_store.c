#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cyan    "\x1b[36m"
#define reset   "\x1b[0m"


#define max 100
int soft=0;

struct Software
{
    char name[50];
    char type[50];
    float version;
    int price;
    char about[500];
};

void view_software(struct Software s[max])
{
    printf(cyan"\n\n===================================================================================================================\n");
    printf("||                                              "reset"Softwares"cyan"                                                        ||\n");
    printf("===================================================================================================================\n"reset);

    for (int i = 0; i < soft; i++) 
    {
        printf(cyan"||"reset" Software Name:   %-90s   "cyan"||"reset"\n", s[i].name);
        printf(cyan"||"reset" Type         :   %-90s   "cyan"||"reset"\n", s[i].type);
        printf(cyan"||"reset" Version      :   %-90.1f   "cyan"||"reset"\n", s[i].version);
        printf(cyan"||"reset" Price        :   %d%-90s"cyan"||"reset"\n", s[i].price, " TK");
        printf(cyan"||"reset" About        :   %-90s   "cyan"||"reset"\n", s[i].about);
        printf(cyan"===================================================================================================================\n"reset);
    }
}


void add_software(struct Software s[max])
{
    while(1)            
    {
        printf("Add software number: %d\n", soft+1);
        printf("Enter Software Name: ");
        gets(s[soft].name);
        if(strcmp(s[soft].name, "") == 0) break;
        printf("Enter Software Type: ");
        gets(s[soft].type);
        printf("Enter Software Version: ");
        scanf("%f", &s[soft].version);
        printf("Enter Software Price: ");
        scanf("%d", &s[soft].price);
        getchar();
        printf("Enter About Software: ");
        gets(s[soft].about);
        soft++;
    }
}

void search_software(struct Software s[max], char soft_name[50])
{
    printf(cyan"\n===================================================================================================================\n");
    printf("||                                      "reset"Search Results for: %-20s"cyan"                                 ||\n", soft_name);
    printf("===================================================================================================================\n"reset);
    for(int i=0; i<=soft; i++)
    {
        if(strncmp(soft_name, s[i].name, strlen(soft_name))==0) 
        {
            printf(cyan"||"reset" Software Name:   %-90s   "cyan"||"reset"\n", s[i].name);
            printf(cyan"||"reset" Type         :   %-90s   "cyan"||"reset"\n", s[i].type);
            printf(cyan"||"reset" Version      :   %-90.1f   "cyan"||"reset"\n", s[i].version);
            printf(cyan"||"reset" Price        :   %d%-90s"cyan"||"reset"\n", s[i].price, " TK");
            printf(cyan"||"reset" About        :   %-90s   "cyan"||"reset"\n", s[i].about);
            printf(cyan"===================================================================================================================\n"reset);
        }
    }
}

void edit_software(struct Software s[max], char soft_name[50])
{
    search_software(s, soft_name);
    printf("Which software do you want to edit? (Type the full name of the softwre)\n");
    gets(soft_name);
    for(int i=0; i<=soft; i++)
    {
        if(strncmp(soft_name, s[i].name, strlen(s[i].name)-1)==0) 
        {
            char number = 'x';
            while(number!='0')
            {
                printf("Which one do you want to edit?\n\n1. Software Name\n\n2. Software Type\n\n3. Software version\n\n4. Software Price\n\n5. About Software\n\n0. Stop Editing\n\n Enter Choice =>");
                scanf("%c", &number);
                getchar();
                switch (number)
                {
                case '0':
                    printf("Edited Successfully.\n");
                    break;
                case '1':
                    printf("New Software Name: ");
                    gets(s[i].name);
                    break;
                case '2':
                    printf("New Software Type: ");
                    gets(s[i].type);
                    break;
                case '3':
                    printf("New Software Version: ");
                    scanf("%f", &s[i].version);
                    getchar();
                    break;
                case '4':
                    printf("New Software Price: ");
                    scanf("%d", &s[i].price);
                    getchar();
                    break;
                case '5':
                    printf("New About Software: ");
                    gets(s[i].about);
                    break;
                }
            }
        }
    }
}

void delete_software(struct Software s[max], char soft_name[50])
{
    int key = -1;
    for(int i=0; i<=soft; i++)
    {
        if(strncmp(soft_name, s[i].name, strlen(s[i].name)-1)==0) 
        {
            key = i;
            break;
        }
    }
    if(key >= 0)
    {
        for(int i=key; i<=soft; i++)
        {
            strcpy(s[i].name, s[i+1].name);
            strcpy(s[i].type, s[i+1].type);
            strcpy(s[i].about, s[i+1].about);
            s[i].version = s[i+1].version;
            s[i].price = s[i+1].price;
        }
        soft--;
    }
    else printf("Software Not Found !!!");
}

void Software_read(struct Software s[max])
{
    FILE *file;
    file = fopen ("software.dat","r");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening software.dat\n\n");
        exit (1);
    }
    int i;
    soft = fread (s, sizeof(struct Software), max, file);
    fclose(file);
}

void Software_write(struct Software s[max])
{
    FILE *file;
        file = fopen ("software.dat","w");
        if (file == NULL)
        {
            fprintf(stderr, "\nError opening software.dat\n\n"); 
            exit (1);
        }
        fwrite(s, sizeof(struct Software), soft, file);
        fclose(file);
}

int main()
{
    system("color");
    printf(cyan"\n                 __  __       _     _      _       ____         __ _                                          \n");
    printf("                |  \\/  | __ _| |__ (_)_ __( )___  / ___|  ___  / _| |___      ____ _ _ __ ___                 \n");
    printf("                | |\\/| |/ _` | '_ \\| | '__|// __| \\___ \\ / _ \\| |_| __\\ \\ /\\ / / _` | '__/ _ \\                \n");
    printf(" _ _ _ _ _ _ _  | |  | | (_| | | | | | |    \\__ \\  ___) | (_) |  _| |_ \\ V  V / (_| | | |  __/  _ _ _ _ _ _ _ \n");
    printf("(_|_|_|_|_|_|_) |_|  |_|\\__,_|_| |_|_|_|    |___/ |____/ \\___/|_|  \\__| \\_/\\_/ \\__,_|_|  \\___| (_|_|_|_|_|_|_)\n"reset);
    struct Software s[max];
    char soft_name[50];
    char num = 'x';
    Software_read(s);
    while (num != '0')
    {
        printf(cyan"\n===================================================================================================================\n"reset);
        printf(cyan"||"reset" [1]. Add Software                                                                                             "cyan"||"reset"\n\n");
        printf(cyan"||"reset" [2]. View Software                                                                                            "cyan"||"reset"\n\n");
        printf(cyan"||"reset" [3]. Search Software                                                                                          "cyan"||"reset"\n\n");
        printf(cyan"||"reset" [4]. Edit Software                                                                                            "cyan"||"reset"\n\n");
        printf(cyan"||"reset" [5]. Delete Software                                                                                          "cyan"||"reset"\n\n");
        printf(cyan"||"reset" [0]. Save and Exit                                                                                            "cyan"||"reset"\n");
        printf(cyan"===================================================================================================================\n"reset);
        printf("|| Enter your choice (0-5) =>"reset);
        scanf("%c", &num);
        getchar();
        switch (num)
        {
        case '1':
            add_software(s);
            break;
        case '2':
            view_software(s);
            break;
        case '3':
            printf("\nSearch: ");
            gets(soft_name);
            search_software(s, soft_name);
            break;
        case '4':
            printf("\nSearch: ");
            gets(soft_name);
            edit_software(s, soft_name);
            break;
        case '5':
            printf("Type the name of the Software to delete: ");
            gets(soft_name);
            delete_software(s, soft_name);
            break;
        }
    }
    Software_write(s);
    return 0;
}
                                                                                                               
                                                                                                                    
