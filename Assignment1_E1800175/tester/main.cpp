#include <iostream>
#include <conio.h>
#include <Material.h>
#include <user.h>
#include <collector.h>
#include <recycler.h>
#include <submission.h>
#include <vector>
#include <stdlib.h>
#include <ctime>

time_t now = time(0);
tm *ltm = localtime(&now);

using namespace std;

void material :: displaymaterial()
{
    cout << "material id :" << materialID <<endl;
    cout << "material name :" << materialName << endl;
    cout << "material description :" << description << endl;
    cout << "material pointPerKG :" << pointsPerkg << endl;
}

void user :: displayuser()
{
    cout << "username   : " << username <<endl;
    cout << "password   : " << password <<endl;
    cout << "fullname   : " << fullName <<endl;
    cout << "totalpoint : " << totalPoint <<endl;
}

void collector :: displaycollector()
{
    cout << "address   : " << address <<endl;
}

void recycler :: displayrecycler(){
    cout << "Eco Level   : " << ecoLevel <<endl;
}

void submission :: displaysubmission()
{
    cout << "Submission ID   : " << submissionID <<endl;
    cout << "Proposed Date   : " << proposedDate <<endl;
    cout << "Actual Date     : " << actualDate <<endl;
    cout << "Weight in KG    : " << weightInKg <<endl;
    cout << "Point Awarded   : " << pointAwarded <<endl;
    cout << "Status          : " << status <<endl;
}

char role;

vector<material> mate;
vector<user> usr;
vector<collector> clct;
vector<recycler> rcyl;
vector<submission> subs;

int materialID;
string materialName;
string description;
double pointsPerkg;

int ai=0, aisub=0;

string username;
string password;
string fullName;
double totalPoint;

string address;

string ecoLevel;

int submissionID;
int proposedDate;
int actualDate;
double weightInKg;
double pointAwarded;
string status;

char choose;

int removematerial=0, removesubmission=0, editIDmaterial=0, editIDSubmission=0;

void adduser(){
    cout << "=============Add New User============="<<endl;
    cout << "Username: ";
    cin >> username;
    cout << "password : ";
    cin >> password;
    cout << "fullname : ";
    cin.ignore();
    getline(cin, fullName);
    cout << "totalpoint : 0 "<<endl;
    totalPoint = 0;
    user newuser(username, password, fullName, totalPoint);
    usr.push_back(newuser);
    role='0';
    while(role!='c' && role!='C' && role!='r' && role!='R'){
            cout << "Select Role" << endl;
            cout << "C. Collector" << endl;
            cout << "R. Recycler" << endl;
            cout << "Select The role :";
            cin>>role;
            if(role=='r' || role=='R'){
                cout <<"Recycler" << endl;
                cout << "EcoLevel : Newbie"<<endl;
                ecoLevel="Newbie";
                recycler newrecycler(ecoLevel);
                rcyl.push_back(newrecycler);
                address="";
                collector newcollector(address);
                clct.push_back(newcollector);
                }
            else if(role=='c' || role=='C'){
                cout <<"Collector" << endl;
                cout << "Address :";
                cin>>address;
                collector newcollector(address);
                clct.push_back(newcollector);
                ecoLevel="";
                recycler newrecycler(ecoLevel);
                rcyl.push_back(newrecycler);
                }
            else{
                cout<<"Wrong Input"<<endl;
                }
            }
}

void addmaterial(){
    ai=ai+1;
    cout << "=============Add New  Material============="<<endl;
    cout << "material id : "<<ai<<endl;
    materialID=ai;
    cout << "material name : ";
    cin >> materialName;
    cout << "material description : ";
    cin >> description;
    cout << "material pointPerKG : ";
    cin >> pointsPerkg;
    material newmaterial(materialID, materialName, description, pointsPerkg);
    mate.push_back(newmaterial);
}

void deletematerial(){
    cout << "Please enter Material ID to delete: " ;
    cin >> removematerial;
    for(int i = 0; i < mate.size() ; i++){
        if (mate[i].materialID == removematerial) {
            mate.erase(mate.begin()+i);
            break;
        }
    }
}

void editmaterial(){
    cout << "Please enter Material ID to Edit: " ;
    cin >> editIDmaterial;
    for(int i = 0; i < mate.size() ; i++){
        if (mate[i].materialID == editIDmaterial) {
            mate.erase(mate.begin()+i);
            break;
        }
    }
    cout << "=============Edit New  Material============="<<endl;
    cout << "material id : "<<editIDmaterial<<endl;
    materialID=editIDmaterial;
    cout << "material name : ";
    cin >> materialName;
    cout << "material description : ";
    cin >> description;
    cout << "material pointPerKG : ";
    cin >> pointsPerkg;
    material newmaterial(editIDmaterial, materialName, description, pointsPerkg);
    mate.push_back(newmaterial);
}

