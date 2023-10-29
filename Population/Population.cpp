#include "Population.h"
#include "../GlobalVariables/GlobalVariables.h"
#include "../UtilityFunctions/UtilityFunctions.h"
#include <set>
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

Chromosome Population::generateRandomChromosome()
{
    Chromosome chromosome;

    for (const auto &module : allModules)
    {
        int moduleSlots = module.getNumberOfTimeSlots();
        std::set<TimeSlot, TimeSlotComparator> chosenTimeSlots;

        while (moduleSlots > 0)
        {
            TimeSlot timeSlot;

            if (moduleSlots == 1)
            {
                timeSlot = getRandomTimeSlot();
                while (chosenTimeSlots.find(timeSlot) != chosenTimeSlots.end())
                {
                    timeSlot = getRandomTimeSlot();
                }
                chosenTimeSlots.insert(timeSlot);
                moduleSlots--;

                // Randomly select a venue for this module
                Venue venue = getRandomVenue();

                // Create a ScheduledModule object
                ScheduledModule scheduledModule(module, timeSlot, venue, false, false, true);

                // Add this ScheduledModule object to the chromosome
                chromosome.addGene(scheduledModule);
            }
            else
            {
                timeSlot = getRandomTimeSlot();
                while (chosenTimeSlots.find(timeSlot) != chosenTimeSlots.end() || isLastSlotOfDay(timeSlot))
                {
                    timeSlot = getRandomTimeSlot();
                }
                chosenTimeSlots.insert(timeSlot);
                std::cout << "the first timeslot id is " << timeSlot.getTimeSlotID() << std::endl;
                TimeSlot nextSlot = timeSlot.getNextTimeSlot();
                std::cout << "the second timeslot id is " << nextSlot.getTimeSlotID() << std::endl;
                chosenTimeSlots.insert(nextSlot);
                moduleSlots -= 2;

                // Randomly select a venue for this module
                Venue venue = getRandomVenue();

                // Create the first slot ScheduledModule object
                ScheduledModule scheduledModule1(module, timeSlot, venue, false, false, true);
                // Create the second slot ScheduledModule object
                ScheduledModule scheduledModule2(module, nextSlot, venue, false, false, true);

                // Add these ScheduledModule object to the chromosome
                chromosome.addGene(scheduledModule1);
                // Add these ScheduledModule object to the chromosome
                chromosome.addGene(scheduledModule2);
            }
        }
    }

    if (chromosome.getGenes().size() != 153)
    {
        std::cout << "size of the chromosome is  " << chromosome.getGenes().size() << std::endl;
        std::cout << "error in size of chromosome &%#&#&%#&#%&#%&%population error " << std::endl;
        exit(1);
    }
    return chromosome;
}

