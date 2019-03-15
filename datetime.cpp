#include "datetime.h"


date::date(int d, int m, int y) {
    if ((m<0)||(m>12)) {
        fprintf(stderr, "Invalid month\n");
        exit(1);
    }
    if ((d<0)||(d>31)) {
        fprintf(stderr, "Invalid day\n");
        exit(1);
    }
    if ((m==2)&&(y%4==0)&&(d>29)) { //leap yeared feb
        fprintf(stderr, "Invalid date format\n");
        exit(1);
    }
    if (((m==4)||(m==6)||(m==9)||(m==11))&&(d>30)) { //30 day-d months
        fprintf(stderr, "Invalid date format\n");
        exit(1);
    }
    this->day = d;
    this->month = m;
    this->year = y;
}
date::~date() {}
int date::get_day() {
    return this->day;
}
int date::get_month() {
    return this->month;
}
int date::get_year() {
    return this->year;
}
void date::set_day(int d) {
    if ((d<0)||(d>31)) {
        fprintf(stderr, "Invalid day\n");
        exit(1);
    }
    else {
        this->day = d;
    }    
    return;
}
void date::set_month(int m) {
    if ((m<0)||(m>12)) {
        fprintf(stderr, "Invalid month\n");
        exit(1);
    }
    else {
        this->month = m;
    } 
    return;
}
void date::set_year(int y) {
    this->year = y;
    return;
}
void date::print_date() {
    fprintf(stdout, "Date is:%d-%d-%d\n",this->get_day(), this->get_month(), this->get_year());
    return;
}
date is_laterD(date dt1, date dt2) {
    if ((dt1.get_year() > dt2.get_year())) {
        return dt1;//2019 > 2017
    }
    else if (dt1.get_year()==dt2.get_year() && (dt1.get_month() > dt2.get_month())) {
        return dt1;//sept 2019 > jan 2019
    }
    else if (dt1.get_year()==dt2.get_year() && (dt1.get_month() == dt2.get_month()) && (dt1.get_day() > dt2.get_day())) {
        return dt1;//2-1-2019 > 1-1-2019
    }
    else {//any other case (also works for dt1 == dt2)
        return dt2;
    }   
}

///
time::time(int h, int m) {
    if ((h<0)||(h>23)) { //00:00 - 23:59
        fprintf(stderr, "Invalid hour\n");
        exit(1);
    }
    if ((m<0)||(m>60)) {
        fprintf(stderr, "Invalid minute\n");
        exit(1);
    }
    //default - all is ok
    this->hours = h;
    this->minutes = m;
    
}
time::~time() {}
int time::get_hours() {
    return this->hours;
}
int time::get_minutes() {
    return this->minutes;
}
void time::set_hours(int h) {
    if ((h<0)||(h>23)) { //00:00 - 23:59
        fprintf(stderr, "Invalid hour\n");
        exit(1);
    }
    else {
        this->hours = h;
    }
    return;
}
void time::set_minutes(int m) {
    if ((m<0)||(m>60)) {
        fprintf(stderr, "Invalid minute\n");
        exit(1);
    }
    else {
        this->minutes = m;
    }
    return;
}
void time::print_time() {
    fprintf(stdout, "Time is:%d-%d\n",this->get_hours(), this->get_minutes());
    return;
}
time is_laterT(time t1, time t2) {
    if (t1.get_hours()>t2.get_hours()) {
        return t1;
    }
    else if ((t1.get_hours()==t2.get_hours())&&(t1.get_minutes()>t2.get_minutes())) {
        return t1;
    }
    else {
        return t2;
    }
}

//datetime
datetime::datetime(int d, int mo, int y, int h, int mi) { 
    //this.dt(d,mo,y);
    this->dt->set_day(d);
    this->dt->set_month(mo);
    this->dt->set_year(y);
    //this->tm(h,mi);
    this->tm->set_hours(h);
    this->tm->set_minutes(mi);
}
datetime::~datetime() {}
void datetime::set_dt(int d, int m, int y) {
    this->dt->set_day(d);
    this->dt->set_month(m);
    this->dt->set_year(y);
}
void datetime::set_tm(int h, int m) {
    this->tm->set_hours(h);
    this->tm->set_minutes(m);

}
date datetime::get_date() {
    return *(this->dt);
}
time datetime::get_time() {
    return *(this->tm);
}
datetime datetime::is_later(datetime dt1, datetime dt2) {
    datetime tmp(0,0,0,0,0);
    time tmp_time(0,0);
    date tmp_date(0,0,0);
    tmp_date = is_laterD(dt1.get_date(), dt2.get_date());
    tmp_time = is_laterT(dt1.get_time(), dt2.get_time());
    tmp.set_dt(tmp_date.get_day(), tmp_date.get_month(), tmp_date.get_year());
    tmp.set_tm(tmp_time.get_hours(), tmp_time.get_minutes());
    return tmp;
}
void datetime::print_dt() {
    this->tm->print_time();
    this->dt->print_date();
    return;
}