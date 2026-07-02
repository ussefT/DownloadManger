#include <stdio.h>
#include <string.h>


#define MAX 2048



// Check if file exists
int fileExist(const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
        return 0;

    fclose(fp);
    return 1;
}

// Write to file
void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    char line[MAX];

    if (fp == NULL) {
        printf("Cannot create file.\n");
        return;
    }

    printf("Enter text line by line.\n");
    printf("Enter 0 to stop.\n");

    while (1) {
        fgets(line, MAX, stdin);

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "0") == 0)
            break;

        fprintf(fp, "%s\n", line);
    }

    fclose(fp);

    printf("File saved successfully.\n");
}

// Read file
int readLine(FILE *fp, char *line, int size) {
    if (fgets(line, size, fp) != NULL)
        return 1;   // Line read successfully

    return 0; 
}

// Search in file
void searchFile(const char *filename, const char *word) {
    FILE *fp = fopen(filename, "r");
    char line[MAX];
    int lineNo = 1, found = 0;

    if (fp == NULL) {
        printf("Cannot open file.\n");
        return;
    }

    while (fgets(line, MAX, fp) != NULL) {
        if (strstr(line, word) != NULL) {
            printf("Found at line %d: %s", lineNo, line);
            found = 1;
        }
        lineNo++;
    }

    if (!found)
        printf("Word not found.\n");

    fclose(fp);
}