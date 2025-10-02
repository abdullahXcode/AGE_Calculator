# 📅 Age Calculator (C++)

This is a simple **Age Calculator program in C++**.  
The program takes **Date of Birth (DD-MM-YYYY)** and **Current Date (DD-MM-YYYY)** as input and calculates:

- ✅ Age in **Years, Months, and Days**  
- ✅ Total number of **days lived**  

---

## 🚀 Features
- Checks if a year is **Leap Year**.
- Finds total **days in a month** (handles leap years).
- Validates whether a date is correct or not.
- Ensures **current date is after date of birth**.
- Calculates age using a simple date difference logic.

---

## 📌 Functions Used
The following functions are implemented as per requirements:

1. **`bool is_leap_year(int year)`**  
   → Checks if the given year is a leap year.  

2. **`int days_in_a_month(int month, int year)`**  
   → Returns the number of days in a given month (handles February).  

3. **`bool is_valid_date(int year, int month, int day)`**  
   → Checks if the date is valid (within 1–2025 range).  

4. **`bool is_valid_input_date(int dayOfBirth, int monthOfBirth, int yearOfBirth, int currentDay, int currentMonth, int currentYear)`**  
   → Ensures the current date comes **after** the date of birth.  

5. **`void age_calculator(...)`**  
   → Calculates age in years, months, and days.  
   → Also calculates **total days lived** using a loop.  

---

## 🖥️ How It Works
1. User enters **Date of Birth** and **Current Date**.  
2. Program validates both dates.  
3. If valid:
   - Age is calculated in `Years : Months : Days`.  
   - Total days are also counted by incrementing from DOB to Current Date.  

---

## 📂 Sample Input / Output

### Input:
