#include "Case.h"
#include<Police.h>

Case Case::Cases[1000];
int Case::Casecnt = 0;
Case::Case()
{
    Pcnt = 0;
    criminalcnt=0;
    vcnt = 0;
}
Case::Case(int val)
{
    Pcnt = val;
}

Case::add()
{
    cout<<"\n\t\tEnter ID: \n";
    cin>>id;
    cout<<"\n\t\tEnter Description: \n";
    cin>>description;
    cout<<"\n\t\tEnter Location of Incident: \n";
    cin>>location;
    cout <<"\n\t\tDATE(DD/MM/YYYY)\n";
    fflush(stdin);
    int c = 0;
    while(!c)
    {
        cout << "\n\t\t\t\t\t Day : ";
        cin >> this->Date.d;
        if((this->Date.d>31) || (this->Date.d<1))
        {
            cout << "\n\t\tTHIS DATE DOES NOT EXIST, TRY AGAIN!!\n";
            c = 0;
        }
        else
            c = 1;
    }
    c = 0;
    fflush(stdin);
    while(!c)
    {
        cout << "\n\t\t\t\t\t Month : ";
        cin >> this->Date.m;
        if((this->Date.m>12) || (this->Date.m<1))
        {
            cout << "\n\t\tTHIS MONTH DOES NOT EXIST, TRY AGAIN!!\n";
            c = 0;
            continue;
        }
        else
            c = 1;

        if((this->Date.d==31) && ((this->Date.m==2) || (this->Date.m==4) ||( this->Date.m==6) ||( this->Date.m==9) || (this->Date.m==11)))
        {
            cout <<"\n\t\tTHIS MONTH DOES NOT HAVE 31 DAYS \n\tTRY AGAIN !!\n";
            c = 0;
        }
        else
            c = 1;
    }
    fflush(stdin);
    c = 0;

    while(!c)
    {
        cout << "\n\t\t\t\t\t Year(4 digits) : ";
        cin >> this->Date.y;
        if((this->Date.y <= 1930)||(this->Date.y>2021))
        {
            cout << "\n\t\tINCORRECT INPUT, TRY AGAIN!!\n";
            c = 0;
        }
        else
            c = 1;
    }
    cout<<"\n\t\tEnter Police Station:  \n";
    cin>>PoliceStation;
    cout<<"\n\t\tEnter Case Type:  \n";
    cin>>type;
    cout<<"\n\t\tEnter Status of Case:  \n";
    cin>>status;
    GetPoliceInfo();
    GetVictimInfo();
    GetCriminalInfo();
    char ch;
    do
    {
        cout << "\n\tDO YOU WANT TO SAVE THIS INFORMATION(Y/N) : ";
        cin >> ch;

        if(ch=='y'||ch=='Y')
        {
            cout << "\n\n\t< RECORD HAS BEEN SAVED >";
            Cases[Casecnt] = (*this);
            for(int i=0; i<Pcnt; ++i)
            {
                // cout<<Pcnt<<endl;
                CPolices[i]->assignCase(&Cases[Casecnt]);
                // CPolices[i]->display();
            }

            Casecnt++;
            // write(*this);
        }
        else
        {
            if((ch!='n')&&(ch!='N'))
            {
                cout<<"\n\t\tENTER CORRECTLY \n\t\t TRY AGAIN !!\n\n";
            }
        }
    }
    while((ch!='y') && (ch!='Y') && (ch!='n') && (ch!='N'));
}
Case::GetPoliceInfo()
{
    cout<<"\n\n\tEnter Police Information:\n";
    int t;
    cout<<"\n\n\tEnter Number of officers:   ";
    cin>>t;
    while(t--)
    {
        char i[10];
        do
        {
            cout<<"\n\n\tEnter Police ID:  ";
            cin>>i;
        }
        while(!AssignPolice(i,CPolices,Pcnt));
        Pcnt++;
    }
}

