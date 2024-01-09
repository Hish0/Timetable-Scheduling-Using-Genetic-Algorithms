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

# Define the path to your text file
file_path = 'chromosome_data.txt'

# Open the file and read its contents
# Your gene data goes here. The provided data contains the schedule.

with open(file_path, 'r') as file:
    gene_data = file.read()


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
