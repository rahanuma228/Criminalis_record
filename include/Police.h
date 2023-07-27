#ifndef POLICE_H
#define POLICE_H
#include<timer.h>
#include <Person.h>
#include<bits/stdc++.h>
using namespace std;

class Case;

class Police : public Person
{
private:
    int join_day;
    int join_month;
    int join_year;
    char station[100];
    char _rank[100];
    double salary;
    char nid[100];
    char post_code[100];
    Case* pCases[100];
    int cscnt;
    static Police polices[];
public:

    friend bool AssignPolice(char id[], Police* p[], int i);
    void get_data();
    void set_data(Police p);
    void add();
    void display_information();
    void remove();
    void modify();
    int check_pid(char v[]);
    void display();
    void list_all();
    bool check_Police_id(char id[]);
    void remove_case(Case *c);
    void assignCase(Case *c);
    void file_to_vector();
    int Set_caseCount(int val);
    Police();
    Police(int val);
    void show_cases();
    void Case_Display();
    void check();
};



#endif // POLICE_H
