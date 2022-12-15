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
#include "dsfuncs.h"

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

//Data Analysis
float dataAnalysis(float arrayf[], int n){
  int i=0;
  int choose;
  qsort(arrayf, n, sizeof(float), cmpfunc);  
    printf("\nCHOOSE FOR A STATIC MEASURE:\n 1 - SUM \n 2 - MEAN \n 3 - MEDIAN \n 4 - VARIANCE \n 5 - STD\n->");
    // 6 - MAX \n 7 - MIN\n 
    scanf("%d" , &choose);
    switch (choose){
      case 1:
          printf("The sum beetwen the first %d lines is \n-> %.2f\n" ,(n), Array_sum(arrayf, n));
          break;
      case 2:
           printf("The mean beetwen the first %d lines is \n-> %.2f\n" ,(n), Array_mean(arrayf, n));
          break;
      case 3:
           printf("The median beetwen the first %d lines is \n-> %.2f\n" ,(n), Find_median(arrayf, n));
           break;
      case 4:
           printf("The variance beetwen the first %d lines is \n-> %.2f\n" ,(n),  Array_variance(arrayf, n));
           break;
      case 5:
           printf("The standart deviation beetwen the first %d lines is \n-> %.2f\n" ,(n),  Array_deviation(Array_variance(arrayf, n)));
           break;
      default:
          printf("Choose for a valid operation!");
    }
}
