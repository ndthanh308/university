#include "HeaderFiles/UniversitiesTextProvider.h"


int myStoi(const string& str)
{
    string numStr; 
    for (char ch : str)
    {
        if (ch >= '0' && ch <= '9') 
        {
            numStr += ch; 
        }
    }
    
    if (numStr.empty())
    {
        cerr << "No digits found in the string." << endl;
        return 0; 
    }

    return stoi(numStr);
}

vector<University> UniversitiesTextProvider::read(string filename) 
{
    vector<University> universities;
    ifstream file(filename);

    if (!file.is_open()) 
    {
        cout << "Cannot open file " << filename << " !!!\n";
        return universities;
    }

    string line;
    // Skip the header line
    getline(file, line);

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string name;
        string fee;
        string undergrad;
        string buffer;

        // Read the first column (Name)
        getline(ss, name, ',');

        // Skip the remaining columns we do not need
        size_t starPos = line.find("\"$");
        starPos += 2;
        size_t endPos = line.find('\"', starPos);

        fee = line.substr(starPos, endPos - starPos);

        size_t lastQuotePos = line.find_last_of('\"');
        size_t secondLastQuotePos = line.find_last_of('\"', lastQuotePos - 1);
        undergrad = line.substr(secondLastQuotePos + 1, lastQuotePos - secondLastQuotePos + 1);

        getline(ss, buffer, ',');
        cout << buffer << '\n';
        
        University university;
        university.setName(name);
        university.setFee(myStoi(fee));
        university.setUndergradEnrollment(myStoi(undergrad));

        universities.push_back(university);
    }

    file.close();
    return universities;
}   