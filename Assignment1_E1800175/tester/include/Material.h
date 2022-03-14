#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

//create class material
class material {
  //public variable
  public:
    int materialID;
    std::string materialName;
    std::string description;
    double pointsPerkg;
  public:

  //public alias
    material(int mID=0, std::string mname="", std::string dsc="", double pnkg =0);
    ~material()
    {
    }
    int getmaterialID();
    std::string getmaterialName();
    std::string getdescription();
    double getpointsPerkg();

    void setmaterialID(int mID);
    void setmaterialName(std::string mname);
    void setdescription(std::string dsc);
    void setpointsPerkg (double pnkg);

    void displaymaterial();
};
material :: material(int mID, std::string mname, std::string dsc, double pnkg)
{
    materialID = mID;
    materialName = mname;
    description = dsc;
    pointsPerkg = pnkg;
}

int material :: getmaterialID()
{
    return materialID;
}

std::string material :: getmaterialName()
{
    return materialName;
}

std::string material :: getdescription()
{
    return description;
}

double material :: getpointsPerkg()
{
    return pointsPerkg;
}




void material :: setmaterialID(int mID)
{
    materialID = mID;
}

void material :: setmaterialName(std::string mname)
{
    materialName = mname;
}

void material :: setdescription(std::string dsc)
{
    description = dsc;
}

void material :: setpointsPerkg (double pnkg)
{
    pointsPerkg = pnkg;
}


#endif // MATERIAL_H
