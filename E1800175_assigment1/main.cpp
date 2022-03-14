#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class material {
  private:
    int materialID;
    string materialName;
    string description;
    double pointsPerkg;
  public:
    material(int mID=0, string mname="", string dsc="", double pnkg =0);
    ~material()
    {
    }
    int getmaterialID();
    string getmaterialName();
    string getdescription();
    double getpointsPerkg();

    void setmaterialID(int mID);
    void setmaterialName(string mname);
    void setdescription(string dsc);
    void setpointsPerkg (double pnkg);

    void display();
};
material :: material(int mID, string mname, string dsc, double pnkg)
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

string material :: getmaterialName()
{
    return materialName;
}

string material :: getdescription()
{
    return description;
}

string material :: getpointsPerkg()
{
    return pointsPerkg;
}




void material :: setmaterialID(int mID)
{
    materialID = mID;
}

void material :: setmaterialName(string mname)
{
    materialName = mname;
}

void material :: setdescription(string dsc)
{
    description = dsc;
}

void material :: setpointsPerkg (double pnkg)
{
    pointsPerkg = pnkg;
}


void material :: display()
{
    cout << "material id " << materialID << endl;
    cout << "material name " << materialName << endl;
    cout << "material description " << description << endl;
    cout << "material pointPerKG " << pointsPerkg << endl;
}


class user {
  private:
    string username;
    string password;
    string fullName;
    double totalPoint;
};


class collector {
  private:
    string address;
};


class recycler {
  private:
    string ecoLevel;
};


class submission {
  private:
    int submissionID;
    int proposedDate;
    int actualDate;
    double weightInKg;
    double pointAwarded;
    string status;
};


int main()
{
    vector<material> mate;
    int materialID;
    string materialName;
    string description;
    double pointsPerkg;

    int choose;
    while(choose != 3)
    {
        cout << "1. Add New users" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose :" << endl;
        cin>>choose;

        switch(choose)
                {
                    case 1:
                        cout << "=============Add New  Material============="<<endl;
                        cout << "material id : ";
                        cin >> materialID;
                        cout << "material name : ";
                        cin >> materialName;
                        cout << "material description : ";
                        cin >> description;
                        cout << "material pointPerKG : ";
                        cin >> pointsPerkg;
                        material newmaterial(materialID, materialName, description, pointsPerkg);
                        mate.push_back(newmaterial);
                        break;
                    case 2:
                        cout << "=============    LOGIN    ============="<<endl;
                        for (int i=0; i<mate.size(); i++)
                        {
                            mate[i].display();
                        }
                        break;
                    case 3:
                        cout << "=============Thanks    You============="<<endl;
                        break;

                    default:cout<<"----================----"<<endl;
                        cout<<"Wrong Input"<<endl;
                        break;
                }
    }




    return 0;
}
