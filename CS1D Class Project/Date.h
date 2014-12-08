/*
 * date.h
 *
 *  Created on: Dec 7, 2014
 *      Author: Bryan
 */

#ifndef date_H_
#define date_H_

#include <string>
#include <iostream>

using namespace std;

//Enumerated type representing the months of the year
enum Month {
   JAN = 0,
   FEB,
   MAR,
   APR,
   MAY,
   JUN,
   JUL,
   AUG,
   SEP,
   OCT,
   NOV,
   DEC
};

class date {
private:
   int day;            //IN&OUT - represents the numbered day of the month
   Month month;        //IN&OUT - represents the month of the year
   int year;           //IN&OUT - represents a numbered year

   //Private Method that verifies if the day, month, and year passed in
   //  is a valid date.
   void verifyDate(int day, Month month, int year) const;

   //Private Method that determines if the year passed in
   //  is a LeapYear
   bool isLeapYear(int year)const;

public:

   //Exception Class; thrown when an invalid date is found
   class Invaliddate{};

   //Default Constructor
   date();

   date(int day, Month month, int year);
   	   //non defalust constructor
   	   //sets data fields to passed parameters

   //GETTERS
   //Returns the day portion of this date as an integer
   int getDay() const;
   //Returns the month portion of this date as a Month (enumerated type)
   Month getMonth() const;
   //Returns the year portion of this date as an integer
   int getYear() const;

   //SETTERS
   //Attempts to set the day of this date; Throws Invaliddate if data passed in
   //  would create an invalid date.
   void setDay(int day);

   //Attempts to set the Month of this date; Throws Invaliddate if data passed in
   //  would create an invalid date.
   void setMonth(Month month);

   //Attempts to set the day of this date; Throws Invaliddate if data passed in
   //  would create an invalid date.
   void setYear(int year);

   //Attempts to set the day, month and year of this date;
   //Throws Invaliddate if data passed in would create an invalid date.
   void setDate(int day, Month month, int year);


   //OVERRIDDEN OPERATORS

   //Returns true if this date is not exactly the same as the date passed in
   bool operator != (const date& date) const;

   //Returns true if this date is exactly the same as the date passed in
   bool operator == (const date& date) const;

   //Returns true if this date is older than the date passed in
   bool operator < (const date& date) const;

   //Returns true if this date is newer than the date passed in
   bool operator > (const date& date) const;

   //Returns true if this date is older than or the same as the date passed in
   bool operator <= (const date& date) const;

   //Returns true if this date is newer than or the same as the date passed in
   bool operator >= (const date& date) const;

   //Allows one to use the insertion operator to print out this date
   friend ostream& operator << (ostream&, const date& date);

   //Creates and returns a string representing this date.  It takes the form of
   //  MM/dd/YYYY
   string toString() const;

   //Prints to screen a string representation of this date taking the form
   // MM/dd/YYYY
   void print() const;

};



#endif /* date_H_ */
