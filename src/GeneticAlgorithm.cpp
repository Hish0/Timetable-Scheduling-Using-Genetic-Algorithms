#include <algorithm>
#include <cstdlib>
#include "../include/GeneticAlgorithm.h"
#include "../include/UtilityFunctions.h"
#include "../include/matplotlibcpp.h"
using namespace Utility;
namespace plt = matplotlibcpp;
GeneticAlgorithm::GeneticAlgorithm(Population &initialPopulation, double mutationRate, double crossoverRate, int eliteCount)
    : population(initialPopulation), mutationRate(mutationRate), crossoverRate(crossoverRate), eliteCount(eliteCount) {}

Population GeneticAlgorithm::selectParents()
{
    vector<Chromosome> selectedParents;
    int tournamentSize = 2; // You can change this

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
        if (child1.getGenes().size() != 147)
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
        if (child2.getGenes().size() != 147)
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
    // Randomly select a gene
    int geneIndex = rand() % chromosome.getGenes().size();
    ScheduledModule &geneToMutate = chromosome.getGene(geneIndex);

    cout << endl
         << "Selected gene at index: " << geneIndex << endl;
    cout << "Initial time state of gene to mutate: " << geneToMutate.getTimeSlot().getTime() << endl;
    cout << "Initial venue state of gene to mutate: " << geneToMutate.getVenue().getName() << endl;

    // Check if it's a one-slot or the first of a two-slot module
    if (geneToMutate.getIsOneSlot())
    {
        cout << "It's a one-slot module." << endl;

        // It's a one-slot module, assign a new random time slot
        TimeSlot newTimeSlot = getRandomTimeSlot();
        Venue newVenue = getRandomVenue();
        cout << "Assigning new time slot: " << newTimeSlot.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlot);
        geneToMutate.setVenue(newVenue);
    }
    else if (geneToMutate.getIsFirstSlot())
    {
        cout << "It's the first of a two-slot module." << endl;

        // It's the first of a two-slot module, assign new consecutive time slots
        TimeSlot newTimeSlotForFirst = getRandomTimeSlot(); // Ensure this is a valid starting slot for two consecutive slots
        // insure the new slot is not the last slot of the day
        while (isLastSlotOfDay(newTimeSlotForFirst))
        {
            newTimeSlotForFirst = getRandomTimeSlot();
        }

        TimeSlot newTimeSlotForSecond = newTimeSlotForFirst.getNextTimeSlot(); // Get the consecutive slot

        Venue newVenue = getRandomVenue();

        cout << "Assigning new consecutive time slots: First - " << newTimeSlotForFirst.getTime() << ", Second - " << newTimeSlotForSecond.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlotForFirst);
        chromosome.getGene(geneIndex + 1).setTimeSlot(newTimeSlotForSecond); // Update the second slot as well
        geneToMutate.setVenue(newVenue);
        chromosome.getGene(geneIndex + 1).setVenue(newVenue);

        cout << "Updated gene at index: " << geneIndex << " to time slot " << newTimeSlotForFirst.getTime() << "and venue " << newVenue.getName() << endl;
        cout << "Updated gene at index: " << geneIndex + 1 << " to time slot " << newTimeSlotForSecond.getTime() << "and venue " << newVenue.getName() << endl;
    }
    else
    {
        cout << "It's neither a one-slot module nor the first of a two-slot module. No mutation applied." << endl;
    }

    // Make sure to re-evaluate and handle any violations this may cause
    // handleViolations(chromosome, geneIndex);
    cout << "Mutation complete. Need to handle potential violations." << endl
         << endl;
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
    //    Get the number of chromosomes to be replaced in the old population
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
    vector<Chromosome> elites = population.getBestNDiverseChromosomes(eliteCount);

    // cout << "Size of elites: " << elites.size() << endl;

    // cout << "Completed Elitism. Starting Selection..." << endl;
    //   2. Selection
    Population parents = selectParents();
    // cout << "After Selection, Size of parent population: " << parents.getChromosomes().size() << endl;
    // cout << "After Selection, Size of population: " << population.getChromosomes().size() << endl;

    // every 50 runs we clear same chromosomes
    // if ((generationCount % 50) == 0)
    // {
    //     int oldPopulationCount = parents.getChromosomes().size();
    //     cout << "Before clearing the population, population size: " << parents.getChromosomes().size() << endl;
    //     parents.clearPopulation();
    //     int newPopulationCount = parents.getChromosomes().size();
    //     cout << "After clearing the population, population size: " << parents.getChromosomes().size() << endl;
    //     parents.populateClearedChromosomes(oldPopulationCount - newPopulationCount);
    //     cout << "After populating the population, population size: " << parents.getChromosomes().size() << endl;
    // }

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
        if (generationCount <= 25)
        {
            if (randomValueForMutation <= mutationRate)
            {
                // cout << "Before mutation, population size: " << population.getChromosomes().size() << endl;
                // cout << "Before mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                // cout << "Before mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
                mutate(child);
                // cout << "After mutation, population size: " << population.getChromosomes().size() << endl;
                // cout << "After mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                // cout << "After mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
            }
        }
        else
        {
            if (randomValueForMutation <= mutationRate)
            {
                // cout << "Before mutation, population size: " << population.getChromosomes().size() << endl;
                // cout << "Before mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                // cout << "Before mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
                mutate(child);
                // cout << "After mutation, population size: " << population.getChromosomes().size() << endl;
                // cout << "After mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                // cout << "After mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
            }
            if (randomValueForMutation <= 0.15)
            {
                // cout << "Before mutation, population size: " << population.getChromosomes().size() << endl;
                // cout << "Before mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                // cout << "Before mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
                offspring.addChromosome(child);
                child = this->getBestChromosome();
                // cout << "------> best child time for first gene" << child.getGene(1).getTimeSlot().getTime();

                std::pair<int, std::string> violation = child.catchViolation();
                if (startsWith(violation.second, "Lecturer's time slot preference violated for gene"))
                {
                    surgeryMutationForTimeSlotPrefrence(child, violation.first);
                }
                else if (startsWith(violation.second, "Time gap detected"))
                {
                    int geneIdToMove = violation.first;                                       // The gene ID to move
                    int lastTimeSlotIdOfPreviousModule = extractLastSlotId(violation.second); // Extract the last slot ID from the message
                    // lastTimeSlotIdOfPreviousModule++;
                    cout << "000000last slot id is " << lastTimeSlotIdOfPreviousModule << " 000000" << endl;
                    surgeryMutationForTimeSlotGap(child, geneIdToMove, lastTimeSlotIdOfPreviousModule);
                }
                else
                {
                    surgeryMutation(child, violation.first);
                }

                // cout << "After mutation, population size: " << population.getChromosomes().size() << endl;
                // cout << "After mutation, Size of offspring population: " << offspring.getChromosomes().size() << endl;
                // cout << "After mutation, Size of parent population: " << parents.getChromosomes().size() << endl;
            }
        }

        // cout << "----------> offspring population: " << offspring.getChromosomes().size() << endl;
        // cout << "----------> child size chromosome: " << child.getGenes().size() << endl;

        if (child.getGenes().size() != 147)
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
    cout << "Best Fitness individual of the population: " << totalBestFit << endl;
    totalBestFitHistory.push_back(totalBestFit); // Assuming totalFitnessHistory is a member vector<double>

    Chromosome bestChromosome = getBestChromosome();
    double totalBestFit1 = bestChromosome.evaluateFitness();

    /////////////////////////////////////

    // Cast gencount to double for plotting
    double gencount_double = static_cast<double>(generationCount);

    // Add the latest fitness values to your history vectors
    totalFitnessHistory.push_back(totalFitness);
    totalBestFitHistory.push_back(totalBestFit1);

    // Ensure the generations vector is the correct size
    std::vector<double> generations(generationCount);
    std::iota(generations.begin(), generations.end(), 1);

    // Clear the previous plot if you're not accumulating the data points
    // plt::clf(); (Uncomment this if you need to clear the previous points)

    // Customize the plot only if it's the first generation
    if (generationCount == 1)
    {
        // Figure 1: Current Points
        plt::figure(1);
        plt::xlabel("Generation");
        plt::ylabel("Fitness Value");
        plt::title("Fitness History VS Best Fit History");
        plt::legend();

        // Figure 2: Fitness History
        plt::figure(2);
        plt::xlabel("Generation");
        plt::ylabel("Total Fitness History");
        plt::title("Fitness History");

        // Figure 3: Best Fit History
        plt::figure(3);
        plt::xlabel("Generation");
        plt::ylabel("Best Fit History");
        plt::title("Best Fit History");
    }

    // Figure 1: Plot of the current points
    plt::figure(1);
    plt::scatter(std::vector<double>{gencount_double}, std::vector<double>{totalFitness}, 10.0); // size of the marker can be adjusted
    plt::scatter(std::vector<double>{gencount_double}, std::vector<double>{totalBestFit1}, 10.0);
    plt::draw();

    // Figure 2: Plot of the fitness history
    plt::figure(2);
    // plt::plot(std::vector<double>(totalFitnessHistory.begin(), totalFitnessHistory.end()));
    plt::scatter(std::vector<double>{gencount_double}, std::vector<double>{totalFitness}, 10.0); // size of the marker can be adjusted
    // plt::scatter(std::vector<double>{gencount_double}, std::vector<double>{totalBestFit1}, 10.0);
    plt::draw();

    // Figure 3: Plot of the best fit history
    plt::figure(3);
    // plt::plot(std::vector<double>(totalBestFitHistory.begin(), totalBestFitHistory.end()));
    // plt::scatter(std::vector<double>{gencount_double}, std::vector<double>{totalFitness}, 10.0); // size of the marker can be adjusted
    plt::scatter(std::vector<double>{gencount_double}, std::vector<double>{totalBestFit1}, 10.0);
    plt::draw();

    // Display the plots with a pause to update the windows
    plt::pause(0.01); // Adjust the pause time as needed
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
    // After all generations are run or an optimal solution is found,
    // display all figures and wait for the user to close them.
    plt::show();
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

