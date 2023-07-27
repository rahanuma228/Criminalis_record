#include "Police.h"
#include<Case.h>

int ocount=0;

void Police::check()
{
    for(int i=0; i<ocount; ++i)
        polices[i].Case_Display();
}

//#endif // POLICE_H
Police::Police()
{

}

Police::Police(int val)
{
    cscnt = 0;
}
Police Police::polices[1000];

void Police::get_data()
{
    int c=0;
    Police x;
    //Police x;
    cout <<"\n\t\t\t\t"<<"  Enter Police ID:";
    cin >> id;
    cout <<"\n\t\t\t\t"<<"  Enter National Identification Number:";
    cin >> nid;
    fflush(stdin);
    Person::get_data();
    system("pause");
    system("cls");
    cout<<"\n\n\n\t"<<"--------------------------ENTER RESIDENTIAL DETAILS----------------------------"<<"\n\n\n";
    Person::get_address();
    cout<<"\n\t\t\t\t"<<"  Enter Postal Code :";
    cin>>post_code;
    system("pause");
    system("cls");
    cout<<"\n\n\n\t"<<"--------------------------ENTER STATION DETAILS----------------------------"<<"\n\n\n";
    cout<<"\n\t\t\t\t"<<"  Enter Station :";
    cin>>station;
    cout<<"\n\t\t\t\t"<<"  Enter Rank :";
    cin>>_rank;
    cout<<"\n\t\t\t\t"<<"  Enter Salary :";
    cin>>salary;
    cout<<"\n\t\t\t\t"<<"  Enter Joining Date: "<<endl;
    while(1)
    {
        cout<<"\n\t\t\t\t    "<<"Date: ";
        cin>>join_day;
        if(join_day>0 && join_day<31)
            break;
        else
            cout<<"\n\t\t\t   "<<"Enter a valid date!"<<endl;
    }
    fflush(stdin);
    while(1)
    {
        cout<<"\n\t\t\t\t    "<<"Month: ";
        cin>>join_month;
        if(join_month>0 &&join_month<13)
            break;
        else
            cout<<"\n\t\t\t    "<<"Enter a valid month!"<<endl;
    }
    fflush(stdin);
    cout<<"\n\t\t\t\t    "<<"Year: ";
    cin>>join_year;
    fflush(stdin);
}
void Police::set_data(Police p)
{
  /*  for(int i=0; i<10; i++)
        p.id[i]=id[i];
    for(int i=0; i<200; i++)
        p.name[i]=name[i];
    p.division=division;
    p.age=age;
    p.gender=gender;
    p.day=day;
    p.month=month;
    p.year=year;
    p.station=station;
    p._rank=_rank;
    p.salary=salary;*/
}

bool Police::check_Police_id(char id[])
{
    if(strcmp(id,id)==0)
        return true;
    else
        return false;
}
void Police::assignCase(Case *c)
{
    pCases[cscnt]=c;
    cscnt++;
}

