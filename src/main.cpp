// #include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <chrono>
#include <fstream>
#include "../include/GlobalVariables.h"
#include "../include/GeneticAlgorithm.h"
#include "../include/matplotlibcpp.h"

namespace plt = matplotlibcpp;

using namespace std;
vector<Lecturer> allLecturers; // Global array to hold all lecturers
vector<TimeSlot> allTimeSlots; // Global array to hold all time slots
vector<Module> allModules;     // Global array to hold all modules
vector<Venue> allVenues;       // Global array to hold all venues
vector<LecturerTimeSlotPreference> globalLecturerPreferences;
vector<Chromosome> initialPopulation;

void chromosomeToTextFile(const Chromosome &chromosome, const string &filename)
{
    ofstream file(filename);
    int counter = 1;
    for (const ScheduledModule &gene : chromosome.getGenes())
    {
        file << "Gene: " << counter << "\n";
        // Write Module, TimeSlot, and Venue info
        file << gene.getModule().toString() << "\n";
        file << gene.getTimeSlot().toString() << "\n";
        file << gene.getVenue().toString() << "\n";
        // Write additional gene attributes
        file << "IsLockedVenue: " << gene.getIsLockedVenue() << "\n";
        file << "IsLockedTimeSlot: " << gene.getIsLockedTimeSlot() << "\n";
        file << "IsValid: " << gene.getIsValid() << "\n";
        file << "IsFirstSlot: " << gene.getIsFirstSlot() << "\n";
        file << "IsOneSlot: " << gene.getIsOneSlot() << "\n";
        counter++;
    }
    file.close();
}

Chromosome textFileToChromosome(const string &filename)
{
    ifstream file(filename);
    string line;
    Chromosome chromosome;

    while (getline(file, line))
    {
        if (line.starts_with("Gene:"))
        {
            ScheduledModule scheduledModule;
            // Read and set Module info
            getline(file, line);
            Module module;
            module.fromString(line);
            scheduledModule.setModule(module);

            // Read and set TimeSlot info
            getline(file, line);
            TimeSlot timeSlot;
            timeSlot.fromString(line);
            scheduledModule.setTimeSlot(timeSlot);

            // Read and set Venue info
            getline(file, line);
            Venue venue;
            venue.fromString(line);
            scheduledModule.setVenue(venue);

            // Read and set additional attributes
            getline(file, line);
            scheduledModule.setIsLockedVenue(parseBool(line));
            getline(file, line);
            scheduledModule.setIsLockedTimeSlot(parseBool(line));
            getline(file, line);
            scheduledModule.setIsValid(parseBool(line));
            getline(file, line);
            scheduledModule.setIsFirstSlot(parseBool(line));
            getline(file, line);
            scheduledModule.setIsOneSlot(parseBool(line));

            // Add the ScheduledModule to the Chromosome
            chromosome.addGene(scheduledModule);
        }
    }

    file.close();
    return chromosome;
}

