/*******************************************************************
 * File: ta12.cpp
 *
 * Description: Use this file as a starting place for your team
 *   activity.
 *******************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;

/*************************************************
 * Struct: Record
 * Description: Can hold a line in the census file
 *************************************************/
struct Record
{
   int age;
   string workClass;
   int fnlwgt;
   string education;
   int educationNum;
   string maritalStatus;
   string occupation;
   string relationship;
   string race;
   string sex;
   int capitalGain;
   int capitalLoss;
   int hoursPerWeek;
   string nativeCountry;
   string income;
};

/***********************************************
 * Function: parseLine
 * Description: Breaks up a line into the fields
 *   of the record.
 ***********************************************/
void parseLine(string line, Record & record)
{
   stringstream buffer(line);

   buffer >> record.age;
   buffer >> record.workClass;
   buffer >> record.fnlwgt;
   buffer >> record.education;
   buffer >> record.educationNum;
   buffer >> record.maritalStatus;
   buffer >> record.occupation;
   buffer >> record.relationship;
   buffer >> record.race;
   buffer >> record.sex;
   buffer >> record.capitalGain;
   buffer >> record.capitalLoss;
   buffer >> record.hoursPerWeek;
   buffer >> record.nativeCountry;
   buffer >> record.income;

   if (buffer.fail())
   {
      cout << "Error parsing record from line: " << line << endl;
   // It would be better to have better error checking here...
   }
}

void readFile(string file, map<string, int> & jobMap)
{
   ifstream fin(file.c_str());

   if (fin.fail())
   {
      cout << "Could not open file: " << file << endl;
      return;
   }

   string line;
   while (getline(fin, line))
   {
      Record record;

      parseLine(line, record);
   
      jobMap[record.occupation]++;
   }

   fin.close();
}

/*************************************************
 * displayResults
 *
 * Iterates through a map of strings->ints and
 * ouputs each key and value.
 *************************************************/
void displayResults(map<string, int> & resultsMap)
{
   for (map<string, int>::iterator it = resultsMap.begin();
        it != resultsMap.end();
        it++)
   {
      cout << setw(25) << it->first << setw(10) << it->second << endl;
   }
}


/************************
 * Function: main
 ************************/
int main()
{
   string file;
   cout << "Enter file: ";
   cin >> file;

   map<string, int> jobMap;

   readFile(file, jobMap);

   cout<< "\nOccupation Results:\n";
   displayResults(jobMap);

   return 0;
}
