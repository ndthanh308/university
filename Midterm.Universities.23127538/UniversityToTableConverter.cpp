#include "HeaderFiles/UniversityToTableConverter.h"


string centerText(const string &text, int width)
{
    stringstream center;
    int padding = width - text.size();
    int leftPadding = padding / 2;
    int rightPadding = padding - leftPadding;

    center << string(leftPadding, ' ') << text << string(rightPadding, ' ');
    return center.str();
}

string convertIntToDollar(int num)
{
    stringstream convert;
    string numStr = to_string(num);
    int insertPosition = numStr.length() - 3;

    while (insertPosition > 0)
    {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    convert << "$ " << numStr;
    return convert.str();
}

string convertIntToString(int num)
{
    stringstream convert;
    string numStr = to_string(num);
    int insertPosition = numStr.length() - 3;

    while (insertPosition > 0)
    {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    convert << numStr;
    return convert.str();
}



// UniversityToTableConverter class implementation

UniversityToTableConverter::UniversityToTableConverter()
    : _headers({}), _columnSizes({}) {}

UniversityToTableConverter::UniversityToTableConverter(vector<string> headers, vector<int> columnSizes)
    : _headers(headers), _columnSizes(columnSizes) {}

vector<string> UniversityToTableConverter::headers() 
{
    return _headers;
}

vector<int> UniversityToTableConverter::columnSizes()
{
    return _columnSizes;
}

string UniversityToTableConverter::convert(vector<University> universities)
{
    stringstream table;
    
    // Convert headers to table header row
    table << '|' << left << setw(_columnSizes[0]) << _headers[0] << '|'
          << left << setw(_columnSizes[1]) << _headers[1] << '|'
          << centerText(_headers[2], _columnSizes[2]) << "|"
          << centerText(_headers[3], _columnSizes[3]) << "|\n";
    
    // Add a separator row
    int sum = _headers.size() + 1;
    for(size_t i = 0; i < _headers.size(); i++)
    {
        sum += _columnSizes[i];
    }
    for(size_t i = 0; i < sum; i++) table << '-';
    table << '\n';
    
    // Convert each university to a row
    UniversityToRowConverter rowConverter(_columnSizes);
    for (size_t i = 0; i < 10; i++)
    {
        table << '|' << left << setw(_columnSizes[0]) << i + 1 << rowConverter.convert(universities[i]) << '\n';
    }

    return table.str();
}

// UniversityToTableConverter::UniversityToRowConverter class implementation

UniversityToTableConverter::UniversityToRowConverter::UniversityToRowConverter()
    : _columnSizes({}) {}

UniversityToTableConverter::UniversityToRowConverter::UniversityToRowConverter(vector<int> columnSizes)
    : _columnSizes(columnSizes) {}

string UniversityToTableConverter::UniversityToRowConverter::convert(University university)
{
    stringstream row;
    row << '|' << left << setw(_columnSizes[1]) << university.name() << '|' 
        << centerText(convertIntToDollar(university.fee()), _columnSizes[2]) << '|'
        << centerText(convertIntToString(university.undergradEnrollment()), _columnSizes[3]) << '|';
    return row.str();
}