int main()
{
    // Step alpha: Capture the starting time
    auto start = std::chrono::high_resolution_clock::now();

    // Step 0: Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Step 1: Initialize Required Data
    initializeTimeSlots();       // Assuming this function initializes all possible time slots
    initializeVenues();          // Assuming this function initializes all possible venues
    initializeLecturers();       // Assuming this function initializes all possible lecturers
    initializeModules();         // Assuming this function initializes all possible modules
    initializeCrossoverPoints(); // Assuming this function initializes all possible CrossoverPoints
    initializeLecturerTimeSlotPreference();

    // Define GA parameters
    int POPULATION_SIZE = 100;
    double MUTATION_RATE = 0.01;
    double CROSSOVER_RATE = 0.75;
    int ELITE_COUNT = 3;
    int NUM_GENERATIONS = 10000;
    /////////////////////////////////////////////////

    Chromosome reconstructedChromosome = textFileToChromosome("chromosome_data.txt");
    //  chromosomeToTextFile(reconstructedChromosome, "chromosome_data_testing.txt");

    /////////////////////////////////////////////////
    int menueChoice = 0;
    while (menueChoice != 3)
    {
        cout << "please choose an option:" << endl
             << "1 :- Run the Genetic algorithm" << endl
             << "2 :- Edit a schedule" << endl
             << "3 :- Exit" << endl;
        cin >> menueChoice;
        if (menueChoice == 1)
        {

            //  Step 2: Initialize the First Population
            Population initialPop;
            initialPop.initializeFirstPopulation(POPULATION_SIZE);

            // Step 3: Initialize the Genetic Algorithm
            GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

            // Step 4: Run the Genetic Algorithm
            GA.run(NUM_GENERATIONS);

            // Step 5: Evaluate and Display the Best Solution Found
            Chromosome bestChromosome = GA.getBestChromosome(); // Assuming you add a function to return the best chromosome

            // Step 6: save the best chromosome in a file named "chromosome_data"
            chromosomeToTextFile(bestChromosome, "chromosome_data.txt");
            chromosomeToTextFile(bestChromosome, "chromosome_data_editing.txt");

            // Step 7: Evaluate fitness of the best chromosome
            double fitness = bestChromosome.evaluateFitness();
            cout << "Best Chromosome Fitness: " << fitness << endl;

            // Step 8: print the progress of the Genetic Algorithm
            GA.printProgress();

            // Step 9: check the state of the best chromosome
            if (fitness == 0)
            {
                cout << "Found a valid solution and is saved in chromosome_data.txt file ready to parse.";
            }
            else
            {
                // Call the function to hold the id of the genes that is violating the constraints violations
                std::pair<int, std::string> violation = bestChromosome.catchViolation();

                // A violation was detected
                std::cout << "Violation detected at gene index " << violation.first << ": " << violation.second << std::endl;
            }

            // Step 10: Capture the ending time
            auto end = std::chrono::high_resolution_clock::now();

            // Compute the total duration in seconds
            auto totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);

            // Extract minutes and seconds
            auto minutes = totalSeconds.count() / 60;
            auto seconds = totalSeconds.count() % 60;

            std::cout << "Time taken to finish is: " << minutes << " minutes and " << seconds << " seconds" << std::endl;
            // exite the code
            menueChoice = 3;
        }
        else if (menueChoice == 2)
        {
            Chromosome reconstructedChromosome = textFileToChromosome("chromosome_data_editing.txt");
            double fitness = reconstructedChromosome.evaluateFitness();

            cout << "Best Chromosome Fitness: " << fitness << endl;

            //  Step 2: Initialize the First Population
            Population initialPop;
            initialPop.initializePopulationChromosome(POPULATION_SIZE, reconstructedChromosome);

            // Step 3: Initialize the Genetic Algorithm
            GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

            // Step 4: Run the Genetic Algorithm
            GA.run(NUM_GENERATIONS);

            // Step 5: Evaluate and Display the Best Solution Found
            Chromosome bestChromosome = GA.getBestChromosome(); // Assuming you add a function to return the best chromosome
            // cout << "Best Chromosome: " << endl;

            // save the best chromosome in a file named "chromosome_data"
            chromosomeToTextFile(bestChromosome, "chromosome_data.txt");

            // Evaluate fitness of the best chromosome
            // double fitness = bestChromosome.evaluateFitness();
            // cout << "Best Chromosome Fitness: " << fitness << endl;

            GA.printProgress();
            ////////////////////////////////////////
            if (fitness == 0)
            {
                cout << "Found a valid solution and is saved in chromosome_data.txt file ready to parse.";
            }
            else
            {
                // Call the function to check for violations
                std::pair<int, std::string> violation = bestChromosome.catchViolation();

                // A violation was detected
                std::cout << "Violation detected at gene index " << violation.first << ": " << violation.second << std::endl;
            }

            ////////////////////////////////////////
            // Step 6: Capture the ending time
            auto end = std::chrono::high_resolution_clock::now();

            // Compute the total duration in seconds
            auto totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);

            // Extract minutes and seconds
            auto minutes = totalSeconds.count() / 60;
            auto seconds = totalSeconds.count() % 60;

            std::cout << "Time taken to finish is: " << minutes << " minutes and " << seconds << " seconds" << std::endl;
        }
        else if (menueChoice == 3)
        {
            exit(1);
        }
        else
        {
            cout << "Your input is incorrect , try again!.." << endl;
        }
    }

    // //  Step 2: Initialize the First Population
    // Population initialPop;
    // // initialPop.initializeFirstPopulation(POPULATION_SIZE);
    // initialPop.initializePopulationChromosome(POPULATION_SIZE, reconstructedChromosome);

    // // Step 3: Initialize the Genetic Algorithm
    // GeneticAlgorithm GA(initialPop, MUTATION_RATE, CROSSOVER_RATE, ELITE_COUNT);

    // // Step 4: Run the Genetic Algorithm
    // GA.run(NUM_GENERATIONS);

    // // Step 5: Evaluate and Display the Best Solution Found
    // Chromosome bestChromosome = GA.getBestChromosome(); // Assuming you add a function to return the best chromosome
    // // cout << "Best Chromosome: " << endl;

    // // save the best chromosome in a file named "chromosome_data"
    // chromosomeToTextFile(bestChromosome, "chromosome_data.txt");

    // // Evaluate fitness of the best chromosome
    // double fitness = bestChromosome.evaluateFitness();
    // cout << "Best Chromosome Fitness: " << fitness << endl;

    // GA.printProgress();
    ////////////////////////////////////////
    // if (fitness == 0)
    // {
    //     cout << "Found a valid solution and is saved in chromosome_data.txt file ready to parse.";
    // }
    // else
    // {
    //     // Call the function to check for violations
    //     std::pair<int, std::string> violation = bestChromosome.catchViolation();

    //     // A violation was detected
    //     std::cout << "Violation detected at gene index " << violation.first << ": " << violation.second << std::endl;
    // }

    // ////////////////////////////////////////
    // // Step 6: Capture the ending time
    // auto end = std::chrono::high_resolution_clock::now();

    // // Compute the total duration in seconds
    // auto totalSeconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    // // Extract minutes and seconds
    // auto minutes = totalSeconds.count() / 60;
    // auto seconds = totalSeconds.count() % 60;

    // std::cout << "Time taken to finish is: " << minutes << " minutes and " << seconds << " seconds" << std::endl;

    return 0;
}