void Police::add()
{

    system("cls");
    Police p;
    cout<<"\n\n\n\t"<<"--------------------------ENTER POLICE DETAILS----------------------------"<<"\n\n\n";
    get_data();
    fflush(stdin);
    int e=-1;
    fstream pf2;
    try
    {
        pf2.open("thana.txt",ios::app|ios::binary);
        if(pf2.fail())
        {
            throw e;
        }
    }
    catch(int e)
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    char ch;
    do
    {
        cout << "\n\n\t\t\tDO YOU WANT TO SAVE THIS INFORMATION(Y/N) : ";
        cin >> ch;

        if(ch=='y'||ch=='Y')
        {
            cout << "\n\n\t\t\t< RECORD HAS BEEN SAVED >";
            pf2.write((char*)this,sizeof(Police));

            polices[ocount]=(*this);
            ocount++;
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

    pf2.close();
    cout << "\n\n\t\t";
    system("pause");
}
int Police::check_pid(char pid[])
{
    system("cls");
    fstream file;
    file.open("thana.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }

    int x = 0, ccount = 0, c;
    int q = file.tellg();
    c = q/sizeof(Police);
    file.close();
    file.open("thana.txt",ios::binary|ios::in);
    for(int i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Police));
        ccount++;//finding the actual position of the id
        if(strcmp(pid,id)==0)
        {
            x++;
            break;
        }
    }
    if(x==0)
    {
        cout<<"\n\n\n\n\tPOLICE NOT FOUND!!!!!! ";
        getchar();
        return 0;
    }
    else
    {
        return ccount;
    }
    file.close();

}

void Police::remove()
{
    system("cls");
    system("pause");
    fstream pf2;
    fflush(stdin);
    cout << "\n\n\n\t\tENTER THE POLICE ID : ";
    char p_i[10];
    gets(p_i);
    pf2.open("thana.txt",ios::binary|ios::in|ios::ate);
    if(pf2.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    int q = pf2.tellg();
    int c = q/sizeof(Police);
    fstream temp;
    temp.open("temp.txt",ios::binary|ios::out);
    pf2.seekg(0,ios::beg);
    int xount=0;
    for(int i=0; i<c; i++)
    {
        pf2.read((char*)this,sizeof(Police));
        if(strcmp(id,p_i) != 0)
            temp.write((char*)this,sizeof(Police));
        else
        {
            xount=1;
        }
    }

    pf2.close();
    temp.close();
    pf2.open("thana.txt",ios::binary|ios::out);
    temp.open("temp.txt",ios::binary|ios::in|ios::ate);
    int a = temp.tellg();
    int size = a/sizeof(Police);
    temp.seekg(0,ios::beg);
    for(int k=0; k<size; k++)
    {
        temp.read((char*)this,sizeof(Police));
        pf2.write((char*)this,sizeof(Police));
    }
    pf2.close();
    temp.close();
    if(xount==0)
    {
        cout<<"\n\n\t\t\t<NO SUCH RECORD EXITS!!!!!! >";
        cout <<"\n";
    }
    else
    {

        cout<<"\n\n\t\t\t<RECORD OF POLICE HAVING ID "<<p_i<<" HAS BEEN DELETED >";
        cout <<"\n";
    }
    fflush(stdin);
    getchar();

    bool yes=false;
    for(int i=0; i<ocount; i++)
    {
        if(polices[i].id==p_i)
        {
            ocount--;
            yes=true;
        }
        if(yes)
        {
            polices[i]=polices[i+1];
        }

    }
}

void Police::remove_case(Case *c)
{
    bool yes=false;
    for(int i=0; i<cscnt; ++i)
    {
        if(pCases[i]->cid_exist(c->get_id()))
        {
            cscnt--;
            yes=true;
        }
        if(yes)
        {
            pCases[i]=pCases[i+1];
        }
    }

    cout << "\n\n\t\t\t < RECORD MODIFIED >";
    system("pause");

}
void Police::display()
{
    system("cls");
    fflush(stdin);
    cout<<"\n\n\n\n\t\t\t       Displaying police information         ";
    cout<<"\n\n\n\n\t\t\t------------Personal Information-------------";
    Person::display_information();
    cout<<"\n\n\t\t\t"<<"NID :"<<nid<<endl;
    system("pause");
    system("cls");
    cout<<"\n\n\n\n\t\t\t------------Residential Information-------------";
    Person::display_address();
    cout<<"\n\n\t\t\t"<<"Postal Code :"<<post_code<<endl;
    system("pause");
    system("cls");
    cout<<"\n\n\n\n\t\t\t------------Occupational Information-------------";
    cout<<"\n\n\t\t\t"<<"Station :"<<station<<endl;
    cout<<"\n\n\t\t\t"<<"Rank :"<<_rank<<endl;
    cout<<"\n\n\t\t\t"<<"Salary :"<<salary<<" BDT"<<endl;
    cout<<"\n\n\t\t\t"<<"Date of Joining :"<<join_day<<"/"<<join_month<<"/"<<join_year<<endl;
    cout <<"\n";
    fflush(stdin);
}
void Police::display_information()
{
    system("cls");
    fflush(stdin);
    char N[10];
    int rec;
    int loc;
    cout << "\n\n\n\t\tENTER THE POLICE ID : ";
    gets(N);
    fstream file;
    rec = this->check_pid(N);
    file.open("thana.txt",ios::binary|ios::in);
    if(rec!=0)
    {
        loc = (rec-1)*sizeof(Police);
        file.seekg(loc);
        file.read((char*)this,sizeof(Police));
        this->display();
    }
    file.close();
    cout <<"\n";
    fflush(stdin);
    system("pause");
    system("cls");
}
void Police::modify()
{
    system("cls");
    fflush(stdin);
    Police pc;
    char N[10];
    char _id[10];
    char _division[100];
    char _district[100];
    char _post_code[100];
    char _area[100];
    char _gender[100];
    char rank2[100];
    //char_dob,
    char _station[100];
    double _salary;
    int _age;
    int m_date;
    int rec;
modify_start:
    cout << "\n\n\n\t\tENTER THE POLICE ID : ";
    gets(N);
    fstream file;
    int k;
    rec = this->check_pid(N);
    bool yes=false;
    for(k=0; k<ocount; k++)
    {
        if(strcmp(N,polices[k].id)==0)
        {
            yes=true;
            break;
        }
    }
    if(rec!=0)
    {
        char c;
        file.open("thana.txt",ios::out|ios::in|ios::binary);
        if(file.fail())
        {
            cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
            cin.ignore();
            cin.get();
        }
        cout << "\n\n\t\tRECORD FOUND !\n\n";
        cout << "\n\tENTER MODIFIED DETAILS\n";
        cout<<"\n\n\t\t\t"<<"-------Residential Details--------";

        cout<<"\n\n\t\t\t"<<"Division :"<<division;
        cout<<"\n\t\t\t"<<"------- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter division : ";
            cin>>_division;
            strcpy(division,_division);

            if(yes)
               strcpy(polices[k].division,_division);
        }
        cout<<"\n\n\t\t\t"<<"District :"<<district;
        cout<<"\n\t\t\t"<<"------- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter district : ";
            cin>>_district;
            strcpy(district,_district);
            if(yes)
              strcpy(polices[k].district,_district);
        }
        cout<<"\n\n\t\t\t"<<"Area :"<<area;
        cout<<"\n\t\t\t"<<"------ ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter area : ";
            cin>>_area;
            strcpy(area,_area);
            if(yes)
               strcpy(polices[k].area,_area);
        }
        cout<<"\n\n\t\t\t"<<"Postal Code :"<<post_code;
        cout<<"\n\t\t\t"<<"------------- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter Postal Code : ";
            cin>>_post_code;
            strcpy(post_code,_post_code);
            if(yes)
                strcpy(polices[k].post_code,_post_code);
        }

        system("pause");
        system("cls");
        cout<<"\n\n\t\t\t"<<"-------Personal Details--------";

        cout<<"\n\n\t\t\t"<<"Age   :"<<age<<" years";
        cout<<"\n\t\t\t"<<"----- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;

        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter age : ";
            cin>>_age;
           age=_age;
            if(yes)
              polices[k].age=_age;
        }
        cout<<"\n\n\t\t\t"<<"Gender   :"<<gender;
        cout<<"\n\t\t\t"<<"------ ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\t\t\t"<<"Enter gender : ";
            cin>>_gender;
            strcpy(gender,_gender);
            if(yes)
                strcpy(polices[k].gender,_gender);
        }
        cout<<"\n\n\t\t\t"<<"Date of birth   :"<<day<<"/"<<month<<"/"<<year;
        cout<<"\n\t\t\t"<<"------------ ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            while(1)
            {
                cout<<"\n\t\t\t\t    "<<"Date: ";


                cin>>m_date;
                if(m_date>0 && m_date<31)
                    break;
                else
                    cout<<"\n\n\t\t\t"<<"Enter a valid date!"<<endl;
            }
            day=m_date;
            if(yes)
                polices[k].day=m_date;
            fflush(stdin);
            while(1)
            {
                cout<<"\n\t\t\t\t    "<<"Month: ";
                cin>>m_date;
                if(m_date>0 &&m_date<13)
                    break;
                else
                    cout<<"\n\n\t\t\t"<<"Enter a valid month!"<<endl;
            }
            month=m_date;
            if(yes)
                polices[k].month=m_date;
            fflush(stdin);
            cout<<"\n\t\t\t\t    "<<"Year: ";
            cin>>m_date;
            year=m_date;
            if(yes)
                polices[k].year=m_date;
        }
        system("pause");
        system("cls");
        cout<<"\n\n\t\t\t"<<"-------Occupational Details--------";
        cout<<"\n\n\t\t\t"<<"Station   :"<<station;
        cout<<"\n\t\t\t"<<"------- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\n\t\t\t"<<"Enter station : ";
            cin>>_station;
            strcpy(station,_station);
            if(yes)
                strcpy(polices[k].station,_station);
        }

        cout<<"\n\n\t\t\t"<<"Rank   :"<<_rank;
        cout<<"\n\t\t\t"<<"---- ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\n\t\t\t"<<"Enter rank : ";
            cin>>rank2;
            strcpy(_rank,rank2);
            if(yes)
                strcpy(polices[k]._rank,rank2);
        }

        cout<<"\n\n\t\t\t"<<"Salary   :"<<salary<<" BDT";
        cout<<"\n\t\t\t"<<"------ ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout<<"\n\n\t\t\t"<<"Enter salary : ";
            cin>>_salary;
            salary=_salary;
            if(yes)
                polices[k].salary=_salary;
        }
        cout<<"\n\n\t\t\t"<<"Date of joining   :"<<join_day<<"/"<<join_month<<"/"<<join_year;
        cout<<"\n\t\t\t"<<"------------ ";
        cout<<"\n\t\t\t"<<"Does this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            while(1)
            {
                cout<<"\n\t\t\t\t    "<<"Date: ";


                cin>>m_date;
                if(m_date>0 && m_date<31)
                    break;
                else
                    cout<<"\n\n\t\t\t"<<"Enter a valid date!"<<endl;
            }
            join_day=m_date;
            if(yes)
                polices[k].join_day=m_date;
            fflush(stdin);
            while(1)
            {
                cout<<"\n\t\t\t\t    "<<"Month: ";
                cin>>m_date;
                if(m_date>0 &&m_date<13)
                    break;
                else
                    cout<<"\n\n\t\t\t"<<"Enter a valid month!"<<endl;
            }
            join_month=m_date;
            if(yes)
                polices[k].join_month=m_date;
            fflush(stdin);
            cout<<"\n\t\t\t\t    "<<"Year: ";
            cin>>m_date;
            join_year=m_date;
            if(yes)
                polices[k].join_year=m_date;
        }


        int loc=(rec-1)*sizeof(Police);
        file.seekp(loc,ios::beg);
        file.write((char*)this,sizeof(Police));
        file.close();
        cout <<"\n";
        fflush(stdin);
        cout << "\n\n\t\t\t < RECORD MODIFIED >";
        system("pause");
    }


    else
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
            //callExit();
        }
    }

}





