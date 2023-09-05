#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <vector>
#include <iostream>
#include "../Population/Population.h"
#include "../Chromosome/Chromosome.h"
#include "../GlobalVariables/GlobalVariables.h"

class GeneticAlgorithm
{
private:
    Population population;
    double mutationRate;
    double crossoverRate;
    int eliteCount;
    std::vector<double> totalFitnessHistory;

public:
    GeneticAlgorithm(Population &initialPopulation, double mutationRate, double crossoverRate, int eliteCount);

    Population selectParents();
    Chromosome crossover(const Chromosome &parent1, const Chromosome &parent2);
    Venue getRandomVenue();
    TimeSlot findEmptyTimeSlot(const std::string &day, const std::vector<Chromosome> &chromosomes);
    TimeSlot getAnotherAvailableTimeSlot(const TimeSlot &current, const std::vector<TimeSlot> &allTimeSlots);
    void mutate(Chromosome &chromosome);
    void replacePopulation(const Population &offspringPopulation);
    void runOneGeneration();
    void run(int numberOfGenerations);
    Chromosome getBestChromosome();
    void printTotalFitnessHistory();
};

#endif // GENETICALGORITHM_H
