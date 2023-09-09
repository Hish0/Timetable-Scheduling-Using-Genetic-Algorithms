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
};

#endif // CHROMOSOME_H
