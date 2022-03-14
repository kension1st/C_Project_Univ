#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct user
{
    char username[20], password[10], fullName[50], mobileNo[50], level;
} user;

typedef struct ServiceReq
{
    char reqID[10], requiredDate[50], notes[50], status[50];
} ServiceReq;

typedef struct seniorHelp
{
} seniorHelp;

typedef struct provider
{
} provider;

typedef struct senior
{
    char address[20];
} senior;

typedef struct review
{
    char date[50], rating[10], comments[50];
} review;

typedef struct serviceType
{
    char servicecode[10], servicedesciption[100];
} serviceType;



int main()
{
    ifstream fi;
    ofstream fo;
    user usr;
    ServiceReq svr;
    char m1, m2, m3, usrn[20], pw[10], r, us[10], ds[10];

    do{

    cout << "=============Menu=============" <<endl;
    cout << "|C / 1| To Create New Account" <<endl;
    cout << "|L / 2| To Login" <<endl<<endl;
    cout <<"Select :";
    cin>>m1;
    cout <<endl<<endl;
    cout << "==============================" <<endl;

    /**
    * write data into the into file.
    */

    if (m1=='c' or m1=='C' or m1=='1')
    {
        fo.open("usr.dat", ios::binary | ios::app);
        cout << "Username     : ";
        cin >> usr.username;
        cout << "Password     : ";
        cin >> usr.password;
        cout << "Full Name    : ";
        cin >> usr.fullName;
        cout << "Mobile Number: ";
        cin >> usr.mobileNo;
        cout <<endl;
        cout << "|S / s| To Become Senior" <<endl;
        cout << "|P / p| To Become Service Provider" <<endl<<endl;
        cout <<"Select :";
        cin>>m2;
        if(m2=='S' or m2=='s'){
            usr.level=m2;
            fo.write((char *) &usr, sizeof(usr));
            fo.close();
        }
        else if(m2=='P' or m2=='p'){
            usr.level=m2;
            fo.write((char *) &usr, sizeof(usr));
            fo.close();

        }
        else{
            cout<<"No Menu Selected"<<endl;
        }
    }
    /**
    * to do login page
    */
    else if (m1=='l' or m1=='L' or m1=='2')
        {
        cout <<"Username :";
        cin>>usrn;
        cout <<"Password: ";
        cin>>pw;


         fi.open("usr.dat", ios::binary);
         while(fi.read((char *) &usr, sizeof(usr)))
            {
                if(strcmp(usr.username, usrn) == 0 && strcmp(usr.password, pw) == 0)
                {
                    cout << "=============Welcome============="<<endl;
                    cout << "Name  : " << usr.username <<endl;

                    /**
                    * Menu Senior.
                    */
                    if(usr.level=='S' or usr.level=='s')
                    {
                        cout << "level : Senior" <<endl<<endl;
                        cout << "|A / 1| To Add New Services" <<endl;
                        cout << "|U / 2| To Update Services" <<endl;
                        cout << "|D / 3| To Delete Services" <<endl<<endl;
                        fi.close();
                        cout <<"Select :";
                        cin>>m3;
                        cout<<endl;


                        if(m3=='a' or m3=='A' or m3=='1')
                        {
                            fo.open("svr.dat", ios::binary | ios::app);
                            cout << "Request ID    : ";
                            cin >> svr.reqID;
                            cout << "Required Date : ";
                            cin >> svr.requiredDate;
                            cout << "notes         : ";
                            cin >> svr.notes;
                            cout << "Status        : ";
                            cin >> svr.status;
                            cout <<endl;
                            fo.write((char *) &svr, sizeof(svr));
                            fo.close();
                        }
                        else if(m3=='U' or m3=='u' or m3=='2')
                        {
                                fi.open("svr.dat", ios::binary);
                                while(fi.read((char *) &svr, sizeof(svr)))
                                {
                                    cout << "Request ID    : " <<svr.reqID <<endl;
                                    cout << "Required Date : " <<svr.requiredDate <<endl;
                                    cout << "notes         : " <<svr.notes <<endl;
                                    cout << "Status        : " <<svr.status <<endl<<endl;

                                }
                                fi.close();

                                cout <<"Select ID To Update:";
                                cin>>us;

                                fstream f;
                                f.open("svr.dat", ios::in|ios::out );
                                while(f.read((char *) &svr, sizeof(svr))){

                                    if(strcmp(svr.reqID, us) == 0) {

                                        //view all detail
                                        cout << "Request ID    : " <<svr.reqID <<endl;
                                        cout << "Required Date : " <<svr.requiredDate <<endl;
                                        cout << "notes         : " <<svr.notes <<endl;
                                        cout << "Status        : " <<svr.status <<endl<<endl;

                                        //input new data
                                        cout<<"Input New Data to Update" <<endl;
                                        cout << "==============================" <<endl;
                                        cout << "Request ID    : ";
                                        cin >> svr.reqID;
                                        cout << "Required Date : ";
                                        cin >> svr.requiredDate;
                                        cout << "notes         : ";
                                        cin >> svr.notes;
                                        cout << "Status        : ";
                                        cin >> svr.status;
                                        cout <<endl;


                                        }
                                    }
                                    f.close();
                        }


                        else if(m3=='D' or m3=='d' or m3=='3')
                        {
                                fi.open("svr.dat", ios::binary);
                                while(fi.read((char *) &svr, sizeof(svr)))
                                {
                                    cout << "Request ID    : " <<svr.reqID <<endl;
                                    cout << "Required Date : " <<svr.requiredDate <<endl;
                                    cout << "notes         : " <<svr.notes <<endl;
                                    cout << "Status        : " <<svr.status <<endl<<endl;

                                }
                                fi.close();

                                cout <<"Select ID To Deleted:";
                                cin>>ds;

                                fi.open("svr.dat", ios::binary);
                                fo.open("tmp.dat", ios::out|ios::binary);
                                int fd = 0;

                                while(fi.read((char*) &svr, sizeof(svr)))
                                {
                                    if(strcmp(svr.reqID, ds) == 0)
                                        {
                                            fd = 1;

                                        }
                                    else{
                                            fo.write((char*)&svr, sizeof(svr));
                                        }
                                }
                                fi.close();
                                fo.close();
                                remove("svr.dat");
                                rename("tmp.dat", "svr.dat");

                                if (fd ==1)
                                {
                                    cout<<"ID " << ds << " Has Been Deleted!\n";
                                }
                                else{
                                    cout<<"ID " << ds << " Not Founded!\n";
                                }
                        }
                        else{
                            cout<<"No Menu Selected"<<endl;
                        }
                    }









                    /**
                    * Menu Service Provider.
                    */
                    else if(usr.level=='P' or usr.level=='p')
                    {
                        cout << "level : Service Provider" <<endl<<endl;
                        cout << "|V / 1| To View Services" <<endl;
                        cout << "|A / 2| To Accept Services" <<endl<<endl;
                        fi.close();
                        cout <<"Select :";
                        cin>>m3;
                        cout<<endl;

                        if(m3=='v' or m3=='V' or m3=='1')
                        {
                                fi.open("svr.dat", ios::binary);
                                while(fi.read((char *) &svr, sizeof(svr)))
                                {
                                    cout << "Request ID    : " <<svr.reqID <<endl;
                                    cout << "Required Date : " <<svr.requiredDate <<endl;
                                    cout << "notes         : " <<svr.notes <<endl;
                                    cout << "Status        : " <<svr.status <<endl<<endl;

                                }
                                fi.close();

                        }
                        else if(m3=='A' or m3=='a' or m3=='2'){
                                fi.open("svr.dat", ios::binary);
                                while(fi.read((char *) &svr, sizeof(svr)))
                                {
                                    cout << "Request ID    : " <<svr.reqID <<endl;
                                    cout << "Required Date : " <<svr.requiredDate <<endl;
                                    cout << "notes         : " <<svr.notes <<endl;
                                    cout << "Status        : " <<svr.status <<endl<<endl;

                                }
                                fi.close();

                                cout <<"Select ID To Update:";
                                cin>>us;

                                fstream f;
                                f.open("svr.dat", ios::in|ios::out );
                                while(f.read((char *) &svr, sizeof(svr))){

                                    if(strcmp(svr.reqID, us) == 0) {

                                        //view all detail
                                        cout << "Request ID    : " <<svr.reqID <<endl;
                                        cout << "Required Date : " <<svr.requiredDate <<endl;
                                        cout << "notes         : " <<svr.notes <<endl;
                                        cout << "Status        : " <<svr.status <<endl<<endl;

                                        //input new status
                                        cout<<"Input New Status of data to Update" <<endl;
                                        cout << "==============================" <<endl;
                                        cout << "Status        : ";
                                        cin >> svr.status;
                                        cout <<endl;

                                        }
                                    }
                                    f.close();

                        }
                        else{
                            cout<<"No Menu Selected"<<endl;
                        }


                    }

                    else{
                        cout << "You are not registered yet" <<endl<<endl;
                    }

                }
            }

        }
     cout<<"Do you wish to continue ? (y/n)??";
     cin>>r;
     system ("CLS");
    }
    while(r=='y' or r=='Y');
}
