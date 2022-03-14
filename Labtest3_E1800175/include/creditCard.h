#ifndef CREDITCARD_H
#define CREDITCARD_H
#include <string>


class creditCard
{
    public:
        std::string ownerName;
        int cardNum;

    public:
        double accPoints;
        int listOfTrans;

    public:
        creditCard(std::string ownN="", int cdn=0, double acpnt=0, int lot=0);
        ~creditCard()
        {
        }

        std::string getownerName();
        double getcardNum();
        double getaccPoints();
        double getlistOfTrans();


        void setownerName(std::string ownN);
        void setcardNum(int cdn);

        void setaccPoints(double acpnt);
        void setlistOfTrans(int lot);

        void print();
};

creditCard :: creditCard (std::string ownN, int cdn, double acpnt, int lot)
{
    ownerName = ownN;
    cardNum = cdn;
    accPoints = acpnt;
    listOfTrans = lot;
}

std::string creditCard :: getownerName()
{
    return ownerName;
}

double creditCard :: getcardNum()
{
    return cardNum;
}

double creditCard :: getaccPoints()
{
    return accPoints;
}
double creditCard :: getlistOfTrans()
{
    return listOfTrans;
}


void creditCard :: setownerName(std::string ownN)
{
    ownerName = ownN;
}
void creditCard ::  setcardNum(int cdn)
{
    cardNum = cdn;
}

void creditCard :: setaccPoints(double acpnt)
{
    accPoints = acpnt;
}
void creditCard :: setlistOfTrans(int lot)
{
    listOfTrans = lot;
}

#endif // CREDITCARD_H