Case::GetCriminalInfo()
{
    cout<<"\n\n\tEnter Criminal Information:\n";
    int t;
    cout<<"\n\n\tEnter Number of Convicts:   ";
    cin>>t;
    while(t--)
    {
        Criminal c;
        c.add(Criminals,criminalcnt);
        //
        //  Criminals[criminalcnt].output();
        //   this->Display();
        criminalcnt++;
    }
}
Case::GetVictimInfo()
{
    cout<<"\n\n\tEnter Victims Information:\n";
    int t;
    cout<<"\n\n\tEnter Number of Victims:   ";
    cin>>t;
    while(t--)
    {
        Victim v;
        v.add();
        //
        //  Criminals[criminalcnt].output();
        //   this->Display();
        Victims[vcnt] = v;
        vcnt++;
    }
}
bool Case::cid_exist(int id)
{
    if(id==this->id)
        return true;
    else
        return false;
}
void Case::Display()
{

    system("cls");
    fflush(stdin);

    cout << "\n\n\t\t----------CASE DETAILS----------";
    cout << "\n\n\tCASE ID           :\t"<<id;
    cout << "\n\tDESCRIPTION         :\t"<<description;
    cout << "\n\tLOCATION            :\t" << location;
    cout << "\n\n\tDATE              :\t"<<Date.d<<"/"<<Date.m<<"/"<<Date.d;
    cout << "\n\tPOLICESTATION       :\t"<<PoliceStation;
    cout << "\n\tCASE TYPE           :\t"<<type;
    cout << "\n\tSTATUS              :\t"<<status;
    cout << "\n\n\n\t\t\t";
    system("pause");


    system("cls");
    cout << "\n\n\t\t----------POLICE INFORMATION----------";
    cout<<"\n\tNumber of POLICES Under Case:    :"<<Pcnt<<"\n\n";
    cout<<"\n\tPRESS ENTER....................";
    system("pause");
    system("cls");
    for(int i=0; i<Pcnt; ++i)
    {
        CPolices[i]->display();
        system("pause");
    }
    cout << "\n\n\t\t----------CRIMINAL INFORMATION----------";
    cout<<"\n\tNUMBER OF CONVICTS UNDER CASE:    :"<<criminalcnt<<"\n\n";
    cout<<"\n\tPress Enter. . . . .";
    system("pause");

    for(int i=0; i<criminalcnt; ++i)
    {
        system("cls");
        Criminals[i]->output();
        system("pause");
    }
}
Case::Add_police()
{
    int t;
    cout<<"\n\n\tEnter Number of officers to add:   ";
    cin>>t;
    while(t--)
    {
        char i[20];
        do
        {
            cout<<"\n\n\tEnter Police ID:  ";
            cin>>i;
        }
        while(!AssignPolice(i,CPolices,Pcnt));
        this->Pcnt++;
        char ch;
        do
        {
            cout << "\n\tDO YOU WANT TO SAVE THIS INFORMATION(Y/N) : ";
            cin >> ch;
            //  CPolices[Pcnt]->display();
            if(ch=='y'||ch=='Y')
            {
                cout << "\n\n\t< RECORD HAS BEEN SAVED >";

                CPolices[Pcnt-1]->assignCase(this);
                //   Pcnt++;
                //  this->Display();

                cout <<"\n";
                fflush(stdin);

            }
            else
            {
                if((ch!='n')&&(ch!='N'))
                {
                    cout<<"\n\t\tENTER CORRECTLY \n\t\t TRY AGAIN !!\n\n";
                }
            }
        }
        while((ch!='y') && (ch!='Y') && (ch!='n') && (ch!='N'));

        for(int i=0; i<Casecnt; ++i)
        {
            if(Cases[i].id==this->id)
                Cases[i] = (*this);
        }
    }
}

void Case::file_to_vector()
{
    fstream file;
    file.open("Cases.txt",ios::in|ios::ate|ios::binary);
    int x = 0, count = 0, c;
    int q = file.tellg();
    c = q/sizeof(Case);
    file.close();
    file.open("Cases.txt",ios::binary|ios::in);
    for(int i=0; i<c; i++)
    {
        file.read(reinterpret_cast<char*>(this),sizeof(Case));
        Cases[Casecnt]=(*this);
        Casecnt++;
    }
    file.close();
}
void Case::remove_police()
{
    bool yes= false;
    char pid[30];
    cout<<"Enter Police ID: ";
    cin>>pid;
    for(int i=0; i<Pcnt; ++i)
    {
        if(CPolices[i]->check_Police_id(pid))
        {
            yes = true;
            Pcnt--;
        }
        if(yes)
        {
            CPolices[i] = CPolices[i+1];
        }
    }
    if(!yes)
        cout<<"POLICE NOT UNDER CASE\n\n";
    for(int i=0; i<Casecnt; ++i)
    {
        if(Cases[i].id==this->id)
            Cases[i] = (*this);
    }
}

int Case::get_id()
{
    return id;
}

