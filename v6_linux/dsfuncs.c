// #include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
//Reading Directories
#include <dirent.h>
// #include <windows.h>
//Owner Headers
#include "measures.h"
#include"reading.h"
#include "dsfuncs.h"

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

//Data Analysis
float dataAnalysis(float arrayf[], int n){
  int i;
  int choose;
  //CTM
  float resultsoma = Array_sum(arrayf, n);
  float resultmedia = Array_mean(arrayf, n);
  qsort(arrayf, n, sizeof(float), cmpfunc);
  float resultmediana = Find_median(arrayf, n);
  //VM
  float resultvariancia = Array_variance(arrayf, n);
  float resultdesvio = Array_deviation(resultvariancia);  
    printf("\nCHOOSE FOR A STATIC MEASURE:\n 1 - SUM \n 2 - MEAN \n 3 - MEDIAN \n 4 - VARIANCE \n 5 - STD\n->");
    // 6 - MAX \n 7 - MIN\n 
    scanf("%d" , &choose);
    switch (choose){
      case 1:
          printf("The sum beetwen the first %d lines is \n-> %.2f\n" ,(n), resultsoma);
          break;
      case 2:
           printf("The mean beetwen the first %d lines is \n-> %.2f\n" ,(n), resultmedia);
          break;
      case 3:
           printf("The median beetwen the first %d lines is \n-> %.2f\n" ,(n), resultmediana);
           break;
      case 4:
           printf("The variance beetwen the first %d lines is \n-> %.2f\n" ,(n),  resultvariancia);
           break;
      case 5:
           printf("The standart deviation beetwen the first %d lines is \n-> %.2f\n" ,(n),  resultdesvio);
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
