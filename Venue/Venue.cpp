#include "Venue.h"
#include "../GlobalVariables/GlobalVariables.h"

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

string Venue::toString() const
{
    std::ostringstream oss;
    oss << "Venue ID: " << venueID
        << ", Name: " << name
        << ", Capacity: " << capacity
        << ", Is Lab: " << (isLab ? "Yes" : "No");
    return oss.str();
}

void Venue::fromString(const std::string &str)
{
    std::istringstream iss(str);
    std::string token;

    // Parse the string and set the attributes of the Venue
    while (getline(iss, token, ','))
    {
        std::istringstream tokenStream(token);
        std::string key;
        std::string value;

        // Split the token into key and value
        getline(tokenStream, key, ':');
        getline(tokenStream, value);
        trimString(key);   // Function to trim leading and trailing spaces
        trimString(value); // Function to trim leading and trailing spaces

        // Set the appropriate attribute based on the key
        if (key == "Venue ID")
        {
            this->venueID = stoi(value);
        }
        else if (key == "Name")
        {
            this->name = value;
        }
        else if (key == "Capacity")
        {
            this->capacity = stoi(value);
        }
        else if (key == "Is Lab")
        {
            this->isLab = (value == "Yes");
        }
    }
}
