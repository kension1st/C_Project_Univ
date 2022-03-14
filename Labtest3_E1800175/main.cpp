#include <iostream>
#include <vector>
#include <creditCard.h>
#include <transactions.h>
#include <string>

using namespace std;
vector <transactions> trans;
vector <creditCard> listCard;
int cd=10000;
int ls=0;

int menu()
{
 cout<<"1. Create visa/master"<<endl;
 cout<<"2. Add Transaction "<<endl;
 cout<<"3. Print Statement "<<endl;
 int option;
 cout<<"Your option >>>>"<<flush;
 cin>>option;
 return option;
}

void addMasterVisa(){
    int choosecd;
    string name="";
    cout<<"1. Create Master Card"<<endl;
    cout<<"2. Create Visa Card "<<endl;
    cout<<"Your option >>>>";
    cin>>choosecd;
    cout<<"Enter name :";
    cin.ignore();
    getline(cin, name);
    cout<<"Card Number with the name "<<name<<" with card number "<<cd<<" has been successfully been created"<<endl;
    creditCard newcreditcard(name, cd, 0, ls);
    listCard.push_back(newcreditcard);
    cd=cd+1;
    ls=ls+1;
}

void addTrans(){
    int cdn;
    string itmname;
    int pc;
    char i;
    int pcn;
    int lsn;
    string name="";
    while(i!='n' && i!='N'){
        cout<<"Enter Credit Card Number";
        cin>>cdn;
        for(int i = 0; i < listCard.size() ; i++){
            if (listCard[i].cardNum == cdn) {
                name=listCard[i].ownerName;
                lsn=listCard[i].listOfTrans;
                pc=listCard[i].accPoints;
                listCard.erase(listCard.begin()+i);

                cout<<"Enter item name";
                cin>>itmname;
                cout<<"Enter Price (in RM)";
                cin>>pcn;
                pc=pcn+pc;
                creditCard newcreditcard(name, cdn, pc, lsn);
                listCard.push_back(newcreditcard);

                transactions newtransactions(itmname, pcn, lsn);
                trans.push_back(newtransactions);
                cout<<"Do you wish to continue (y/n)";
                cin>>i;
                break;
            }
            else{
                cout<<"Not Founded"<<endl;
                i='n';
            }
        }


    }
}

void creditCard :: print()
{
        cout << "username   : " << ownerName <<endl;
        cout << "password   : " << cardNum <<endl;
}


int main()
{
 int option;
 do
 {
 option=menu();
 switch (option)
 {
 case 1: addMasterVisa(); //creating master/visa
 break;
 case 2: addTrans(); //add transactions for a specific card
 break;
 case 3: for (int i=0; i<listCard.size(); i++)
        {
            listCard[i].print(); //to print statement for a specific card
        }
 default :cout<<"Bye"<<endl;
 }

 }while (option <=3);
 listCard.clear();
 return 0;
}


//wr
