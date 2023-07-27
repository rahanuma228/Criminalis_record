
#include <Person.h>
//#include<timer.h>
#include<bits/stdc++.h>
using namespace std;

class Criminal:public Person
{
protected:
   char convict_id[10];
    char gender[200];
    char nid[200];
    int post_code;
    char blood_type[200];
    char complexion[200];
    char face[200];
    char imark[100];
    char height[100];
    char eye_color[100];
    char ethnicity[100];
    char hair_color[100];
    char weight[100];
    char crime[100];
    char crimeplace[100];
    int crimeday;
    int crimemonth;
    int crimeyear;
    int crime_age;
    char crimediv[100];
    char crimedis[100];
    char crimearea[100];
    int crime_pcode;
    char station[100];
    char fir_no[100];
    char arrest_warrant[100];
    char arrest_date[100];
    static Criminal criminals[];
public:
    void modify(char v[]);
    bool match_id(char v[]);
    void get_Personal_Info();
    void get_Description();
    void get_CrimeInfo();
    void get_PoliceInfo();
    void add(Criminal* Case_criminal[], int n);
    int check_id(char id[]);
    int duplicate_check(char id[]);
    void output() ;
    void display();
    void delete_record(char str[]);
    void remove();
    void list_all();
    void show_division_statistics();
    void show_crime_statistics();
    void show_Overall_statistics();
    void div_pie();
    void crime_pie();
    void get_data();
};
