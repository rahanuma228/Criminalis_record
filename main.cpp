#include <bits/stdc++.h>
#include<Case.h>
#include<Admin.h>
#include<timer.h>
using namespace std;


void PoliceMenu()
{
    int input;
    Police p;
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t\t";
    cout << " 1.  ADD NEW POLICE INFORMATION\n\n";
    cout << "\t\t\t\t";
    cout << " 2.  REMOVE POLICE INFORMATION\n\n";
    cout << "\t\t\t\t" ;
    cout << " 3.  MODIFY POLICE INFORMATION\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 4.  SEARCH POLICE INFORMATION\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 5.  LIST ALL POLICE INFORMATION\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 6. RETURN\n\n" ;
    cout << "\t\t\t\t" ;

    cout << "Choose Option:[1/2/3/4/5/6] : ";
    fflush(stdin);
    cin >> input;
    switch(input)
    {
    case 1:
    {
        p.add();
        break;
    }
    case 2 :
    {
        p.remove();
        break;
    }
    case 3 :
    {
        p.modify();
        break;
    }
    case 4 :
    {
        p.display_information();
        break;
    }
    case 5 :
    {
        p.list_all();
        break;
    }
    case 6:
    {
        return;
        //system("pause");
        //  callExit();
    }
    break;

    default:
    {
        cout << "\n\n\n" ;
        cout << "\t\t\t\t" ;
        cout << "      Invalid input!" ;
        cout << "\n\n" ;
        cout << "\t\t\t\t" ;
        fflush(stdin);
        getchar();
        PoliceMenu();
    }
    }
}
void AdminMenu(Admin* CurrentUser)
{
    int input;
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t\t";
    cout << " 1.  ADD NEW ADMIN\n\n";
    cout << "\t\t\t\t";
    cout << " 2.  MODIFY MY USER INFO\n\n";
    cout << "\t\t\t\t" ;
    cout << " 3.  RETURN\n\n" ;
    cout << "\t\t\t\t" ;
    cout << "Choose Option:[1/2/3] : ";
    fflush(stdin);
    cin >> input;
    switch(input)
    {
    case 1:
    {
        Padmin b;
        int n;
        system("cls");
        cout<<"\t\t\t\t TYPE OF ADMIN:\n\n\t\t\t\t 1.DATABASE ADMIN\n\n\t\t\t\t 2.POLICE ADMIN\n\n";
        cout << "\t\t\t\tChoose Option:[1/2] : ";
        cin>>n;
        if(n==1)
        {
            Dadmin a;
            a.Admin::Create_Admin();
            a.Create_Admin();
        }
        else
            b.Create_Admin();
        break;
    }
    case 2 :
    {
        CurrentUser->Modify_Admin();
        break;
    }
    case 3:
    {
        return;
    }
    break;

    default:
    {
        cout << "\n\n\n" ;
        cout << "\t\t\t\t" ;
        cout << "      Invalid input!" ;
        cout << "\n\n" ;
        cout << "\t\t\t\t" ;
        fflush(stdin);
        getchar();
        AdminMenu(CurrentUser);
    }
    }
}
void DatabaseAdmin_menu(Admin* CurrentUser)
{
    int input;
    while(true)
    {
        system("cls");
        cout << "\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t    ----------------------------------\n";
        cout << "\t\t\t\t    |POLICE STATION MANAGEMENT SYSTEM|\n";
        cout << "\t\t\t\t    ----------------------------------\n";
        cout << "\n\n\n\n";
        cout << "\t\t\t\t";
        cout << " 1.  POLICE INFORMATION\n\n";
        cout << "\t\t\t\t";
        cout << " 2.  ADMIN INFORMATION\n\n";
        cout << "\t\t\t\t" ;
        cout << " 3.  LOGOUT\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 4.  EXIT\n\n" ;
        cout << "\t\t\t\t" ;
        cout << "Choose Option:[1/2/3/4] : ";
        fflush(stdin);
        cin >> input;
        switch(input)
        {
        case 1:
        {
            PoliceMenu();
            //  cout<<"                    POLICE              \n";
            break;
        }
        case 2 :
        {
            AdminMenu(CurrentUser);
            // cout<<"                    ADMIN             \n";
            break;
        }
        case 3:
        {
            Admin a;
            a.login();
        }
        case 4:
        {
            callExit();
            break;
        }


        default:
        {
            cout << "\n\n\n" ;
            cout << "\t\t\t\t" ;
            cout << "      Invalid input!" ;
            cout << "\n\n" ;
            cout << "\t\t\t\t" ;
            fflush(stdin);
            getchar();
            DatabaseAdmin_menu(CurrentUser);
        }
        }
    }
}
void Case_menu(Admin *a)
{
    int input;
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";
    cout << " 1.  CREATE CASE\n\n";
    cout << "\t\t\t\t";
    cout << " 2.  REMOVE CASE\n" ;
    cout << "\t\t\t\t" ;
    cout << " 3.  MODIFY CASE\n\n" ;
    cout << "\t\t\t\t";
    cout << " 4.  MY CASES\n" ;
    cout << "\t\t\t\t" ;
    cout << " 5.  RETURN TO MAIN MENU\n\n" ;
    cout << "\t\t\t\t" ;
    cout << "Choose Option:[1/2/3/4/5] : " ;
    fflush(stdin);
    cin >> input;
    switch(input)
    {
    case 1:
    {
        Case c;
        c.add();
        break;
    }
    case 2 :
    {
        Case c;
        c.removeCase();
        break;
    }
    case 3:
    {
        Case c;
        c.modify_case();
        break;
    }

    case 4:
    {
        a->show_cases();
        break;
    }
    case 5:
        return;

    default:
    {
        cout << "\n\n\n" ;
        cout << "\t\t\t\t" ;
        cout << "      Invalid input!" ;
        cout << "\n\n" ;
        cout << "\t\t\t\t" ;
        fflush(stdin);
        getchar();
        Case_menu(a);
    }
    }
}

