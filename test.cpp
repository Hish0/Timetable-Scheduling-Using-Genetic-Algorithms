#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <algorithm>
#include <random> // for random functions
#include <sstream>
#include "Lecturer/Lecturer.h"
#include "TimeSlot/TimeSlot.h"
#include "Module/Module.h"
#include "Venue/Venue.h"
#include "LecturerTimeSlotPreference/LecturerTimeSlotPreference.h"
#include "ScheduledModule/ScheduledModule.h"
#include "Chromosome/Chromosome.h"
#include "GlobalVariables/GlobalVariables.h"
#include "GeneticAlgorithm/GeneticAlgorithm.h"

using namespace std;
vector<Lecturer> allLecturers; // Global array to hold all lecturers
vector<TimeSlot> allTimeSlots; // Global array to hold all time slots
vector<Module> allModules;     // Global array to hold all modules
vector<Venue> allVenues;       // Global array to hold all venues
vector<Chromosome> initialPopulation;

int main()
{
    cout << "Seeding random number generator..." << endl;
    // Step 0: Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Initializing required data..." << endl;
    // Step 1: Initialize Required Data
    initializeTimeSlots(); // Assuming this function initializes all possible time slots
    initializeVenues();    // Assuming this function initializes all possible venues
    initializeLecturers(); // Assuming this function initializes all possible lecturers
    initializeModules();   // Assuming this function initializes all possible modules

    // Define GA parameters
    int POPULATION_SIZE = 10;
    double MUTATION_RATE = 0.1;
    double CROSSOVER_RATE = 0.3;
    int ELITE_COUNT = 5;
    int NUM_GENERATIONS = 3;

    // cout << "Initializing first population..." << endl;
    //  Step 2: Initialize the First Population
    Population initialPop;
    initialPop.initializeFirstPopulation(POPULATION_SIZE);
    // cout << "Initial population size: " << initialPop.getChromosomes().size() << endl;

    cout << "Initializing Genetic Algorithm..." << endl;
    // Step 3: Initialize the Genetic Algorithm
    GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

    cout << "Running Genetic Algorithm..." << endl;
    // Step 4: Run the Genetic Algorithm
    GA.run(NUM_GENERATIONS);
    cout << "Genetic Algorithm completed." << endl;

    // Step 5: Evaluate and Display the Best Solution Found
    Chromosome bestChromosome = GA.getBestChromosome(); // Assuming you add a function to return the best chromosome
    cout << "Best Chromosome: " << endl;

    int counter = 1;
    for (const ScheduledModule &gene : bestChromosome.getGenes())
    {
        // Print information about the gene/module, venue, and time slot
        cout << "Gene: " << counter << endl;
        gene.getModule().printInfo();
        gene.getTimeSlot().printInfo();
        gene.getVenue().printInfo();
        counter++;
    }

    // Evaluate fitness of the best chromosome
    double fitness = bestChromosome.evaluateFitness();
    cout << "Best Chromosome Fitness: " << fitness << endl;
    bestChromosome.checkGeneSize();
    bestChromosome.printGenesByDay();

    GA.printTotalFitnessHistory();

    return 0;
}