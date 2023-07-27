#ifndef PERSON_H
#define PERSON_H
#include<timer.h>
#include<bits/stdc++.h>
using namespace std;
class Person
{
protected:
    char id[10];
    char name[200];
    int age;
    int day;
    int month;
    int year;
    char gender[100];
    char division[100];
    char district[100];
    char area[100];
public:
    virtual void remove()=0;
    virtual void get_data();
    virtual void get_address();
    virtual void display_information();
    virtual void display_address();
};




#endif // PERSON_H
