#include <iostream>
using namespace std;

void input_current_date(int &cDay, int &cMonth, int &cYear)
{
    char sep;
    cout << "Enter current date in dd:mm:yy format    : ";
    cin >> cDay >> sep >> cMonth >> sep >> cYear;
}

void input_DOB(int &day, int &month, int &year)
{
    char sep;
    cout << "Enter date of birth in dd:mm:yy format     : ";
    cin >> day >> sep >> month >> sep >> year;  
}

bool is_leap_year(int year)
{
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year % 4 == 0)
        return true;
    else
        return false;
}

int days_in_a_month(int month, int year)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if(month == 2)
        return is_leap_year(year) ? 29 : 28;
    return 0;
}

bool is_valid_date(int day, int month, int year)
{
    if(year < 1 || year > 2026) return false;
    if(month < 1 || month > 12) return false;
    if(day < 1 || day > days_in_a_month(month, year)) return false;
    return true;
}

bool is_valid_input_date(int dayOfBirth, int monthOfBirth, int yearOfBirth, int currentDay, int currentMonth, int currentYear)
{
    if(!is_valid_date(dayOfBirth, monthOfBirth, yearOfBirth)) return false;
    if(!is_valid_date(currentDay, currentMonth, currentYear)) return false;

    if(currentYear < yearOfBirth) return false;
    else if(currentYear == yearOfBirth)
    {
        if(currentMonth < monthOfBirth) return false;
        else if(currentMonth == monthOfBirth)
        {
            if(currentDay < dayOfBirth) return false;
        }
    }
    return true;
}

void age_calculator(int dayOfBirth, int monthOfBirth, int yearOfBirth, int currentDay, int currentMonth, int currentYear)
{
    if(!is_valid_input_date(dayOfBirth, monthOfBirth, yearOfBirth, currentDay, currentMonth, currentYear))
    {
        cout << "ERROR: Invalid dates entered......" << endl;
        return;
    }

    int years = currentYear - yearOfBirth;
    int months = currentMonth - monthOfBirth;
    int days = currentDay - dayOfBirth;

    if(days < 0)
    {
        months--;
        int pMonth = currentMonth - 1;
        int pYear = currentYear;
        if(pMonth == 0) { pMonth = 12; pYear--; }
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
    input_current_date(cDay, cMonth, cYear);
    age_calculator(day, month, year, cDay, cMonth, cYear);

    return 0;
}
