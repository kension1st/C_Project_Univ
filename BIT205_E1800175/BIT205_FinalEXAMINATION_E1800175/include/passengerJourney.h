#ifndef PASSENGERJOURNEY_H
#define PASSENGERJOURNEY_H
#include <trainJourney.h>
#include <string>


/// QUESTION 3
class passengerJourney: public trainJourney {
    int noFirstClass, noSecondClass, noEcoClass;
    bool catering;
public:
    passengerJourney(
            const string &startTown,
            const string &endTown,
            int journeyTime,
            int noFirstClass,
            int noSecondClass,
            int noEcoClass,
            bool catering
            ): trainJourney(
            startTown,
            endTown,
            journeyTime
            ), noFirstClass(noFirstClass),
               noSecondClass(noSecondClass),
               noEcoClass(noEcoClass),
               catering(catering) {}

    int getNoFirstClass() const {
        return noFirstClass;
    }

    void setNoFirstClass(int noFirstClass) {
        passengerJourney::noFirstClass = noFirstClass;
    }

    int getNoSecondClass() const {
        return noSecondClass;
    }

    void setNoSecondClass(int noSecondClass) {
        passengerJourney::noSecondClass = noSecondClass;
    }

    int getNoEcoClass() const {
        return noEcoClass;
    }

    void setNoEcoClass(int noEcoClass) {
        passengerJourney::noEcoClass = noEcoClass;
    }

    bool isCatering() const {
        return catering;
    }

    void setCatering(bool catering) {
        passengerJourney::catering = catering;
    }

    void viewJourney() override {
        cout << "(Passenger Journey) "
             << "has"
             << (catering ? " " : " no ")
             << "restaurant on board. ";
        printAttributes();
        cout << "[First: "
        << noEcoClass
        << ", Second: "
        << noSecondClass
        << ", Eco: "
        << noEcoClass
        << "]"
        << endl;
    }
};

#endif // PASSENGERJOURNEY_H
