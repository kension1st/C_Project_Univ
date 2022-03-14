//Name  : I Kadek Yau Dwi Mega Saputra
//Nim   : E1800175
//Compal: CodeBlock


#include <iostream>
#include <trainJourney.h>
#include <freightJourney.h>
#include <passengerJourney.h>

#include <vector>

using namespace std;

int trainJourney::ai = 1111;
/// Methods required for question 4
int menu();
void addtrainJourney(vector<trainJourney*> &listJourney);
void viewpassengerJourneys(
        vector<trainJourney*> &listJourney,
        const string& startTown,
        const string& endTown

        );
void summaryReport(vector<trainJourney*> &listJourney);


int main() {
    vector<trainJourney*> listJourney;
    int chosenMenu;
    do {
        chosenMenu = menu();
        switch (chosenMenu) {
            case 0: {
                cout << "Quitting.." << endl;
                break;
            }
            case 1: {
                addtrainJourney(listJourney);
                break;
            }
            case 2: {
                trainJourney *journey;
                for (int i=0; i<listJourney.size(); i++)
                            {
                                listJourney[i].viewJourney();
                            }
                break;
            }
            case 3: {
                summaryReport(listJourney);
                break;
            }
            default:
                cout << "Invalid input"; break;
        }
        cout << "\n----------------------------------------\n";
    } while (chosenMenu != 0);
    return 0;
}

int menu() {
    int selMenu;
    cout << "1. Add a new train journey\n"
            "2. View passenger train journey\n"
            "3. Summary report\n"
            "0. quit\n"
            ">>>>>>>> ";
    cin >> selMenu;
    return selMenu;
}

void addtrainJourney(vector<trainJourney*> &listJourney) {
    string st, et;
    int jTime;
    trainJourney *journey;

    int chosenJourneyType;
    do {
        cout << "1. Freight\n"
                "2. Passenger\n"
                ">>> ";
        cin >> chosenJourneyType;
        if (chosenJourneyType != 1 && chosenJourneyType != 2)
            cout << "Invalid journey type" << endl;
        else break;
    } while (true);

    cout << "Enter origin town: ";
    cin >> ws;
    getline(cin, st);

    cout << "Enter destination town: ";
    cin >> ws;
    getline(cin, et);

    cout << "Time it takes: ";
    cin >> jTime;

    if (chosenJourneyType == 1) {
        int capacity, carriages;
        string hazardousOpt;
        bool canCarryHazarous;
        cout << "Capacity: ";
        cin >> capacity;
        cout << "Carriages: ";
        cin >> carriages;
        cout << "Can carry hazardous materials ? [y to allow]";
        cin >> ws;
        getline(cin, hazardousOpt);
        canCarryHazarous = (hazardousOpt == "y" || hazardousOpt == "Y");
        journey = new freightJourney(st,et, jTime, capacity, carriages,
                canCarryHazarous);
        listJourney.push_back(journey);
    } else {
        int noFirst, noSecond, noEco;
        string restaurantOpt;
        bool hasRestaurantOnBoard;
        cout << "First class capacity: ";
        cin >> noFirst;
        cout << "Second class capacity: ";
        cin >> noSecond;
        cout << "Economy class capacity: ";
        cin >> noEco;
        cout << "Has a restaurant on board? [Y/n]";
        cin >> ws;
        getline(cin, restaurantOpt);
        hasRestaurantOnBoard = (restaurantOpt == "y" || restaurantOpt == "Y");
        journey = new passengerJourney(st, et, jTime, noFirst, noSecond,
                noEco, hasRestaurantOnBoard);
        listJourney.push_back(journey);
    }
    cout << "New train journey added! Detail: \n";
    journey->viewJourney();
}

void viewpassengerJourneys(
        vector<trainJourney*> &listJourney,
        const string& startTown,
        const string& endTown
) {
}

void summaryReport(vector<trainJourney*> &listJourney) {

}
