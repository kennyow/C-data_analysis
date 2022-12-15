// #include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
//Reading Directories
#include <dirent.h>
#include <windows.h>
//Owner Headers
#include "measures.h"
#include"reading.h"


//Return the string of directorie and file path
const char* readPath(){
  //if find an error in filepath return to begin of program
  //this make who code reset variable values
  //stock_error: 
  //setlocale(LC_ALL, "Portuguese");
  //begin_: ; //semicolon solve problem with variables declared immediately before labels, don't remove it for any hypotesis
 
  //READING DIRECTORY, JUMP THIS BLOCK!
  ///Declaring Statments
        DIR *folder;
        
        char directory[256];//256 is the "MAX_PATH" limit for mostly Miscrosoft Windows Systems
        char filename[256];//256 is the "MAX_PATH" limit for mostly Miscrosoft Windows Systems
        struct dirent *entry; // modify struct of dirent library with atributtes to read info from directory
        int files = 0;
        
        //Reading inputs
        printf("Type the filepath of stocks: "); //In our example the directory who contain stocks is "Data/Stocks"
        scanf("%s" , &directory);
        folder = opendir(directory);

        if(folder == NULL){
            printf("An error as ocurred while opening directory of data, please try again");
            //goto begin_;
        }
        //
        else{
             printf("Choose a stock to read beetween options follow:\n");
             printf("\nLoading stocks...\n");
             for(int i = 0 ; i < 10 ; i++){
                printf("%d..." , i);
                Sleep(600);
             };
             printf("\n");
             printf("-------------CHOOSE YOUR STOCK----------------\n");
              while( (entry=readdir(folder)) ){
                files++;
                if(files>2){
                   printf("File %3d: %s \n", (files-2), entry->d_name);
                }
               
             };
        
        printf("\nChoose for a stock who you want to analyse .csv: ");

        scanf("%s", filename);
        strcat(directory , "/");
        strcat(directory, filename);
        char *string = directory;
        return string;
  }
}