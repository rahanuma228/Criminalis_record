#include "Criminal.h"
#include<graphics.h>
int ccount=0;

void Criminal::get_Personal_Info()
{
    cout<<endl<<endl<<endl;
    int d=0;
    cout<<"\tEnter Convict ID: ";
    cin>>convict_id;

    cout<<endl<<endl;
    cout<<"Enter Convict Details: "<<endl;
    cout<<endl;

    fflush(stdin);
    cout<<"\tEnter name: ";
    gets(name);
    fflush(stdin);
    cout<<"\tGender: ";
    cin>>gender;
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
    cout<<"\tEnter blood type: ";
    cin>>blood_type;
    fflush(stdin);
    cout<<endl<<endl;
}
void Criminal::get_Description()
{
    cout<<endl<<endl<<endl;
    cout<<"Enter description of the convict: "<<endl<<endl;
    cout<<"\tEthnicity: ";
    cin>>ethnicity;
    fflush(stdin);
    cout<<"\tComplexion: ";
    cin>>complexion;
    fflush(stdin);
    cout<<"\tFace: ";
    cin>>face;
    fflush(stdin);
    cout<<"\tEye color: ";
    cin>>eye_color;
    fflush(stdin);
    cout<<"\tHair color: ";
    cin>>hair_color;
    fflush(stdin);
    cout<<"\tIdentification mark: ";
    gets(imark);
    fflush(stdin);
    cout<<"\tHeight: ";
    cin>>height;
    fflush(stdin);
    cout<<"\tWeight: ";
    cin>>weight;
    fflush(stdin);
    cout<<endl<<endl;
}
void Criminal::get_CrimeInfo()
{
    cout<<endl<<endl<<endl;
    cout<<"Enter information about the crime: "<<endl<<endl;
    cout<<"\tAct of Crime: ";
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
    cout<<"\t\tDivision: ";
    cin>>crimediv;
    fflush(stdin);
    cout<<"\t\tDistrict: ";
    cin>>crimedis;
    fflush(stdin);
    cout<<"\t\tArea: ";
    cin>>crimearea;
    fflush(stdin);
    cout<<"\t\tPostal Code: ";
    cin>>crime_pcode;
    fflush(stdin);
    cout<<endl<<endl;

}
 void Criminal::get_PoliceInfo()
    {
        cout<<endl<<endl<<endl;
        cout<<"Enter Criminal Station Information: "<<endl<<endl;
        cout<<"\tStation: ";
        cin>>station;
        fflush(stdin);
        cout<<"\tCase no.: ";
        cin>>fir_no;
        fflush(stdin);
        cout<<"\tArrest Warrant:"<<endl
            <<"\t\t1.Issued"<<endl
            <<"\t\t2.Not Issued"<<endl;
        cout<<"\t\tChoice: ";
        int arrest;
        cin>>arrest;
        if(arrest==1)
        {
            strcpy(arrest_warrant,"Issued");
            cout<<"\tDate of Arrest {Format: dd/mm/year}: ";
            gets(arrest_date);
        }
        else if(arrest==2)
            strcpy(arrest_warrant,"Not Issued");
        fflush(stdin);
        cout<<endl<<endl;
    }
