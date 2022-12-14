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

//Data Struct usada para armazenamento
typedef struct{
    char date[100];
    float open, high, low, close, adjclose, volume;
}Market;

//Data Analysis
float dataAnalysis(float arrayf[], int n){
  int i;
  int choose;
  //CTM
  float resultsoma = Array_sum(arrayf, n);
  float resultmedia = Array_mean(arrayf, n);
  float resultmediana = Find_median(arrayf, n);
  //VM
  float resultvariancia = Array_variance(arrayf, n);
  float resultdesvio = Array_deviation(resultvariancia);
  
  

  
    printf("\nCHOOSE FOR A STATIC MEASURE:\n 1 - SUM \n 2 - MEAN \n 3 - MEDIAN \n 4 - VARIANCE \n 5 - STD\n 6 - MAX \n 7 - MIN\n ->");
    scanf("%d" , &choose);
    switch (choose){
      case 1:
          printf("%.2f" , resultsoma);
          break;
      case 2:
           printf("%.2f" , resultmedia);
          break;
      case 3:
           printf("%.2f" , resultmediana);
           break;
      case 4:
           printf("%.2f" , resultvariancia);
           break;
      case 5:
           printf("%.2f" , resultdesvio);
           break;
      /*
      case 6:
          Array_sort_descres(arrayf, n);
          
          break;
      case 7:
          Array_sort_cres(arrayf , n);
          
          break;
      */   
      default:
          printf("Choose for a valid operation!");
    }
}
  


int main()
{
  setlocale(LC_ALL, "Portuguese");
  
  Market estruturadados[100];
	char filename[1000];
  //READING DIRECTORY, JUMP THIS BLOCK!
  ///Declaring Statments
        DIR *folder;
        //256 os the "MAX_PATH" limit for mostly Miscrosoft Windows Systems
        char directory[256];
        char stock[256];
        struct dirent *entry; // modify struct of dirent library with atributtes to read info from directory
        int files = 0;
        
        //Reading inputs
        printf("Type the filepath of stocks: "); //In our example the directory who contain stocks is "Data/Stocks"
        scanf("%s" , &directory);
        folder = opendir(directory);

        if(folder == NULL){
            printf("An error as ocurred while opening directory of data, please try again");
            return (1);
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
        stock_error:
        printf("\nChoose for a stock who you want to analyse .csv: ");

        scanf("%s", filename);
        strcat(directory , "/");
        strcat(directory, filename);
        printf("\nIN PATH: %s\n------------------" , directory);
  
  
  //READING FILE!
  FILE* fp = fopen(directory,"r");
	if (!fp){

		printf("This file don't could be finded\n");
    goto stock_error;
    getchar();
    return 0;
    }
	else {
		char buffer[1000];
		int row = 0;
		int column = 0;
    int contador = 0;
    float valorf = 0;
    int resp = 0;
    int numcoluna = 0;
    int rowmax = 0;
    do{
      printf("\nEnter with the column who you want analyse\n");
      printf("1-OPEN\n");
      printf("2-HIGH\n");
      printf("3-LOW\n");
      printf("4-CLOSE\n");
      printf("5-ADJ CLOSE\n");
      printf("6-VOLUME\n");
      printf("7-SAIR\n");
      printf("->");
      scanf("%d",&numcoluna);

      if (numcoluna == 7)
          return 0;
  
      printf("\nEnter with the num of rows who you want to read:");
      scanf("%d", &rowmax);
      
      while (fgets(buffer, sizeof(buffer), fp)) {

  			column = 0;
        row++;
        
  			if (row == rowmax)
  				break;
  
        if (row == 1) continue;
        
  			char* value = strtok(buffer, ", ");
  
  			while (value) {
          
          if (numcoluna== 0){
            strcpy(estruturadados[row-1].date , value);
          }
          if (contador == 1){
            valorf = strtof(value,NULL);
            estruturadados[row-1].open = valorf;
          }
          if (contador == 2){
            valorf = strtof(value,NULL);
            estruturadados[row-1].high = valorf;
          }
          if (contador == 3){
            valorf = strtof(value,NULL);
            estruturadados[row-1].low = valorf;
          }
          if (contador == 4){
            valorf = strtof(value,NULL);
            estruturadados[row-1].close = valorf;
          }
          if (contador == 5){
            valorf = strtof(value,NULL);
            estruturadados[row-1].adjclose = valorf;
          }
          if (contador == 6){
            valorf = strtof(value,NULL);
            estruturadados[row-1].volume = valorf;
          }
  				value = strtok(NULL, ", ");
          contador++;
  			}
        column++;
        contador = 0;
  		}
      
    int i;
    float arrayf[row-2];

    switch(numcoluna){
      case 1:
      printf("OPENING DATA : \n");
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].open;
          
          }
        for(int j = 0; j <= row ; j++){
          printf("%f\n" , arrayf[j]);
        }
        
        dataAnalysis(arrayf, row-2);
        break;
      case 2:
      printf("HIGH DATA : \n");
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].high;
          printf("%.2f\n", arrayf[i-1]);
          }
        dataAnalysis(arrayf, row-2);
        break;
      case 3:
      printf("LOW DATA : \n");
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].low;
          printf("%.2f\n", arrayf[i-1]);
          }
        dataAnalysis(arrayf, row-2);
        break;
      case 4:
      printf("CLOSE DATA : \n");
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].close;
          printf("%.2f\n", arrayf[i-1]);
          }
        dataAnalysis(arrayf, row-2);
        break;
      case 5:
      printf("ADJ CLOSE DATA : \n");
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].adjclose;
          printf("%.2f\n", arrayf[i-1]);
          }
        dataAnalysis(arrayf, row-2);
        break;
      case 6:
      printf("ADJ VOLUME DATA : \n");
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].volume;
          printf("%.2f\n", arrayf[i-1]);
          }
        dataAnalysis(arrayf, row-2);
        break;
      default:
        printf("\nInvalid number...");
        break;
      }
    }while(resp == 0);
        };
    
  
  return 0;
  }
}
