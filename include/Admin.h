#ifndef ADMIN_H
#define ADMIN_H
#include<Police.h>
//#include<Case.h>
#include<timer.h>
#include<bits/stdc++.h>
using namespace std;
void callExit();
bool AssignPolice(char pid[], Police* p[], int Pcnt);
enum Admin_type {DatabaseAdmin, PoliceAdmin};

class Admin
{
public:
    // int id;
    string username;
    string pass;
    static Admin* Admins[];
    static int admincnt;

public:
    Admin();
    Admin(string user, string _pass);
    // virtual ~Admin();
    virtual void Create_Admin();

    Admin_type get_type();
    virtual void set_police(Police *pl)
     {

     }
    void Modify_Admin();
    int login();
    virtual void show_cases()
    {

    }


};

class Dadmin: public Admin
{
public:
    Dadmin();
    Dadmin(string user, string _pass);
    Create_Police_account();
    Modify_Police_account();
    void Create_Admin();
};

class Padmin: public Admin
{
private:
      Police *p;
public:
    void Create_Admin();
    void set_police(Police *pl)
    {
        p = pl;
    }
    void show_cases()
    {
        p->show_cases();
    }

};

#endif // ADMIN_H








