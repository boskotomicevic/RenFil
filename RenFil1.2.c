#include<stdio.h>
#include<string.h>
#include<dirent.h>
#define PATH "../test/"

int endsWith(char *str, char *suffix) {
    if (!str || !suffix) return 0;
    int lenstr = strlen(str);
    int lensuffix = strlen(suffix);
    if (lensuffix >  lenstr) return 0;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}

void renameFiles(DIR* dir, char name[255], char extension[255]) {
    struct dirent *entry;
    int i = 1;
    while ((entry = readdir(dir)) != NULL) {
        if (!endsWith(entry->d_name, extension)) continue;
        char oldName[255];
        strcpy(oldName, PATH);
        strcat(oldName, entry->d_name);
        char newName[255] = "";
        char number[10];
        snprintf(number, 10, "%d", i);
        strcpy(newName, PATH);
        strcat(newName, name);
        strcat(newName, number);
        strcat(newName, extension);
        printf("Renaming %s to %s\n", entry->d_name, newName);
        rename(oldName, newName);
        i++;
    }
}

void fileNames(DIR* dir) {
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }
}

int main(){
    char directoryName[255] = "../";
    puts("Upisi ime foldera:");
    gets(directoryName+3);
    DIR* dir;
    if ((dir = opendir(directoryName)) == NULL) {
        printf("Folder '%s' ne postoji\n", directoryName);
        return 1;
    }
    char extension[255] = "";
    puts("Upisi ime extenzije:");
    gets(extension);
    if (extension[0] != '.') {
        printf("Extenzija mora poceti tackom\n");
        return 1;
    }
    char newName[255];
    puts("Upisi novo ime fajlova:");
    gets(newName);
    renameFiles(dir, newName, extension);
    closedir(dir);
    return 0;
}