void deletesubmission(){
    cout << "Please enter Submission ID to delete: " ;
    cin >> removesubmission;
    for(int i = 0; i < subs.size() ; i++){
        if (subs[i].submissionID == removesubmission) {
            subs.erase(subs.begin()+i);
            break;
        }
    }
}

void editsubmission(){
    cout << "Please enter Submission ID to delete: " ;
    cin >> editIDSubmission;
    for(int i = 0; i < subs.size() ; i++){
        if (subs[i].submissionID == editIDSubmission) {
            subs.erase(subs.begin()+i);
            break;
        }
    }
    cout << "=============Edit Submission============="<<endl;
    cout << "Submission ID   : "<<editIDSubmission<<endl;
    submissionID=editIDSubmission;
    cout << "Proposed Date   : ";
    cin>> proposedDate;
    cout << "Actual Date     : ";
    cin>> actualDate;
    cout << "Weight in KG    : ";
    cin>>weightInKg;
    cout << "Point Awarded   : ";
    cin>>pointAwarded;
    cout << "Status          : ";
    cin>>status;
    submission newsubmission(submissionID, proposedDate, actualDate, weightInKg, pointAwarded, status);
    subs.push_back(newsubmission);
}

void addsubmission(){
    aisub=aisub+1;
    cout << "=============Add New Submission============="<<endl;
    cout << "Submission ID   : "<<aisub<<endl;
    submissionID=aisub;
    cout << "Proposed Date   : "<<ltm->tm_mday<<endl;
    proposedDate=ltm->tm_mday;
    cout << "Actual Date     : "<<1900 + ltm->tm_year<<endl;
    actualDate=1900 + ltm->tm_year;
    cout << "Weight in KG    : ";
    cin>>weightInKg;
    cout << "Point Awarded   : ";
    cin>>pointAwarded;
    cout << "Status          : Proposed"<<endl;
    status="Proposed";
    submission newsubmission(submissionID, proposedDate, actualDate, weightInKg, pointAwarded, status);
    subs.push_back(newsubmission);
}


void usermenu(){
while(choose!='3')
    {
        cout << "=============    DATA USER    ============="<<endl;
        cout << "1. Add New User" << endl;
        cout << "2. List User" << endl;
        cout << "3. Back" << endl;
        cout << "Choose :" << endl;
        cin>>choose;
        switch(choose){
            case '1':
            {
                adduser();
            }
            break;
            case '2':
            {
                cout << "=============    USER    ============="<<endl;
                for (int i=0; i<usr.size(); i++)
                {
                    usr[i].displayuser();
                    if(rcyl[i].ecoLevel != ""){
                        rcyl[i].displayrecycler();
                        }
                    else if(clct[i].address != ""){
                        clct[i].displaycollector();
                        }
                }
            }
            break;

            case '3':
                        break;

            default:
                        cout<<"----================----"<<endl;
                        cout<<"Wrong Input"<<endl;
                        cout<<"----================----"<<endl;
                        break;
        }
    }
}

void admin(){
 while(choose != '0')
    {
        cout << "=============    Admin Dashboard    ============="<<endl;
        cout << "1. Add Material" << endl;
        cout << "2. Display Material" << endl;
        cout << "3. Edit Material" << endl;
        cout << "4. Deleted Material" << endl;

        cout << "5. Add Submission" << endl;
        cout << "6. Display Submission" << endl;
        cout << "7. Edit Submission" << endl;
        cout << "8. Delete Submission" << endl;

        cout << "9. User" << endl;

        cout << "0. Exit" << endl;
        cout << "R. Refresh / Clear" << endl;
        cout << "Choose :" << endl;
        cin>>choose;

        switch(choose)
                {
                    case '1':
                        {
                            addmaterial();
                        }
                        break;
                    case '2':
                        {
                          cout << "=============    Display Material    ============="<<endl;
                          for (int i=0; i<mate.size(); i++)
                            {
                                mate[i].displaymaterial();
                            }
                        }
                        break;

                    case '3':
                        {
                          cout << "=============    Edit Material    ============="<<endl;
                          for (int i=0; i<mate.size(); i++)
                            {
                                mate[i].displaymaterial();
                            }
                          editmaterial();
                        }
                        break;

                    case '4':
                        {
                            cout << "=============    List Material    ============="<<endl;
                            for (int i=0; i<mate.size(); i++)
                            {
                                mate[i].displaymaterial();
                            }
                            deletematerial();
                        }
                        break;

                    case '5':
                        {
                            addsubmission();
                        }
                        break;
                    case '6':
                        {
                          cout << "=============    Display Submission    ============="<<endl;
                          for (int i=0; i<subs.size(); i++)
                            {
                                subs[i].displaysubmission();
                            }
                        }
                        break;
                    case '7':
                        {
                          cout << "=============    Edit Submission    ============="<<endl;
                          for (int i=0; i<subs.size(); i++)
                            {
                                subs[i].displaysubmission();
                            }
                          editsubmission();
                        }
                        break;
                    case '8':
                        {
                            cout << "=============    List Submission    ============="<<endl;
                            for (int i=0; i<subs.size(); i++)
                            {
                                subs[i].displaysubmission();
                            }
                            deletesubmission();
                        }
                        break;
                    case '9':
                        {
                         usermenu();
                        }
                    case 'R': case 'r':
                        {
                          system ("CLS");
                          break;
                        }
                    case '0':
                         system ("CLS");
                         break;

                    default:
                        cout<<"----================----"<<endl;
                        cout<<"Wrong Input"<<endl;
                        cout<<"----================----"<<endl;
                        break;
                }
    }
}