void Criminal::get_data()
{
    get_Personal_Info();
    system("cls");
    get_Description();
    system("cls");
    get_CrimeInfo();
    system("cls");
    get_PoliceInfo();
}
Criminal Criminal::criminals[10000];
bool Criminal::match_id(char v[])
{
    if(strcmp(id,v)==0)
        return true;
    return false;
}
void Criminal::add(Criminal* Case_Criminals[], int criminalcnt)      // Function for getting Convicts Record
{

    system("cls");
    fstream file;
    int error=-1;
    try
    {
        file.open("oporadhii.txt",ios::app|ios::binary);
        if(file.fail())
            throw error;

    }
    catch(int error)
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    Criminal c;
    get_data();
    // c.
    fflush(stdin);

    char ch;
    do
    {
        cout << endl<<"DO YOU WANT TO SAVE THIS INFORMATION(Y/N) : ";
        cin >> ch;

        if(ch=='y'||ch=='Y')
        {
            cout << "\n\n\t< RECORD HAS BEEN SAVED >";
            file.write((char*)this,sizeof(Criminal));
            criminals[ccount]=(*this);
            Case_Criminals[criminalcnt] = &criminals[ccount];
            ccount++;

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

int Criminal::check_id(char id[])
{
    system("cls");
    fstream file;
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    int x = 0, count = 0, c;
    int q = file.tellg();
    c = q/sizeof(Criminal);
    file.close();
    file.open("oporadhii.txt",ios::in|ios::binary);
    for(int i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Criminal));
        count++;//finding the actual position of the id
        if(strcmp(id,convict_id)==0)
        {
            x++;
            break;
        }
    }
    if(x==0)
    {
        //cout<<count;
        cout<<"\n\n\n\n\tCONVICT RECORD NOT FOUND!!!!!! ";
        getchar();
        return 0;
    }
    else
    {
        return count;
    }
    file.close();
}
void Criminal::output()      // Function for showing Convict's Record
{
    system("cls");
    fflush(stdin);

    cout << "\n\n\t\t----------PERSONAL RECORD OF CONVICT----------";
    cout << "\n\tConvict ID             :\t"<<convict_id;
    cout << "\n\tName                   :\t"<<name;
    cout << "\n\tGender                 :\t" << gender;
    cout << "\n\tAddress                \t";
    cout<<"\n\t\tDivision       :\t"<<division<<endl;
    cout<<"\t\tDistrict       :\t"<<district<<endl;
    cout<<"\t\tArea           :\t"<<area<<endl;
    cout<<"\t\tPostal Code    :\t"<<post_code<<endl;
    cout<<endl<<"\tDate of Birth          :\t"<<day<<"/"<<month<<"/"<<year;

    cout << "\n\n\n\t\t\t";
    system("pause");
    fflush(stdin);
    system("cls");

    cout << "\n\n\t\t\t----------DESCRIPTION----------\n";
    cout<< "\n\tEthnicity              :\t"<<ethnicity;
    cout << "\n\tSkin Complexion        :\t"<<complexion;
    cout << "\n\tFace                   :\t"<<face;
    cout << "\n\tIdentification Mark    :\t"<<imark;
    cout << "\n\tHeight                 :\t"<<height;
    cout <<"\n\tWeight                 :\t"<<weight;
    cout << "\n\tEye Color              :\t"<<eye_color;
    cout <<"\n\tHair color             :\t"<<hair_color;
    cout << "\n\n\n\t\t\t";

    system("pause");
    system("cls");
    fflush(stdin);

    cout << "\n\n\t\t----------CRIMINAL RECORD----------";
    cout << "\n\tAct of Crime                       :\t"<<crime;
    cout << "\n\tDate of Crime                      :\t"<<crimeday<<"/"<<crimemonth<<"/"<<crimeyear;
    cout << "\n\tPlace of Crime";
    cout<<"\n\t\tDivision       :\t"<<crimediv<<endl;
    cout<<"\t\tDistrict       :\t"<<crimedis<<endl;
    cout<<"\t\tArea           :\t"<<crimearea<<endl;
    cout<<"\t\tPostal Code    :\t"<<crime_pcode<<endl;
    cout << "\n\n\n\t\t\t";

    system("pause");
    fflush(stdin);
    system("cls");

    cout << "\n\n\n\t\t----------POLICE INFORMATION---------- \n\n";
    cout << "\n\tPolice Station       :\t"<<station;
    cout << "\n\tCase NO.             :\t"<<fir_no;
    cout<<"\n\tArrest Warrant       :\t"<<arrest_warrant;
    if(arrest_warrant=="Issued")
        cout << "\n\tDate of arrest    :\t"<<arrest_date;
    cout << "\n\n\n\t\t\t";
    system("pause");
    fflush(stdin);
}

void Criminal::display()    // function to display record
{
    system("cls");
    fflush(stdin);
    char N[10];
    int rec;
    int loc;
    cout << "\n\n\n\t\tENTER THE CONVICT ID TO SEE INFORMATION: ";
    gets(N);
    fstream file;
    rec = this->check_id(N);
    file.open("oporadhii.txt",ios::app|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    if(rec!=0)
    {
        loc = (rec-1)*sizeof(Criminal);
        file.seekg(loc);
        file.read((char*)this,sizeof(Criminal));
        this->output();
    }
    file.close();
    cout <<"\n";
    fflush(stdin);
}

void Criminal::modify(char str[]) // function to modify record
{
    system("cls");
    fflush(stdin);
    fstream file;
    char modified_data[100];
    // char str[10];
    int check,loc,mod_date;
    Criminal x;
    fflush(stdin);
modify_start:
    //  cout << "\n\tENTER CONVICT ID TO EDIT RECORD: ";
    //  cin>>str;
    check = this->check_id(str);
    int k;
    bool yes=false;
    for(k=0; k<ccount; k++)
    {
        if(str==criminals[k].convict_id)
        {
            yes=true;
            break;
        }
    }
    char c;
     if(check!=0)
          {
               file.open("oporadhii.txt",ios::out|ios::in|ios::binary);
                if(file.fail())
                {
                    cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
                    cin.ignore();
                    cin.get();
                }
                cout << "\n\n\t\tRECORD FOUND !\n\n";
                    cout << "\n\t\tConvict ID             :\t"<<convict_id;
                    cout << "\n\t\tName                   :\t"<<name<<endl<<endl;
                cout << "\n\t----ENTER MODIFIED DETAILS----\n";
                cout << "\n\tAct of Crime                       :\t"<<crime;

                    cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
                    cin>>c;
                    if(c=='Y' || c=='y')
                    {
                        cout << "\n\t\t\t\tAct of Crime      : ";
                        cin >> modified_data;
                        strcpy(crime,modified_data);
                        //if(yes) criminals[k].crime=modified_data;
                    }
                    fflush(stdin);
                    cout << "\n\tPlace of Crime                     :\t";
                        cout<<"\n\t\tDivision       :\t"<<crimediv<<endl;
                        cout<<"\t\tDistrict       :\t"<<crimedis<<endl;
                        cout<<"\t\tArea           :\t"<<crimearea<<endl;
                        cout<<"\t\tPostal Code    :\t"<<crime_pcode<<endl;
                    cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
                    cin>>c;
                    if(c=='Y' || c=='y')
                    {
                        int temp;
                        cout << "\n\tPlace of Crime                     :\t";
                                cout<<"\t\tDivision: ";
                                cin>>modified_data;
                                strcpy(crimediv,modified_data);
                                //if(yes) criminals[k].crimediv=modified_data;
                                fflush(stdin);

                                cout<<"\t\tDistrict: ";
                                cin>>modified_data;
                                strcpy(crimedis,modified_data);
                               // if(yes) criminals[k].crimedis=modified_data;
                                fflush(stdin);

                                cout<<"\t\tArea: ";
                                cin>>modified_data;
                                strcpy(crimearea,modified_data);
                                //if(yes) criminals[k].crimearea=modified_data;
                                fflush(stdin);

                                cout<<"\t\tPostal Code: ";
                                cin>>temp;
                                crime_pcode=temp;
                               // if(yes) criminals[k].crime_pcode=temp;
                                fflush(stdin);

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
                                if(yes) criminals[k].crimeday=mod_date;
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
                                if(yes) criminals[k].crimemonth=mod_date;
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
                                if(yes) criminals[k].crimeyear=mod_date;
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
                        strcpy(station,modified_data);
                        // if(yes) criminals[k].station=modified_data;
                    }

                    cout << "\n\tCase NO.             :\t"<<fir_no;
                    cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
                    cin>>c;
                    if(c=='Y' || c=='y')
                    {
                        cout << "\n\tCase NO.             :\t";
                        cin>>modified_data;
                        strcpy(fir_no,modified_data);
                        //if(yes) criminals[k].fir_no=modified_data;
                    }
                    fflush(stdin);
                    cout<<"\n\tArrest Warrant       :\t"<<arrest_warrant;
                     cout<<"\n\t\tDoes this need to be modified?(y/n)? : ";
                    cin>>c;
                    if(c=='Y' || c=='y')
                    {
                         cout<<"\n\tArrest Warrant       :\t";
                        int choice;
                        cout<<"\t\t1.Issued"<<endl
                            <<"\t\t2.Not Issued"<<endl;
                        cout<<"\t\tChoice: ";
                        cin>>choice;
                        if(choice==1)
                        {
                            strcpy(arrest_warrant,"Issued");
                            //if(yes) criminals[k].arrest_warrant=arrest_warrant;
                            cout<<"\t\tDate of Arrest {Format: dd/mm/year}: ";
                            cin>>modified_data;
                            strcpy(arrest_date,modified_data);
                           // if(yes) criminals[k].arrest_date=modified_data;
                        }
                        else if(choice==2)
                        {
                             strcpy(arrest_warrant,"Not Issued");
                           // if(yes) criminals[k].arrest_warrant=arrest_warrant;
                        }

                        fflush(stdin);
                        cout<<endl<<endl;
                    }
                loc = (check-1)*sizeof(Criminal);
                file.seekp(loc);
                file.write((char*)this,sizeof(Criminal));

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

void Criminal::delete_record(char con_no[]) // function for deleting a record
{
    fstream file;
    fflush(stdin);
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    int c = q/sizeof(Criminal);
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
        file.read((char*)this,sizeof(Criminal));
        if(strcmp(con_no,convict_id) != 0)
            temp.write((char*)this,sizeof(Criminal));
    }
    file.close();
    temp.close();
    file.open("oporadhii.txt",ios::out|ios::binary);
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
    int size = a/sizeof(Criminal);
    temp.seekg(0,ios::beg);
    for(int k=0; k<size; k++)
    {
        temp.read((char*)this,sizeof(Criminal));
        file.write((char*)this,sizeof(Criminal));
    }
    file.close();
    temp.close();
    cout<<"\n\n\t\t< THE RECORD HAS BEEN DELETED >";
    cout <<"\n";
    fflush(stdin);
    getchar();
}


void Criminal::remove()
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
    //vector<Criminal>::iterator it;
    bool yes=false;
    for(int i=0; i<ccount; i++)
    {
        if(criminals[i].convict_id==id)
        {
            ccount--;
            yes=true;
        }
        if(yes)
        {
            criminals[i]=criminals[i+1];
        }

    }
}

void Criminal::list_all() // function to list all criminal records
{
    system("cls");
    fflush(stdin);
    int j ;
    fstream file;
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    int q = file.tellg();
    int c = q/sizeof(Criminal);
    file.seekg(0);
    cout<<"                            \n";
    cout<<"		                                 \n";
    cout<<"                                CONVICT  LIST    \n";
    cout<<"			                         \n";
    cout<<"                            \n";
    cout<<"\n============================================================================================================\n";
    cout<<"SR.\tNAME\t\t\tCONVICT NO.\t\t\tCRIME \t\t   ARREST WARRANT STATUS\n";
    cout<<"============================================================================================================\n";
    int i = 0;
    while(file.read((char*)this,sizeof(Criminal)))
    {
        i++;
        cout << i << "       ";
        for(j=0; j<strlen(this->name); j++)
            cout << this->name[j];
        cout<<"\t\t\t    ";
        for(j=0; j<strlen(this->convict_id); j++)
            cout << this->convict_id[j];
        cout << "\t\t\t   ";
        for(j=0; j<strlen(this->crime); j++)
          cout << this->crime[j];
        cout << "\t\t\t   ";
        for(j=0; j<strlen(this->arrest_warrant); j++)
          cout << this->arrest_warrant[j];
        cout <<"\n";
        fflush(stdin);
        getchar();
        cout << "\n-------------------------------------------------------------------------------------------------------------\n";
        if((i%5)==0&&(i!=c))
        {
            system("pause");
            system("cls");
            cout << "\n======================================================================================================\n";
            cout << "SR.\tNAME\t\t\tCONVICT NO.\t\t\tCRIME \t\t   ARREST WARRANT STATUS\n";
            cout << "============================================================================================================\n";
        }
    }
    file.close();
    getchar();
}

void Criminal::show_division_statistics()
{
    system("cls");
    vector<string>temp;
    fflush(stdin);
    string div_name;
    map<string,int>statistics;
    fstream file;
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    int c = q/sizeof(Criminal);
    file.close();
    file.open("oporadhii.txt",ios::in|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    for(int i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Criminal));
        div_name=crimediv;
        transform(div_name.begin(), div_name.end(), div_name.begin(), ::tolower);
        temp.push_back(div_name);
    }
    file.close();
    for(int j=0; j<temp.size(); j++)
    {
        //cout<<temp[j]<<endl;
        temp[j][0]=toupper(temp[j][0]);
        statistics[temp[j]]++;
    }
    cout<<"\n";
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Division"<<"               Crime Count"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    map<string,int>::iterator it;
    for(it=statistics.begin(); it!=statistics.end(); it++)
    {
        cout<<(*it).first<<"                          "<<(*it).second<<endl;
        cout<<"--------------------------------------------------"<<endl;
    }
    system("pause");

}

void Criminal::show_crime_statistics()
{
    system("cls");
    fflush(stdin);
    fstream file;
    map<string,int>crimes;
    map<string,int>::iterator itr;
    vector<string>v;
    string cname;
    int i;
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED!!!!!!!";

        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    int c = q/sizeof(Criminal);
    file.seekp(0,ios::beg);
    for(i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Criminal));
        cname=crime;
        transform(cname.begin(), cname.end(), cname.begin(), ::tolower);
        v.push_back(cname);
    }
    for(i=0; i<v.size(); i++)
    {
        v[i][0]=toupper(v[i][0]);
        crimes[v[i]]++;
    }
    cout << "\n======================================================\n";
    cout << "NAME OF CRIMES\t\t\tCRIME COUNT\n";
    cout << "======================================================\n";
    for(itr=crimes.begin(); itr!=crimes.end(); itr++)
    {
        cout<<(*itr).first<<"                              "<<(*itr).second<<endl;
        cout << "------------------------------------------------------\n";
    }

    system("pause");
}

