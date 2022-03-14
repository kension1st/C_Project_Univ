#ifndef FREIGHTJOURNEY_H
#define FREIGHTJOURNEY_H
#include <trainJourney.h>
#include <string>

/// QUESTION 2
class freightJourney: public trainJourney {
    int capacity;
    int carriages;
    bool hazardous;
public:
    freightJourney(
            const string &startTown,
            const string &endTown,
            int journeyTime,
            int capacity,
            int carriages,
            bool hazardous
            ): trainJourney(
                    startTown,
                    endTown,
                    journeyTime
                    ),
                    capacity(capacity),
                    carriages(carriages),
                    hazardous(hazardous) {}

    int getCapacity() const {
        return capacity;
    }

    void setCapacity(int capacity) {
        freightJourney::capacity = capacity;
    }

    int getCarriages() const {
        return carriages;
    }

    void setCarriages(int carriages) {
        freightJourney::carriages = carriages;
    }

    bool isHazardous() const {
        return hazardous;
    }

    void setHazardous(bool hazardous) {
        freightJourney::hazardous = hazardous;
    }

    void viewJourney() override {
        cout << "(Freight Journey) "
        << "hazardous materials"
        << (hazardous ? " " : " not ")
        << "allowed. ";
        printAttributes();
        cout << "Capacity: " << capacity
        << ". Carriages: " << carriages
        << endl;
    }
};
#endif // FREIGHTJOURNEY_H
