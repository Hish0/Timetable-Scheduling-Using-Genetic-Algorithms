#include "GeneticAlgorithm.h"
#include <algorithm>
#include <cstdlib>

GeneticAlgorithm::GeneticAlgorithm(Population &initialPopulation, double mutationRate, double crossoverRate, int eliteCount)
    : population(initialPopulation), mutationRate(mutationRate), crossoverRate(crossoverRate), eliteCount(eliteCount) {}

Population GeneticAlgorithm::selectParents()
{
    vector<Chromosome> selectedParents;
    int tournamentSize = 6; // You can change this

    for (int i = 0; i < population.getChromosomes().size() - eliteCount; ++i) // Leave space for elites
    {
        vector<Chromosome> tournament;

        // Randomly select k individuals for the tournament
        for (int j = 0; j < tournamentSize; ++j)
        {
            int index = rand() % population.getChromosomes().size();
            tournament.push_back(population.getChromosomes()[index]);
        }

        // cout << "Tournament Size: " << tournament.size() << endl;

        // Find the best individual in the tournament
        Chromosome best = *min_element(
            tournament.begin(), tournament.end(),
            [](Chromosome &a, Chromosome &b)
            {
                return a.evaluateFitness() < b.evaluateFitness(); // Assuming lower fitness is better
            });

        // cout << "Before adding the best individual, selectedParents size: " << selectedParents.size() << endl;
        //  Add the winner to the list of parents
        selectedParents.push_back(best);
        // cout << "After adding the best individual, selectedParents size: " << selectedParents.size() << endl;
    }
    // cout << "Before returning the selectedParents, selectedParents size: " << selectedParents.size() << endl;
    return Population(selectedParents);
}

Chromosome GeneticAlgorithm::crossover(const Chromosome &parent1, const Chromosome &parent2)
{
    Chromosome child1, child2;
    int geneLength = parent1.getGenes().size();

    // // Identify valid crossover points (every 2 genes, for example)
    // vector<int> crossoverPoints;
    // int currentPoint = 0;

    // // Always start with 0
    // crossoverPoints.push_back(currentPoint);
    // for (const Module &module : allModules)
    // {
    //     int numSlots = module.getNumberOfTimeSlots();

    //     // If the number of slots is even, we add points in increments of 2
    //     if (numSlots % 2 == 0)
    //     {
    //         for (int i = 2; i <= numSlots; i += 2)
    //         {
    //             crossoverPoints.push_back(currentPoint + i);
    //         }
    //     }
    //     // If the number of slots is odd, we add points in increments of 2, but also add the last slot
    //     else
    //     {
    //         for (int i = 2; i < numSlots; i += 2)
    //         {
    //             crossoverPoints.push_back(currentPoint + i);
    //         }
    //         crossoverPoints.push_back(currentPoint + numSlots);
    //     }

    //     // Update the current point for the next module
    //     currentPoint += numSlots;
    // }

    // this is for knowing what are the right indexes that is being stored in crossoverPoints vector
    // for (int i = 0; i < crossoverPoints.size(); i++)
    // {
    //     cout << "the crossoverpoints of the index  " << i << " is " << crossoverPoints[i] << endl;
    // }

    // Randomly select two crossover points
    int crossoverIndex1 = crossoverPoints[rand() % crossoverPoints.size()];
    int crossoverIndex2 = crossoverPoints[rand() % crossoverPoints.size()];

    while (crossoverIndex1 == crossoverIndex2)
    {
        crossoverIndex2 = crossoverPoints[rand() % crossoverPoints.size()];
    }

    // Sort the indices
    if (crossoverIndex1 > crossoverIndex2)
    {
        swap(crossoverIndex1, crossoverIndex2);
    }

    // cout << "the idices are : " << crossoverIndex1 << " and " << crossoverIndex2 << endl;

    // Perform crossover to create two children
    for (int i = 0; i < geneLength; ++i)
    {
        if (i < crossoverIndex1 || i >= crossoverIndex2)
        {
            child1.addGene(parent1.getGenes()[i]);
            child2.addGene(parent2.getGenes()[i]);
        }
        else
        {
            child1.addGene(parent2.getGenes()[i]);
            child2.addGene(parent1.getGenes()[i]);
        }
    }

    // Choose one child for the next generation based on fitness (you could also return both)
    if (child1.evaluateFitness() < child2.evaluateFitness())
    {
        if (child1.getGenes().size() != 153)
        {
            cout << "the child 1 ERROR" << endl;
            cout << "##########child size : " << child1.getGenes().size() << endl;

            exit(1);
        }
        else
        {
            return child1;
        }
    }
    else
    {
        if (child2.getGenes().size() != 153)
        {
            cout << "the child 2 ERROR" << endl;
            cout << "##########child size : " << child2.getGenes().size() << endl;

            exit(1);
        }
        else
        {
            return child2;
        }
    }
}