// this function needs to be global for population and GA classes
bool GeneticAlgorithm::isLastSlotOfDay(const TimeSlot &timeSlot)

{
    int slotId = timeSlot.getTimeSlotID();
    return slotId % 8 == 0;
}

void GeneticAlgorithm::surgeryMutation(Chromosome &chromosome, int geneId)
{
    // Randomly select a gene
    // int geneIndex = rand() % chromosome.getGenes().size();
    ScheduledModule &geneToMutate = chromosome.getGene(geneId);

    cout << endl
         << "Selected gene at index: " << geneId << endl;
    cout << "Initial time state of gene to mutate: " << geneToMutate.getTimeSlot().getTime() << endl;
    cout << "Initial venue state of gene to mutate: " << geneToMutate.getVenue().getName() << endl;

    // Check if it's a one-slot or the first of a two-slot module
    if (geneToMutate.getIsOneSlot())
    {
        cout << "It's a one-slot module." << endl;

        // It's a one-slot module, assign a new random time slot
        TimeSlot newTimeSlot = getRandomTimeSlot();
        Venue newVenue = getRandomVenue();
        cout << "Assigning new time slot: " << newTimeSlot.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlot);
        geneToMutate.setVenue(newVenue);
    }
    else if (geneToMutate.getIsFirstSlot())
    {
        cout << "It's the first of a two-slot module." << endl;

        // It's the first of a two-slot module, assign new consecutive time slots
        TimeSlot newTimeSlotForFirst = getRandomTimeSlot(); // Ensure this is a valid starting slot for two consecutive slots
        // insure the new slot is not the last slot of the day
        while (isLastSlotOfDay(newTimeSlotForFirst) || newTimeSlotForFirst.getTimeSlotID() == 20)
        {
            newTimeSlotForFirst = getRandomTimeSlot();
        }

        TimeSlot newTimeSlotForSecond = newTimeSlotForFirst.getNextTimeSlot(); // Get the consecutive slot

        Venue newVenue = getRandomVenue();

        cout << "Assigning new consecutive time slots: First - " << newTimeSlotForFirst.getTime() << ", Second - " << newTimeSlotForSecond.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlotForFirst);
        chromosome.getGene(geneId + 1).setTimeSlot(newTimeSlotForSecond); // Update the second slot as well
        geneToMutate.setVenue(newVenue);
        chromosome.getGene(geneId + 1).setVenue(newVenue);

        cout << "Updated gene at index: " << geneId << " to time slot " << newTimeSlotForFirst.getTime() << "and venue " << newVenue.getName() << endl;
        cout << "Updated gene at index: " << geneId + 1 << " to time slot " << newTimeSlotForSecond.getTime() << "and venue " << newVenue.getName() << endl;
    }
    else
    {
        cout << "It's the second of a two-slot module." << endl;

        // It's the second of a two-slot module, assign new consecutive time slots
        TimeSlot newTimeSlotForFirst = getRandomTimeSlot(); // Ensure this is a valid starting slot for two consecutive slots
        // insure the new slot is not the last slot of the day
        while (isLastSlotOfDay(newTimeSlotForFirst) || newTimeSlotForFirst.getTimeSlotID() == 20)
        {
            newTimeSlotForFirst = getRandomTimeSlot();
        }

        TimeSlot newTimeSlotForSecond = newTimeSlotForFirst.getNextTimeSlot(); // Get the consecutive slot

        Venue newVenue = getRandomVenue();

        cout << "Assigning new consecutive time slots: First - " << newTimeSlotForFirst.getTime() << ", Second - " << newTimeSlotForSecond.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlotForSecond);
        chromosome.getGene(geneId - 1).setTimeSlot(newTimeSlotForFirst); // Update the second slot as well
        geneToMutate.setVenue(newVenue);
        chromosome.getGene(geneId - 1).setVenue(newVenue);

        cout << "Updated gene at index: " << geneId - 1 << " to time slot " << newTimeSlotForFirst.getTime() << "and venue " << newVenue.getName() << endl;
        cout << "Updated gene at index: " << geneId << " to time slot " << newTimeSlotForSecond.getTime() << "and venue " << newVenue.getName() << endl;
    }

    // Make sure to re-evaluate and handle any violations this may cause
    // handleViolations(chromosome, geneIndex);
    cout << "Mutation complete. Need to handle potential violations." << endl
         << endl;
}

