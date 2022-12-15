## C data Analysis

### Data Scientists 
  - Kennyo
  - Benn
  - Walker
  - Jafet
  - Pedro
  
#### Objectives
Provide statistical measures to help investors make their decisions about buying and selling stocks.

#### DataBase
The database is an adaptation of : https://www.kaggle.com/datasets/jacksoncrow/stock-market-dataset 
and can be found at : https://drive.google.com/drive/folders/1cp_DhFOfwioHjzSHrHjAWXfpdRx1aJQy?usp=sharing

##### Database Structure
The database we use can be located in the directory "data/stocks" and it has 4 csv files, each one with the following columns:<br>
Date,Open,High,Low,Close,Adj Close,Volume.<br>
Which are the data about the stocks of each of the referred companies.<br>

#### The code
The last version provides an executable "main.exe", an terminal program which do the following iterations:<br>
1- Select the data from a company.<br>
2- Select the column to be read from a csv file.<br>
3- Select the information to be extracted.<br>

##### Market Struct
```
typedef struct{
    char date[100];
    float open, high, low, close, adjclose, volume;
}Market;
```
This struct receives the data from database, in this case we are using an CSV as relational database.

#### How to use the program?

1- The program will ask for the path of Data. Enter with "Data/Stocks" to openning all options of csv files to read.<br>
2- The program will ask which csv file you want to analyse. Enter the file name with ".csv" at the end of it.<br>
3- The program will ask how much rows you want to see. Enter the desired number of rows.<br>
4- The program will show up the values of: open, high, low, close, adjclose and volume of every date of the csv file.<br>

##### How to use the functions of the program?

1- The program will ask which function you want to use. <br>
2- The functions are: mean, median, variance and deviation.<br>
3- Choose one of the functions and the program will calculate the value for each line except the date.<br>

#### How is the program is organized?
- dsfuncs.h  : an header with the processment of analyse.<br>
- measures.h : an header with the implementation of statics functions like mean, median, standart deviation, variance, and more.<br>
- reading.h  : this module is responsable for read the path of file and send it to the main file.<br>

#### V5 features
1- Version 5 fixes display errors in the terminal for some utf-8 characters, the solution was to translate the source code to English.<br>
2- The user will be able to choose a CSV option within an entire database, and that database will be listed to the user.<br>
3- In addition to choosing the lines, you can view the measurements abstracted as structure fields.<br>
4- Modularization of our owner functions.<br>
5- User can choose who operation will be done with the column and rows chosen.<br>

#### Conclusion
- The exploration of stock data can be greatly expanded through the use of modularization, with low use of computational resources, a typical feature of the language, in the future, expanding the ability to read lines and plot graphs, these topics were beyond the scope of the initial analysis.
- The use of structures allows the elements of the csv file to be read as fields of the csv file, thus significantly reducing the verbosity of the code, and facilitating the abstraction of the data for the programmer.

##### PDF version
The pdf report is available at: 

