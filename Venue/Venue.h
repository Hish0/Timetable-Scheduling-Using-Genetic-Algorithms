#ifndef VENUE_H
#define VENUE_H

#include <string>
#include <iostream>

using namespace std;

class Venue
{
private:
    int venueID;
    string name;
    int capacity;
    bool isLab;

public:
    // Default Constructor
    Venue();

    // Parameterized Constructor
    Venue(int id, const string &venueName, int cap, bool lab);

    bool operator==(const Venue &other) const;

    // Getter methods
    int getVenueID() const;
    string getName() const;
    int getCapacity() const;
    bool getIsLab() const;

    // Setter methods
    void setVenueID(int id);
    void setName(const string &venueName);
    void setCapacity(int cap);
    void setIsLab(bool lab);

    void printInfo() const;
};

#endif // VENUE_H