#ifndef RECYCLER_H
#define RECYCLER_H
#include <string>

//create class recycler
class recycler {
  //public variable
  public:
    std::string ecoLevel;
  public:

  //public alias
    recycler(std::string ecol="");
    ~recycler()
    {
    }
    std::string getecolevel();

    void setecolevel(std::string ecol);

    void displayrecycler();
};

recycler :: recycler(std::string ecol)
{
    ecoLevel = ecol;
}

std::string recycler :: getecolevel()
{
    return ecoLevel;
}

void recycler :: setecolevel(std::string ecol)
{
    ecoLevel = ecol;
}

#endif // COLLEC
