#include <stdio.h>
#include <locale.h>
#include <dirent.h>
#include <math.h>
#include <windows.h>
#include <string.h>
//Summatory
float Array_sum(float array[] , int n)
{
    //Read an array and return the sum
    float sum;
     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
    }
    return sum;
}

//Fun��o M�DIA
float Array_media(float array[] , int n)
{
    //read an avarage and return the mean beetween values into
    float media;
    float sum;

     for (int i = 0; i < n; i++) {
       sum = sum + array[i];
       media = sum/n;
    }
    return media;
}


//Rearranjo da array
void Array_sort(int *arr , int n)
{
    //Receive an pointer to array and reorder this 


    // Declarando vari�veis locais
    int i=0 , j=0 , temp=0;


    // Comando FOR para reposicionar os elementos da array:
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j< n-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp        = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
            }
        }
    }

}

// Fun��o MEDIANA:
float Find_median(float array[] , int n)
{
    //Receive an array and find the median
    float median=0;

    // se o n�mero de elementos da array for �mpar
    if(n%2 == 0)
        median = (array[(n-1)/2] + array[n/2])/2.0;
    // se o n�mero de elementos for par
    else
        median = array[n/2];

    return median;
}

//Fun��o VARI�NCIA
float Array_variance(float array[] , int n, float media, float sum)
{

    float x[n];
    float variance;


    for (int i = 0; i < n; i++)
    {
        sum = sum + pow((array[i] - media), 2);
    }
    variance = sum / (float)n;

    return variance;
}

//Fun��o DESVIO PADR�O
float Array_deviation(float variance)
{
    float std_deviation;


    std_deviation = sqrt(variance);
    return std_deviation;
}

//Menu and commands
int main()
{   
    /**
     * READING DATA
     *  User can choose an file to read
     * So we'll opening the directorie and read the name of files inside
     * After of it the program read all data inside of choosed file
     * The data should go to an struct
     * The struct atributtes has be arrays
     * Choose a column to calculate statics
     * Call statics function to solve it
     * Put results in txt file and save in specific folder for user
     * 
     * */
    // Loop of code execution
    do{
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
                Sleep(1000);
             };
             
             while( (entry=readdir(folder)) ){
                files++;
                printf("File %3d: %s \n", files, entry->d_name);
             };
             scanf("%s" , &stock);
             //Reading Stock Data
             strcat(directory , "/");
             strcat(directory,stock);
             
             FILE* fp = fopen(directory , "r");
             if(!fp){
                printf("An error ocurred while openning stock file, please try again!\n");
             }
             else{
                //Declaring Statments
                char buffer[1024];
                int row = 0;
                int column = 0;
                /**
                 * FGETS
                 * 1- the name of vector to save string , in this case, buffer
                 * 2- The maxium of characters to read
                 * 3- Where data come from, in this case, from fp FILE struct type pointer***/
                while (fgets(buffer,1024,fp))
                {
                    column = 0;
                    row++;

                    if (row == 10) continue;

                    //breaks string str into a series of tokens using the delimiter ',' ; because our program read CSV
                    // CSV is comma separeted values
                    char* value = strtok(buffer,",");

                    while(value){
                        if (column == 0){
                            printf("Name:");
                        }
                        if(column == 1){
                            printf("\tAccount No.:");
                        }
                        if(column == 2){
                            printf("\tAmoun :t");
                        }

                        printf("%s" , value);
                        value = strtok(NULL, ",");
                        column ++;

                    };
                    printf("\n");
                    //Close the file
                    fclose(fp);
                };
            
             }
        }
        closedir(folder);

    }while(1);
    
    //First I need to read the csv choosed for user 
    // 
    
    
    
    //int choose = 1;
    //loop of input code
    
    /*do{
        //Receive the operation of user want to make
        printf("Choose an option\n
        1 - Sum of a column  \n
        2 - Avarage\n
        0 - to exit of program");
        scanf("%d" , choose);
        switch (choose)
        {
        case 1:
            //call a function based in user input
            break;
        
        default:
            break;
        }
    }while(exit != 0);
*/
    return 0;
}
