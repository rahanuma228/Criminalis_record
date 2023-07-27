#include "Admin.h"

void PoliceMenu();
void AdminMenu(Admin* CurrentUser);
void DatabaseAdmin_menu(Admin* CurrentUser);
void Case_menu(Admin *a);
void PoliceUser_menu(Admin* a);

Admin::Admin()
{

}

Admin::Admin(string user, string _pass):username(user),pass(_pass)
{

}


void Admin::Create_Admin()
{
    cout<<"Enter Username:  ";
    cin>>this->username;
    cout<<"Enter Password:  ";
    cin>>this->pass;
}

Admin* Admin::Admins[10000];
int Admin::admincnt = 0;
Dadmin::Dadmin()
{

}
Dadmin::Dadmin(string user, string _pass):Admin(user,_pass)
{

}
void Dadmin::Create_Admin()
{

    Admins[admincnt] = new Dadmin;
    Admins[admincnt]->username = this->username;
    Admins[admincnt]->pass = this->pass;
    admincnt++;
    system("cls");
    system("pause");
}



void Padmin::Create_Admin()
{
    Admin::Create_Admin();
    char id[30];
    do
    {
        cout<<"\n\n\tEnter Police ID:  ";
        cin>>id;
    }
    while(!AssignPolice(id,&p,0));
    Admins[admincnt] = new Padmin;
    Admins[admincnt]->username = this->username;
    Admins[admincnt]->pass = this->pass;

    Admins[admincnt]->set_police(p);
     admincnt++;
}
Admin_type Admin::get_type()
{
    if( typeid(*this) == typeid(Dadmin) )
        return DatabaseAdmin;
    else if( typeid(*this)==typeid(Padmin) )
        return PoliceAdmin;
    else
    {
        cerr << "\nBad employee type";
        exit(1);
    }
}
void Admin::Modify_Admin()
{
    string user,pass,olduser,oldpass;
    olduser = this->username;
    oldpass = this->pass;
    system("cls");

    cout<<this->username<<"             "<<this->pass;
    system("pause");
    cout<<"Enter Username:  ";
    cin>>user;
    cout<<"Enter Password:  ";
    cin>>pass;
    if(user == this->username && pass == this->pass)
    {
        char ch;
        cout<<"Do you want to change username?(Y/N)";
        do
        {
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                cout<<"Enter New Username:  ";
                cin>>user;
                cout<<"Enter New Password:   ";
                cin>>pass;
                this->username=user;
                this->pass= pass;
            }
            else
            {
                if((ch!='n')&&(ch!='N'))
                {
                    cout<<"\n\n\t\t\tENTER CORRECTLY \n\n\t\t\t TRY AGAIN !!\n\n";
                }
            }
        }
        while((ch!='y') && (ch!='Y') && (ch!='n') && (ch!='N'));
    }
    else
    {
        cout<<"Invalid Username or Password!!!!\n\n";
        return;
    }

}
int Admin::login()
{
    string username;
    string password;
    int true1 = 1;
    int try1 = 0;
    int i=0;
    do
    {
        system("cls");
        cout << "\n\n\n\n\n\n";
        cout <<"\t\t\t\t    ----------------------------------\n";
        cout <<"\t\t\t\t    |POLICE STATION MANAGEMENT SYSTEM|\n";
        cout <<"\t\t\t\t    ----------------------------------\n";
        cout <<"\n\n";
        cout << "\t\t\t\t\t";
        cout << "Username : ";
        cin >> username;
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "Password : ";
        cin >> password;
        bool yes=false;
        for(int i=0; i<admincnt; ++i)
        {
            if(Admins[i]->username==username &&  Admins[i]->pass == password)

            {
                yes = true;
                cout << "\n\n";
                cout << "\t\t\t\t";
                cout << "You are accessed to the system!\n\n";
                cout << "\t\t\t\t";
                system("pause");
                system("cls");
                true1 = 0;
                if( typeid(*Admins[i]) == typeid(Dadmin) )
                {

                    DatabaseAdmin_menu(Admins[i]);
                }
                else if( typeid(*Admins[i])==typeid(Padmin) )
                    PoliceUser_menu(Admins[i]);
                return 1;
            }
        }

        if(!yes)
        {
            system("cls");
            try1 = try1+1;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << 3-try1;
            cout << "\n\n";
            cout << "\t\t\t\t";
            system("pause");
            if(try1>=3)
            {

                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!\n\n";
                cout << "\t\t\t\t";
                system("pause");
                  callExit();
            }

        }

    }
    while(try1<3);
}
