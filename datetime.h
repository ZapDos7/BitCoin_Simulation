#ifndef _DT_H_
#define _DT_H_

#include <stdio.h>
#include <stdlib.h>

class date
{
private:
    int day;
    int month;
    int year;
public:
    date(int d, int m, int y);
    ~date();;
    int get_day();
    int get_month();
    int get_year();
    void set_day(int d);
    void set_month(int m);
    void set_year(int y);
    void print_date();
};
date is_laterD(date dt1, date dt2);

class time
{
private:
    int hours;
    int minutes;
public:
    time(int h, int m);
    ~time();
    int get_hours();
    int get_minutes();
    void set_hours(int h);
    void set_minutes(int m);
    void print_time();
};
time is_laterT(time t1, time t2);

class datetime
{
private:
    date* dt;
    time* tm;
public:
    datetime(int d, int mo, int y, int h, int mi);
    ~datetime();
    void set_dt(int d, int m, int y);
    void set_tm(int h, int m);
    date get_date();
    time get_time();
    datetime is_later(datetime dt1, datetime dt2);
    void print_dt();
};

#endif