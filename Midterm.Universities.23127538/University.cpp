#include "HeaderFiles/University.h"

// Constructor definitions
University::University() : _name(""), _location(""), _rank(0), _description(""), _fee(0), _in_state(""), _undergradEnrollment(0) {}

University::University(string name, string location, int rank, string des, int fee, string in_state, int undergrad)
    : _name(name), _location(location), _rank(rank), _description(des), _fee(fee), _in_state(in_state), _undergradEnrollment(undergrad) {}

// Getter function implementations
string University::name() const 
{
    return _name;
}

string University::location() const 
{
    return _location;
}

int University::rank() const 
{
    return _rank;
}

string University::description() const 
{
    return _description;
}

int University::fee() const 
{
    return _fee;
}

string University::in_state() const 
{
    return _in_state;
}

int University::undergradEnrollment() const 
{
    return _undergradEnrollment;
}

// Setter function implementations
void University::setName(const string& name) 
{
    _name = name;
}

void University::setLocation(const string& location) 
{
    _location = location;
}

void University::setRank(int rank) 
{
    _rank = rank;
}

void University::setDescription(const string& description) 
{
    _description = description;
}

void University::setFee(int fee) 
{
    _fee = fee;
}

void University::setInState(const string& in_state) 
{
    _in_state = in_state;
}

void University::setUndergradEnrollment(int undergradEnrollment) 
{
    _undergradEnrollment = undergradEnrollment;
}
