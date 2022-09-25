//C:\Program Files (x86)\Microsoft Visual S
//tudio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\include
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>
#define MAX_LEN 300

void menu(FILE *fptr,int cNumOp, char *filename){ // ascii menu 
   int i = 0;
   char read_string[MAX_LEN];
   while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
    if((fptr = fopen(filename,"r")) == NULL){
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
   for(i=0;i<10;i++)
      printf("\n");
   printf("Select option ~~~:>    ");
   scanf("%d",&cNumOp);
   fclose(fptr);
}

void extSelect(char extype[],char cext[],int  cNumEx){
    int i;
    printf("Choose extension type: ");
    
    for(i = 0; i < sizeof(extype)/sizeof(extype[0]); i++)
        printf("%s\n",extype[i]);
    for(i=0;i<10;i++)
      printf("\n");

    printf("~~:>");
    scanf("%d", &cNumEx);

    switch (cNumEx){
    case 1:
         strcpy(cext, extype[0]);
        puts(cext);
        break;
    case 2:
        strcpy(cext, extype[1]);
        puts(cext);
        break;
    
    }
}
//2. upis putanje fajla
void folderSelect(char folderPath, char cext, char *p, DIR* dir, struct dirent *entry){
    printf("** \\ for PATH **");
    printf("Enter path of folder: \n");
    printf("~~:> ");
    gets(folderPath);
    dir = opendir(folderPath);
    
    if (dir == NULL)
        printf("Cannot open directory '%s'\n", folderPath);
    printf("PATH: %s", folderPath);
    while((entry = readdir(dir)) != NULL){
        if(p)
            printf("[%s]\n", entry->d_name);
        
    }
    closedir(dir);
}
void folderSort(char folderPath, char cext, char *p, DIR *dir, struct dirent *entry){
    dir = opendir(folderPath);
    if (dir == NULL)
        printf("Cannot open directory '%s'\n", folderPath);
    printf("PATH: %s", folderPath);
    printf("Enter new names for files");
    printf("\n");
    printf("~~:> ");
}

int main(int argc, char *argv[]){
    //varijable koje su skupljene su iskoriscene
    DIR* dir;
    struct dirent *entry;
    char folderPath[50]; // path of choosed folder with 
    int i;
    FILE *fptr;
    char *filename = "RenFil.txt";
    char extype[][10] = {".txt", ".jpg"};  // extension types
    char cext[10]; // choosed extension
    int  cNumEx;  // choosed number extension
    int cNumOp; // choosed number option
    char *p; 
    p = strstr(entry->d_name, cext);
    char fnn[50]; // new sorting name of the file
    
    menu(fptr,cNumOp,filename);
    
    //3. promena imena fajla sa izabranom ekstenzijom i sortiranje fajlova   
    return 0;
}