void editprofileR(){
    for(int i = 0; i < usr.size() ; i++){
        if (usr[i].username == username && usr[i].password == password) {
            totalPoint=usr[i].totalPoint;
            usr.erase(usr.begin()+i);
            break;
        }
    }
    cout << "Username: "<<username<<endl;
    cout << "password : "<<password<<endl;
    cout << "fullname : ";
    cin.ignore();
    getline(cin, fullName);
    cout << "totalpoint : "<<totalPoint<<endl;
    user newuser(username, password, fullName, totalPoint);
    usr.push_back(newuser);
    ecoLevel="Newbie";
    recycler newrecycler(ecoLevel);
    rcyl.push_back(newrecycler);
    address="";
    collector newcollector(address);
    clct.push_back(newcollector);
}

void editprofileC(){
    for(int i = 0; i < usr.size() ; i++){
        if (usr[i].username == username && usr[i].password == password) {
            totalPoint=usr[i].totalPoint;
            usr.erase(usr.begin()+i);
            break;
        }
    }
    cout << "Username: "<<username<<endl;
    cout << "password : "<<password<<endl;
    cout << "fullname : ";
    cin.ignore();
    getline(cin, fullName);
    cout << "totalpoint : "<<totalPoint<<endl;
    user newuser(username, password, fullName, totalPoint);
    usr.push_back(newuser);
    cout << "Address :";
    cin>>address;
    collector newcollector(address);
    clct.push_back(newcollector);
    ecoLevel="";
    recycler newrecycler(ecoLevel);
    rcyl.push_back(newrecycler);
}

void recyclermenu(){

        cout << "=============    Recycler Menu    ============="<<endl;
        cout << "P. Edit Profile" << endl;
        cout << "1. Makes Appointments " << endl;
        cout << "2. Display Submission" << endl;
        cout << "3. Deleted Submission" << endl;

        cout << "4. Logout" << endl;
        cout << "R. Refresh / Clear" << endl;
        cout << "Choose :" << endl;
        cin>>choose;

        switch(choose)
                {
                    case 'P': case 'p':
                        {
                            editprofileR();
                        }
                        break;
                    case '1':
                        {
                            addsubmission();
                        }
                        break;
                    case '2':
                        {
                          cout << "=============    Display Submission    ============="<<endl;
                          for (int i=0; i<subs.size(); i++)
                            {
                                subs[i].displaysubmission();
                            }
                        }
                        break;
                    case '3':
                        {
                            cout << "=============    List Submission    ============="<<endl;
                            for (int i=0; i<subs.size(); i++)
                            {
                                subs[i].displaysubmission();
                            }
                            deletesubmission();
                        }
                        break;

                    case 'R': case 'r':
                        {
                          system ("CLS");
                          break;
                        }

                    default:
                        cout<<"----================----"<<endl;
                        cout<<"Wrong Input"<<endl;
                        cout<<"----================----"<<endl;
                        break;
                }

}


