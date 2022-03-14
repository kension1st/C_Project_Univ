#include <iostream>

using namespace std;

struct salespersons{
    string ID;
    int testKitsSold;
    double totalSales;
};

salespersons n[10];
int index = 0;
int qt = 4;
int lqt = 0;
int total=0;
int iq=0;
int i=0;
int hq=0;
string highest_id;
int qt1=0;
int qt2=0;
int qt3=0;
int qt4=0;
int highestamount, highestq;
void calTotalSales()
{
         int SalesMade=0, tls=0;
         tls=n[i].totalSales;
         SalesMade=tls*250;
         cout<<" "<<SalesMade<<endl;

}

void detMaxSales()
{
    for(int i=0; i<index; i++)
    {
        int SalesMade=0, tls=0;
        tls=n[i].totalSales;
        SalesMade=tls*250;
        if(SalesMade>highestamount){
            highest_id=n[i].ID;
            highestamount=n[i].totalSales;
        }
        else{
            highest_id=highest_id;
            highestamount=highestamount;
        }
    }
    cout<<"Max Sale by SalesPerson : ID = "<<highest_id<<", Amount = RM "<<highestamount<<endl;

}

void detMaxQuart()
{
    int c = 1;
    for(int i=0; i<index; i++)
    {
         for(int i=0 ; iq<qt; iq++)
             {
              c=c+1;
              n[iq].testKitsSold;
              if(n[iq].testKitsSold>highestq)
              {
                  highestq=n[iq].testKitsSold;
                  highest_id=n[i].ID;
                  hq=c;
              }
              else{
                  highestq=highestq;
                  highest_id=highest_id;
              }
            }
         qt=qt+4;
         c=1;
    }
    cout<<"Max Sale by Quarter: Quarter = "<<hq<<", Total Test Kits Sold = "<<highestq<<" Amount = RM"<<highestq*250<<endl;

}

void displayReport()
{

         cout<<n[i].ID<<"\t \t";

         for(int i=0 ; iq<qt; iq++)
             {
              cout<<" "<<n[iq].testKitsSold<<"\t";
            }
         qt=qt+4;
         cout<<"\t "<<n[i].totalSales<<"\t";

}

int main()
{
    int select;
    int c = 1;
     while(select != 3)
    {
        cout<<"----HELP Pharmacy----"<<endl;
        cout<<"1. Enter sales information"<<endl;
        cout<<"2. Print Report (as per the output defined above)"<<endl;
        cout<<"3. Exit"<<endl<<endl;
        cout<<"Input Menu :";
        cin>>select;

        switch(select)
        {
            case 1: cout<<"----================----"<<endl;
                    cout<<"Enter sales information "<<endl;
                    cout<<"Input ID : ";
                    cin>> n[index].ID;
                    for(int i=0; i<qt; i++)
                    {
                        cout<<"Input QT "<<c<<" :";
                        int qtc;
                        c=c+1;
                        cin>> qtc;
                        n[lqt].testKitsSold=qtc;
                        total=total+qtc;
                        lqt=lqt+1;

                    }
                    c=1;
                    n[index].totalSales=total;
                    cout<<"Total Sales : "<<total<<endl<<endl;
                    total=0;
                    index=index+1;
                    break;

            case 2: cout<<"----================----"<<endl;
                    cout<<"Print Report"<<endl;
                    cout<<"ID \t \t Q1 \t Q2 \t Q3 \t Q4 \t \t Total \t Sales"<<endl;
                    cout<<"   \t \t    \t    \t    \t    \t \t Sales \t Made"<<endl;
                    for(int i=0; i<index; i++)
                    {
                        displayReport();
                        calTotalSales();
                        cout<<endl;
                    }
                    cout<<endl<<endl;
                    detMaxSales();
                    detMaxQuart();

                    break;

            case 3: cout<<"----================----"<<endl;
                    cout<<"Thanks You"<<endl;
                    break;

            default:cout<<"----================----"<<endl;
                    cout<<"Wrong Input"<<endl;
                    break;
        }
    }
    return 0;
}
