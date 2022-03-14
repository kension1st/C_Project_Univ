#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <string>


class transactions
{
    private:
        std::string itemName;
        double purchaseAmount;
        int loft;

    public:
        transactions(std::string itmnm="", double prchamnt=0, int ls=0);
        ~transactions()
        {
        }
        std::string getitemName();
        double getpurchaseAmount();
        int getloft();

        void setitemName(std::string itmnm);
        void setpurchaseAmount(int prchamnt);
        void setloft(int ls);

        void displaytransaction();
};

transactions :: transactions (std::string itmnm, double prchamnt, int ls)
{
    itemName = itmnm;
    purchaseAmount = prchamnt;
    loft = ls;
}

std::string transactions :: getitemName()
{
    return itemName;
}
double transactions :: getpurchaseAmount()
{
    return purchaseAmount;
}

int transactions :: getloft()
{
    return loft;
}

void transactions :: setitemName(std::string itmnm)
{
    itemName = itmnm;
}

void transactions :: setpurchaseAmount(int prchamnt)
{
    purchaseAmount = prchamnt;
}

void transactions :: setloft(int ls)
{
    loft = ls;
}



#endif // TRANSACTIONS_H