void PoliceUser_menu(Admin* a)
{
    int input;
    while(true)
    {
        system("cls");
        cout << "\n\n\n";
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t    -------------------\n";
        cout << "\t\t\t\t    |CRIMINALIS RECORD|\n";
        cout << "\t\t\t\t    -------------------\n";
        cout << "\n\n\n\n";
        cout << "\t\t\t\t";
        cout << " 1.  CASE INFORMATION\n\n";
        cout << "\t\t\t\t";
        cout << " 2.  SEARCH CRIMINAL\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 3.  ALL CRIMINAL INFORMATION\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 4.  OVERALL CRIME STATISTICS\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 5.  CRIME STATISTICS\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 6.  DIVISIONWISE CRIME STATISTICS\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 7.  GRAPHICAL REPRESENTATION OF OCCURENCE OF CRIME\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 8.  GRAPHICAL REPRESENTATION OF DIVISIONWISE CRIME OCCURENCE\n\n" ;
        cout << "\t\t\t\t" ;
        cout << " 9. EXIT\n\n" ;
        cout << "\t\t\t\t" ;
        cout << "Choose Option:[1/2/3/4/5/6/7] : " ;
        fflush(stdin);
        cin >> input;
        switch(input)
        {
        case 1:
        {
            Case_menu(a);
            break;
        }
        case 2 :
        {
            Criminal *c;
            c->display();
            break;
        }
        case 3:
        {
            Criminal *c;
            c->list_all();
            break;
        }
        case 4:
        {
            Criminal *c;
            c->show_Overall_statistics();
            break;
        }
        case 5:
        {
            Criminal *c;
            c->show_crime_statistics();
            break;
        }
        case 6:
        {
            Criminal *c;
            c->show_division_statistics();
            break;
        }
        case 7:
        {
            Criminal *c;
            c->crime_pie();
            break;
        }
        case 8:
        {
            Criminal *c;
            c->div_pie();
            break;
        }
        case 9:
        {
            callExit();
            break;
        }

        default:
        {
            cout << "\n\n\n" ;
            cout << "\t\t\t\t" ;
            cout << "      Invalid input!" ;
            cout << "\n\n" ;
            cout << "\t\t\t\t" ;
            fflush(stdin);
            getchar();
            PoliceUser_menu(a);
        }
        }
    }
}

void mainpage()
{
    int process=0;
    system("cls");
    date1();
    cout << "\n";
    cout <<"\t\t\t\t    -------------------\n";
    cout <<"\t\t\t\t    |CRIMINALIS RECORD|\n";
    cout <<"\t\t\t\t    -------------------\n";
    cout <<"\n\n";
    cout <<"\t\t\t\t";
    cout <<"\n\n";
    cout <<"\t\t\t\t";
    cout <<"\n\n";
    cout <<"\n\n";
    cout <<"\t\t\t\t";
    system("pause");
    cout <<"\n\t\t\t\tLoading";

    for(process=0; process<25; process++)
    {
        delay(150);
        cout <<".";
    }
}

int main()
{
    ///////////////////////////////////////////
    Dadmin defaultuser("hlw","pass");
    defaultuser.Create_Admin();
    Dadmin a("test","pass");
    a.Create_Admin();
    Admin* CurrentUser;
    system("cls");
    mainpage();
    int x,res=1;
    a.login();
  //  p.check();
  //  res = defaultuser.login();
}
