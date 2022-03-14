//NAME : I Kadek Yau Dwi Mega Saputra
//STUDENT ID : E1800175
//SUBJECT : LAB TEST 2

#include <iostream>

using namespace std;

struct training
{
    double cost; //cost of training
    string trainingName;
    string typeOfTraining; // can be either Zumba, Yoga, Pilates only
    int maxParticipants;
    training *next;
};

class trainingRec    {       // The class
    public:             // Access specifier
    int trainerNumber;        // Attribute (int variable)
    string trainerName;  // Attribute (string variable)
};

int menu()
{
     cout<<"1. Create new trainers"<<endl;
     cout<<"2. Add Trainings "<<endl;
     cout<<"3. Edit Trainings "<<endl;
     cout<<"4. Print Trainings "<<endl;
     int option;
     cout<<"Your option >>>>"<<flush;
     cin>>option;
     return option;
}

training train[100];
int index = 0;
int indexe = 0;
int select;

void addTrainers(){
    string name;
    trainingRec trainer;
    cout<<"Input Trainer Name : ";
    cin>>name;
    trainer.trainerName = name;
    cout<<endl;
}
void addTrainings(){
    string type;
    cout<<endl;
    cout<<"Input trainingName : ";
    cin>> train[index].trainingName;
    do
     {
        cout<<"List Of Type Training"<<endl;
        cout<<"1. Zumba"<<endl;
        cout<<"2. Yoga"<<endl;
        cout<<"3. Pilates"<<endl;
        cout<<"Select Type :";
        cin>>select;

            if (select==1){
                type="Zumba";
            }
            else if (select==2){
                type="Yoga";
            }
            else if (select==3){
                type="Pilates";
            }
            else{
                cout<<"Wrong Input"<<endl;
            }
    }while (select > 3);
    train[index].typeOfTraining=type;
    cout<<"Input Max Participant : ";
    cin>> train[index].maxParticipants;
    index=index+1;
    cout<<endl;
}
void editTrainigs(){

    cout<<"Input Code : ";
    cin>> indexe;
    string type;
    cout<<endl;
    cout<<"trainingName : "<<train[indexe].trainingName<<endl;
    do
     {
        cout<<"List Of Type Training"<<endl;
        cout<<"1. Zumba"<<endl;
        cout<<"2. Yoga"<<endl;
        cout<<"3. Pilates"<<endl;
        cout<<"Select Type :";
        cin>>select;

            if (select==1){
                type="Zumba";
            }
            else if (select==2){
                type="Yoga";
            }
            else if (select==3){
                type="Pilates";
            }
            else{
                cout<<"Wrong Input"<<endl;
            }
    }while (select > 3);
    train[indexe].typeOfTraining=type;
    cout<<"Input Max Participant : ";
    cin>> train[indexe].maxParticipants;
    cout<<endl;
}
void printTrainings(){
    for(int i=0; i<index; i++)
    {
        cout<<endl;
        cout<<"list :"<<i<<endl;
        cout<<"Training Name \t :"<<train[i].trainingName<<endl;
        cout<<"Type Training \t :"<<train[i].typeOfTraining<<endl;
        cout<<"Max Participant :"<<train[i].maxParticipants<<endl;
        cout<<endl;
    }

}


int main()
{
     trainingRec trainer;
     int option;
     do
     {
        option=menu();
        switch (option)
        {
             case 1: addTrainers(); //creating a trainer
             break;
             case 2:
                 cout << trainer.trainerName << "\n";
                 addTrainings(); //add trainings sessions
             break;
             case 3:
                 cout << trainer.trainerName << "\n";
                 printTrainings();
                 editTrainigs(); //editing a training session
             break;
             case 4:
                 cout << trainer.trainerName << "\n";
                 printTrainings(); //to print all the training sessions
             break;

             default :cout<<"Bye"<<endl;
         }
     }while (option <=4);

     return 0;
}