void GeneticAlgorithm::surgeryMutationForTimeSlotPrefrence(Chromosome &chromosome, int geneId)
{
    // Randomly select a gene
    // int geneIndex = rand() % chromosome.getGenes().size();
    ScheduledModule &geneToMutate = chromosome.getGene(geneId);

    cout << endl
         << "Selected gene at index: " << geneId << endl;
    cout << "Initial time state of gene to mutate: " << geneToMutate.getTimeSlot().getTime() << endl;
    cout << "Initial venue state of gene to mutate: " << geneToMutate.getVenue().getName() << endl;

    // Check if it's a one-slot or the first of a two-slot module
    if (geneToMutate.getIsOneSlot())
    {
        cout << "It's a one-slot module." << endl;

        // It's a one-slot module, assign a new random time slot
        TimeSlot newTimeSlot = getRandomTimeSlotFromPreference(geneToMutate.getModule());
        Venue newVenue = getRandomVenue();
        cout << "Assigning new time slot: " << newTimeSlot.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlot);
        geneToMutate.setVenue(newVenue);
    }
    else if (geneToMutate.getIsFirstSlot())
    {
        cout << "It's the first of a two-slot module." << endl;

        // It's the first of a two-slot module, assign new consecutive time slots
        TimeSlot newTimeSlotForFirst = getRandomTimeSlotFromPreference(geneToMutate.getModule()); // Ensure this is a valid starting slot for two consecutive slots
        // insure the new slot is not the last slot of the day
        while (isLastSlotOfDay(newTimeSlotForFirst) || newTimeSlotForFirst.getTimeSlotID() == 20)
        {
            newTimeSlotForFirst = getRandomTimeSlotFromPreference(geneToMutate.getModule());
        }

        TimeSlot newTimeSlotForSecond = newTimeSlotForFirst.getNextTimeSlot(); // Get the consecutive slot

        Venue newVenue = getRandomVenue();

        cout << "Assigning new consecutive time slots: First - " << newTimeSlotForFirst.getTime() << ", Second - " << newTimeSlotForSecond.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlotForFirst);
        chromosome.getGene(geneId + 1).setTimeSlot(newTimeSlotForSecond); // Update the second slot as well
        geneToMutate.setVenue(newVenue);
        chromosome.getGene(geneId + 1).setVenue(newVenue);

        cout << "Updated gene at index: " << geneId << " to time slot " << newTimeSlotForFirst.getTime() << "and venue " << newVenue.getName() << endl;
        cout << "Updated gene at index: " << geneId + 1 << " to time slot " << newTimeSlotForSecond.getTime() << "and venue " << newVenue.getName() << endl;
    }
    else
    {
        cout << "It's the second of a two-slot module." << endl;

        // It's the second of a two-slot module, assign new consecutive time slots
        TimeSlot newTimeSlotForFirst = getRandomTimeSlotFromPreference(geneToMutate.getModule()); // Ensure this is a valid starting slot for two consecutive slots
        // insure the new slot is not the last slot of the day
        while (isLastSlotOfDay(newTimeSlotForFirst) || newTimeSlotForFirst.getTimeSlotID() == 20)
        {
            newTimeSlotForFirst = getRandomTimeSlotFromPreference(geneToMutate.getModule());
        }

        TimeSlot newTimeSlotForSecond = newTimeSlotForFirst.getNextTimeSlot(); // Get the consecutive slot

        Venue newVenue = getRandomVenue();

        cout << "Assigning new consecutive time slots: First - " << newTimeSlotForFirst.getTime() << ", Second - " << newTimeSlotForSecond.getTime() << endl;
        cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlotForSecond);
        chromosome.getGene(geneId - 1).setTimeSlot(newTimeSlotForFirst); // Update the second slot as well
        geneToMutate.setVenue(newVenue);
        chromosome.getGene(geneId - 1).setVenue(newVenue);

        cout << "Updated gene at index: " << geneId - 1 << " to time slot " << newTimeSlotForFirst.getTime() << "and venue " << newVenue.getName() << endl;
        cout << "Updated gene at index: " << geneId << " to time slot " << newTimeSlotForSecond.getTime() << "and venue " << newVenue.getName() << endl;
    }

    // Make sure to re-evaluate and handle any violations this may cause
    // handleViolations(chromosome, geneIndex);
    cout << "Mutation complete. Need to handle potential violations." << endl
         << endl;
}

