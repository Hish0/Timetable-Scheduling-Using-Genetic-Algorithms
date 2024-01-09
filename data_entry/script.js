document.getElementById('geneForm').addEventListener('submit', function(e) {
    e.preventDefault();

    // Get form data
    let formData = new FormData(this);
    let formattedData = formatDataForDisplay(formData);

    // Set the formatted data into the textarea for the user to copy
    document.getElementById('output').value = formattedData;
});

function formatDataForDisplay(formData) {
    // Convert form data to a structured object
    let geneData = {};
    for (let [key, value] of formData) {
        geneData[key] = value;
    }

    // Format the data into the snippet structure
    let formattedData = `Gene: ${geneData['Gene']}\n`;
    formattedData += `Module ID: ${geneData['Module ID']}, Lecturer: ${geneData['Lecturer']}, Name: ${geneData['Module Name']}, Level: ${geneData['Level']}, Enrolled Students: ${geneData['Enrolled Students']}, Is Lab: ${geneData['Is Lab']}, Number of time slots: ${geneData['Number of time slots']}\n`;
    formattedData += `TimeSlot ID: ${geneData['TimeSlot ID']}, Day: ${geneData['Day']}, Time: ${geneData['Time']}\n`;
    formattedData += `Venue ID: ${geneData['Venue ID']}, Name: ${geneData['Venue Name']}, Capacity: ${geneData['Capacity']}, Is Lab: ${geneData['Is Lab (Venue)']}\n`;
    formattedData += `IsLockedVenue: ${geneData['IsLockedVenue'] || '0'}\n`;
    formattedData += `IsLockedTimeSlot: ${geneData['IsLockedTimeSlot'] || '0'}\n`;
    formattedData += `IsValid: ${geneData['IsValid'] || '0'}\n`;
    formattedData += `IsFirstSlot: ${geneData['IsFirstSlot'] || '0'}\n`;
    formattedData += `IsOneSlot: ${geneData['IsOneSlot'] || '0'}\n`;

    return formattedData;
}

// document.getElementById('geneForm').addEventListener('submit', function(e) {
//     e.preventDefault();

//     // Get form data
//     let formData = new FormData(this);
//     let formattedData = formatDataForDisplay(formData);

//     // Set the formatted data into the textarea for the user to copy
//     document.getElementById('output').value = formattedData;
// });

// function formatDataForDisplay(formData) {
//     // Your existing code to format the data
// }

function populateFields() {
    let inputData = document.getElementById('inputData').value;
    let lines = inputData.split('\n');
    let geneData = {};
    let isModuleSection = true; // Flag to identify if we are parsing the module section

    lines.forEach((line) => {
        // Split the line into key-value pairs
        let parts = line.split(', ');
        parts.forEach((part) => {
            let [key, value] = part.split(': ');
            if (key && value) {
                key = key.trim();
                value = value.trim();

                // Check if we've moved past the module section
                if (key === 'TimeSlot ID') {
                    isModuleSection = false;
                }

                // Handle 'Name' key based on section
                if (key === 'Name') {
                    key = isModuleSection ? 'Module Name' : 'Venue Name';
                }

                geneData[key] = value;
            }
        });
    });

    // Populate the form fields
    for (let key in geneData) {
        let value = geneData[key];
        let field = document.querySelector(`[name="${key}"]`);
        if (field) {
            if (field.type === 'checkbox') {
                field.checked = value === '1';
            } else if (field.tagName === 'SELECT') {
                field.value = value === 'Yes' ? 'Yes' : 'No';
            } else {
                field.value = value;
            }
        }
    }
}


// You would still need your formatDataForDisplay function here if you want to auto-increment gene IDs

