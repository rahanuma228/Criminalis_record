#include "Victim.h"

int vcount=0;

void Victim::get_Personal_Info()
{
    cout<<endl<<endl<<endl;
    int d=0;
    cout<<"\tEnter Victim ID: ";
    cin>>victim_id;
    fflush(stdin);
    cout<<endl<<endl;
    cout<<"Enter Victim Details: "<<endl;
    cout<<endl;
    fflush(stdin);
    cout<<"\tEnter name: ";
    gets(name);
    fflush(stdin);
    cout<<"\tGender: ";
    cin>>gender;
    fflush(stdin);
    cout<<"\tOccupation: ";
    cin>>occupation;
    fflush(stdin);
    cout<<"\tEnter National Identification no.: ";
    cin>>nid;
    fflush(stdin);
    cout<<"\tEnter Date of Birth: "<<endl;
    while(1)
    {
        cout<<"\t\tDate: ";
        cin>>day;
        if(day>0 && day<31)
            break;
        else
            cout<<"\t\tENTER A VALID DATE!"<<endl;
    }
    fflush(stdin);
    while(1)
    {
        cout<<"\t\tMonth: ";
        cin>>month;
        if(month>0 && month<13)
            break;
        else
            cout<<"\t\tENTER A VALID MONTH!"<<endl;
    }
    fflush(stdin);
    cout<<"\t\tYear: ";
    cin>>year;
    fflush(stdin);
    cout<<"\tEnter Address of the covict:"<<endl;
    cout<<"\t\tDivision: ";
    cin>>division;
    fflush(stdin);
    cout<<"\t\tDistrict: ";
    cin>>district;
    fflush(stdin);
    cout<<"\t\tArea: ";
    cin>>area;
    fflush(stdin);
    cout<<"\t\tPostal Code: ";
    cin>>post_code;
    fflush(stdin);
    cout<<endl<<endl;
}
void Victim::get_CrimeInfo()
{
    cout<<endl<<endl<<endl;
    cout<<"Enter information about the crime: "<<endl<<endl;
    cout<<"\tCrime: ";
    cin>>crime;
    fflush(stdin);
    cout<<"\tDate of crime: "<<endl;
    while(1)
    {
        cout<<"\t\tDate: ";
        cin>>crimeday;
        if(crimeday>0 && crimeday<31)
            break;
        else
            cout<<"\t\tENTER A VALID DATE!"<<endl;
    }
    fflush(stdin);
    while(1)
    {
        cout<<"\t\tMonth: ";
        cin>>crimemonth;
        if(crimemonth>0 && crimemonth<13)
            break;
        else
            cout<<"\t\tENTER A VALID MONTH!"<<endl;
    }
    fflush(stdin);
    while(1)
    {
        cout<<"\t\tYear: ";
        cin>>crimeyear;
        if(crimeyear>year)
            break;
        else
            cout<<"\t\tENTER A VALID YEAR!"<<endl;
    }
    fflush(stdin);
    cout<<"\tPlace of crime: ";
    cin>>crimeplace;
    fflush(stdin);
    cout<<endl<<endl;

}
void Victim::get_PoliceInfo()
{
    cout<<endl<<endl<<endl;
    cout<<"Enter Victim Station Information: "<<endl<<endl;
    cout<<"\tStation: ";
    cin>>station;
    fflush(stdin);
    cout<<"\tCase no.: ";
    cin>>fir_no;
    fflush(stdin);

}

