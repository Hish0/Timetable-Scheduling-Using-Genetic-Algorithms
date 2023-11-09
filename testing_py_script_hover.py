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


# Define colors for levels
level_colors = {
   '1': 'red',
   '2': 'blue',
   '3': 'green',
   '4': 'orange',
   '5': 'purple',
   '6': 'darkcyan',
   '7': 'brown',
   '8': 'darkolivegreen'
}

# Initialize an empty schedule for each venue and each day of the week
def initialize_schedule(venues, days, times):
    schedule = {}
    for venue in venues:
        schedule[venue] = {day: {time: '' for time in times} for day in days}
    return schedule

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
        for time in times_of_day:
            module_info = schedule.get(day, {}).get(time)
            if module_info:
                # Here we use module_info as is because it already contains HTML with interactive elements
                html += f'<td>{module_info}</td>'
            else:
                html += '<td></td>'
        html += '</tr>'
    html += '</table>'
    return html


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
Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 11, Day: Sunday, Time: 10:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 2
Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 3
Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 23, Day: Monday, Time: 2:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 4
Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 24, Day: Monday, Time: 3:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 5
Module ID: 1, Lecturer: Dr. Mo3eed 1, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 40, Day: Wednesday, Time: 3:00 PM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 6
Module ID: 2, Lecturer: Dr. Khadeja, Name: MM101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 1, Day: Saturday, Time: 8:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 7
Module ID: 2, Lecturer: Dr. Khadeja, Name: MM101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 2, Day: Saturday, Time: 9:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 8
Module ID: 2, Lecturer: Dr. Khadeja, Name: MM101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 9
Module ID: 2, Lecturer: Dr. Khadeja, Name: MM101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 16, Day: Sunday, Time: 3:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 10
Module ID: 2, Lecturer: Dr. Khadeja, Name: MM101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 41, Day: Thursday, Time: 8:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 11
Module ID: 3, Lecturer: Dr. Salsabil, Name: MM102, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 36, Day: Wednesday, Time: 11:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 12
Module ID: 3, Lecturer: Dr. Salsabil, Name: MM102, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 37, Day: Wednesday, Time: 12:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 13
Module ID: 3, Lecturer: Dr. Salsabil, Name: MM102, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 14
Module ID: 3, Lecturer: Dr. Salsabil, Name: MM102, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 7, Day: Saturday, Time: 2:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 15
Module ID: 3, Lecturer: Dr. Salsabil, Name: MM102, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 28, Day: Tuesday, Time: 11:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 16
Module ID: 4, Lecturer: Dr. Nabeel, Name: ST101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 17
Module ID: 4, Lecturer: Dr. Nabeel, Name: ST101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 5, Day: Saturday, Time: 12:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 18
Module ID: 4, Lecturer: Dr. Nabeel, Name: ST101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 44, Day: Thursday, Time: 11:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 19
Module ID: 4, Lecturer: Dr. Nabeel, Name: ST101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 45, Day: Thursday, Time: 12:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 20
Module ID: 4, Lecturer: Dr. Nabeel, Name: ST101, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 32, Day: Tuesday, Time: 3:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 21
Module ID: 5, Lecturer: Dr. Mokhtar, Name: PH112, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 17, Day: Monday, Time: 8:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 22
Module ID: 5, Lecturer: Dr. Mokhtar, Name: PH112, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 23
Module ID: 5, Lecturer: Dr. Mokhtar, Name: PH112, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 42, Day: Thursday, Time: 9:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 24
Module ID: 5, Lecturer: Dr. Mokhtar, Name: PH112, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 43, Day: Thursday, Time: 10:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 25
Module ID: 5, Lecturer: Dr. Mokhtar, Name: PH112, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 25, Day: Tuesday, Time: 8:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 26
Module ID: 6, Lecturer: Dr. Mo3eed 2, Name: CS111, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 5, Day: Saturday, Time: 12:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 27
Module ID: 6, Lecturer: Dr. Mo3eed 2, Name: CS111, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 28
Module ID: 6, Lecturer: Dr. Mo3eed 2, Name: CS111, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 25, Day: Tuesday, Time: 8:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 29
Module ID: 6, Lecturer: Dr. Mo3eed 2, Name: CS111, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 26, Day: Tuesday, Time: 9:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 30
Module ID: 6, Lecturer: Dr. Mo3eed 2, Name: CS111, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 46, Day: Thursday, Time: 1:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 31
Module ID: 7, Lecturer: Dr. Ahmed abd almutaleb, Name: MM103, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 28, Day: Tuesday, Time: 11:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 32
Module ID: 7, Lecturer: Dr. Ahmed abd almutaleb, Name: MM103, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 29, Day: Tuesday, Time: 12:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 33
Module ID: 7, Lecturer: Dr. Ahmed abd almutaleb, Name: MM103, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 36, Day: Wednesday, Time: 11:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 34
Module ID: 7, Lecturer: Dr. Ahmed abd almutaleb, Name: MM103, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 37, Day: Wednesday, Time: 12:00 PM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 35
Module ID: 7, Lecturer: Dr. Ahmed abd almutaleb, Name: MM103, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 45, Day: Thursday, Time: 12:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 36
Module ID: 8, Lecturer: Dr. Aljalali, Name: MM104, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 19, Day: Monday, Time: 10:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 37
Module ID: 8, Lecturer: Dr. Aljalali, Name: MM104, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 20, Day: Monday, Time: 11:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 38
Module ID: 8, Lecturer: Dr. Aljalali, Name: MM104, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 2, Day: Saturday, Time: 9:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 39
Module ID: 8, Lecturer: Dr. Aljalali, Name: MM104, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 40
Module ID: 8, Lecturer: Dr. Aljalali, Name: MM104, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 38, Day: Wednesday, Time: 1:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 41
Module ID: 9, Lecturer: Dr. Ali alaswad, Name: ST102, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 43, Day: Thursday, Time: 10:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 42
Module ID: 9, Lecturer: Dr. Ali alaswad, Name: ST102, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 44, Day: Thursday, Time: 11:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 43
Module ID: 9, Lecturer: Dr. Ali alaswad, Name: ST102, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 23, Day: Monday, Time: 2:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 44
Module ID: 9, Lecturer: Dr. Ali alaswad, Name: ST102, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 24, Day: Monday, Time: 3:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 45
Module ID: 9, Lecturer: Dr. Ali alaswad, Name: ST102, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 10, Day: Sunday, Time: 9:00 AM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 46
Module ID: 10, Lecturer: Dr. Mariam British, Name: EL101, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 33, Day: Wednesday, Time: 8:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 47
Module ID: 10, Lecturer: Dr. Mariam British, Name: EL101, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 34, Day: Wednesday, Time: 9:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 48
Module ID: 11, Lecturer: Dr. Amira alelagi, Name: AR051, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 14, Day: Sunday, Time: 1:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 49
Module ID: 11, Lecturer: Dr. Amira alelagi, Name: AR051, Level: 2, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 50
Module ID: 12, Lecturer: Dr. Naema albadri, Name: CS115, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 1, Day: Saturday, Time: 8:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 51
Module ID: 12, Lecturer: Dr. Naema albadri, Name: CS115, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 2, Day: Saturday, Time: 9:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 52
Module ID: 12, Lecturer: Dr. Naema albadri, Name: CS115, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 29, Day: Tuesday, Time: 12:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 53
Module ID: 12, Lecturer: Dr. Naema albadri, Name: CS115, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 30, Day: Tuesday, Time: 1:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 54
Module ID: 12, Lecturer: Dr. Naema albadri, Name: CS115, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 42, Day: Thursday, Time: 9:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 55
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 46, Day: Thursday, Time: 1:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 56
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 47, Day: Thursday, Time: 2:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 57
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 20, Day: Monday, Time: 11:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 58
Module ID: 13, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 21, Day: Monday, Time: 12:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 59
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 26, Day: Tuesday, Time: 9:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 60
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 27, Day: Tuesday, Time: 10:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 61
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 62
Module ID: 14, Lecturer: Dr. Abd Alsalam almaraghni, Name: CS207, Level: 3, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 19, Day: Monday, Time: 10:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 63
Module ID: 15, Lecturer: Dr. Farhat, Name: MA200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 34, Day: Wednesday, Time: 9:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 64
Module ID: 15, Lecturer: Dr. Farhat, Name: MA200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 35, Day: Wednesday, Time: 10:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 65
Module ID: 15, Lecturer: Dr. Farhat, Name: MA200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 66
Module ID: 15, Lecturer: Dr. Farhat, Name: MA200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 67
Module ID: 15, Lecturer: Dr. Farhat, Name: MA200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 48, Day: Thursday, Time: 3:00 PM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 68
Module ID: 16, Lecturer: Dr. Elbadri, Name: PH200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 69
Module ID: 16, Lecturer: Dr. Elbadri, Name: PH200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 7, Day: Saturday, Time: 2:00 PM
Venue ID: 10, Name: HALL 74, Capacity: 200, Is Lab: No
Gene: 70
Module ID: 16, Lecturer: Dr. Elbadri, Name: PH200, Level: 3, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 31, Day: Tuesday, Time: 2:00 PM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 71
Module ID: 17, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 39, Day: Wednesday, Time: 2:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 72
Module ID: 17, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 40, Day: Wednesday, Time: 3:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 73
Module ID: 17, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 74
Module ID: 17, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 7, Day: Saturday, Time: 2:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 75
Module ID: 17, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 48, Day: Thursday, Time: 3:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 76
Module ID: 18, Lecturer: Dr. Omaima Alsheli, Name: CS215, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 35, Day: Wednesday, Time: 10:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 77
Module ID: 18, Lecturer: Dr. Omaima Alsheli, Name: CS215, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 36, Day: Wednesday, Time: 11:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 78
Module ID: 18, Lecturer: Dr. Omaima Alsheli, Name: CS215, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 9, Day: Sunday, Time: 8:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 79
Module ID: 18, Lecturer: Dr. Omaima Alsheli, Name: CS215, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 10, Day: Sunday, Time: 9:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 80
Module ID: 18, Lecturer: Dr. Omaima Alsheli, Name: CS215, Level: 4, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 31, Day: Tuesday, Time: 2:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 81
Module ID: 19, Lecturer: Dr. Tasneem, Name: MA206, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 17, Day: Monday, Time: 8:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 82
Module ID: 19, Lecturer: Dr. Tasneem, Name: MA206, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 83
Module ID: 19, Lecturer: Dr. Tasneem, Name: MA206, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 84
Module ID: 19, Lecturer: Dr. Tasneem, Name: MA206, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 13, Day: Sunday, Time: 12:00 PM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 85
Module ID: 19, Lecturer: Dr. Tasneem, Name: MA206, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 1, Day: Saturday, Time: 8:00 AM
Venue ID: 6, Name: HALL 70, Capacity: 200, Is Lab: No
Gene: 86
Module ID: 20, Lecturer: Dr. Elbadri, Name: PH201, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 14, Day: Sunday, Time: 1:00 PM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 87
Module ID: 20, Lecturer: Dr. Elbadri, Name: PH201, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 9, Name: HALL 73, Capacity: 200, Is Lab: No
Gene: 88
Module ID: 20, Lecturer: Dr. Elbadri, Name: PH201, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 89
Module ID: 21, Lecturer: Dr. Amira alelagi, Name: AR052, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 25, Day: Tuesday, Time: 8:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 90
Module ID: 21, Lecturer: Dr. Amira alelagi, Name: AR052, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 26, Day: Tuesday, Time: 9:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 91
Module ID: 22, Lecturer: Dr. Mariam British, Name: EL102, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 45, Day: Thursday, Time: 12:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 92
Module ID: 22, Lecturer: Dr. Mariam British, Name: EL102, Level: 4, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 46, Day: Thursday, Time: 1:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 93
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 31, Day: Tuesday, Time: 2:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 94
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 32, Day: Tuesday, Time: 3:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 95
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 45, Day: Thursday, Time: 12:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 96
Module ID: 23, Lecturer: Dr. Wafaa Nasser, Name: CS321, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 46, Day: Thursday, Time: 1:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 97
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 42, Day: Thursday, Time: 9:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 98
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 43, Day: Thursday, Time: 10:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 99
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 14, Day: Sunday, Time: 1:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 100
Module ID: 24, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 101
Module ID: 25, Lecturer: Dr. Omaima Alsheli, Name: CS315, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 2, Day: Saturday, Time: 9:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 102
Module ID: 25, Lecturer: Dr. Omaima Alsheli, Name: CS315, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 103
Module ID: 25, Lecturer: Dr. Omaima Alsheli, Name: CS315, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 104
Module ID: 25, Lecturer: Dr. Omaima Alsheli, Name: CS315, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 13, Day: Sunday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 105
Module ID: 25, Lecturer: Dr. Omaima Alsheli, Name: CS315, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 25, Day: Tuesday, Time: 8:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 106
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 107
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 19, Day: Monday, Time: 10:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 108
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 35, Day: Wednesday, Time: 10:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 109
Module ID: 26, Lecturer: Dr. Naema albadri, Name: CS319, Level: 5, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 36, Day: Wednesday, Time: 11:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 110
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 43, Day: Thursday, Time: 10:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 111
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 44, Day: Thursday, Time: 11:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 112
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 18, Day: Monday, Time: 9:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 113
Module ID: 27, Lecturer: Dr. Alsunni, Name: CS332, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 19, Day: Monday, Time: 10:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 114
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 37, Day: Wednesday, Time: 12:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 115
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 38, Day: Wednesday, Time: 1:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 116
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 5, Day: Saturday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 117
Module ID: 28, Lecturer: Dr. Wafaa Nasser, Name: CS322, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 6, Day: Saturday, Time: 1:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 118
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 23, Day: Monday, Time: 2:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 119
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 24, Day: Monday, Time: 3:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 120
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 10, Day: Sunday, Time: 9:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 121
Module ID: 29, Lecturer: Dr. Raneem Nashnoosh, Name: CS336, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 11, Day: Sunday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 122
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 15, Day: Sunday, Time: 2:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 123
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 16, Day: Sunday, Time: 3:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 124
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 39, Day: Wednesday, Time: 2:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 125
Module ID: 30, Lecturer: Dr. Fardous, Name: CS340, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 40, Day: Wednesday, Time: 3:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 126
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 127
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 4, Day: Saturday, Time: 11:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 128
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 29, Day: Tuesday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 129
Module ID: 31, Lecturer: Dr. Adnan Alshreef, Name: CS355, Level: 6, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 30, Day: Tuesday, Time: 1:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 130
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 39, Day: Wednesday, Time: 2:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 131
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 40, Day: Wednesday, Time: 3:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 132
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 7, Day: Saturday, Time: 2:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 133
Module ID: 32, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 8, Day: Saturday, Time: 3:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 134
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 12, Day: Sunday, Time: 11:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 135
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 13, Day: Sunday, Time: 12:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 136
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 26, Day: Tuesday, Time: 9:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 137
Module ID: 33, Lecturer: Dr. Alsunni, Name: CS437, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 27, Day: Tuesday, Time: 10:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 138
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 10, Day: Sunday, Time: 9:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 139
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 11, Day: Sunday, Time: 10:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 140
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 22, Day: Monday, Time: 1:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 141
Module ID: 34, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 23, Day: Monday, Time: 2:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 142
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 42, Day: Thursday, Time: 9:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 143
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 43, Day: Thursday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 144
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 34, Day: Wednesday, Time: 9:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 145
Module ID: 35, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 7, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 35, Day: Wednesday, Time: 10:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 146
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 2, Day: Saturday, Time: 9:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 147
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 3, Day: Saturday, Time: 10:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 148
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 28, Day: Tuesday, Time: 11:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 149
Module ID: 36, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 29, Day: Tuesday, Time: 12:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 150
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 37, Day: Wednesday, Time: 12:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 151
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 38, Day: Wednesday, Time: 1:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 152
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 13, Day: Sunday, Time: 12:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 153
Module ID: 37, Lecturer: Dr. Ali Aborass, Name: CS438, Level: 8, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 14, Day: Sunday, Time: 1:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
'''

# Define your days and times
days_of_week = ['Saturday', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
times_of_day = ['8:00 AM', '9:00 AM', '10:00 AM', '11:00 AM', '12:00 PM', '1:00 PM', '2:00 PM', '3:00 PM']

# Define the list of all venues
all_venues = ['HALL 72', 'HALL 73', 'HALL 70', 'HALL 71', 'HALL 74']  # Add all your venues here

# Initialize the schedules
timetables = initialize_schedule(all_venues, days_of_week, times_of_day)
consolidated_timetable = {day: {time: '' for time in times_of_day} for day in days_of_week}


# Initialize dictionary to store the timetable for each venue
# timetables = {}
# consolidated_timetable = {}


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
    level = gene_dict['Module']['Level']  # Extract the level information
    
    # Determine the color based on the level
    color = level_colors.get(level, 'black')  # default to black if level not found


    # Prepare the module info string with interactive elements
    module_info = f'''
        <div class="module-info" style="color:{color};" onmouseover="showTooltip(this)" onmouseout="hideTooltip(this)">
            {module_name}
            <span class="tooltip-text">Lecturer: {lecturer_name}<br>Venue: {venue_name}</span>
        </div>
    '''
    # Add module info to the venue schedule
    if venue_name in timetables and day in timetables[venue_name] and time in timetables[venue_name][day]:
        timetables[venue_name][day][time] = module_info

    # Add module info to the consolidated timetable
    consolidated_timetable[day][time] += f'{module_info}<br>' if consolidated_timetable[day][time] else module_info



all_tables_html = '<h2>All Timetables</h2>'
for venue_name, schedule in timetables.items():
    all_tables_html += generate_venue_table(venue_name, schedule)

# Generate the HTML for the consolidated timetable
consolidated_table_html = generate_consolidated_table(consolidated_timetable)


# Wrap the HTML content with necessary headers and styles, including tooltip and popup styles and JavaScript
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


       /* Tooltip styling */
       .module-info {
           position: relative; /* Set relative positioning context for the tooltip */
           display: inline-block; /* Ensure the divs line up next to each other */
           margin-right: -4px; /* Negative margin to reduce space between modules */
           padding: 2px; /* Reduced padding */
           cursor: pointer;
       }
       .tooltip-text {
           visibility: hidden;
           width: 120px;
           background-color: black;
           color: #fff;
           text-align: center;
           border-radius: 6px;
           padding: 5px;
           position: absolute;
           z-index: 1;
           bottom: 100%;
           left: 50%;
           margin-left: -60px;
           transition: opacity 0.5s linear;
           opacity: 0;
       }
       .module-info:hover .tooltip-text {
           visibility: visible;
           opacity: 1;
       }


       /* Popup styling */
       .popup {
           display: none;
           position: fixed;
           left: 50%;
           top: 50%;
           transform: translate(-50%, -50%);
           border: 1px solid #ccc;
           background-color: white;
           padding: 10px;
           z-index: 2;
       }
   </style>
</head>
<body style="background-color: #d3d3d3;">
''' + all_tables_html + consolidated_table_html + '''
   <div id="popup" class="popup"></div>
   <script>
       // Function to show the popup
       function showPopup(module, lecturer, venue) {
           var popup = document.getElementById('popup');
           popup.innerHTML = 'Module: ' + module + '<br>Lecturer: ' + lecturer + '<br>Venue: ' + venue;
           popup.style.display = 'block';
       }

        

       // Clicking on the popup closes it
       document.getElementById('popup').addEventListener('click', function() {
           this.style.display = 'none';
       });
       
       
   </script>
</body>
</html>
'''


# Save the HTML content to a file
with open('all_timetables_interactive.html', 'w') as f:
   f.write(final_html)



