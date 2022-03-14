#ifndef USER_H
#define USER_H
#include <string>

//create class user
class user {
  //public variable
  public:
    std::string username;
    std::string password;
    std::string fullName;
    double totalPoint;
  public:

  //public alias
    user(std::string usrname="", std::string pass="", std::string flname="", double ttlp =0);
    ~user()
    {
    }
    std::string getusername();
    std::string getpassword();
    std::string getfullname();
    double gettotalpoint();

    void setusername(std::string usrname);
    void setpassword (std::string pass);
    void setfullname (std::string flname);
    void settotalpoint (double ttlp);

    void displayuser();
};

user :: user(std::string usrname, std::string pass, std::string flname, double ttlp)
{
    username = usrname;
    password = pass;
    fullName = flname;
    totalPoint = ttlp;
}

std::string user :: getusername()
{
    return username;
}
std::string user :: getpassword()
{
    return password;
}
std::string user :: getfullname()
{
    return fullName;
}
double user :: gettotalpoint()
{
    return totalPoint;
}

void user :: setusername(std::string usrname)
{
    username = usrname;
}

void user :: setpassword(std::string pass)
{
    password = pass;
}

void user :: setfullname(std::string flname)
{
    fullName = flname;
}

void user :: settotalpoint(double ttlp)
{
    totalPoint = ttlp;
}

#endif // USER_H
