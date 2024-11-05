#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient_data.h"

// Function to process and display patient data
void process_patient_data(const char* data) {
    printf("Processing patient data:\n");
    printf("%s\n", data);

    // Extract heart rate and temperature from the data string
    char temp_str[1024];
    strcpy(temp_str, data);
    char* heart_rate_str = strstr(temp_str, "HeartRate=") + 10;
    char* temp_str_ptr = strstr(temp_str, "Temperature=") + 12;

    int heart_rate = atoi(heart_rate_str);
    float temperature = atof(temp_str_ptr);

    // Print extracted values
    printf("Heart Rate: %d bpm\n", heart_rate);
    printf("Temperature: %.1f°F\n", temperature);

    // Checking and alerting for specific abnormal values
    if (heart_rate > 100) {
        printf("ALERT! Heart rate is high: %d bpm\n", heart_rate);
    }
    if (temperature > 99.0) {
        printf("ALERT! Temperature is high: %.1f°F\n", temperature);
    } else if (temperature < 97.0) {
        printf("ALERT! Temperature is low: %.1f°F\n", temperature);
    }
}

// Function to log data to a file
void log_data_to_file(const char* data) {
    FILE* file = fopen("log_file.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s\n", data);
    fclose(file);
}
