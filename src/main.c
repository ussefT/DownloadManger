#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"


#define MAX 2048

void clear_screen(void){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showMenu(){
    printf("\n---------- Download Manager ----------\n");
    printf("1- Add URL \n");
    printf("2- Download direct\n");
    printf("3- Download links\n");
    
    printf("0- exit  \n");
}


void handle_direct_download(int status)
{
    char command[4096];
    char line[MAX];

    if (status == 0)
    {
        printf("URL: ");

        fgets(line, sizeof(line), stdin);

        if (line[0] == '\n')
            fgets(line, sizeof(line), stdin);

        line[strcspn(line, "\n")] = '\0';

        snprintf(command, sizeof(command),
                 "wget -c \"%s\" 2>&1", line);

        printf("Running: %s\n", command);

        FILE *pipe = popen(command, "r");

        if (pipe == NULL)
        {
            perror("popen");
            return;
        }

        while (fgets(line, sizeof(line), pipe) != NULL)
            printf("%s", line);

        int result = pclose(pipe);

        if (result == 0)
            printf("Download completed.\n");
        else
            printf("wget exited with code %d\n", result);
    }
    else
    {
        char filename[256];

        printf("Enter file name: ");
        scanf("%255s", filename);
        getchar();

        if (!fileExist(filename))
        {
            printf("File does not exist.\n");
            return;
        }

        FILE *fp = fopen(filename, "r");

        if (fp == NULL)
        {
            perror("fopen");
            return;
        }

        while (readLine(fp, line, sizeof(line)))
        {
            line[strcspn(line, "\n")] = '\0';

            if (strlen(line) == 0)
                continue;

            snprintf(command, sizeof(command),
                     "wget -c \"%s\" 2>&1", line);

            printf("\nRunning: %s\n", command);

            FILE *pipe = popen(command, "r");

            if (pipe == NULL)
            {
                perror("popen");
                continue;
            }

            char output[MAX];

            while (fgets(output, sizeof(output), pipe) != NULL)
                printf("%s", output);

            int result = pclose(pipe);

            if (result != 0)
                printf("wget exited with code %d\n", result);
        }

        fclose(fp);
    }
}

int main(void){
    
    clear_screen();

    int choice;

    while(1){
        showMenu();

        if(scanf("%d", &choice)!=1){
            while(getchar()!='\n');
            printf("enter a number");
            continue;
        }

        if(choice==0){
            return 0;
        }else if(choice==1){
            // printf("1- Add a link")
            
        }
        switch(choice){
            case 1 :
                
            char filename[50];
            char word[MAX];

            printf("Enter file name : ");
            scanf("%49s",filename);
            getchar();

            if(fileExist(filename))
                printf("File exist %s\n.",filename);
            else
                printf("File does not exist %s.\n",filename);
            
            writeFile(filename);


            break;
            

            case 2:
            handle_direct_download(0);
            break;
            case 3:
            handle_direct_download(1);
            break;
            case 0:
            break;
            default:
            printf("\nChoice is not valid");
        }


    }
    return 0;
}



