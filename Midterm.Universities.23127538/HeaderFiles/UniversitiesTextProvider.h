#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "University.h"
using namespace std;

class UniversitiesTextProvider 
{
public:
    vector<University> read(string filename);
};

int myStoi(const string& str);