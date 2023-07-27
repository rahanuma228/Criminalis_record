#ifndef VICTIM_H
#define VICTIM_H

#include <Person.h>

class Victim
{
protected:
    char victim_id[10];
    char name[200];
    int day;
    int month;
    int year;
    string division;
    string district;
    string area;
    string gender;
    string nid;
    string occupation;
    int post_code;
    string crime;
    string crimeplace;
    int crimeday;
    int crimemonth;
    int crimeyear;
    int crime_age;
    string station;
    string fir_no;
    static Victim victims[];

public:
    void get_Personal_Info();
    void get_CrimeInfo();
    void get_PoliceInfo();
    void get_data();
    void add();
    int check_id(char id[]);
    void output() ;
    void display();
    void modify();
    void delete_record(char str[]);
    void remove();
    void list_all();

};

#endif // VICTIM_H
