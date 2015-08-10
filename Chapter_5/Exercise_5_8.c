/*Exercise 5-8. There is no error checking in day_of_year or month_day . Remedy this defect.*/

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
 int day_of_year( int year,  int month,  int day);
int month_day( int year,  int yearday,  int *pmonth,  int *pday);
char *month_name(int n);

int main()
{
     int year, month, day, yearday, result;
    printf("\nEnter year : ");
    scanf("%d", &year);
    printf("\nEnter day of year : ");
    scanf("%d", &yearday);
    result = month_day(year, yearday, &month, &day);
    if(result == -1)
    {
	    printf("\nCheck your input.\n");
	    return -1;
    }
    printf("\n%dth day in year %d is%s%dth.\n", yearday, year, month_name(month), day);

    printf("\nEnter year: ");
    scanf("%d", &year);
    printf("\nEnter month: ");
    scanf("%d", &month);
    printf("\nEnter day:");
    scanf("%d", &day);
    result =  day_of_year(year, month, day);
    if(result == -1)
    {
	    printf("\nCheck your input.\n");
	    return -1;
    }
    printf("\n%dth%sin year %d is %dth day in year %d.\n\n", day, month_name(month),\
		    year, result, year);


    return 0;
}

/* day_of_year: set day of year from month & day */
 int day_of_year( int year,  int month,  int day)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if(year < 0)
	    return -1;
    if(month < 1 && month > 13)
	    return -1;
    if(day > daytab[leap][month])
	    return -1;  

    for (i = 1; i < month; i++)
	day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
int month_day( int year,  int yearday,  int *pmonth,  int *pday)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if(year < 0)
	    return -1;
    for (i = 1; yearday > daytab[leap][i]; i++)
	yearday -= daytab[leap][i];
    if(i < 1)
	    return -1;
    *pmonth = i;
    *pday = yearday;
    return 0;
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[] = {
	" Illegal month ",
	" January ", " February ", " March ",
	" April ", " May ", " June ",
	" July ", " August ", " September ",
	" October ", " November ", " December "
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}
