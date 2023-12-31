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
    formattedData += `Module ID: ${geneData['Module ID']}, Lecturer: ${geneData['Lecturer']}, Name: ${geneData['Name']}, Level: ${geneData['Level']}, Enrolled Students: ${geneData['Enrolled Students']}, Is Lab: ${geneData['Is Lab']}, Number of time slots: ${geneData['Number of time slots']}\n`;
    formattedData += `TimeSlot ID: ${geneData['TimeSlot ID']}, Day: ${geneData['Day']}, Time: ${geneData['Time']}\n`;
    formattedData += `Venue ID: ${geneData['Venue ID']}, Name: ${geneData['Venue Name']}, Capacity: ${geneData['Capacity']}, Is Lab: ${geneData['Is Lab (Venue)']}\n`;
    formattedData += `IsLockedVenue: ${geneData['IsLockedVenue'] || '0'}\n`;
    formattedData += `IsLockedTimeSlot: ${geneData['IsLockedTimeSlot'] || '0'}\n`;
    formattedData += `IsValid: ${geneData['IsValid'] || '0'}\n`;
    formattedData += `IsFirstSlot: ${geneData['IsFirstSlot'] || '0'}\n`;
    formattedData += `IsOneSlot: ${geneData['IsOneSlot'] || '0'}\n`;

    return formattedData;
}
