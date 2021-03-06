//DONE

/*
    get number of cases
    loop through the number of cases
        get the date
        sort out the info and use it Date struct (Howard Cheng's code)
        for loop up to 7 * 40 starting at 0
            add a Day using Date struct  (Howard's Code)
        for loop up to 12 starting at 0   (checking sign)
            if the computed Date is in the sign range
                print the sign and break out of the loop.

*/

#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
#include <cctype>

using namespace std;
using namespace std::rel_ops;

//----------------------------------------------------------------
//Howard Cheng code for date

struct Date {

  int yyyy;
  int mm;
  int dd;

  // no dates before 1753
  static int const BASE_YEAR = 1753;

  // Enumerated type for names of the days of the week
  enum dayName {SUN,MON,TUE,WED,THU,FRI,SAT};

  // Is a date valid
  static bool validDate(int yr, int mon, int day)
  {
    return yr >= BASE_YEAR && mon >= 1 && mon <= 12 &&
      day > 0 && day <= daysIn(mon, yr);
  }

  bool isValid() const
  {
    return validDate(yyyy, mm, dd);
  }

  // Constructor to create a specific date.  If the date is invalid,
  // the behaviour is undefined
  Date(int yr = 1970, int mon = 1, int day = 1)
  {
    yyyy = yr;
    mm = mon;
    dd = day;
  }

  // Returns the day of the week for this
  dayName dayOfWeek() const
  {
    int a = (14 - mm) / 12;
    int y = yyyy - a;
    int m = mm + 12 * a - 2;
    return (dayName)((dd + y + y/4 - y/100 + y/400 + 31 * m / 12) % 7);
  }

  // comparison operators
  bool operator==(const Date &d) const
  {
    return dd == d.dd && mm == d.mm && yyyy == d.yyyy;
  }

  bool operator<(const Date &d) const
  {
    return yyyy < d.yyyy || (yyyy == d.yyyy && mm < d.mm) ||
      (yyyy == d.yyyy && mm == d.mm && dd < d.dd);
  }

  // Returns true if yr is a leap year
  static bool leapYear(int y)
  {
    return (y % 400 ==0 || (y % 4 == 0 && y % 100 != 0));
  }

  // number of days in this month
  static int daysIn(int m, int y)
  {
    switch (m) {
    case 4  :
    case 6  :
    case 9  :
    case 11 :
      return 30;
    case 2  :
      if (leapYear(y)) {
	return 29;
      }
      else {
	return 28;
      }
    default :
      return 31;
    }
  }

  // increment by day, month, or year
  //
  // Use negative argument to decrement
  //
  // If adding a month/year results in a date before BASE_YEAR, the result
  // is undefined.
  //
  // If adding a month/year results in an invalid date (Feb 29 on a non-leap
  // year, Feb 31, Jun 31, etc.), the results are automatically "rounded down"
  // to the last valid date

  // add n days to the date: complexity is about n/30 iterations
  void addDay(int n = 1)
  {
    dd += n;
    while (dd > daysIn(mm,yyyy)) {
      dd -= daysIn(mm,yyyy);
      if (++mm > 12) {
	mm = 1;
	yyyy++;
      }
    }

    while (dd < 1) {
      if (--mm < 1) {
	mm = 12;
	yyyy--;
      }
      dd += daysIn(mm,yyyy);
    }
  }

  // add n months to the date: complexity is about n/12 iterations
  void addMonth(int n = 1)
  {
    mm += n;
    while (mm > 12) {
      mm -= 12;
      yyyy++;
    }

    while (mm < 1)  {
      mm += 12;
      yyyy--;
    }

    if (dd > daysIn(mm,yyyy)) {
      dd = daysIn(mm,yyyy);
    }
  }

  // add n years to the date
  void addYear(int n = 1)
  {
    yyyy += n;
    if (!leapYear(yyyy) && mm == 2 && dd == 29) {
      dd = 28;
    }
  }

  // number of days since 1753/01/01, including the current date
  int daysFromStart() const
  {
    int c = 0;
    Date d(BASE_YEAR, 1, 1);
    Date d2(d);

    d2.addYear(1);
    while (d2 < *this) {
      c += leapYear(d.yyyy) ? 366 : 365;
      d = d2;
      d2.addYear(1);
    }

    d2 = d;
    d2.addMonth(1);
    while (d2 < *this) {
      c += daysIn(d.mm, d.yyyy);
      d = d2;
      d2.addMonth(1);
    }
    while (d <= *this) {
      d.addDay();
      c++;
    }
    return c;
  }
};

// Reads a date in yyyy/mm/dd format, assumes date is valid and in the
// right format
istream& operator>>(istream &is, Date &d)
{
  char c;
  return is >> d.yyyy >> c >> d.mm >> c >> d.dd;
}

// print date in yyyy/mm/dd format
ostream& operator<< (ostream &os, const Date &d) {
  char t = os.fill('0');
  // os << d.yyyy << '/' << setw(2) << d.mm << '/' << setw(2) << d.dd;
  //prints month/day/year
  os << setw(2) << d.mm << '/' << setw(2) << d.dd << '/' << d.yyyy;
  os.fill(t);
  return os;
}
//END Howard Cheng's code
//----------------------------------------------------------------
void solve(Date date);

long long curCase = 1;

//ignore the year, it's not being used.
Date signsRange [12][2] = {
                        {Date(1970, 1, 21), Date(1970, 2, 19)},     // aquarius
                        {Date(1970, 2, 20), Date(1970, 3, 20)},     // pisces
                        {Date(1970, 3, 21), Date(1970, 4, 20)},     // aries
                        {Date(1970, 4, 21), Date(1970, 5, 21)},     // taurus
                        {Date(1970, 5, 22), Date(1970, 6, 21)},     // gemini
                        {Date(1970, 6, 22), Date(1970, 7, 22)},     // cancer
                        {Date(1970, 7, 23), Date(1970, 8, 21)},     // leo
                        {Date(1970, 8, 22), Date(1970, 9, 23)},     // virgo
                        {Date(1970, 9, 24), Date(1970, 10, 23)},    // libra
                        {Date(1970, 10, 24), Date(1970, 11, 22)},   // scorpio
                        {Date(1970, 11, 23), Date(1970, 12, 22)},   // sagittarius
                        {Date(1970, 12, 23), Date(1970, 1, 20)}    // capricorn
                     };
string signs [] = {"aquarius","pisces","aries","taurus","gemini","cancer",
                   "leo","virgo","libra","scorpio","sagittarius","capricorn"};

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        string curDate;
        cin >> curDate;
        Date date;
        date.mm = stoi(curDate.substr(0, 2));
        date.dd = stoi(curDate.substr(2, 2));
        date.yyyy = stoi(curDate.substr(4, 4));
        solve(date);
    }
}

void solve(Date date)
{
    for(int i = 0; i < 7 * 40; i++)
    {
        date.addDay();
    }
    cout << curCase++ << " " << date << " ";
    for(int i = 0; i < 12; i++)
    {
        if(
           (date.dd >= signsRange[i][0].dd && date.mm == signsRange[i][0].mm) ||
           (date.dd <= signsRange[i][1].dd && date.mm == signsRange[i][1].mm)
          )
        {
            cout << signs[i] << endl;
            break;
        }
    }
}
