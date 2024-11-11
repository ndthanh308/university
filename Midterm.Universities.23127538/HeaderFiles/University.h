#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class University
{
    private:
        string _name;
        string _location;
        int _rank;
        string _description;
        int _fee;
        string _in_state;
        int _undergradEnrollment;
    public:
        University();
        University(string name, string location, int rank, string des, int fee, string in_state, int undergrad);
    public:
        // Getter functions
        string name() const;
        string location() const;
        int rank() const;
        string description() const;
        int fee() const;
        string in_state() const;
        int undergradEnrollment() const;

        // Setter functions
        void setName(const string& name);
        void setLocation(const string& location);
        void setRank(int rank);
        void setDescription(const string& description);
        void setFee(int fee);
        void setInState(const string& in_state);
        void setUndergradEnrollment(int undergradEnrollment);
};