void Population::initializeFirstPopulation(int POPULATION_SIZE)
{
    for (int i = 0; i < POPULATION_SIZE; ++i)
    {
        Chromosome chromosome;

        for (const auto &module : allModules)
        {
            int moduleSlots = module.getNumberOfTimeSlots();
            std::set<TimeSlot, TimeSlotComparator> chosenTimeSlots;

            while (moduleSlots > 0)
            {
                TimeSlot timeSlot;

                if (moduleSlots == 1)
                {
                    timeSlot = getRandomTimeSlot();
                    while (chosenTimeSlots.find(timeSlot) != chosenTimeSlots.end())
                    {
                        timeSlot = getRandomTimeSlot();
                    }
                    chosenTimeSlots.insert(timeSlot);
                    moduleSlots--;

                    // Randomly select a venue for this module
                    Venue venue = getRandomVenue();

                    // Create a ScheduledModule object
                    ScheduledModule scheduledModule(module, timeSlot, venue, false, false, true);

                    // Add this ScheduledModule object to the chromosome
                    chromosome.addGene(scheduledModule);
                }
                else
                {
                    timeSlot = getRandomTimeSlot();
                    while (chosenTimeSlots.find(timeSlot) != chosenTimeSlots.end() || isLastSlotOfDay(timeSlot))
                    {
                        timeSlot = getRandomTimeSlot();
                    }
                    chosenTimeSlots.insert(timeSlot);
                    // std::cout << "the first timeslot id is " << timeSlot.getTimeSlotID() << std::endl;
                    TimeSlot nextSlot = timeSlot.getNextTimeSlot();
                    // std::cout << "the second timeslot id is " << nextSlot.getTimeSlotID() << std::endl;
                    chosenTimeSlots.insert(nextSlot);
                    moduleSlots -= 2;

                    // Randomly select a venue for this module
                    Venue venue = getRandomVenue();

                    // Create the first slot ScheduledModule object
                    ScheduledModule scheduledModule1(module, timeSlot, venue, false, false, true);
                    // Create the second slot ScheduledModule object
                    ScheduledModule scheduledModule2(module, nextSlot, venue, false, false, true);

                    // Add these ScheduledModule object to the chromosome
                    chromosome.addGene(scheduledModule1);
                    // Add these ScheduledModule object to the chromosome
                    chromosome.addGene(scheduledModule2);
                }
            }
        }

        // Add this chromosome to the initial population
        addChromosome(chromosome);

        if (chromosome.getGenes().size() != 153)
        {
            std::cout << "size of the chromosome is  " << chromosome.getGenes().size() << std::endl;
            std::cout << "error in size of chromosome &%#&#&%#&#%&#%&%population error " << std::endl;
            exit(1);
        }
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

double Population::getBestFitness()
{
    vector<Chromosome> bestChromosomes = getBestNChromosomes(1);
    if (!bestChromosomes.empty())
    {
        return bestChromosomes[0].evaluateFitness();
    }
    else
    {
        // Handle the case where no chromosomes are present
        // For example, you can return a default value or throw an exception
        return -1.0;
    }
}

vector<Chromosome> Population::getBestNDiverseChromosomes(int n)
{
    vector<Chromosome> sortedChromosomes = chromosomes;
    vector<Chromosome> newElites;

    // Sort the chromosomes based on their fitness
    sort(sortedChromosomes.begin(), sortedChromosomes.end(),
         [](Chromosome &a, Chromosome &b)
         {
             return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
         });

    // Loop through the sorted chromosomes to find diverse elites
    for (auto &candidate : sortedChromosomes)
    {
        bool isDiverse = true;

        // Check if the candidate is diverse from all new elites
        for (auto &elite : newElites)
        {
            if (!candidate.isDiverse(elite))
            {
                isDiverse = false;
                break;
            }
        }

        // If the candidate is diverse, add it to the new elites
        if (isDiverse)
        {
            newElites.push_back(candidate);
        }

        // Stop if we've found enough new elites
        if (newElites.size() >= n)
        {
            break;
        }
    }
    if (newElites.size() < n)
    {
        cout << "Error: Could not find enough diverse elite chromosomes." << endl;
    }

    return newElites;
}

void Population::clearPopulation()
{
    // Sort the population by fitness
    sort(chromosomes.begin(), chromosomes.end(),
         [](Chromosome &a, Chromosome &b)
         {
             return a.evaluateFitness() < b.evaluateFitness();
         });

    vector<Chromosome> clearedPopulation;

    // Clear the population
    for (const Chromosome &individual : chromosomes)
    {
        bool isDiverse = true;

        for (const Chromosome &cleared : clearedPopulation)
        {
            if (!individual.isDiverse(cleared))
            {
                isDiverse = false;
                break;
            }
        }

        if (isDiverse)
        {
            clearedPopulation.push_back(individual);
        }
    }

    // Replace the old population with the cleared population
    chromosomes = clearedPopulation;
}

void Population::populateClearedChromosomes(int numberOfChromosomesToAdd)
{
    for (int i = 0; i < numberOfChromosomesToAdd; ++i)
    {
        Chromosome newChromosome = generateRandomChromosome(); // Assuming you have a function that generates a random chromosome
        chromosomes.push_back(newChromosome);
    }
}

bool Population::similarChromo(double threshold)
{
    int count = 0;              // To keep track of the number of similar chromosomes
    int n = chromosomes.size(); // Total number of chromosomes in the population

    // Nested loop to compare each pair of chromosomes
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // Assuming you have implemented the isDiverse method in Chromosome class
            if (!chromosomes[i].isDiverse(chromosomes[j]))
            {
                count++; // Increase count if the chromosomes are not diverse
            }
        }
    }

    // Calculate the percentage of similar chromosomes
    double percentage = (double)count / (double)(n * (n - 1) / 2);

    return percentage >= threshold;
}

bool Population::isLastSlotOfDay(const TimeSlot &timeSlot)
{
    int slotId = timeSlot.getTimeSlotID();
    return slotId % 8 == 0;
}