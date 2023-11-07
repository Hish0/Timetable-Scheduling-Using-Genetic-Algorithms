#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <vector>
#include <map>
#include "../ScheduledModule/ScheduledModule.h" // Adjust this path based on your folder structure

using namespace std;

class Chromosome
{
private:
    vector<ScheduledModule> genes;

public:
    // Default Constructor
    Chromosome();

    // Parameterized Constructor
    Chromosome(const vector<ScheduledModule> &genes);

    void addGene(const ScheduledModule &gene);
    vector<ScheduledModule> getGenes() const;
    void setGenes(const vector<ScheduledModule> &newGenes);
    void printGenesByDay() const;
    void checkGeneSize();
    bool operator==(const Chromosome &other) const;
    double evaluateFitness();
    bool isDiverse(const Chromosome &other) const;
    int getModuleHours(int moduleID) const;
    ScheduledModule &getGene(int index);
    std::pair<int, std::string> catchViolation();
};

#endif // CHROMOSOME_H
