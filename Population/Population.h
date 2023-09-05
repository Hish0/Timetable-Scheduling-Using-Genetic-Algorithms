#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <algorithm>
#include "../Chromosome/Chromosome.h" // Adjust this path based on your folder structure

using namespace std;

class Population
{
private:
    vector<Chromosome> chromosomes;

public:
    // Constructors
    Population();
    Population(const vector<Chromosome> &initialPopulation);

    void addChromosome(const Chromosome &chromosome);
    void addChromosomes(const vector<Chromosome> &newChromosomes);
    void removeChromosome(const Chromosome &target);
    vector<Chromosome> getChromosomes() const;
    void setChromosomes(const vector<Chromosome> &newChromosomes);
    void initializeFirstPopulation(int POPULATION_SIZE);
    vector<Chromosome> getBestNChromosomes(int n);
    vector<Chromosome> getWorstNChromosomes(int n);
    double getTotalFitness();
};

#endif // POPULATION_H
