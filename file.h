#ifndef FILE_H
#define FILE_H

#define MAX 2048


int fileExist(const char *filename);
void writeFile(const char *filename);
int readLine(FILE *fp, char *line, int size);
void searchFile(const char *filename, const char *word);

#endif