void GeneticAlgorithm::surgeryMutationForTimeSlotGap(Chromosome &chromosome, int geneIdToMove, int lastTimeSlotIdOfPreviousModule)
{
    // Retrieve the gene that needs to be moved
    ScheduledModule &geneToMutate = chromosome.getGene(geneIdToMove);

    cout << "Selected gene at index: " << geneIdToMove << endl;
    cout << "Initial time state of gene to mutate: " << geneToMutate.getTimeSlot().getTime() << endl;
    cout << "Initial venue state of gene to mutate: " << geneToMutate.getVenue().getName() << endl;

    // Check the type of module and handle accordingly
    if (geneToMutate.getIsOneSlot())
    {
        cout << "It's a one-slot module." << endl;
        // For one-slot module, the new time slot is just after the last module
        int newTimeSlotId = lastTimeSlotIdOfPreviousModule + 1;
        if (newTimeSlotId == 21 || newTimeSlotId == 22)
        {
            newTimeSlotId = 23;
        }
        TimeSlot newTimeSlot = getTimeSlotById(newTimeSlotId);
        // Venue newVenue = getRandomVenue();

        cout << "Assigning new time slot: " << newTimeSlot.getTime() << endl;
        // cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlot);
        // geneToMutate.setVenue(newVenue);
    }
    else if (geneToMutate.getIsFirstSlot())
    {
        cout << "It's the first of a two-slot module." << endl;
        // For the first of a two-slot module, assign new consecutive time slots
        int newTimeSlotIdForFirst = lastTimeSlotIdOfPreviousModule + 1;
        if (newTimeSlotIdForFirst == 21 || newTimeSlotIdForFirst == 22)
        {
            newTimeSlotIdForFirst = 23;
        }
        TimeSlot newTimeSlotForFirst = getTimeSlotById(newTimeSlotIdForFirst);
        TimeSlot newTimeSlotForSecond = newTimeSlotForFirst.getNextTimeSlot();
        // Venue newVenue = getRandomVenue();

        cout << "Assigning new consecutive time slots: First - " << newTimeSlotForFirst.getTime() << ", Second - " << newTimeSlotForSecond.getTime() << endl;
        // cout << "Assigning new venue name: " << newVenue.getName() << endl;

        geneToMutate.setTimeSlot(newTimeSlotForFirst);
        chromosome.getGene(geneIdToMove + 1).setTimeSlot(newTimeSlotForSecond);
        // geneToMutate.setVenue(newVenue);
        // chromosome.getGene(geneIdToMove + 1).setVenue(newVenue);
    }
    else
    {
        cout << "It's the second of a two-slot module." << endl;
        // For the second of a two-slot module, adjust the first slot accordingly
        int newTimeSlotIdForFirst = lastTimeSlotIdOfPreviousModule + 1;
        if (newTimeSlotIdForFirst == 21 || newTimeSlotIdForFirst == 22)
        {
            newTimeSlotIdForFirst = 23;
        }
        TimeSlot newTimeSlotForFirst = getTimeSlotById(newTimeSlotIdForFirst);
        TimeSlot newTimeSlotForSecond = newTimeSlotForFirst.getNextTimeSlot();
        // Venue newVenue = getRandomVenue();

        cout << "Assigning new consecutive time slots: First - " << newTimeSlotForFirst.getTime() << ", Second - " << newTimeSlotForSecond.getTime() << endl;
        // cout << "Assigning new venue name: " << newVenue.getName() << endl;

        chromosome.getGene(geneIdToMove - 1).setTimeSlot(newTimeSlotForFirst);
        geneToMutate.setTimeSlot(newTimeSlotForSecond);
        // chromosome.getGene(geneIdToMove - 1).setVenue(newVenue);
        // geneToMutate.setVenue(newVenue);
    }

    cout << "Mutation complete. Need to handle potential violations." << endl
         << endl;
}
