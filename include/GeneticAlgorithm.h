#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <vector>
#include <iostream>
#include "Population.h"
#include "Chromosome.h"
#include "GlobalVariables.h"

class GeneticAlgorithm
{
private:
    Population population;
    double mutationRate;
    double crossoverRate;
    int eliteCount;
    std::vector<double> totalFitnessHistory;
    std::vector<double> totalBestFitHistory;

public:
    GeneticAlgorithm(Population &initialPopulation, double mutationRate, double crossoverRate, int eliteCount);

    Population selectParents();
    Chromosome crossover(const Chromosome &parent1, const Chromosome &parent2);
    Venue getRandomVenue();
    TimeSlot findEmptyTimeSlot(const std::string &day, const std::vector<Chromosome> &chromosomes);
    TimeSlot getAnotherAvailableTimeSlot(const TimeSlot &current, const std::vector<TimeSlot> &allTimeSlots);
    void mutate(Chromosome &chromosome);
    void replacePopulation(const Population &offspringPopulation);
    void runOneGeneration(int generationCount);
    void run(int numberOfGenerations);
    Chromosome getBestChromosome();
    void printTotalFitnessHistory();
    void printTotalBestFitHistory();
    void printProgress();
    bool isLastSlotOfDay(const TimeSlot &timeSlot);
    void surgeryMutation(Chromosome &chromosome, int geneId);
    void surgeryMutationForTimeSlotPrefrence(Chromosome &chromosome, int geneId);
    void surgeryMutationForTimeSlotGap(Chromosome &chromosome, int geneIdToMove, int lastTimeSlotIdOfPreviousModule);
};

#endif // GENETICALGORITHM_H
