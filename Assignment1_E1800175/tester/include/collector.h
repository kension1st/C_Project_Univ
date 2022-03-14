#ifndef COLLECTOR_H
#define COLLECTOR_H
#include <string>

//create class collector
class collector {
  //public variable
  public:
    std::string address;
  public:

  //public alias
    collector(std::string adrs="");
    ~collector()
    {
    }
    std::string getaddress();

    void setaddress(std::string adrs);

    void displaycollector();
};

collector :: collector(std::string adrs)
{
    address = adrs;
}

std::string collector :: getaddress()
{
    return address;
}

void collector :: setaddress(std::string adrs)
{
    address = adrs;
}

#endif // COLLECTOR_H