void Police::list_all()
{

    system("cls");
    fflush(stdin);
    int j ;
    fstream file;
    file.open("thana.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    int c = q/sizeof(Police);
    file.seekg(0);
    cout<<"                            \n";
    cout<<"		                                 \n";
    cout<<"                                          LIST OF ALL POLICE     \n";
    cout<<"			                         \n";
    cout<<"                            \n";
    cout<<"\n=======================================================================================================================\n";
    cout << "SR.\tPOLICE ID\t NAME          \t\t\t         STATION                \t\tRANK\n";
    cout<<"=========================================================================================================================\n";
    int i = 0;
    while(file.read((char*)this,sizeof(Police)))
    {
        i++;
        cout << i << "         ";
        for(j=0; j<strlen(this->id); j++)
            cout << this->id[j];
        cout<<"              ";

        for(j=0; j<strlen(this->name); j++)
            cout << this->name[j];
        cout << "          \t\t\t  ";
        for(j=0; j<strlen(this->station); j++)
            cout << this->station[j];
        cout << "\t\t\t        ";
        for(j=0; j<strlen(this->_rank); j++)
            cout << this->_rank[j];
        cout << "\t\t\t        ";
        cout <<"\n";
        fflush(stdin);
        getchar();
        cout << "\n-------------------------------------------------------------------------------------------------------------\n";
        if((i%5)==0&&(i!=c))
        {
            system("pause");
            system("cls");
            cout<<"\n=================================================================================================================\n";
            cout << "SR.\tPOLICE ID\t NAME          \t\t\t         STATION                \t\tRANK\n";
            cout<<"====================================================================================================================\n";
        }
    }
    file.close();
    getchar();
}



/////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////


void Police::show_cases()
{
    cout<<"                       hello                 "<<cscnt;
    for(int i=0; i<cscnt; ++i)
    {
         system("cls");
        pCases[i]->Display();
        system("pause");
    }

}

//////////////////////////////////////////////////////////////////////////////////////
int Police::Set_caseCount(int val)
{
    cscnt = val;
}

void Police::Case_Display()
{
    // cout<<"CScount here b  "<<cscnt;
    for(int i=0; i<cscnt; ++i)
    {
        pCases[i]->Display();
    }
}

bool AssignPolice(char pid[], Police* p[], int Pcnt)
{
    ///check from existing polices if exists////This will be a friend function of the policeS class
    int flag = false;
    for(int i=0; i<ocount; ++i)
    {
        //  Police::polices[i].display();
        if(strcmp(pid,Police::polices[i].id)==0)
        {
            p[Pcnt]=&(Police::polices[i]);
            //   p[Pcnt]->display();
            flag=true;
            return flag;
        }
    }
    if(!flag)
    {
        cout<<"\n\t\tENTER CORRECTLY \n\t\t TRY AGAIN !!\n\n";
        return false;
    }

}