void Victim::get_data()
{
    get_Personal_Info();
    system("cls");
    get_CrimeInfo();
    system("cls");
    get_PoliceInfo();
}
Victim Victim::victims[10000];
void Victim::add()      // Function for getting VICTIMs Record
{
    system("cls");
    fstream file;
    file.open("bechara.txt",ios::app|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    Victim c;
    get_data();
    fflush(stdin);

    char ch;
    do
    {
        cout << endl<<"DO YOU WANT TO SAVE THIS INFORMATION(Y/N) : ";
        cin >> ch;

        if(ch=='y'||ch=='Y')
        {
            cout << "\n\n\t< RECORD HAS BEEN SAVED >"<<endl;
            file.write((char*)this,sizeof(Victim));


            victims[vcount]=(*this);
            vcount++;
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
    file.close();
    cout << "\n\n\t\t";
    system("pause");

}

int Victim::check_id(char id[])
{
    system("cls");
    fstream file;
    file.open("bechara.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    int x = 0, count = 0, c;
    int q = file.tellg();
    c = q/sizeof(Victim);
    file.close();
    file.open("bechara.txt",ios::in|ios::binary);
    for(int i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Victim));
        count++;//finding the actual position of the id
        if(strcmp(id,victim_id)==0)
        {
            x++;
            break;
        }
    }
    if(x==0)
    {
        //cout<<count;
        cout<<"\n\n\n\n\tVICTIM RECORD NOT FOUND!!!!!! ";
        getchar();
        return 0;
    }
    else
    {
        return count;
    }
    file.close();
}
void Victim::output()      // Function for showing VICTIM's Record
{
    system("cls");
    fflush(stdin);

    cout << "\n\n\t\t----------PERSONAL RECORD OF VICTIM----------";
    cout << "\n\tVICTIM ID             :\t"<<victim_id;
    cout << "\n\tName                   :\t"<<name;
    cout << "\n\tGender                 :\t" << gender;
    cout<<"\n\tOccupation             :\t"<<occupation;
    cout << "\n\tAddress                \t";
    cout<<"\n\t\tDivision       :\t"<<division<<endl;
    cout<<"\t\tDistrict       :\t"<<district<<endl;
    cout<<"\t\tArea           :\t"<<area<<endl;
    cout<<"\t\tPostal Code    :\t"<<post_code<<endl;
    cout<<endl<<"\tDate of Birth          :\t"<<day<<"/"<<month<<"/"<<year;

    cout << "\n\n\n\t\t\t";
    system("pause");
    system("cls");
    fflush(stdin);

    cout << "\n\n\t\t----------CRIME INFORMATION----------";
    cout << "\n\tAct of Crime                       :\t"<<crime;
    cout << "\n\tDate of Crime                      :\t"<<crimeday<<"/"<<crimemonth<<"/"<<crimeyear;
    cout << "\n\tCrime Scene                        :\t"<<crimeplace;

    cout << "\n\n\n\t\t\t";

    system("pause");
    fflush(stdin);
    system("cls");

    cout << "\n\n\n\t\t----------POLICE INFORMATION---------- \n\n";
    cout << "\n\tPolice Station       :\t"<<station;
    cout << "\n\tCase NO.             :\t"<<fir_no;

    cout << "\n\n\n\t\t\t";
    system("pause");
    fflush(stdin);
}

void Victim::display()    // function to display record
{
    system("cls");
    fflush(stdin);
    char N[10];
    int rec;
    int loc;
    cout << "\n\n\n\t\tENTER THE VICTIM ID TO SEE INFORMATION: ";
    gets(N);
    fstream file;
    rec = this->check_id(N);
    file.open("bechara.txt",ios::app|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    if(rec!=0)
    {
        loc = (rec-1)*sizeof(Victim);
        file.seekg(loc);
        file.read((char*)this,sizeof(Victim));
        this->output();
    }
    file.close();
    cout <<"\n";
    fflush(stdin);
}

void Victim::modify() // function to modify record
{
    system("cls");
    fflush(stdin);
    fstream file;
    string modified_data;
    char str[10];
    int check,loc,mod_date;
    Victim x;
    fflush(stdin);
modify_start:
    cout << "\n\tENTER VICTIM ID TO EDIT RECORD: ";
    cin>>str;
    check = this->check_id(str);
    int k;
    bool yes=false;
    for(k=0; k<vcount; k++)
    {
        if(str==victims[k].victim_id)
        {
            yes=true;
            break;
        }
    }
    char c;
    if(check!=0)
    {
        file.open("bechara.txt",ios::out|ios::in|ios::binary);
        if(file.fail())
        {
            cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
            cin.ignore();
            cin.get();
        }
        cout << "\n\n\t\tRECORD FOUND !\n\n";
        cout << "\n\t\tVictim ID             :\t"<<victim_id;
        cout << "\n\t\tName                   :\t"<<name<<endl<<endl;
        cout << "\n\t----ENTER MODIFIED DETAILS----\n";
        cout << "\n\tCrime                       :\t"<<crime;

        cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout << "\n\t\t\t\tCrime      : ";
            cin >> modified_data;
            crime=modified_data;
            if(yes)
                victims[k].crime=modified_data;
        }
        fflush(stdin);
        cout << "\n\tPlace of Crime                     :\t"<<crimeplace;
        cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout << "\n\tPlace of Crime                     :\t";
            cin >> modified_data;
            crimeplace=modified_data;
            if(yes)
                victims[k].crimeplace=modified_data;
        }
        fflush(stdin);
        cout << "\n\tDate of Crime                      :\t"<<crimeday<<"/"<<crimemonth<<"/"<<crimeyear;
        cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout << "\n\tDate of Crime                      :\t";
            while(1)
            {
                cout<<"\n\t\tDate: ";
                cin>>mod_date;
                if(mod_date>0 && mod_date<=31)
                {
                    crimeday=mod_date;
                    if(yes)
                        victims[k].crimeday=mod_date;
                    break;
                }

                else
                    cout<<"Enter a valid date!"<<endl;
            }
            fflush(stdin);
            while(1)
            {
                cout<<"\t\tMonth: ";
                cin>>x.crimemonth;
                if(mod_date>0 && mod_date<13)
                {
                    crimemonth=mod_date;
                    if(yes)
                        victims[k].crimemonth=mod_date;
                    break;
                }

                else
                    cout<<"Enter a valid month!"<<endl;
            }
            fflush(stdin);
            while(1)
            {
                cout<<"\t\tYear: ";
                cin>>mod_date;
                if(mod_date>year)
                {
                    crimeyear=mod_date;
                    if(yes)
                        victims[k].crimeyear=mod_date;
                    break;
                }

                else
                    cout<<"\t\tENTER A VALID YEAR!"<<endl;
            }
        }
        system("cls");
        cout << "\n\t\t----ENTER THE  MODIFIED POLICE RECORD----\n";
        cout << "\n\tPolice Station       :\t"<<station;
        cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout << "\n\tPolice Station       :\t";
            cin>>modified_data;
            station=modified_data;
            if(yes)
                victims[k].station=modified_data;
        }

        cout << "\n\tCase NO.             :\t"<<fir_no;
        cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
        cin>>c;
        if(c=='Y' || c=='y')
        {
            cout << "\n\tCase NO.             :\t";
            cin>>modified_data;
            fir_no=modified_data;
            if(yes)
                victims[k].fir_no=modified_data;
        }
        fflush(stdin);
        cout<<endl<<endl;
        loc = (check-1)*sizeof(Victim);
        file.seekp(loc);
        file.write((char*)this,sizeof(Victim));

        file.close();
        cout <<"\n";
        fflush(stdin);
        cout << "\n\n\t\t\t < RECORD MODIFIED >"<<endl<<endl;

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
            //  callExit();
        }
    }

}

