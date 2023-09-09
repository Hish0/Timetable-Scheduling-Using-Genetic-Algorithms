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
        <th>8:00 AM</th>
        <th>10:00 AM</th>
        <th>12:00 PM</th>
        <th>2:00 PM</th>
    </tr>
    '''
    
    # Days of the week
    days_of_week = ['Saturday', 'Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
    
    # Generate table rows for each day
    for day in days_of_week:
        html += f'<tr><td>{day}</td>'
        for time in ['8:00 AM', '10:00 AM', '12:00 PM', '2:00 PM']:
            cell_content = schedule.get(day, {}).get(time, '')
            html += f'<td>{cell_content}</td>'
        html += '</tr>'
        
    html += '</table>'
    return html

# Sample gene data (replace this with your actual data)
gene_data = '''
Gene: 1
Module ID: 1, Lecturer: Dr. Fardous, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 17, Day: Wednesday, Time: 8:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 2
Module ID: 1, Lecturer: Dr. Fardous, Name: CS100, Level: 1, Enrolled Students: 100, Is Lab: No
TimeSlot ID: 6, Day: Sunday, Time: 10:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 3
Module ID: 2, Lecturer: Dr. Raneem Nashnoosh, Name: CS111, Level: 1, Enrolled Students: 95, Is Lab: No
TimeSlot ID: 13, Day: Tuesday, Time: 8:00 AM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 4
Module ID: 2, Lecturer: Dr. Raneem Nashnoosh, Name: CS111, Level: 1, Enrolled Students: 95, Is Lab: No
TimeSlot ID: 7, Day: Sunday, Time: 12:00 PM
Venue ID: 8, Name: HALL 72, Capacity: 200, Is Lab: No
Gene: 5
Module ID: 3, Lecturer: Dr. Wafaa Nasser, Name: CS115, Level: 1, Enrolled Students: 85, Is Lab: No
TimeSlot ID: 4, Day: Saturday, Time: 2:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 6
Module ID: 3, Lecturer: Dr. Wafaa Nasser, Name: CS115, Level: 1, Enrolled Students: 85, Is Lab: No
TimeSlot ID: 3, Day: Saturday, Time: 12:00 PM
Venue ID: 7, Name: HALL 71, Capacity: 200, Is Lab: No
Gene: 7
Module ID: 4, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 2, Enrolled Students: 30, Is Lab: Yes
TimeSlot ID: 16, Day: Tuesday, Time: 2:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 8
Module ID: 4, Lecturer: Dr. Adnan Alshreef, Name: CS200, Level: 2, Enrolled Students: 30, Is Lab: Yes
TimeSlot ID: 4, Day: Saturday, Time: 2:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 9
Module ID: 5, Lecturer: Dr. Abd Alsalam Bnoor, Name: CS207, Level: 2, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 2, Day: Saturday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 10
Module ID: 5, Lecturer: Dr. Abd Alsalam Bnoor, Name: CS207, Level: 2, Enrolled Students: 25, Is Lab: Yes
TimeSlot ID: 7, Day: Sunday, Time: 12:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 11
Module ID: 6, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 2, Enrolled Students: 30, Is Lab: Yes
TimeSlot ID: 18, Day: Wednesday, Time: 10:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 12
Module ID: 6, Lecturer: Dr. Fatima Hmeed, Name: CS211, Level: 2, Enrolled Students: 30, Is Lab: Yes
TimeSlot ID: 10, Day: Monday, Time: 10:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 13
Module ID: 7, Lecturer: Dr. Lutfi alhaweji, Name: CS215, Level: 2, Enrolled Students: 30, Is Lab: Yes
TimeSlot ID: 3, Day: Saturday, Time: 12:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 14
Module ID: 7, Lecturer: Dr. Lutfi alhaweji, Name: CS215, Level: 2, Enrolled Students: 30, Is Lab: Yes
TimeSlot ID: 9, Day: Monday, Time: 8:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 15
Module ID: 8, Lecturer: Dr. Ali Aborass, Name: CS315, Level: 3, Enrolled Students: 27, Is Lab: Yes
TimeSlot ID: 6, Day: Sunday, Time: 10:00 AM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 16
Module ID: 8, Lecturer: Dr. Ali Aborass, Name: CS315, Level: 3, Enrolled Students: 27, Is Lab: Yes
TimeSlot ID: 12, Day: Monday, Time: 2:00 PM
Venue ID: 5, Name: LAB 5, Capacity: 30, Is Lab: Yes
Gene: 17
Module ID: 9, Lecturer: Dr. Adnan Alshreef, Name: CS319, Level: 3, Enrolled Students: 26, Is Lab: Yes
TimeSlot ID: 5, Day: Sunday, Time: 8:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 18
Module ID: 9, Lecturer: Dr. Adnan Alshreef, Name: CS319, Level: 3, Enrolled Students: 26, Is Lab: Yes
TimeSlot ID: 22, Day: Thursday, Time: 10:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 19
Module ID: 10, Lecturer: Dr. Fathia Abu Amer, Name: CS321, Level: 3, Enrolled Students: 20, Is Lab: Yes
TimeSlot ID: 16, Day: Tuesday, Time: 2:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 20
Module ID: 10, Lecturer: Dr. Fathia Abu Amer, Name: CS321, Level: 3, Enrolled Students: 20, Is Lab: Yes
TimeSlot ID: 9, Day: Monday, Time: 8:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 21
Module ID: 11, Lecturer: Dr. Fathia Abu Amer, Name: CS322, Level: 3, Enrolled Students: 24, Is Lab: Yes
TimeSlot ID: 13, Day: Tuesday, Time: 8:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 22
Module ID: 11, Lecturer: Dr. Fathia Abu Amer, Name: CS322, Level: 3, Enrolled Students: 24, Is Lab: Yes
TimeSlot ID: 24, Day: Thursday, Time: 2:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 23
Module ID: 12, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 3, Enrolled Students: 22, Is Lab: Yes
TimeSlot ID: 11, Day: Monday, Time: 12:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 24
Module ID: 12, Lecturer: Dr. Raneem Nashnoosh, Name: CS331, Level: 3, Enrolled Students: 22, Is Lab: Yes
TimeSlot ID: 1, Day: Saturday, Time: 8:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 25
Module ID: 13, Lecturer: Dr. Alsunni, Name: CS332, Level: 3, Enrolled Students: 23, Is Lab: Yes
TimeSlot ID: 17, Day: Wednesday, Time: 8:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 26
Module ID: 13, Lecturer: Dr. Alsunni, Name: CS332, Level: 3, Enrolled Students: 23, Is Lab: Yes
TimeSlot ID: 4, Day: Saturday, Time: 2:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 27
Module ID: 14, Lecturer: Dr. Zainab Ahmed, Name: CS336, Level: 3, Enrolled Students: 18, Is Lab: Yes
TimeSlot ID: 20, Day: Wednesday, Time: 2:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 28
Module ID: 14, Lecturer: Dr. Zainab Ahmed, Name: CS336, Level: 3, Enrolled Students: 18, Is Lab: Yes
TimeSlot ID: 23, Day: Thursday, Time: 12:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 29
Module ID: 15, Lecturer: Dr. Fardous, Name: CS340, Level: 3, Enrolled Students: 17, Is Lab: Yes
TimeSlot ID: 21, Day: Thursday, Time: 8:00 AM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 30
Module ID: 15, Lecturer: Dr. Fardous, Name: CS340, Level: 3, Enrolled Students: 17, Is Lab: Yes
TimeSlot ID: 19, Day: Wednesday, Time: 12:00 PM
Venue ID: 3, Name: LAB 3, Capacity: 30, Is Lab: Yes
Gene: 31
Module ID: 16, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 4, Enrolled Students: 15, Is Lab: Yes
TimeSlot ID: 21, Day: Thursday, Time: 8:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 32
Module ID: 16, Lecturer: Dr. Hassan Abuaisha, Name: CS436, Level: 4, Enrolled Students: 15, Is Lab: Yes
TimeSlot ID: 19, Day: Wednesday, Time: 12:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 33
Module ID: 17, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 4, Enrolled Students: 13, Is Lab: Yes
TimeSlot ID: 8, Day: Sunday, Time: 2:00 PM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 34
Module ID: 17, Lecturer: Dr. Samir Embarek, Name: CS443, Level: 4, Enrolled Students: 13, Is Lab: Yes
TimeSlot ID: 17, Day: Wednesday, Time: 8:00 AM
Venue ID: 2, Name: LAB 2, Capacity: 30, Is Lab: Yes
Gene: 35
Module ID: 18, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 4, Enrolled Students: 14, Is Lab: Yes
TimeSlot ID: 6, Day: Sunday, Time: 10:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 36
Module ID: 18, Lecturer: Dr. Hassan Abuaisha, Name: CS456, Level: 4, Enrolled Students: 14, Is Lab: Yes
TimeSlot ID: 15, Day: Tuesday, Time: 12:00 PM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 37
Module ID: 19, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 4, Enrolled Students: 16, Is Lab: Yes
TimeSlot ID: 1, Day: Saturday, Time: 8:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 38
Module ID: 19, Lecturer: Dr. Abd Allatif Alshwehdi, Name: CS431, Level: 4, Enrolled Students: 16, Is Lab: Yes
TimeSlot ID: 5, Day: Sunday, Time: 8:00 AM
Venue ID: 1, Name: LAB 1, Capacity: 30, Is Lab: Yes
Gene: 39
Module ID: 20, Lecturer: Dr. Alsunni, Name: CS437, Level: 4, Enrolled Students: 19, Is Lab: Yes
TimeSlot ID: 3, Day: Saturday, Time: 12:00 PM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
Gene: 40
Module ID: 20, Lecturer: Dr. Alsunni, Name: CS437, Level: 4, Enrolled Students: 19, Is Lab: Yes
TimeSlot ID: 18, Day: Wednesday, Time: 10:00 AM
Venue ID: 4, Name: LAB 4, Capacity: 30, Is Lab: Yes
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
    timetables[venue_name][day][time] = f"{module_name} by {lecturer_name}"

# Generate HTML tables for all venues
all_tables_html = '<h2>All Timetables</h2>'
for venue_name, schedule in timetables.items():
    all_tables_html += generate_venue_table(venue_name, schedule)

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
