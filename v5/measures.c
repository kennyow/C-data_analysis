#include <stdio.h>
//IMPLEMENTATIONS OF FUNCTIONS

#include  "measures.h"
#include <math.h>

float Array_sum(float array[] , int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++) {
       sum = sum + array[i];
    }
    return sum;
}

float Array_mean(float array[] , int n)
{
    float media = 0;
    float sum = Array_sum(array, n);
    media = sum / n;
    return media;
}


//Ordenação crescente
void Array_sort_cres(int *arr , int n)
{
    int i=0 , j=0 , temp=0;
  
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j< n-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp      = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }
    printf("%d" , arr[0]);

}

//Ordenação decrescente
void Array_sort_descres(int *arr , int n)
{
    int i=0 , j=0 , temp=0;

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j< n-1 ; j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp        = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }
    printf("%d" , arr[0]);

}

//Mediana
float Find_median(float array[] , int n)
{
    float median=0;

    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    else
        median = array[n/2];
    return median;
}

//Variancia
float Array_variance( float array[], int n)
{
    float sum = 0.0;
    float dev = 0.0;
    float med = Array_mean( array, n );
    int i = 0;

    for( i = 0; i < n; i++ )
    {
        dev = array[i] - med;
        sum += (dev * dev);
    }

    return sum / n;
}

//Desvio Padrao
float Array_deviation(float variance)
{
    float std_deviation=0;

    std_deviation = sqrt(variance);
    return std_deviation;
}