void Case::change_case_details()
{
    string _description;
    string _location;
    date _Date;
    string _PoliceStation;
    string _type;
    string _status;

    fstream file;

    if(true)
    {
        char c;
        fstream file;
        file.open("Cases.txt",ios::out|ios::in|ios::binary);
        cout << "\n\n\t\tCASE FOUND !\n\n";
        cout << "\n\tENTER MODIFIED DETAILS\n";

        cout<<"\n\n\t\t\t"<<"DESCRIPTION ";
        cout<<"\n\t\t\t"<<"------- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter description : ";
            cin>>_description;
            description=_description;
        }

        cout<<"\n\n\t\t\t"<<"location ";
        cout<<"\n\t\t\t"<<"--- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter location : ";
            cin>>_location;
            location=_location;
        }

        system("pause");
        system("cls");
        cout<<"\n\n\t\t\t"<<"Date of Filing CASE  ";
        cout<<"\n\t\t\t"<<"------------ ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            int m_date;
            while(1)
            {
                cout<<"\n\t\tDate: ";

                cin>>m_date;
                if(m_date>0 && m_date<31)
                    break;
                else
                    cout<<"\n\n\t\t\t"<<"Enter a valid date!"<<endl;
            }
            this->Date.d=m_date;

            fflush(stdin);
            while(1)
            {
                cout<<"\n\t\tMonth: ";
                cin>>m_date;
                if(m_date>0 &&m_date<13)
                    break;
                else
                    cout<<"\n\n\t\t\t"<<"Enter a valid month!"<<endl;
            }
            this->Date.m=m_date;
            fflush(stdin);
            cout<<"\n\t\tYear: ";
            cin>>m_date;
            this->Date.y = m_date;
        }
        cout<<"\n\n\t\t\t"<<"Station ";
        cout<<"\n\t\t\t"<<"------- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            string _station;
            cout<<"\n\n\t\t\t"<<"Enter station : ";
            cin>>_station;
            PoliceStation=_station;
            for(int i=0; i<Casecnt; ++i)
            {
                if(Cases[i].id==this->id)
                    Cases[i] = (*this);
            }
            /* if(yes)
                 policess[k].station=_station;*/
        }

        /* int loc=(k)*sizeof(Case);
         file.seekp(loc,ios::beg);
         file.write((char*)this,sizeof(Case));
         file.close();
         cout <<"\n";
         fflush(stdin);
         cout << "\n\n\t\t\t < RECORD MODIFIED >";
         system("pause");*/
    }


    /*  else
       {
           cout << "\n\n\n\t\tPRESS 'Y' TO TRY AGAIN 'N' TO GO TO QUIT : ";
           char ch_m;
           cin >> ch_m;
           fflush(stdin);
           if(ch_m == 'y' || ch_m == 'Y')
           {
               system("cls");
               goto modify_start;
           }

           else
           {
               callExit();
           }
       }*/
}
void Case::modify_case()
{

    int k;
    k = check_cid();
    if(k!=-1)
    {
        int n;
        cout<<"\n\t\t!1.MODIFY CASE DETAILS!!\n\n";
        cout<<"\n\t\t!2.ADD OFFICER!!\n\n";
        cout<<"\n\t\t!3.REMOVE OFFICER FROM CASE!!\n\n";
        cout<<"\n\t\t!4.ADD CONVICT INFO!!\n\n";
        cout<<"\n\t\t!5.REMOVE CONVICT!!\n\n";
        cout<<"\n\t\t6.MODIFY CONVICT INFO!!\n\n";
        cout<<"\n\t\t!1.MODIFY VICTIM INFO!!\n\n";
        cout<<"\n\t\t!ENTER OPTION:\n\n";
        cin>>n;
        switch(n)
        {
        case 1:
            change_case_details();
            break;
        case 2:
            Add_police();
            break;
        case 3:
            remove_police();
            break;
        case 4:
            // Add_criminal(k);
            break;
        case 5:
            //   Remove_criminal(k);
            break;
        case 6:
            //   modify_criminal();
            break;
        case 7:
            change_case_details();
            break;

        }

    }

}
void Case::modify_criminal()
{
    bool yes = false;
    char cid[10];

    cout<<"\t\tENTER CRIMINAL ID:  ";
    cin>>cid;
    for(int i=0; i<criminalcnt; ++i)
    {
        if(Criminals[i]->match_id(cid))
        {
            Criminals[i]->modify(cid);

            cout<<"PAWA GESEEEEE";
        }

    }
    for(int i=0; i<Casecnt; ++i)
    {
        if(Cases[i].id==(this->id))
            Cases[i] = (*this);
    }
    if(!yes)
        cout<<"CRIMINAL NOT FOUND!!!!\n";
}
void Case::Remove_criminal()
{
    bool yes = false;
    char crid[10];

    cout<<"\t\tENTER CRIMINAL ID:  ";
    cin>>crid;
    for(int i=0; i<criminalcnt; ++i)
    {
        if(Criminals[i]->match_id(crid))
        {
            criminalcnt--;
            yes = true;
            cout<<"PAWA GESEEEEE";
        }
        if(yes)
            Criminals[i] = Criminals[i+1];
    }
    for(int i=0; i<Casecnt; ++i)
    {
        if(Cases[i].id==this->id)
            Cases[i] = (*this);
    }

}
