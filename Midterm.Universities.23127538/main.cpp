#include "HeaderFiles/main.h"

int main()
{
    cout << "\n\n";
    vector<string> headers = {"STT", "Ten truong", "Hoc phi", "Chi tieu"};
    vector<int> columnSizes = {3, 60, 11, 11};
    UniversitiesTextProvider provider;
    UniversityToTableConverter converter(headers, columnSizes);
    const string filename = "UniversitiesRankings.csv";
    

    vector<University> universities = provider.read(filename);
    sortFee(universities);
    cout << converter.convert(universities);

    cout << "\n\n";
    return 0;
}

void sortFee(vector<University>& universities) 
{
    // sort the vector in ascending order based on the fee
    sort(universities.begin(), universities.end(), [](const University& a, const University& b) 
    {
        return a.fee() > b.fee(); // descending order
    });
}