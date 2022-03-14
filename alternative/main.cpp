#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct material {
    int materialID;
    string materialName;
    string description;
    double pointsPerkg;
} material;
typedef struct user {
    string username;
    string password;
    string fullName;
    double totalPoint;
};
typedef struct collector {
    string address;
};
typedef struct recycler {
    string ecoLevel;
};
typedef struct submission {
    int submissionID;
    int proposedDate;
    int actualDate;
    double weightInKg;
    double pointAwarded;
    string status;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
