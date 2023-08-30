int main()
{
    // Initialize Lecturers
    Lecturer lecturer1(1, "Dr. Smith");
    Lecturer lecturer2(2, "Dr. Johnson");

    // Initialize TimeSlots
    TimeSlot timeSlot1(1, "Monday", "9:00 AM");
    TimeSlot timeSlot2(2, "Monday", "10:00 AM");
    TimeSlot timeSlot3(3, "Monday", "11:00 AM");

    // Initialize Venues
    Venue venue1(1, "Room A", 30, false);
    Venue venue2(2, "Room B", 40, true);
    Venue venue3(3, "Room s", 40, true);

    // Initialize Modules
    Module module1(1, lecturer1, "Math", 1, 25, false);      // Level 1
    Module module2(2, lecturer2, "Physics", 1, 35, true);    // Level 1
    Module module3(3, lecturer2, "Chemistry", 2, 35, false); // Level 2

    // Initialize ScheduledModules
    ScheduledModule scheduledModule1(module1, timeSlot3, venue1, false, false, true); // Should violate the first constraint
    ScheduledModule scheduledModule2(module2, timeSlot1, venue3, false, false, true); // Should violate the first constraint
    ScheduledModule scheduledModule3(module2, timeSlot2, venue1, false, false, true);
    ScheduledModule scheduledModule4(module3, timeSlot1, venue2, false, false, true);

    // Initialize Chromosome
    std::vector<ScheduledModule> genes = {scheduledModule1, scheduledModule2, scheduledModule3, scheduledModule4};
    Chromosome chromosome(genes);

    // Evaluate Fitness
    double fitness = chromosome.evaluateFitness();

    // Output the fitness value
    std::cout << "Fitness value: " << fitness << std::endl;

    return 0;
}
