# Function to parse a single gene block and return a dictionary
def parse_gene(gene_block):
    gene_dict = {}
    lines = gene_block.strip().split('\n')
    # Parsing module information
    module_info = lines[1].split(", ")
    gene_dict['Module'] = {item.split(": ")[0]: item.split(": ")[1] for item in module_info}
    # Parsing time slot information
    time_slot_info = lines[2].split(", ")
    gene_dict['TimeSlot'] = {item.split(": ")[0]: item.split(": ")[1] for item in time_slot_info}
    # Parsing venue information
    venue_info = lines[3].split(", ")
    gene_dict['Venue'] = {item.split(": ")[0]: item.split(": ")[1] for item in venue_info}
    return gene_dict

# Function to generate HTML table for a single venue
def generate_venue_table(venue_name, schedule):
    html = f'<h3>{venue_name}</h3>'
    html += '<table>'
    # Header row
    html += '''
    <tr class="header">
        <th>Days / Time</th>
        <th>8:00 AM - 9:00 AM</th>
        <th>9:00 AM - 10:00 AM</th>
        <th>10:00 AM - 11:00 AM</th>
        <th>11:00 AM - 12:00 PM</th>
        <th>12:00 PM - 1:00 PM</th>
        <th>1:00 PM - 2:00 PM</th>
        <th>2:00 PM - 3:00 PM</th>
        <th>3:00 PM - 4:00 PM</th>
    </tr>
    '''
    # Days of the week
    days_of_week = ['Saturday', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
    # Generate table rows for each day
    for day in days_of_week:
        html += f'<tr><td>{day}</td>'
        for time in ['8:00 AM', '9:00 AM', '10:00 AM', '11:00 AM', '12:00 PM', '1:00 PM', '2:00 PM', '3:00 PM']:
            cell_content = schedule.get(day, {}).get(time, '')
            html += f'<td>{cell_content}</td>'
        html += '</tr>'
    html += '</table>'
    return html

# Initialize a dictionary to store the consolidated timetable
consolidated_timetable = {}

# Function to generate a consolidated HTML table with all modules and venues
def generate_consolidated_table(consolidated_schedule):
    html = '<h3>Consolidated Timetable</h3>'
    html += '<table>'
    # Header row
    html += '''
    <tr class="header">
        <th>Days / Time</th>
        <th>8:00 AM - 9:00 AM</th>
        <th>9:00 AM - 10:00 AM</th>
        <th>10:00 AM - 11:00 AM</th>
        <th>11:00 AM - 12:00 PM</th>
        <th>12:00 PM - 1:00 PM</th>
        <th>1:00 PM - 2:00 PM</th>
        <th>2:00 PM - 3:00 PM</th>
        <th>3:00 PM - 4:00 PM</th>
    </tr>
    '''
    # Days of the week
    days_of_week = ['Saturday', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
    # Generate table rows for each day
    for day in days_of_week:
        html += f'<tr><td>{day}</td>'
        for time in ['8:00 AM', '9:00 AM', '10:00 AM', '11:00 AM', '12:00 PM', '1:00 PM', '2:00 PM', '3:00 PM']:
            cell_content = consolidated_schedule.get(day, {}).get(time, '')
            html += f'<td>{cell_content}</td>'
        html += '</tr>'
    html += '</table>'
    return html

# Your gene data goes here. The provided data already contains some of the new time slots.
gene_data = '''
Gene: 1
Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 36, Day: Wednesday, Time: 1:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 2
Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 37, Day: Wednesday, Time: 2:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 3
Module ID: 2, Lecturer: Dr. Khadeja, Name: MM101, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 4
Module ID: 2, Lecturer: Dr. Khadeja, Name: MM101, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 5
Module ID: 3, Lecturer: Dr. Salsabil, Name: MM102, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 41, Day: Thursday, Time: 10:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 6
Module ID: 3, Lecturer: Dr. Salsabil, Name: MM102, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 42, Day: Thursday, Time: 11:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 7
Module ID: 4, Lecturer: Dr. Nabeel, Name: ST101, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 9, Day: Sunday, Time: 8:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 8
Module ID: 4, Lecturer: Dr. Nabeel, Name: ST101, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 10, Day: Sunday, Time: 9:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 9
Module ID: 5, Lecturer: Dr. Mokhtar, Name: PH112, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 27, Day: Tuesday, Time: 12:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 10
Module ID: 5, Lecturer: Dr. Mokhtar, Name: PH112, Level: 1, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 28, Day: Tuesday, Time: 1:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 11
Module ID: 6, Lecturer: Dr. Mo3eed 2, Name: CS111, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 12
Module ID: 6, Lecturer: Dr. Mo3eed 2, Name: CS111, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 13, Day: Sunday, Time: 12:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 13
Module ID: 7, Lecturer: Dr. Ahmed abd almutaleb, Name: MM103, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 45, Day: Thursday, Time: 2:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 14
Module ID: 7, Lecturer: Dr. Ahmed abd almutaleb, Name: MM103, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 46, Day: Thursday, Time: 3:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 15
Module ID: 8, Lecturer: Dr. Aljalali, Name: MM104, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 34, Day: Wednesday, Time: 11:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 16
Module ID: 8, Lecturer: Dr. Aljalali, Name: MM104, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 35, Day: Wednesday, Time: 12:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 17
Module ID: 9, Lecturer: Dr. Ali alaswad, Name: ST102, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 22, Day: Monday, Time: 3:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 18
Module ID: 9, Lecturer: Dr. Ali alaswad, Name: ST102, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 23, Day: Tuesday, Time: 8:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 19
Module ID: 10, Lecturer: Dr. Mariam British, Name: EL101, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 17, Day: Monday, Time: 8:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 20
Module ID: 10, Lecturer: Dr. Mariam British, Name: EL101, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 21
Module ID: 11, Lecturer: Dr. Amira alelagi, Name: AR051, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 25, Day: Tuesday, Time: 10:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 22
Module ID: 11, Lecturer: Dr. Amira alelagi, Name: AR051, Level: 2, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 26, Day: Tuesday, Time: 11:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 23
Module ID: 12, Lecturer: Dr. Naema albadri, Name: CS115, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 33, Day: Wednesday, Time: 10:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 24
Module ID: 12, Lecturer: Dr. Naema albadri, Name: CS115, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 34, Day: Wednesday, Time: 11:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 25
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 21, Day: Monday, Time: 2:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 26
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 22, Day: Monday, Time: 3:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 27
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 41, Day: Thursday, Time: 10:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 28
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 42, Day: Thursday, Time: 11:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 29
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 30, Day: Tuesday, Time: 3:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 30
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 31, Day: Wednesday, Time: 8:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 31
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 32
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 33
Module ID: 15, Lecturer: Dr. Farhat, Name: MA200, Level: 3, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 23, Day: Tuesday, Time: 8:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 34
Module ID: 15, Lecturer: Dr. Farhat, Name: MA200, Level: 3, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 24, Day: Tuesday, Time: 9:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 35
Module ID: 16, Lecturer: Dr. Elbadri, Name: PH200, Level: 3, Enrolled Students: 100, Is Lab: No, Number of time slots: 3
TimeSlot ID: 45, Day: Thursday, Time: 2:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 36
Module ID: 16, Lecturer: Dr. Elbadri, Name: PH200, Level: 3, Enrolled Students: 100, Is Lab: No, Number of time slots: 3
TimeSlot ID: 46, Day: Thursday, Time: 3:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 37
Module ID: 16, Lecturer: Dr. Elbadri, Name: PH200, Level: 3, Enrolled Students: 100, Is Lab: No, Number of time slots: 3
TimeSlot ID: 35, Day: Wednesday, Time: 12:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 1
Gene: 38
Module ID: 17, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 4, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 39
Module ID: 17, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 4, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 40
Module ID: 18, Lecturer: Dr. Omaima Alsheli, Name: CS215, Level: 4, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 28, Day: Tuesday, Time: 1:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 41
Module ID: 18, Lecturer: Dr. Omaima Alsheli, Name: CS215, Level: 4, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 29, Day: Tuesday, Time: 2:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 42
Module ID: 19, Lecturer: Dr. Tasneem, Name: MA206, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 10, Day: Sunday, Time: 9:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 43
Module ID: 19, Lecturer: Dr. Tasneem, Name: MA206, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 11, Day: Sunday, Time: 10:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 44
Module ID: 20, Lecturer: Dr. Elbadri, Name: PH201, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 3
TimeSlot ID: 42, Day: Thursday, Time: 11:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 45
Module ID: 20, Lecturer: Dr. Elbadri, Name: PH201, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 3
TimeSlot ID: 43, Day: Thursday, Time: 12:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 46
Module ID: 20, Lecturer: Dr. Elbadri, Name: PH201, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 3
TimeSlot ID: 39, Day: Thursday, Time: 8:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 1
Gene: 47
Module ID: 21, Lecturer: Dr. Amira alelagi, Name: AR052, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 31, Day: Wednesday, Time: 8:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 48
Module ID: 21, Lecturer: Dr. Amira alelagi, Name: AR052, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 32, Day: Wednesday, Time: 9:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 49
Module ID: 22, Lecturer: Dr. Mariam British, Name: EL102, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 50
Module ID: 22, Lecturer: Dr. Mariam British, Name: EL102, Level: 4, Enrolled Students: 100, Is Lab: No, Number of time slots: 2
TimeSlot ID: 16, Day: Sunday, Time: 3:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 51
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 11, Day: Sunday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 52
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 53
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 22, Day: Monday, Time: 3:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 54
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 23, Day: Tuesday, Time: 8:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 55
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 9, Day: Sunday, Time: 8:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 56
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 10, Day: Sunday, Time: 9:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 57
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 26, Day: Tuesday, Time: 11:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 58
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 27, Day: Tuesday, Time: 12:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 59
Module ID: 25, Lecturer: Dr. Omaima Alsheli, Name: CS315, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 5, Day: Saturday, Time: 12:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 60
Module ID: 25, Lecturer: Dr. Omaima Alsheli, Name: CS315, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 2
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 61
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 17, Day: Monday, Time: 8:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 62
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 63
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 38, Day: Wednesday, Time: 3:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 64
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 39, Day: Thursday, Time: 8:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 65
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 22, Day: Monday, Time: 3:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 66
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 23, Day: Tuesday, Time: 8:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 67
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 33, Day: Wednesday, Time: 10:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 68
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 34, Day: Wednesday, Time: 11:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 69
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 35, Day: Wednesday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 70
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 36, Day: Wednesday, Time: 1:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 71
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 1, Day: Saturday, Time: 8:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 72
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 2, Day: Saturday, Time: 9:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 73
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 74
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 16, Day: Sunday, Time: 3:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 75
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 31, Day: Wednesday, Time: 8:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 76
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 32, Day: Wednesday, Time: 9:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 77
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 5, Day: Saturday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 78
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 79
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 27, Day: Tuesday, Time: 12:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 80
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 28, Day: Tuesday, Time: 1:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 81
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 43, Day: Thursday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 82
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 44, Day: Thursday, Time: 1:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 83
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 84
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 13, Day: Sunday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 85
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 41, Day: Thursday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 86
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 42, Day: Thursday, Time: 11:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 87
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 20, Day: Monday, Time: 11:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 88
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 21, Day: Monday, Time: 2:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 89
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 17, Day: Monday, Time: 8:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 90
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 91
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 92
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 16, Day: Sunday, Time: 3:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 93
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 11, Day: Sunday, Time: 10:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 94
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 95
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 44, Day: Thursday, Time: 1:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 96
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 45, Day: Thursday, Time: 2:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 97
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 98
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 7, Day: Saturday, Time: 2:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 99
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 30, Day: Tuesday, Time: 3:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 100
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 31, Day: Wednesday, Time: 8:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 101
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 28, Day: Tuesday, Time: 1:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 102
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 29, Day: Tuesday, Time: 2:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 103
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 21, Day: Monday, Time: 2:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 104
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 22, Day: Monday, Time: 3:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 105
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 106
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
Gene: 107
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 13, Day: Sunday, Time: 12:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 1
IsOneSlot: 0
Gene: 108
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes, Number of time slots: 4
TimeSlot ID: 14, Day: Sunday, Time: 1:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
IsLockedVenue: 0
IsLockedTimeSlot: 0
IsValid: 1
IsFirstSlot: 0
IsOneSlot: 0
'''

# Initialize dictionary to store the timetable for each venue
timetables = {}

# Split the raw data into individual genes and parse each one
gene_blocks = gene_data.strip().split("Gene: ")[1:]
for gene_block in gene_blocks:
    gene_dict = parse_gene(gene_block)
    # Extract relevant information
    venue_name = gene_dict['Venue']['Name']
    day = gene_dict['TimeSlot']['Day']
    time = gene_dict['TimeSlot']['Time']
    module_name = gene_dict['Module']['Name']
    lecturer_name = gene_dict['Module']['Lecturer']
    
    # Update timetable dictionary
    if venue_name not in timetables:
        timetables[venue_name] = {}
    if day not in timetables[venue_name]:
        timetables[venue_name][day] = {}
    timetables[venue_name][day][time] = f"{module_name} | {lecturer_name}"

    # Populate the consolidated timetable using data from individual venue timetables
    cell_content = f"{module_name} | {lecturer_name} | {venue_name}"
    if day not in consolidated_timetable:
        consolidated_timetable[day] = {}
    if time not in consolidated_timetable[day]:
        consolidated_timetable[day][time] = ''
    else:
        consolidated_timetable[day][time] += '<br>'
    consolidated_timetable[day][time] += cell_content

# Generate HTML tables for all venues
all_tables_html = '<h2>All Timetables</h2>'
for venue_name, schedule in timetables.items():
    all_tables_html += generate_venue_table(venue_name, schedule)

# Generate the HTML for the consolidated timetable
consolidated_table_html = generate_consolidated_table(consolidated_timetable)

# Wrap the HTML content with necessary headers and styles
final_html = '''
<!DOCTYPE html>
<html>
<head>
    <title>All Timetables</title>
    <style>
        /* Table styling */
        table {
            border-collapse: collapse;
            width: 100%;
            margin-bottom: 20px;
        }
        th, td {
            border: 1px solid black;
            text-align: center;
            padding: 8px;
        }
        /* Header styling */
        .header {
            background-color: #4CAF50;
            color: white;
        }
    </style>
</head>
<body>
''' + all_tables_html + '''
</body>
</html>
'''

# Save the HTML content to a file
with open('all_timetables.html', 'w') as f:
    f.write(final_html)

# Wrap the HTML content for the consolidated table with necessary headers and styles
final_consolidated_html = '''
<!DOCTYPE html>
<html>
<head>
    <title>Consolidated Timetable</title>
    <style>
        /* Table styling */
        table {
            border-collapse: collapse;
            width: 100%;
            margin-bottom: 20px;
        }
        th, td {
            border: 1px solid black;
            text-align: center;
            padding: 8px;
        }
        /* Header styling */
        .header {
            background-color: #4CAF50;
            color: white;
        }
    </style>
</head>
<body>
''' + consolidated_table_html + '''
</body>
</html>
'''

# Save the HTML content to a file
with open('consolidated_timetable.html', 'w') as f:
    f.write(final_consolidated_html)
