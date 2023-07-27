#include "time_function.h"

void callExit()
{
    int process = 0;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\n\tTaking You Out of The System";
    for(process=0; process<25; process++)
    {
        delay(150);
        cout <<".";
    }
    system("cls");
    cout <<"\n\n\n\n\n\n\n\n\n\n\n";
    cout <<"\t\t\t\t\t";
    cout <<"You are out of the System.\n";
    cout <<"\t\t\t\t\t\t";
    cout << "Thank You !";
    cout <<"\n\n";
    cout <<"\t\t\t\t\t";
    system("pause");
    exit(0);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void date1()
{
    time_t T= time(NULL);
    struct  tm tm = *localtime(&T);
    cout << "\n\n\n";
    cout << "\t\t\t\t\t   Date:" << tm.tm_mday << "/" << tm.tm_mon+1  << "/" << tm.tm_year+1900 << "\n";
}