void Victim::delete_record(char con_no[]) // function for deleting a record
{
    fstream file;
    fflush(stdin);
    file.open("bechara.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    int c = q/sizeof(Victim);
    fstream temp;
    temp.open("temp.txt",ios::out|ios::binary);
    if(temp.fail())
    {
        cout<<"THE TEMPORARY FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    file.seekg(0,ios::beg);
    for(int i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Victim));
        if(strcmp(con_no,victim_id) != 0)
            temp.write((char*)this,sizeof(Victim));
    }
    file.close();
    temp.close();
    file.open("bechara.txt",ios::out|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    temp.open("temp.txt",ios::in|ios::ate|ios::binary);
    if(temp.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    int a = temp.tellg();
    int size = a/sizeof(Victim);
    temp.seekg(0,ios::beg);
    for(int k=0; k<size; k++)
    {
        temp.read((char*)this,sizeof(Victim));
        file.write((char*)this,sizeof(Victim));
    }
    file.close();
    temp.close();
    cout<<"\n\n\t\t< THE RECORD HAS BEEN DELETED >";
    cout <<"\n";
    fflush(stdin);
    getchar();
}


void Victim::remove()
{
    fflush(stdin);
    system("cls");
    char id[10];
    int s;
    cout << "\n\n\n\t\tENTER THE CONVICT ID TO BE DELETED: ";
    cin>>id;
    s = this->check_id(id);
    if(s!=0)
        this->delete_record(id);
    bool yes=false;
    for(int i=0; i<vcount; i++)
    {
        if(victims[i].victim_id==id)
        {
            vcount--;
            yes=true;
        }
        if(yes)
        {
            victims[i]=victims[i+1];
        }

    }
}

void Victim::list_all() // function to list all Victim records
{
    system("cls");
    fflush(stdin);
    int j ;
    fstream file;
    file.open("bechara.txt",ios::in|ios::ate|ios::binary);
    int q = file.tellg();
    int c = q/sizeof(Victim);
    file.seekg(0);
    cout<<"                            \n";
    cout<<"		                                 \n";
    cout<<"                                VICTIM  LIST    \n";
    cout<<"			                         \n";
    cout<<"                            \n";
    cout<<"\n===============================================================================\n";
    cout<<"SR.\tNAME\t\t\tVICTIM ID.\t\t\tCRIME \t\t\n";
    cout<<"===============================================================================\n";
    int i = 0;
    while(file.read((char*)this,sizeof(Victim)))
    {
        i++;
        cout << i << "       ";
        for(j=0; j<strlen(this->name); j++)
            cout << this->name[j];
        cout<<"\t\t\t    ";
        for(j=0; j<strlen(this->victim_id); j++)
            cout << this->victim_id[j];
        cout << "\t\t\t   ";
        for(j=0; j<(this->crime.size)(); j++)
            cout << this->crime[j];
        cout << "\t\t\t   ";

        cout <<"\n";
        fflush(stdin);
        getchar();
        cout << "\n-------------------------------------------------------------------------------------------------------------\n";
        if((i%5)==0&&(i!=c))
        {
            system("pause");
            system("cls");
            cout << "\n============================================================================\n";
            cout << "SR.\tNAME\t\t\tVICTIM NO.\t\t\tCRIME \t\t\n";
            cout << "=================================================================================\n";
        }
    }
    file.close();
    getchar();
}
