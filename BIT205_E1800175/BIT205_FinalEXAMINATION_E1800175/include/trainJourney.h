#ifndef TRAINJOURNEY_H
#define TRAINJOURNEY_H
#include <string>

using namespace std;

/// QUESTION 1
class trainJourney {
    int trainID;
    string startTown;
    string endTown;
    int journeyTime;

public:
    static int ai;

    trainJourney(
            const string &startTown,
            const string &endTown,
            int journeyTime
            ):
            startTown(startTown),
            endTown(endTown),
            journeyTime(journeyTime) { trainID = ai++; }

    int getTrainId() const {
        return trainID;
    }

    const string &getStartTown() const {
        return startTown;
    }

    const string &getEndTown() const {
        return endTown;
    }

    int getJourneyTime() const {
        return journeyTime;
    }

    virtual void viewJourney() = 0;

    friend
    bool operator==(const trainJourney &ltj, const trainJourney &rtj) {
        return ltj.trainID == rtj.trainID &&
               ltj.startTown == rtj.startTown &&
               ltj.endTown == rtj.endTown &&
               ltj.journeyTime == rtj.journeyTime;
    }

protected:
    void setTrainId(int trainId) {
        trainID = trainId;
    }

    void setStartTown(const string &startTown) {
        trainJourney::startTown = startTown;
    }

    void setEndTown(const string &endTown) {
        trainJourney::endTown = endTown;
    }

    void setJourneyTime(int journeyTime) {
        trainJourney::journeyTime = journeyTime;
    }

    void printAttributes() {
        cout << "ID: " << trainID
        << " Origin: " << startTown
        << " Destination: " << endTown
        << " takes " << journeyTime << " minutes.";
    }
};



#endif // TRAINJOURNEY_H
