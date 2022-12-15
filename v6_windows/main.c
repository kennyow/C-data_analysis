//#include <conio.h>

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
#include "reading.h"
#include "dsfuncs.h"

//Data Struct used for storagement
typedef struct{
    char date[100];
    float open, high, low, close, adjclose, volume;
}Market;

int main(){
  const char* directory = readPath();
  char path[256];
  strcpy(path, directory);
  printf("%s" , path);
  printf("\nIN PATH: %s\n------------------" , path); 

  //READING FILE! BUGS HERE!
  Market estruturadados[15000];
  FILE* fp = fopen(path,"r");
	if (!fp){
    //if fp returns null, so this block of code is executed

		printf("This file don't could be finded\n");

    //goto stock_error;
    getchar();
    return 0;
    }

	else {
    int resp = 1;
    do{
      char buffer[1000];
		  int row = 0;
		  int column = 0;
      int contador = 0;
      float valorf = 0;
      int numcoluna = 0;
      int rowmax = 0;

      printf("\nEnter with the column which you want to analyse\n");
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
  
      printf("\nEnter with the number of rows which you want to read\n");
      printf("->");
      scanf("%d", &rowmax);
      
      while (fgets(buffer, sizeof(buffer), fp)) {

  			column = 0;
        row++;
        
  			if (row-2 == rowmax)
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
      
    int i=0;
    float arrayf[row-2];

    switch(numcoluna){
      case 1:
      printf("OPENING DATA : \n");
        for(i = 1; i <= row-2; i++) {
          arrayf[i-1] = estruturadados[i].open;
          printf("%.2f\n", arrayf[i-1]);
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
    printf("Do you want to continue? \n[1]-Yes\n[0]-No\n->");
    scanf("%d" , &resp);
   
    }while(resp != 0);
  }
  return 0;
}
