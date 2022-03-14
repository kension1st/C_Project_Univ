#include <iostream>
#include "system.h"
#include <vector>

using namespace std;

int main()
{
    ecoSave collector;
    ecoSave recycler;
    ecoSave admin;
    ecoSave material;
    string username, password, fullname, totalpoints, address, materialID, materialName, description, pointPerKg, ecolevel;
    char choice;
    while ( choice !='q' || choice !='Q'){
        loop :
        cout << "-----------MAIN MENU------------" << endl;
        cout << "1. Add New User" << endl;
        cout << "2. Login Your Account" << endl;
        cout << "3. Quit the Program"<< endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "Enter Choice :" ;
        cin >> choice;

        if (choice == '1'){
            cout << endl;
            cout << "Choose Collector or Recycler :" << endl;
            cout << " C for (Collector)" << endl;
            cout << " R for (Recycler)" << endl;
            cout << " A for (Admin)" << endl;
            cout <<  endl;
            cout << " Please Enter Your Choice :";
            cin >> choice;
            while (choice !='1'){
                    if (choice == 'C' || choice == 'c'){
                        cout << "Add User Collector" << endl;
                        cout << endl;
                        cout << "Username :" ; //username
                        cin >> username;
                        cout << "Pass :" ; //password
                        cin >> password;
                        cout << "Fllname :" ; //fullname
                        cin >> fullname;
                        cout << "Ttl Point :" ; //total point
                        cin >> totalpoints;
                        cout << "Addrss :" ; //address
                        cin >> address;
                        cout << collector.sadd(username, password, fullname, totalpoints, address);
                        cout << endl;
                }
                    else if (choice == 'R' || choice == 'r'){
                        cout << "Add User Recycler " << endl;
                        cout << endl;
                        cout << "Username :"  ; //username
                        cin >> username;
                        cout << "Pass :"  ; //password
                        cin >> password;
                        cout << "Fllname :" ;  //fullname
                        getline(cin >> ws, fullname);
                        cout << "Ttl Points :" ; //total point
                        cin >> totalpoints;
                        cout << "Eco Evel :"  ;
                        cin >>ecolevel;
                        cout << collector.sacc(username, password, fullname, totalpoints, ecolevel);
                        cout << endl;

                }
                    else if (choice == 'A' || choice == 'a')
                    {
                        cout << "Add User Admin" << endl;
                        cout << endl;
                        cout << "Username :" ; //username
                        cin >> username;
                        cout << "Pass :" ; //password
                        cin >> password;
                        cout << "Fllname :" ; //fullname
                        cin >> fullname;
                        cout << "Addrss :" ; //address
                        cin >> address;
                        cout << admin.sadd(username, password, fullname, 0, address);
                        cout << endl;
                    }

                break;
            }
            goto loop;

        }
        else if (choice == '2'){
            cout << "Login Your Account" << endl;
            cout << "Username :";  //username
            cin >> username;
            cout << "pass :";  //password
            cin >> password;


                user* sadd=nullptr;
                user*sacc=nullptr;
                user* adm=nullptr;
                sacc = recycler.loginuser(username,password);//Recycler
                sadd = collector.loginuser(username, password); //Collectors
                adm = admin.loginuser(username, password);//Admin
                if (sadd==nullptr || sacc==nullptr || adm==nullptr){//Collectors
                    cout <<  endl;
                    cout << "Your Id Or Password Is Wrong" << endl;
                    cout << "Make Your Account" << endl;
                }
                else if (sadd !=nullptr ) { //Collectors
                    user*pi = dynamic_cast <user*>(sadd);
                    if (pi !=nullptr){
                    cout << "1.Edit Profile" << endl;
                    cout << "2.Making Submission" << endl;
                    cout << "3.View Submission" << endl;
                    cout << "4.Exit" << endl;
                    cout <<"Enter Choice :";
                    cin >> choice;
                    }
                }
                else if (sacc != nullptr) { //Recycler
                    user*pi = dynamic_cast <user*>(sacc);
                    if (pi !=nullptr){
                        cout <<"1. Edit Profile" << endl;
                        cout <<"2. Adding submission" << endl;
                        cout <<"3. Edit submission" << endl;
                        cout <<"4. Exit" << endl;
                        cout <<"Enter Choice :";
                        cin >> choice;
                    }
                }
                else if (adm != nullptr) //Admin
                {
                    user* pa = dynamic_cast<user*>(adm);
                    if (pa != nullptr)
                    {
                        cout << "1. Add Material" <<endl;
                        cout << "2. Update Material" <<endl;
                        cout << "3. Delete Material" <<endl;
                        cout << "4. View Material" <<endl;
                        cout << "5. Exit" <<endl;
                        cout << "your choice: ";
                        cin >> choice;

                        if(choice == 'a' || choice == 'A')
                        {
                            string material_name, _description;
                            int pointsPer_kg;
                            cout << "Input Material Name: ";
                            cin >> materialName;
                            cout << "Input description: ";
                            cin >> _description;
                            cout << "Input Points Per Kg: ";
                            cin >> pointsPer_kg;
                            cout << endl;
                            cout << material.addingMaterialData(materialName, _description, pointsPer_kg)<<endl;
                            cout << "Data Added \n";


                        }

                    }
                }
            }

        }
    return 0;
}
