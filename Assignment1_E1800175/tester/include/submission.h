#ifndef SUBMISSION_H
#define SUBMISSION_H
#include <string>

//create class submission
class submission {
  //public variable
  public:
    int submissionID;
    int proposedDate;
    int actualDate;
    double weightInKg;
    double pointAwarded;
    std::string status;
  public:

  //public alias
    submission(int sID=0, int ppdate=0, int acldate=0, double wnkg=0, double pnawd=0, std::string sts="");
    ~submission()
    {
    }

    int getsubmissionID();
    int getproposedDate();
    int getactualDate();
    double getweightInKg();
    double getpointAwarded();
    std::string getstatus();

    void setsubmissionID(int sID);
    void setproposedDate(int ppdate);
    void setactualDate(int acldate);
    void setweightInKg(double wnkg);
    void setpointAwarded(double pnawd);
    void setstatus(std::string sts);

    void displaysubmission();
};

submission :: submission(int sID, int ppdate, int acldate, double wnkg, double pnawd, std::string sts)
{
    submissionID = sID;
    proposedDate = ppdate;
    actualDate = acldate;
    weightInKg = wnkg;
    pointAwarded = pnawd;
    status = sts;
}

int submission :: getsubmissionID()
{
    return submissionID;
}
int submission :: getproposedDate()
{
    return proposedDate;
}
int submission :: getactualDate()
{
    return actualDate;
}
double submission :: getweightInKg()
{
    return weightInKg;
}
double submission :: getpointAwarded()
{
    return pointAwarded;
}
std::string submission :: getstatus()
{
    return status;
}

void submission :: setsubmissionID(int sID)
{
    submissionID = sID;
}
void submission :: setproposedDate(int ppdate)
{
    proposedDate = ppdate;
}
void submission :: setactualDate(int acldate)
{
    actualDate = acldate;
}
void submission :: setweightInKg(double wnkg)
{
    weightInKg = wnkg;
}
void submission :: setpointAwarded(double pnawd)
{
    pointAwarded = pnawd;
}
void submission :: setstatus(std::string sts)
{
    status = sts;
}

#endif // SUBMISSION_H
