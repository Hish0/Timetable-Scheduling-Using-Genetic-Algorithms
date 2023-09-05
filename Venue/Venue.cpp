#include "Venue.h"

// Default Constructor
Venue::Venue() : venueID(0), name("Unknown"), capacity(0), isLab(false) {}

// Parameterized Constructor
Venue::Venue(int id, const string &venueName, int cap, bool lab)
    : venueID(id), name(venueName), capacity(cap), isLab(lab) {}

bool Venue::operator==(const Venue &other) const
{
    return (this->venueID == other.venueID &&
            this->name == other.name &&
            this->capacity == other.capacity &&
            this->isLab == other.isLab);
}

// Getter methods
int Venue::getVenueID() const
{
    return venueID;
}

string Venue::getName() const
{
    return name;
}

int Venue::getCapacity() const
{
    return capacity;
}

bool Venue::getIsLab() const
{
    return isLab;
}

// Setter methods
void Venue::setVenueID(int id)
{
    venueID = id;
}

void Venue::setName(const string &venueName)
{
    name = venueName;
}

void Venue::setCapacity(int cap)
{
    capacity = cap;
}

void Venue::setIsLab(bool lab)
{
    isLab = lab;
}

void Venue::printInfo() const
{
    cout << "Venue ID: " << venueID
         << ", Name: " << name
         << ", Capacity: " << capacity
         << ", Is Lab: " << (isLab ? "Yes" : "No") << endl;
}
