#include "Population.h"
#include "../GlobalVariables/GlobalVariables.h"
#include "../UtilityFunctions/UtilityFunctions.h"
using namespace Utility;

// Default Constructor
Population::Population() {}

// Parameterized Constructor
Population::Population(const vector<Chromosome> &initialPopulation) : chromosomes(initialPopulation) {}

void Population::addChromosome(const Chromosome &chromosome)
{
    chromosomes.push_back(chromosome);
}

void Population::addChromosomes(const vector<Chromosome> &newChromosomes)
{
    chromosomes.insert(chromosomes.end(), newChromosomes.begin(), newChromosomes.end());
}

void Population::removeChromosome(const Chromosome &target)
{
    auto it = find(chromosomes.begin(), chromosomes.end(), target);
    if (it != chromosomes.end())
    {
        chromosomes.erase(it);
    }
}

vector<Chromosome> Population::getChromosomes() const
{
    return chromosomes;
}

void Population::setChromosomes(const vector<Chromosome> &newChromosomes)
{
    chromosomes = newChromosomes;
}

void Population::initializeFirstPopulation(int POPULATION_SIZE)
{

    for (int i = 0; i < POPULATION_SIZE; ++i)
    {
        Chromosome chromosome;
        int counter = 0;

        for (const auto &module : allModules)
        {
            // cout << "Size of allModules: " << allModules.size() << endl;
            //  Schedule this module twice, as each module has 4 hours per week.

            // Randomly select two different time slots for this module
            TimeSlot timeSlot1 = getRandomTimeSlot();
            TimeSlot timeSlot2 = getRandomTimeSlot(timeSlot1); // Make sure this is different from timeSlot1

            // Randomly select a venue for this module
            Venue venue = getRandomVenue();

            // Create two ScheduledModule objects
            ScheduledModule scheduledModule1(module, timeSlot1, venue, false, false, true);
            ScheduledModule scheduledModule2(module, timeSlot2, venue, false, false, true);

            // Add these ScheduledModule objects to the chromosome
            chromosome.addGene(scheduledModule1);
            chromosome.addGene(scheduledModule2);
            counter++;
        }
        // cout << "Loop ran " << counter << " times." << endl;
        //  Add this chromosome to the initial population
        addChromosome(chromosome);
        // cout << "the size of the chromosome num ==>" << i + 1;
        // chromosome.checkGeneSize();
    }
}

vector<Chromosome> Population::getBestNChromosomes(int n)
{
    vector<Chromosome> sortedChromosomes = chromosomes;

    sort(sortedChromosomes.begin(), sortedChromosomes.end(),
         [](Chromosome &a, Chromosome &b)
         {
             return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
         });

    return vector<Chromosome>(sortedChromosomes.begin(), sortedChromosomes.begin() + n);
}

vector<Chromosome> Population::getWorstNChromosomes(int n)
{
    vector<Chromosome> sortedChromosomes = chromosomes;

    sort(sortedChromosomes.begin(), sortedChromosomes.end(),
         [](Chromosome &a, Chromosome &b)
         {
             return a.evaluateFitness() > b.evaluateFitness(); // Assuming higher fitness is worse
         });

    return vector<Chromosome>(sortedChromosomes.end() - n, sortedChromosomes.end());
}

double Population::getTotalFitness()
{
    double totalFitness = 0.0;
    for (auto &chromosome : chromosomes)
    {
        totalFitness += chromosome.evaluateFitness();
    }
    return totalFitness;
}
