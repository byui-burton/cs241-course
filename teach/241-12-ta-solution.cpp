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

void readFile(string file)
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
    
      cout << "The occupation was: " << record.occupation << endl;
   }

   fin.close();
}

/************************
 * Function: main
 ************************/
int main()
{
   string file;
   cout << "Enter file: ";
   cin >> file;

   readFile(file);

   return 0;
}
