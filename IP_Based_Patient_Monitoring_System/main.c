// main.c
#include <stdio.h>
#include <string.h>
#include "patient_data.h"
#include "real_time_monitoring.h"

int main() {
    int choice;

    printf("Welcome to the IP-based Patient Monitoring System\n");
    printf("1. Enter and process patient data manually\n");
    printf("2. Simulate real-time monitoring (updates every 2 seconds)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar();  // Consume newline character

    if (choice == 1) {
        char patient_data[1024];

        // Prompt the user to input patient data
        printf("Enter patient data (e.g., PatientID=123;HeartRate=85;Temperature=98.7):\n");
        fgets(patient_data, 1024, stdin);

        // Remove the newline character from input
        patient_data[strcspn(patient_data, "\n")] = '\0';

        printf("\nProcessing patient data:\n");
        process_patient_data(patient_data);

        // Log the data to a file
        log_data_to_file(patient_data);
    } else if (choice == 2) {
        int updates;
        printf("Enter number of updates to simulate: ");
        scanf("%d", &updates);

        printf("\nStarting real-time monitoring...\n");
        simulate_real_time_monitoring(updates);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
