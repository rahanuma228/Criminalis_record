#ifndef CASE_H
#define CASE_H
#include<bits/stdc++.h>
#include <Police.h>
#include <Criminal.h>
#include<Victim.h>
using namespace std;

struct date
{
    int d;
    int m;
    int y;
};

class Case
{
public:
    add();
    GetPoliceInfo();
    GetCriminalInfo();
    GetVictimInfo();
    Add_criminal();
    void Remove_criminal();
    void modify_criminal();
    int get_id();
    bool cid_exist(int id);
    void Display();
    void remove_police();
    void change_case_details();
    void modify_case();
    Add_police();
    void file_to_vector();
    static void write(Case c)
    {
        fstream file;
        file.open("Cases.txt",ios::app|ios::binary);
        if(!file)
        {
            cout << "\nCan’t open file\n";
            return;
        }
        file.write((char*)&c,sizeof(Case));
    }
    static int check_cid()
    {
        int exist=0;
        int id,index = -1;
        cout<<"\n\n\t\tEnter Case ID: ";
        cin>>id;
        for(int i=0; i<Casecnt; ++i)
        {
            if(Cases[i].id==id)
            {
                index = i;
                exist=1;
                break;
            }
        }
        if(!exist)
        {
            cout<<"\n\n\tCase does not exist!!!\n";
        }
        return index;
    }
    void static read()
    {
        fstream file;
        file.open("Cases.txt",ios::in|ios::ate|ios::binary);
        if(!file)
        {
            cout << "\nCan’t open file\n";
            return;
        }
        while(!file.eof())
        {
            file.read( (char*)&Cases[Casecnt], sizeof(Case) );
            Casecnt++;
        }
        file.close();
    }

    void removeCase()
    {
        bool yes = false;
        int id;
        cout<<"\n\n\t\tEnter Case ID: ";
        cin>>id;
        for(int i=0; i<Casecnt; ++i)
        {
            if(Cases[i].id==id)
            {
                yes = true;
                for(int j=0; j<Pcnt; ++j)
                {
                    CPolices[j]->remove_case(&Cases[i]);
                }
                Casecnt--;
            }
            if(yes)
            {
                Cases[i]=Cases[i+1];
            }
        }
        if(!yes)
        {
            cout<<"\n\n\tCase does not exist!!!\n";
            return;
        }
    }
    Case();
    static void display_all_cases()
    {
        for(int i=0; i<Casecnt; ++i)
        {
            system("cls");
            Cases[i].Display();
            system("pause");
        }
    }
    Case(int val);

private:
    int id;
    string description;
    string location;
    date Date;
    string PoliceStation;
    string type;
    string status;
    Police* CPolices[1000];
    Victim Victims[1000];
    Criminal* Criminals[1000];
    static Case Cases[];
    static int Casecnt;
    int vcnt;
    int Pcnt;
    int criminalcnt;
};
bool AssignPolice(char pid[], Police* p[], int Pcnt);


#endif // CASE_H
