
#include "Person.h"

void Person::get_data()
{

    //cin>>id;*/
    cout<<"\n\t\t\t\t"<<"  Enter Name :";
    gets(name);
    cout<<"\n\t\t\t\t"<<"  Enter Age :";
    cin>>age;
    cout<<"\n\t\t\t\t"<<"  Enter Gender :";
    cin>>gender;
    cout<<"\n\t\t\t\t"<<"  Enter Date of Birth: "<<endl;
    while(1)
    {
        cout<<"\n\t\t\t\t    "<<"Date: ";
        cin>>day;
        if(day>0 && day<31)
            break;
        else
            cout<<"\n\t\t\t   "<<"Enter a valid date!"<<endl;
    }
    fflush(stdin);
    while(1)
    {
        cout<<"\n\t\t\t\t    "<<"Month: ";
        cin>>month;
        if(month>0 && month<13)
            break;
        else
            cout<<"\n\t\t\t    "<<"Enter a valid month!"<<endl;
    }
    fflush(stdin);
    cout<<"\n\t\t\t\t    "<<"Year: ";
    cin>>year;
    fflush(stdin);
}
void Person::get_address()
{
    cout<<"\n\t\t\t\t"<<"  Enter Division :";
    cin>>division;
    cout<<"\n\t\t\t\t"<<"  Enter District :";
    cin>>district;
    cout<<"\n\t\t\t\t"<<"  Enter Area :";
    cin>>area;
}

void Person::display_information()
{

    cout<<"\n\n\t\t\t"<<"ID :"<<id<<endl;
    cout<<"\n\n\t\t\t"<<"Name :"<<name<<endl;
    cout<<"\n\n\t\t\t"<<"Age :"<<age<< " years"<<endl;
    cout<<"\n\n\t\t\t"<<"Gender :"<<gender<<endl;
    cout<<"\n\n\t\t\t"<<"Date of birth :"<<day<<"/"<<month<<"/"<<year<<endl;

}
void Person::display_address()
{
    cout<<"\n\n\t\t\t"<<"Division :"<<division<<endl;
    cout<<"\n\n\t\t\t"<<"District :"<<district<<endl;
    cout<<"\n\n\t\t\t"<<"Area :"<<area<<endl;
}
