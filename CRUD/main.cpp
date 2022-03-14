#include <iostream>

using namespace std;

void input(){
    cout<<"Create Data";
    return;
}
void output(){
    cout<<"List Data";
    return;
}
void update(){
    cout<<"Edit Data";
    return;
}
void delate(){
    cout<<"Delete Data";
    return;
}

int main()
{
    int menu;
    cout << "Welcome to Database" << endl;
    cout << "===================" << endl;
    cout << "1. Create Data" << endl;
    cout << "2. List Data" << endl;
    cout << "3. Edit Data" << endl;
    cout << "4. Delete Data"<<endl<<endl;

    cout << "Select Menu :";
    cin>>menu;

    if(menu==1){
        input();
    }
    else if(menu==2){
        output();
    }
    else if(menu==3){
        update();
    }
    else if(menu==4){
        delate();
    }

}