void collectormaterial(){
    cout << "Please enter Material ID to Collected: " ;
    cin >> editIDmaterial;
    for(int i = 0; i < mate.size() ; i++){
        if (mate[i].materialID == editIDmaterial) {
            materialName = mate[i].materialName;
            description = mate[i].description;
            pointAwarded = mate[i].pointsPerkg;
            mate.erase(mate.begin()+i);
            break;
        }
    }
    aisub=aisub+1;
    cout << "=============Add New Submission============="<<endl;
    cout << "Submission ID   : "<<aisub<<endl;
    submissionID=aisub;
    cout << "Proposed Date   : "<<ltm->tm_mday<<endl;
    proposedDate=ltm->tm_mday;
    cout << "Actual Date     : "<<1900 + ltm->tm_year<<endl;
    actualDate=1900 + ltm->tm_year;
    cout << "Weight in KG    : ";
    cin>>weightInKg;
    cout << "Point Awarded   : "<<pointAwarded*pointsPerkg<<endl;
    pointAwarded=pointAwarded*pointsPerkg;
    cout << "Status          : Proposed"<<endl;
    status="Proposed";
    submission newsubmission(submissionID, proposedDate, actualDate, weightInKg, pointAwarded, status);
    subs.push_back(newsubmission);
    cout << "=============Material Already Collected============="<<endl;
    material newmaterial(editIDmaterial, materialName, description, pointsPerkg);
    mate.push_back(newmaterial);

    for(int i = 0; i < usr.size() ; i++){
        if (usr[i].username == username && usr[i].password == password) {
            totalPoint=usr[i].totalPoint;
            fullName=usr[i].totalPoint;
            usr.erase(usr.begin()+i);
            break;
        }
    }
    cout << "Username: "<<username<<endl;
    cout << "password : "<<password<<endl;
    cout << "fullname : "<<fullName<<endl;;
    fullName=fullName;
    cout << "totalpoint : "<<totalPoint+pointsPerkg<<endl;
    totalPoint=totalPoint+pointsPerkg;
    user newuser(username, password, fullName, totalPoint);
    usr.push_back(newuser);
    ecoLevel="Newbie";
    recycler newrecycler(ecoLevel);
    rcyl.push_back(newrecycler);
    address="";
    collector newcollector(address);
    clct.push_back(newcollector);

}
void collectormenu(){

        cout << "=============    Collector Menu    ============="<<endl;
        cout << "P. Edit Profile" << endl;
        cout << "1. Collect Material" << endl;
        cout << "2. Display Material" << endl;

        cout << "3. Logout" << endl;
        cout << "R. Refresh / Clear" << endl;

        cout << "Choose :" << endl;
        cin>>choose;

        switch(choose)
                {
                    case 'P': case 'p':
                        {
                            editprofileR();
                        }
                        break;
                    case '1':
                        {
                            cout << "=============    List Material    ============="<<endl;
                            for (int i=0; i<mate.size(); i++)
                            {
                                if(mate[i].pointsPerkg>0){
                                    mate[i].displaymaterial();
                                }
                            }
                            cout << "=============    Collect Material    ============="<<endl;
                            addsubmission();
                        }
                        break;
                    case '2':
                        {
                          cout << "=============    Display Material    ============="<<endl;
                          for (int i=0; i<mate.size(); i++)
                            {
                                mate[i].displaymaterial();
                            }
                        }
                        break;
                    case 'R': case 'r':
                        {
                          system ("CLS");
                          break;
                        }


                    default:
                        cout<<"----================----"<<endl;
                        cout<<"Wrong Input"<<endl;
                        cout<<"----================----"<<endl;
                        break;
                }

}

void login(){
    cout << "Username: ";
    cin >> username;
    cout << "password : ";
    cin >> password;

    if (username =="admin" && password=="admin")
       {
           system ("CLS");
           cout<<"Successfully Login"<<endl;
           cout<<"==========Welcome Admin=========="<<endl;
           admin();
       }
    else{
           for (int i=0; i<usr.size(); i++)
           {
               if(usr[i].username==username && usr[i].password==password){
                    system ("CLS");
                    cout<<"Successfully Login"<<endl;
                    if(rcyl[i].ecoLevel != ""){
                        while(choose != '3')
                        {
                            cout<<"Name :"<<usr[i].fullName<<endl;
                            cout<<"Role : Recycler"<<endl;
                            collectormenu();
                        }
                    }
                    else if(clct[i].address != ""){
                        while(choose != '4')
                        {
                            cout<<"Name :"<<usr[i].fullName<<endl;
                            cout<<"Role : Collector"<<endl;
                            recyclermenu();
                        }
                    }
               }
               else{
                    cout<<"Login Failed"<<endl;
                    cout<<"Make Sure your already Registered"<<endl;
                    cout<<"===================="<<endl;
               }
           }
    }

}


int main()
{
    while(choose != '3')
    {
        cout<<"==========Welcome=========="<<endl;
        cout << "L. Login" << endl;
        cout << "A. Add New User / Registered" << endl;
        cout << "3. Exit" << endl;
        cout << "R. Refresh / Clear" << endl;
        cout << "Choose :" << endl;
        cin>>choose;
        switch(choose)
                {
                    case 'A': case 'a':
                        {
                            adduser();
                        }
                        break;
                    case 'L': case 'l':
                        {
                            login();
                        }
                        break;
                    case '3':
                        break;

                    case 'R': case 'r':
                        {
                          system ("CLS");
                          break;
                        }
                    default:
                        cout<<"----================----"<<endl;
                        cout<<"Wrong Input"<<endl;
                        cout<<"----================----"<<endl;
                        break;
                }
    }

    return 0;
}
