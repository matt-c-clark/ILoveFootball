#include "date.h"
#include <sstream>

using namespace std;

//Constructor for date Class; Verifies entered date is valid or throws
//  Invaliddate.

date::date(int day, Month month, int year) {

   verifyDate(day, month, year);

   this->day = day;
   this->month = month;
   this->year = year;
}

date::date() {

   this->day = 1;
   this->month = JAN;
   this->year = 1970;
}

//GETTERS

//Returns an integer representing the day portion of the date

int date::getDay() const {
   return day;
}

//Returns a Month (enumerated type) representing the month portion of the date

Month date::getMonth() const {
   return month;
}

//returns an integer representing the year portion of the date

int date::getYear() const {
   return year;
}


//SETTERS


//Attempts to set the day of this date; Throws Invaliddate if data passed in
//  would create an invalid date.

void date::setDay(int day) {

   verifyDate(day, this->month, this->year);

   this->day = day;
}

void date::setMonth(Month month) {

   verifyDate(this->day, month, this->year);

   this->month = month;
}

void date::setYear(int year) {

   verifyDate(this->day, this->month, year);

   this->year = year;
}

//stes the date to the passed parameters
void date::setDate(int day, Month month, int year) {

   verifyDate(day, month, year);

   this->day = day;
   this->month = month;
   this->year = year;
}

//string that contains the info of the class
string date::toString() const {

   ostringstream stream;

   if ((month) < 9) {
       stream << "0";
   }
   stream << (month + 1) << "/";
   if (day <= 9) {
       stream << "0";
   }
   stream << day << "/" << year;

   return stream.str();


}

//output the toString of the date class to the console
void date::print() const {
   cout << toString();
}

//checks if the year is a leap year
bool date::isLeapYear(int year) const {

   if (year % 4 != 0) {
       return false;
   } else {
       if (year % 100 == 0) {

           if (year % 400 == 0) {
               return true;
           } else {
               return false;
           }
       } else {
           return true;
       }
   }

}

//checks to make sure the date is valid
void date::verifyDate(int day, Month month, int year) const {

   int maxDays;

   //checks witch month it is
   switch (month) {
       case JAN:
       case MAR:
       case MAY:
       case JUL:
       case AUG:
       case OCT:
       case DEC: maxDays = 31;
           break;
       case APR:
       case JUN:
       case SEP:
       case NOV: maxDays = 30;
           break;
       case FEB: if (isLeapYear(year)) {
               maxDays = 29;
           } else {
               maxDays = 28;
           }
           break;
   }

   if (day < 1 || (day > maxDays)) {
       throw Invaliddate();
   }
}

//Returns true if this date is not exactly the same as the date passed in

bool date::operator !=(const date& date) const {

   if (this->year == date.year &&
           this->month == date.month &&
           this->day == date.day) {
       return false;
   } else {
       return true;
   }
}

bool date::operator ==(const date& date) const {

   if (this->year == date.year &&
           this->month == date.month &&
           this->day == date.day) {
       return true;
   } else {
       return false;
   }
}

bool date::operator<(const date& date) const {

   int dDay = date.getDay();
   Month dMonth = date.getMonth();
   int dYear = date.getYear();

   //COMPARE YEARS:

   //If this date's year is less than the year of the date passed in, then
   //  return true.
   if (this->year < dYear) {
       return true;
   }
   //If this date's year is equal to the year of the date passed in, then
   //  compare months.
   else if (this->year == dYear) {

       //COMPARE MONTHS:

       //If this date's month is less than the month of the date passed in, return
       //  true.
       if (this->month < dMonth) {
           return true;
       }
       //If this date's month is equal to the month of the date passed in,
       //  compare days.
       else if (this->month == dMonth) {

           //COMPARE DAYS:

           //If this date's day is less than the day of the date passed in,
           //  return true.
           if(this->day < dDay){
               return true;
           }
           //This date is greater-than or equal-to the date passed in,
           //  so return false.
           else {
               return false;
           }

       } else {

           //This date's year is equal to the year of the date passed in,
           //  but this date's month is greater than the month of the
           //  date passed in.  As such, this date is NOT less than the
           //  date passed in.  Return false.
           return false;
       }
   }
   //This date's year is greater than the year of the date passed in,
   //  therefore this date is NOT less than the date passed in.  Return
   //  false.
   else {
       return false;
   }
}

bool date::operator>(const date& date) const {

   int dDay = date.getDay();
   Month dMonth = date.getMonth();
   int dYear = date.getYear();

   //COMPARE YEARS:

   //If this date's year is greater than the year of the date passed in, then
   //  return true.
   if (this->year > dYear) {
       return true;
   }
   //If this date's year is equal to the year of the date passed in, then
   //  compare months.
   else if (this->year == dYear) {

       //COMPARE MONTHS:

       //If this date's month is greater than the month of the date passed in, return
       //  true.
       if (this->month > dMonth) {
           return true;
       }
       //If this date's month is equal to the month of the date passed in,
       //  compare days.
       else if (this->month == dMonth) {

           //COMPARE DAYS:

           //If this date's day is greater than the day of the date passed in,
           //  return true.
           if(this->day > dDay){
               return true;
           }
           //This date is greater-than or equal-to the date passed in,
           //  so return false.
           else {
               return false;
           }

       } else {

           //This date's year is equal to the year of the date passed in,
           //  but this date's month is less than the month of the
           //  date passed in.  As such, this date is NOT greater than the
           //  date passed in.  Return false.
           return false;
       }
   }
   //This date's year is less than the year of the date passed in,
   //  therefore this date is NOT greater than the date passed in.  Return
   //  false.
   else {
       return false;
   }
}

bool date::operator <=(const date& date) const {


   if (*this == date || *this < date) {
       return true;
   } else {
       return false;
   }
}

bool date::operator >=(const date& date) const {

   if (*this == date || *this > date) {
       return true;
   } else {
       return false;
   }
}

ostream& operator <<(ostream& osObject, const date& date) {
   osObject << date.toString();

   return osObject;
}
