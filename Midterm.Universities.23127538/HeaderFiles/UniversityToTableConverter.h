#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include "University.h"

class UniversityToTableConverter
{
    private:
        vector<string> _headers;
        vector<int> _columnSizes;

    public:
        UniversityToTableConverter();
        UniversityToTableConverter(vector<string> headers, vector<int> columnSizes);
    
    public:
        vector<string> headers();
        vector<int> columnSizes();
        string convert(vector<University> universities);

    private:
        class UniversityToRowConverter
        {
            private:
                vector<int> _columnSizes;
            public:
                UniversityToRowConverter();
                UniversityToRowConverter(vector<int> columnSizes);
                string convert(University university);
        };
};


string centerText(const string &text, int width);
string convertIntToDollar(int num);
string convertIntToString(int num);
