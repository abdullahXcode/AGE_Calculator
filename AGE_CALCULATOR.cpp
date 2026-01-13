#include <iostream>

using namespace std;


void input_current_date(int &cDay, int &cMonth, int &cYear)
{
    cout << "Enter current date in dd:mm:yy format    : " << endl;
    cin >> cDay >> cMonth >> cYear;
}

void input_DOB(int &day, int &month, int &year)
{
   
    cout << "Enter date of birth dd:mm:yy format     : " << endl;
    cin >> day >> month >> year;  
}

bool is_leap_year(int year)
{
    if(year % 400)
    {
        return true;
    }
    else if(year % 100)
    {
        return false;
    }
    else if(year % 4)
    {
        return true;
    }
    else{
        return false;
    }
}

void days_in_a_month(int month, int year)
{
    if(month == 1 or month == 3 or month == 5 or
       month == 7 or month == 8 or month == 10 or month == 12)
    {
        return 31;
    }
    else if(month == 4 or month == 6 or month == 9 or month == 11)
    {
        return 30;
    }
    else if(month == 2)
    {
        if(is_leap_year(year))
        {
            return 29;
        }
        else{
            return 28;
        }
    }
}

bool is_valid_date(int day, int month, int year)
{
    if(year < 1 or year > 2025)
    {
        return false;
    }
    else if(month < 1 or month > 12)
    {
        return false;
    }
    else if(day < 1 or day > days_in_a_month(month, year))
    {
        return false;
    }
    return true;
}



bool is_valid_input_date(int dayOfBirth, int monthOfBirth, int yearOfBirth, int currentDay, int currentMonth, int currentYear)
{
    if(is_valid_date(dayOfBirth, monthOfBirth, yearOfBirth) == false )
    {
        return false;
    }
    if(is_valid_date(currentDay, currentMonth, currentMonth) == false )
    {
        return false;
    }

    if(currentYear < yearOfBirth)
    {
        return false;
    }
    else if(currentYear == yearOfBirth)
    {
        if(currentMonth < monthOfBirth)
        {
            return false;
        }
        else if(currentMonth == monthOfBirth)
        {
            if(currentDay < dayOfBirth)
            {
                return false;
            } // equal days ?
            else{
                return true;
            }
        }
        else{
            return true;
        }
    }
    else{
        return true;
    }

}

void age_calculator(int dayOfBirth, int monthOfBirth, int yearOfBirth, int currentDay, int currentMonth, int currentYear)
{
    if(is_valid_input_date(dayOfBirth, monthOfBirth, yearOfBirth, currentDay, currentMonth, currentYear) == false )
    {
        cout << "ERROR: Invalid dates entered......" << endl;
        return ;
    }

    int years = currentYear - yearOfBirth;
    int months = currentMonth - monthOfBirth;
    int days = currentDay - dayOfBirth;

    if(days < 0)
    {
        months--;
        int pMonth = currentMonth - 1;
        int pYear = currentYear ;
        days = currentDay + days_in_a_month(pMonth, pYear) - dayOfBirth;
    }
    if(months < 0)
    {
        years--;
        months += 12;
    }
    cout << "Age: " << years << " years, " << months << " months, " << days << " days......." << endl;

    int d = dayOfBirth, m = monthOfBirth, y = yearOfBirth;
    int totalDays = 0;
    while (d != currentDay || m != currentMonth || y != currentYear)
    {
        d++;
        if (d > days_in_a_month(m, y)) 
        {
            d = 1; 
            m++;
            if (m > 12) 
            { 
                m = 1; 
                y++; 
            }
        }
        totalDays++;
    }
    cout << "Total no of days from DOB to Current date   : " << totalDays << endl;
}



int main() 
{
    int day, month, year;
    int cDay, cMonth, cYear;

    input_DOB(day, month, year);
    is_leap_year(year);
    input_current_date(cDay, cMonth, cYear);
    age_calculator(day, month, year, cDay, cMonth, cYear);

    return 0;
}
