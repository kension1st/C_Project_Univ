#ifndef system_H
#define system_H
#include <string>
#include <vector>
using namespace std;

class user;
class material;
class ecoSave;
class recycler;
class submission;
class collector;
class admin;

class user
{
    protected:
        string username;
        string password;
        string fullname;
        string totalpoints;



    public:
        user( string _username, string _password, string _fullname, string _totalpoints)
       {
        username = _username;
        password = _password;
        fullname = _fullname;
        totalpoints = _totalpoints;
       }
       ~user(){}

    //getter
    string getusername(){
    return username;
    }

    //setter
    void setusername(string _username){
    username = _username;
    }

    //getter
    string getpassword(){
    return password;
    }

    //setter
    void setpassword(string _password){
    password = _password;
    }

    //getter
    string getfullname(){
    return fullname;
    }

    //setter
    void setfullname (string _fullname){
    fullname = _fullname;
    }

    //getter
    string gettotalpoints(){
    return totalpoints;
    }

    //setter
    void settotalpoints (string _totalpoints){
    totalpoints = _totalpoints;
    }


    //showing
    virtual string showing() = 0;
};

class material
{
    private:
        int materialID;
        static int generateID;
        string materialName;
        string description;
        int pointsPerKg;

    public:

        //constructor
        material(  string _materialName, string _description, int _pointsPerKg)
        {
        materialID = generateID++;
        materialName = _materialName ;
        description = _description;
        pointsPerKg = _pointsPerKg;
        }

    //getter
    int getmaterialID(){
    return materialID;
    }

    //setter
    void setmaterialID(int _materialID){
    materialID = _materialID;
    }

    //getter
    string getmaterialName(){
    return materialName;
    }

    //setter
    void setmaterialName(string _materialName){
    materialName = _materialName;
    }

    //getter
    string getdescription(){
    return description;
    }

    //setter
    void setdescription (string _description){
    description = _description;
    }

    //getter
    int getpointsPerKg(){
    return pointsPerKg;
    }

    //setter
    void setpointsPerKg (int _pointsPerKg)
    {
    pointsPerKg = _pointsPerKg;
    }

    //showing
    string showing(){
    return  "Material ID :"+to_string(materialID)+"\nMaterial Name :"+materialName+"\nDescription :"+description+"\nPoint Per Kg :"+to_string(pointsPerKg)+"\n";
    }
};

int material::generateID = 1;

class collector : public user
{
    private:
        string address;
        string level;

    public:

         collector(string _username, string _password, string _fullname, string _totalpoints, string _address):
            user(_username, _password, _fullname, _totalpoints)
        {
            address = _address;
        }

        //getter
        string getaddress()
        {
            return address;
        }

    //setter
        void setaddress(string _address)
        {
            address = _address;
        }


    //showing
        string showing(){

       return "Data : \nUsername :"+getusername()
       + "\nPassword :"+getpassword()
       +"\nFull Name :"+getfullname()
       +"\nTotal Points :"+gettotalpoints()
       +"\nAddress : "+getaddress();
    }
};

class admin : public user
{
    private:
        string address;

    public:

         admin (string _username, string _password, string _fullname, string _totalpoints, string _address):
            user(_username, _password, _fullname, _totalpoints)
        {
            address = _address;
        }

        //getter
        string getaddress()
        {
            return address;
        }

    //setter
        void setaddress(string _address)
        {
            address = _address;
        }


    //showing
        string showing(){

       return "Data : \nUsername :"+getusername()
       + "\nPassword :"+getpassword()
       +"\nFull Name :"+getfullname()
       +"\nTotal Points :"+gettotalpoints()
       +"\nAddress : "+getaddress();
    }
};
class recycler : public user
{
    private:
        string ecolevel;

    public:

         recycler(string _username, string _password, string _fullname, string _totalpoints, string _ecolevel):
            user(_username, _password, _fullname, _totalpoints)
        {
            ecolevel = _ecolevel;
        }

        //getter
        string getecolevel()
        {
        return ecolevel;
        }

    //setter
        void setecolevel(string _ecolevel)
        {
        ecolevel = _ecolevel;
        }

    //showing
        string showing(){

        return "Data : \nUsername :"+getusername()
       + "\nPassword :"+getpassword()
       +"\nFull Name :"+getfullname()
       +"\nTotal Points :\n"+gettotalpoints()
       +"\nEcolevel : "+getecolevel();
    }

};

class submission
{
    private:
        string submissionID;
        string proposedDate;
        string actualDate;
        string weightInKg;
        string pointsAwarded;
        string status;

    public:

        submission(string _submissionID, string _proposedDate, string _actualDate, string _weightInKg, string _pointsAwarded, string _status)
        {
            submissionID = _submissionID;
            proposedDate = _proposedDate;
            actualDate = _actualDate;
            weightInKg = _weightInKg;
            pointsAwarded = _pointsAwarded;
            status = _status;
        }

        string getsubmissionID(){
        return submissionID;
        }

        void setsubmissionID(string _submissionID){
        submissionID = _submissionID;
        }


        string getproposedDate(){
        return proposedDate;
        }

        void setproposedDate(string _proposedDate){
        proposedDate = _proposedDate;
        }


        string getactualDate(){
        return actualDate;
        }

        void setactualDate(string _actualDate){
        actualDate = _actualDate;
        }


        string getweightInKg(){
        return weightInKg;
        }

        void setweightInKg(string _weightInKg){
        weightInKg = _weightInKg;
        }


        string getpointsAwarded(){
        return pointsAwarded;
        }

        void setpointsAwarded(string _pointsAwarded){
        pointsAwarded = _pointsAwarded;
        }

        string getstatus(){
        return status;
        }

        void setstatus(string _status){
        status = _status;
        }

        string showing()
        {
            return "Submission ID :"+submissionID+"\n";
            "Proposed Date :"+proposedDate+"\n";
            "Actual Date :"+actualDate+"\n";
            "Weight in Kg :"+weightInKg+"\n";
            "Points Awarded :"+pointsAwarded+"\n";
            "Status :"+status+"\n";
        }
};

class ecoSave
{
    private:

        vector <user*> x;
        vector <material*> y;

    public:
        ecoSave()
        {
        }

        ~ecoSave()
        {

        }

       string sadd(string username, string password, string fullname, string totalpoints, string address)
          {
         user* collector_data = new collector(username, password, fullname, totalpoints, address);
         x.push_back(collector_data);
         return collector_data->showing();
          }

        string sacc(string username, string password, string fullname, string totalpoints, string ecolevel)
          {
         user* recycler_data = new recycler(username, password, fullname, totalpoints, ecolevel);
         x.push_back(recycler_data);
         return recycler_data->showing();

          }

          string adm(string username, string password, string fullname, string totalpoints, string address)
          {
              user* admin_new = new admin(username, password, fullname, totalpoints, address);
              x.push_back(admin_new);
              return admin_new->showing();
          }

        user* loginuser (string username, string password)
         {
             vector <user*> :: iterator iter;
             for(iter=x.begin();iter!=x.end();iter++){
                if ((*iter)->getusername() == username){
                    if ((*iter)->getpassword() == password){
                        return *iter;
                    }
                }
             }
             return NULL;
         }
         string addingMaterialData(string materialName, string description, int pointsPerKg)
         {
            material* plesrequest = new material( materialName, description, pointsPerKg);
            y.push_back(plesrequest);
            return plesrequest->showing();
         }



};


#endif // system_H