Venue GeneticAlgorithm::getRandomVenue()
{
    // Assuming `allVenues` is a vector containing all available Venue objects
    int index = rand() % allVenues.size();
    return allVenues[index];
}

TimeSlot GeneticAlgorithm::findEmptyTimeSlot(const std::string &day, const std::vector<Chromosome> &chromosomes)
{
    // Let's assume timeSlots is a vector containing all possible TimeSlot objects for a given day
    for (const auto &candidateTimeSlot : allTimeSlots)
    {
        bool isEmpty = true;

        // Loop through all chromosomes and their genes to check if the time slot is empty
        for (const auto &chromosome : chromosomes)
        {
            for (const auto &gene : chromosome.getGenes())
            {
                if (gene.getTimeSlot().getDay() == day &&
                    gene.getTimeSlot().getTimeSlotID() == candidateTimeSlot.getTimeSlotID())
                {
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty)
                break;
        }

        // If we found an empty slot, return it
        if (isEmpty)
            return candidateTimeSlot;
    }

    // If no empty time slot is found, return a default TimeSlot or signal that none was found
    return TimeSlot(); // This could be a special TimeSlot indicating no empty slot was found
}

TimeSlot GeneticAlgorithm::getAnotherAvailableTimeSlot(const TimeSlot &current, const std::vector<TimeSlot> &allTimeSlots)
{
    vector<TimeSlot> otherSlots;

    // Loop through all available time slots and find one that is different from `current`
    for (const auto &slot : allTimeSlots)
    {
        if (slot.getTimeSlotID() != current.getTimeSlotID())
        {
            otherSlots.push_back(slot);
        }
    }

    // Randomly select one from otherSlots
    int index = rand() % otherSlots.size();
    return otherSlots[index];
}

void GeneticAlgorithm::mutate(Chromosome &chromosome)
{
    // Assuming `chromosome.getGenes()` returns a reference to the vector of genes
    // vector<ScheduledModule> &genes = chromosome.getGenes();
    vector<ScheduledModule> genes = chromosome.getGenes();

    // Randomly pick one gene to change the venue
    int randomIndexForVenue = rand() % genes.size();
    // Venue newVenue = getRandomVenue();
    // genes[randomIndexForVenue].setVenue(newVenue);

    // Randomly pick another gene to change the time slot
    int randomIndexForTimeSlot = rand() % genes.size();
    while (randomIndexForTimeSlot == randomIndexForVenue)
    {
        // Ensure we pick a different gene
        randomIndexForTimeSlot = rand() % genes.size();
    }

    string day = genes[randomIndexForTimeSlot].getTimeSlot().getDay();

    // First, try to find an empty time slot
    TimeSlot newTimeSlot = findEmptyTimeSlot(day, population.getChromosomes());

    // If we can't find an empty time slot, get another available time slot
    if (newTimeSlot.isEmpty())
    { // Assuming TimeSlot() returns a special "empty" time slot
        newTimeSlot = getAnotherAvailableTimeSlot(genes[randomIndexForTimeSlot].getTimeSlot(), allTimeSlots);
    }

    genes[randomIndexForTimeSlot].setTimeSlot(newTimeSlot);

    chromosome.setGenes(genes);
}

void GeneticAlgorithm::replacePopulation(const Population &offspringPopulation)
{
    vector<Chromosome> newOffspring = offspringPopulation.getChromosomes();
    vector<Chromosome> oldElites = this->population.getBestNChromosomes(eliteCount);

    // cout << "in--> Selection befor removing elites, Size of population: " << population.getChromosomes().size() << endl;
    // cout << "in--> Selection befor removing elites, Size of oldElites: " << oldElites.size() << endl;

    // Remove elites from the old population
    for (const Chromosome &elite : oldElites)
    {
        this->population.removeChromosome(elite);
    }

    // cout << "in--> Selection after removing elites, Size of population: " << population.getChromosomes().size() << endl;
    // cout << "in--> Selection after removing elites, Size of oldElites: " << oldElites.size() << endl;

    // cout << "in--> Selection after removing elites, Size of newOffspring####: " << newOffspring.size() << endl;
    //   Get the number of chromosomes to be replaced in the old population
    int numToReplace = newOffspring.size();

    // Get the worst-performing individuals to remove them
    vector<Chromosome> oldWorst = this->population.getWorstNChromosomes(numToReplace);

    // cout << "in--> Selection befor removing worst-performing, Size of population: " << population.getChromosomes().size() << endl;

    // Remove worst-performing individuals
    for (const Chromosome &worst : oldWorst)
    {
        this->population.removeChromosome(worst);
    }

    // cout << "in--> Selection after removing worst-performing, Size of population: " << population.getChromosomes().size() << endl;

    // cout << "in--> Selection before Add new offspring, Size of population: " << population.getChromosomes().size() << endl;

    // Add new offspring
    this->population.addChromosomes(newOffspring);
    // cout << "in--> Selection after Add new offspring, Size of population: " << population.getChromosomes().size() << endl;
    // cout << "in--> Selection before Add back the elites, Size of population: " << population.getChromosomes().size() << endl;

    // Add back the elites
    this->population.addChromosomes(oldElites);
    // cout << "in--> Selection after Add back the elites, Size of population: " << population.getChromosomes().size() << endl;
}

void GeneticAlgorithm::runOneGeneration(int generationCount)
{
    cout << "Running generation..." << generationCount << endl;
    //  Check Elitism
    if (eliteCount > population.getChromosomes().size())
    {
        cout << "Error: Elite count greater than population size!" << endl;
        // You may choose to return or throw an exception here
        return;
    }
    // cout << "Starting Elitism..." << endl;
    //   1. Elitism
    //  vector<Chromosome> elites = population.getBestNChromosomes(eliteCount);
    vector<Chromosome> elites = population.getBestNDiverseChromosomes(eliteCount);

    // cout << "Size of elites: " << elites.size() << endl;

    // cout << "Completed Elitism. Starting Selection..." << endl;
    //   2. Selection
    Population parents = selectParents();
    // cout << "After Selection, Size of parent population: " << parents.getChromosomes().size() << endl;
    // cout << "After Selection, Size of population: " << population.getChromosomes().size() << endl;

    // // every 5 runs we clear same chromosomes
    // if (parents.similarChromo())
    // {
    //     int oldPopulationCount = parents.getChromosomes().size();
    //     cout << "Before clearing the population, population size: " << parents.getChromosomes().size() << endl;
    //     parents.clearPopulation();
    //     int newPopulationCount = parents.getChromosomes().size();
    //     cout << "After clearing the population, population size: " << parents.getChromosomes().size() << endl;
    //     parents.populateClearedChromosomes(oldPopulationCount - newPopulationCount);
    //     cout << "After populating the population, population size: " << parents.getChromosomes().size() << endl;
    // }
    // every 5 runs we clear same chromosomes
    if ((generationCount % 15) == 0)
    {
        int oldPopulationCount = parents.getChromosomes().size();
        cout << "Before clearing the population, population size: " << parents.getChromosomes().size() << endl;
        parents.clearPopulation();
        int newPopulationCount = parents.getChromosomes().size();
        cout << "After clearing the population, population size: " << parents.getChromosomes().size() << endl;
        parents.populateClearedChromosomes(oldPopulationCount - newPopulationCount);
        cout << "After populating the population, population size: " << parents.getChromosomes().size() << endl;
    }

    parents.addChromosomes(elites); // Add elites
    // cout << "After adding the elites to the parents, Size of parent population: " << parents.getChromosomes().size() << endl;
    // cout << "After adding the elites to the parents, Size of population: " << population.getChromosomes().size() << endl;

    // cout << "Completed Selection. Starting Crossover and Mutation..." << endl;

    // 3.Crossover and Mutation
    Population offspring;
    for (int i = 0; i < parents.getChromosomes().size(); i += 2)
    {
        // cout << "----------> start <----------" << endl;

        // cout << "----------> before random values " << endl;

        double randomValueForCrossover = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        double randomValueForMutation = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        // cout << "----------> after random values " << endl;

        Chromosome child;

        if (randomValueForCrossover <= crossoverRate)
        {
            // cout << "----------> if true child size chromosome Before cross: " << child.getGenes().size() << endl;
            child = crossover(parents.getChromosomes()[i], parents.getChromosomes()[i + 1]);
            // cout << "----------> if true child size chromosome After cross: " << child.getGenes().size() << endl;
        }
        else
        {
            // cout << "----------> if false child size chromosome Before not cross: " << child.getGenes().size() << endl;
            //  If not crossing over, add one of the parents to the next generation.
            child = parents.getChromosomes()[i];
            // cout << "----------> if false child size chromosome After not cross: " << child.getGenes().size() << endl;
        }
        // cout << "----------> After crossover child size chromosome: " << child.getGenes().size() << endl;

        // if (randomValueForMutation <= mutationRate)
        // {
        //     cout << "Before mutation, population size: " << population.getChromosomes().size() << endl;
        //     cout << "Before mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
        //     cout << "Before mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
        //     mutate(child);
        //     cout << "After mutation, population size: " << population.getChromosomes().size() << endl;
        //     cout << "After mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
        //     cout << "After mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
        // }
        // cout << "----------> offspring population: " << offspring.getChromosomes().size() << endl;
        // cout << "----------> child size chromosome: " << child.getGenes().size() << endl;

        // printing information about the gene/module (child in this case), venue, and time slot
        // int counter = 1;
        // for (const ScheduledModule &gene : child.getGenes())
        // {
        //     // Print information about the gene/module, venue, and time slot
        //     cout << "Gene: " << counter << endl;
        //     gene.getModule().printInfo();
        //     gene.getTimeSlot().printInfo();
        //     gene.getVenue().printInfo();
        //     counter++;
        // }

        if (child.getGenes().size() != 153)
        {
            cout << "the child ERROR" << endl;
            cout << "^^^^^^^^^^^^child size : " << child.getGenes().size() << endl;

            exit(1);
        }
        offspring.addChromosome(child);
        // cout << "----------> end <----------" << endl;
    }
    // cout << "After Crossover and Mutation, population size: " << population.getChromosomes().size() << endl;
    // cout << "After Crossover and Mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
    // cout << "After Crossover and Mutation, Size of parent population: " << parents.getChromosomes().size() << endl;

    // cout << "Before Replacement, population size: " << population.getChromosomes().size() << endl;
    // cout << "Before Replacement, Size of offspring population: " << offspring.getChromosomes().size() << endl;
    // cout << "Before Replacement, Size of parent population: " << parents.getChromosomes().size() << endl;

    // cout << "Completed Crossover and Mutation. Starting Replacement..." << endl;

    // 4. Replacement
    replacePopulation(offspring);
    // cout << "After Replacement, population size: " << population.getChromosomes().size() << endl;
    // cout << "After Replacement, Size of offspring population: " << offspring.getChromosomes().size() << endl;
    // cout << "After Replacement, Size of parent population: " << parents.getChromosomes().size() << endl;

    // cout << "Completed Replacement." << endl;

    cout << "One generation completed." << endl;
    //   After replacing the population, calculate and store the total fitness
    double totalFitness = population.getTotalFitness();
    cout << "Total fitness of the population: " << totalFitness << endl;
    totalFitnessHistory.push_back(totalFitness); // Assuming totalFitnessHistory is a member vector<double>

    double totalBestFit = population.getBestFitness();
    cout << "total Best Fit of the population: " << totalBestFit << endl;
    totalBestFitHistory.push_back(totalBestFit); // Assuming totalFitnessHistory is a member vector<double>

    // // every 5 runs we clear same chromosomes
    // if ((generationCount % 5) == 0)
    // {
    //     int oldPopulationCount = population.getChromosomes().size();
    //     cout << "Before clearing the population, population size: " << population.getChromosomes().size() << endl;
    //     population.clearPopulation();
    //     int newPopulationCount = population.getChromosomes().size();
    //     cout << "After clearing the population, population size: " << population.getChromosomes().size() << endl;
    //     population.populateClearedChromosomes(oldPopulationCount - newPopulationCount);
    //     cout << "After populating the population, population size: " << population.getChromosomes().size() << endl;
    // }
}

void GeneticAlgorithm::run(int numberOfGenerations)
{
    cout << "Starting GA run for " << numberOfGenerations << " generations." << endl;
    for (int i = 0; i < numberOfGenerations; ++i)
    {
        // cout << "Starting generation " << i + 1 << endl;
        runOneGeneration(i + 1);
        // cout << "Completed generation " << i + 1 << endl;

        Chromosome bestChromosome = getBestChromosome();
        if (bestChromosome.evaluateFitness() == 0)
        {
            cout << "Optimal solution found. Stopping GA." << endl;
            break;
        }
    }
    // cout << "GA run completed." << endl;
}

Chromosome GeneticAlgorithm::getBestChromosome()
{
    // Assuming that Population::getBestNChromosomes returns the best 'n' chromosomes sorted by fitness
    vector<Chromosome> bestChromosomes = population.getBestNChromosomes(1);

    // Since we asked for only 1 best chromosome, it will be at index 0.
    return bestChromosomes[0];
}

void GeneticAlgorithm::printTotalFitnessHistory()
{
    std::cout << "Total Fitness History:" << std::endl;
    for (size_t i = 0; i < totalFitnessHistory.size(); ++i)
    {
        std::cout << "Generation " << (i + 1) << ": " << totalFitnessHistory[i] << std::endl;
    }
}

void GeneticAlgorithm::printTotalBestFitHistory()
{
    std::cout << "Total Best Fit History: ";
    for (const auto &val : totalBestFitHistory)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void GeneticAlgorithm::printProgress()
{
    std::cout << "=== Progress ===" << std::endl;
    // printTotalFitnessHistory();
    // printTotalBestFitHistory();
    for (size_t i = 0; i < totalFitnessHistory.size(); ++i)
    {
        std::cout << "Generation " << (i + 1) << ": Total Generation Fitness =>" << totalFitnessHistory[i] << " Best fit individual =>" << totalBestFitHistory[i] << std::endl;
    }
    std::cout << "================" << std::endl;
}