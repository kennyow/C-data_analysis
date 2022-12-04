import pandas as pd
'''
This function receive a txt file and converts to relational database as csv file
'''
def generateDataAsCsv(data,name):
    dataFrame = pd.read_fwf(data) #read a txt file as a dataFrame
    return dataFrame.to_csv(name) #convert this dataFrame to csv 
    #we'll use this csv as a relational database to our data analysis in C programming
def getData():
    data = input('Type txt path file:')
    name = input('Type path to store csv file')
    generateDataAsCsv(data , name)

getData()


