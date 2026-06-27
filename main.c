#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void showMenu(){
    printf("\n---------- Download Manager ----------\n");
    printf("1- Add URL \n");
    printf("2- Download direct\n");
    printf("3- exit 0 \n");
}

void handle_direct_download(){

    char command[1024];
    char url[512];

    printf("URL:\n");

    // clear buffer
    while(getchar()!='\n');

    fgets(url,sizeof(url),stdin);  // get input 

    url[strcspn(url,"\n")] = 0; // clear new line

    snprintf(command, sizeof(command),"wget %s 2>&1",url);

    printf("Runngin : %s\n",command);

    FILE *fp = popen(command,"r"); // run command

    if(fp==NULL){
        perror("Error to popne.");
        return;
    }

    char line[1024];
    while(fgets(line,sizeof(line),fp)!=NULL){
        printf("%s",line); // show eveyline
    }

    int status=pclose(fp);
    if(status==0){
        printf("ok");
    }else{
        printf("Error output code %d\n.",status);
    }
}

int main(){

    int choice;
    int running = 1;
    while(running){
        showMenu();

        if(scanf("%d", &choice)!=1){
            while(getchar()!='\n');
            printf("enter a number");
            continue;
        }

        switch(choice){
            case 1 : 
            printf("Hi");
            break;
            case 2:
            handle_direct_download();
            break;
            case 0:
            running=0;
            break;
            default:
            printf("\nChoice is not valid");
        }
    }
    return 0;
}



