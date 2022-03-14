#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct order
{
    int orderID;
    int accountNo;
    double tax, total;
} order;
typedef struct customer
{
    int accountNo;
    string accountName, shippingAdd;
} customer;

typedef struct orderbyphone
{
    int accountNo;
    string clerkName, phoneNumber;
} orderbyphone;
typedef struct orderbyInternet
{
    int accountNo;
    string urlAddress;
} orderbyInternet;

int main()
{
     char option,r,r2;
     ifstream fi;
     ofstream fo;
     order ord;
     customer cst;
     orderbyInternet odbi;
     orderbyphone odbp;
     do{
            cout<<"\n\nWelcome to HELP Inventory System"<<endl;
            cout<<"1. Create customer"<<endl;
            cout<<"2. Add Order "<<endl;
            cout<<"3. Print Statement "<<endl;
            cout<<"4. Exit "<<endl;
            cout<<"Your option >>>>";
            cin>>option;

            if(option=='1'){
                    int idn;
                    fi.open("cst.dat", ios::binary);
                    while(fi.read((char *) &cst, sizeof(cst)))
                    {
                        idn=cst.accountNo;
                    }
                    idn=idn+1;
                    fi.close();

                    char name,add;

                    fo.open("cst.dat", ios::binary | ios::app);
                    cout << "Enter Name             : ";
                    cin >> name;
                    cst.accountName = name;
                    cout << "Enter Shipping Address : ";
                    cin >> add;
                    cst.shippingAdd = add;
                    cout <<endl;
                    cst.accountNo=idn;
                    fo.write((char *) &cst, sizeof(cst));
                    fo.close();

                    cout<<"Customer "<<name<<" with account no "<<idn<<" has been successfully been created";

            }
            else if(option=='2'){
                    int idn;
                    cout<<"Enter Account No.";
                    cin>>idn;
                    fi.open("cst.dat", ios::binary);
                             while(fi.read((char *) &cst, sizeof(cst)))
                                {
                                if(cst.accountNo == idn)
                                {
                                    cout<<"1. Order by Phone"<<endl;
                                    cout<<"2. Order by Internet "<<endl;
                                    fi.close();
                                    cout<<"Your option >>>>";
                                    cin>>r;
                                    cout<<endl;
                                    if(r=='1'){
                                            fstream f;
                                            string name, phone;
                                            double tax, total;
                                            fo.open("odbp.dat", ios::binary | ios::app);
                                            f.open("ord.dat", ios::binary | ios::app);
                                            cout << "Enter Clerk Name       : ";
                                            cin >> name;
                                            odbp.clerkName=name;
                                            cout << "Enter Phone Number     : ";
                                            cin >> phone;
                                            odbp.phoneNumber=phone;
                                            cout << "Enter Tax              : RM";
                                            cin >> tax;
                                            ord.tax=tax;
                                            cout << "Enter Total            : RM";
                                            cin >> total;
                                            ord.total=total;
                                            cout <<endl;
                                            odbp.accountNo=idn;
                                            ord.accountNo=idn;
                                            fo.write((char *) &odbp, sizeof(odbp));
                                            f.write((char *) &ord, sizeof(ord));
                                            fo.close();
                                            f.close();


                                    }
                                    else if(r=='2'){
                                            fstream f;
                                            string name;
                                            double tax, total;
                                            fo.open("odbi.dat", ios::binary | ios::app);
                                            f.open("odr.dat", ios::binary | ios::app);
                                            cout << "Enter URL              : ";
                                            cin >> name;
                                            odbi.urlAddress=name;
                                            cout << "Enter Tax              : RM";
                                            cin >> tax;
                                            ord.tax=tax;
                                            cout << "Enter Total            : RM";
                                            cin >> total;
                                            ord.total=total;
                                            cout <<endl;
                                            odbi.accountNo=idn;
                                            ord.accountNo=idn;
                                            fo.write((char *) &odbi, sizeof(odbi));
                                            f.write((char *) &ord, sizeof(ord));
                                            fo.close();
                                            f.close();
                                    }
                                }
                                else{
                                cout << "You are not registered yet" <<endl<<endl;
                                }
                                }
            }



            else if(option=='3'){
                    int idn;
                    string name;
                    cout<<"Enter Account No.";
                    cin>>idn;
                    cout<<"Enter Name       :";
                    cin>>name;
            }
            else if(option=='4'){
                    cout<<"Exit.....";
            }
            cout<<endl;
            cout<<"Do you reset ? (y/n)??";
            cin>>r2;
            system ("CLS");

        }
        while(r2=='Y' or r2=='y');

}