void Criminal:: show_Overall_statistics()
{
    system("cls");
    vector<string>temp;
    fflush(stdin);
    string div_name;
    map<string,int>stats,dhk,brsh,ctg,khul,syl,rjs,rang,mymen;
    fstream file;
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    const int c = q/sizeof(Criminal);
    file.close();

    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    file.seekp(0,ios::beg);
    for(int i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Criminal));
        div_name=crimediv;
        transform(div_name.begin(), div_name.end(), div_name.begin(), ::tolower);
        if(div_name=="dhaka")
            dhk[crime]++;
        else if(div_name=="barishal" || division=="barisal")
            brsh[crime]++;
        else if(div_name=="khulna")
            khul[crime]++;
        else if(div_name=="rajshahi")
            rjs[crime]++;
        else if(div_name=="chittagong" || division=="chattagram")
            ctg[crime]++;
        else if(div_name=="rangpur")
            rang[crime]++;
        else if(div_name=="khulna")
            khul[crime]++;
        else
            mymen[crime]++;
    }
    //1.Dhaka
    cout << "\t\t\t======================================================\n";
    cout<<"\t\t\t|\t\t\tDhaka"<<"                        |  "<<endl;
    cout << "\t\t\t======================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t======================================================\n";
    for(auto &pr:dhk)
    {
        cout<<"\t\t\t-------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t-------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");
    //2.Barishal
    cout << "\t\t\t=========================================================\n";
    cout<<"\t\t\t|\t\t\tBarishal"<<"                        |  "<<endl;
    cout << "\t\t\t=========================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t=========================================================\n";
    for(auto &pr:brsh)
    {
        cout<<"\t\t\t---------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t---------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");
    //3.Rajshahi
    cout << "\t\t\t========================================================\n";
    cout<<"\t\t\t|\t\t\tRajshahi"<<"                        |  "<<endl;
    cout << "\t\t\t========================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t========================================================\n";
    for(auto &pr:rjs)
    {
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");
    //4.Sylhet
    cout << "\t\t\t=======================================================\n";
    cout<<"\t\t\t|\t\t\tSylhet"<<"                        |  "<<endl;
    cout << "\t\t\t=======================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t=======================================================\n";
    for(auto &pr:syl)
    {
        cout<<"\t\t\t-------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t-------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");

    //5.Khulna
    cout << "\t\t\t=======================================================\n";
    cout<<"\t\t\t|\t\t\tKhulna"<<"                        |  "<<endl;
    cout << "\t\t\t=======================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t=======================================================\n";
    for(auto &pr:khul)
    {
        cout<<"\t\t\t-------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t-------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");
    //6.Chittagong
    cout << "\t\t\t===========================================================\n";
    cout<<"\t\t\t|\t\t\tChittagong"<<"                        |  "<<endl;
    cout << "\t\t\t===========================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t===========================================================\n";
    for(auto &pr:ctg)
    {
        cout<<"\t\t\t------------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t---------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");

    //7.Rangpur
    cout << "\t\t\t========================================================\n";
    cout<<"\t\t\t|\t\t\tRangpur"<<"                        |  "<<endl;
    cout << "\t\t\t========================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t========================================================\n";
    for(auto &pr:rang)
    {
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t--------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");
    //8.Mymensingh
    cout << "\t\t\t===========================================================\n";
    cout<<"\t\t\t|\t\t\tMymensingh"<<"                        |"<<endl;
    cout << "\t\t\t===========================================================\n";
    cout << "\t\t\tNAME OF CRIMES\t\t|\t\tCOUNT\n";
    cout << "\t\t\t===========================================================\n";
    for(auto &pr:mymen)
    {
        cout<<"\t\t\t---------------------------------------------------------"<<endl;
        if(pr.first.size()<6)
            cout<<"\t\t\t"<<pr.first<<"     \t\t\t|\t\t  "<<pr.second<<endl;
        else
            cout<<"\t\t\t"<<pr.first<<"\t\t\t|\t\t  "<<pr.second<<endl;
        cout<<"\t\t\t---------------------------------------------------------"<<endl;
    }
    system("pause");
    system("cls");

}
void Criminal::crime_pie()
{
  system("cls");
   fstream file;
    map<string,int>crimes;
    map<string,int>::iterator itr;
    vector<string>v;
    int count=0;
    string cname;
    int i;
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED!!!!!!!";

        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    int c = q/sizeof(Criminal);
    file.seekp(0,ios::beg);
    for(i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Criminal));
        cname=crime;
        transform(cname.begin(),cname.end(),cname.begin(),::toupper);
        v.push_back(cname);
        count++;
    }
    int n=count;
    int gd = DETECT, gm, x, y;
    initwindow(800,600,"OCCURENCE OF CRIME");
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(215,50,"   OCCURENCE OF CRIME");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    int m=0,d=0;
    int u=0;

    for(i=0; i<v.size(); i++)
    {
        crimes[v[i]]++;
    }
    int e=200;
    int cn=0;
    int sum=0;
         cout<<"-----------------------------------------------------";
    cout<<"\n\tNAME OF CRIME\t\t\t"<<"OCCURENCE RATE"<<endl;
      cout<<"-----------------------------------------------------";
    for(itr=crimes.begin(); itr!=crimes.end(); itr++)
        {
        u++;
        int a;
        if(cn==crimes.size()-1)
        {
            a=360-sum;
        }
        else
        a=((*itr).second*360)/n;
        sum=sum+a;
        float ry=(float((*itr).second)*100)/n;
        string b=(*itr).first;
        cout<<"\n\t"<<b<<"\t\t\t\t"<<ry<<"%"<<endl;
       cout<<"-----------------------------------------------------";
        setfillstyle(SOLID_FILL,u);
        pieslice(300, 300,m,m+a,150);
        setfillstyle(SOLID_FILL,u);
        circle(538, e, 10);
        floodfill(540,e+2,15);
        if(b[0]=='M'&& b[1]=='U' && b[2]=='R' )
        {
            outtextxy(550,e-10,"  MURDER");
        }
        else if(b[0]=='D'&& b[1]=='R' && b[2]=='U')
        {
            outtextxy(550,e-10,"  DRUG");
        }
        else if(b[0]=='R'&& b[1]=='A' && b[2]=='P')
        {
            outtextxy(550,e-10,"  RAPE");
        }
        else if(b[0]=='C'&& b[1]=='H' && b[2]=='I' )
        {
            outtextxy(550,e-10,"  CHILD ABUSE");
        }
        else if(b[0]=='D' && b[1]=='O' && b[2]=='M' )
        {
            outtextxy(550,e-10,"   DOMESTIC ABUSE");
        }
        else if(b[0]=='R' && b[1]=='O' && b[2]=='B')
        {
            outtextxy(550,e-10,"  ROBBERY");
        }
        else if(b[0]=='E' && b[1]=='V' && b[2]=='E')
        {
            outtextxy(550,e-10,"  EVE TEASING");
        }
        else if(b[0]=='F' && b[1]=='R' && b[2]=='A')
        {
            outtextxy(550,e-10,"  FRAUD");
        }
        else if(b[0]=='T' && b[1]=='E' && b[2]=='R')
        {
            outtextxy(550,e-10,"  TERRORISM");
        }
        else if(b[0]=='C' && b[1]=='O' && b[2]=='N')
        {
            outtextxy(550,e-10,"  CONTRACT KILLING");
        }
        e=e+30;
        m=m+a;
        if(u==15)
        {
            u=0;
        }
        cn++;
    }
    getch();
    closegraph();
}
void Criminal::div_pie()
{
    system("cls");
   fstream file;
    map<string,int>crimes;
    map<string,int>::iterator itr;
    vector<string>v;
    int count=0;
    string cdiv;
    int i;
    file.open("oporadhii.txt",ios::in|ios::ate|ios::binary);
    if(file.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED!!!!!!!";

        cin.ignore();
        cin.get();
    }
    int q = file.tellg();
    int c = q/sizeof(Criminal);
    file.seekp(0,ios::beg);
    for(i=0; i<c; i++)
    {
        file.read((char*)this,sizeof(Criminal));
        cdiv=crimediv;
        transform(cdiv.begin(),cdiv.end(),cdiv.begin(),::toupper);
        v.push_back(cdiv);
        count++;
    }
    int n=count;
    int gd = DETECT, gm, x, y;
   initwindow(900,600,"CRIME RATE IN DIVISIONS");
    settextstyle(BOLD_FONT,HORIZ_DIR,3);
    outtextxy(215,50,"   CRIME RATE IN DIVISIONS");
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    int m=0,d=0;
    int u=0;


    for(i=0; i<v.size(); i++)
    {
        crimes[v[i]]++;
    }
    int e=200;
    int zum=0;
    int cx=0;
     cout<<"-------------------------------------------------------------";
    cout<<"\n\tDIVISION\t\t\t"<<"OCCURENCE OF CRIME"<<endl;
      cout<<"------------------------------------------------------------";
    for(itr=crimes.begin(); itr!=crimes.end(); itr++)
    {
        u++;
        int a;
        if(cx==crimes.size()-1)
        {
            a=360-zum;
        }
         else
            a=((*itr).second*360)/n;
         zum=zum+a;
        float ry=(float((*itr).second)*100)/n;
        string b=(*itr).first;
        cout<<"\n\t"<<b<<"\t\t\t\t"<<ry<<"%"<<endl;
       cout<<"------------------------------------------------------------";
        setfillstyle(SOLID_FILL,u);
        pieslice(300,300,m,m+a,150);
        setfillstyle(SOLID_FILL,u);
        circle(540, e, 10);
        floodfill(542,e+2,15);
        if(b[0]=='B')
        {
            outtextxy(550,e-10,"  BARISAL");
        }
        else if(b[0]=='D' )
        {
            outtextxy(550,e-10,"  DHAKA");
        }
        else if(b[0]=='C')
        {
            outtextxy(550,e-10,"  CHITTAGONG");
        }
        else if(b[0]=='K')
        {
            outtextxy(550,e-10,"  KHULNA");
        }
        else if(b[0]=='S' )
        {
            outtextxy(550,e-10,"  SYLHET");
        }
        else if(b[0]=='M' )
        {
            outtextxy(550,e-10,"  MYMENSINGH");
        }
        else if(b[0]=='R' && b[2]=='J' )
        {
            outtextxy(550,e-10,"  RAJSHASHI");
        }
        else if(b[0]=='R' && b[2]=='N' )
        {
            outtextxy(550,e-10,"  RANGPUR");
        }
        e=e+30;
        m=m+a;
        if(u==15)
        {
            u=0;
        }
        cx++;
    }
    getch();
    closegraph();
}

