#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>  // For Windows systems
#else
#include <unistd.h>   // For POSIX systems
#endif

#include "real_time_monitoring.h"
#include "patient_data.h"

// Function to generate random patient data string
void generate_random_patient_data(char* data) {
    int patient_id = 101;  // Fixed patient ID
    int heart_rate = rand() % 40 + 60;  // Random heart rate between 60 and 100
    float temperature = (rand() % 30 + 965) / 10.0;  // Random temperature between 96.5 and 99.4

    // Format the patient data into a string
    sprintf(data, "PatientID=%d;HeartRate=%d;Temperature=%.1f", patient_id, heart_rate, temperature);
}

// Function to simulate real-time patient monitoring
void simulate_real_time_monitoring(int updates) {
    char patient_data[1024];
    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < updates; i++) {
        generate_random_patient_data(patient_data);

        printf("\nUpdate %d: New patient data generated:\n", i + 1);
        process_patient_data(patient_data);

        // Log the data to a file
        log_data_to_file(patient_data);

        // Extract heart rate and temperature values from patient_data
        char temp_str[1024];
        strcpy(temp_str, patient_data);
        char* heart_rate_str = strstr(temp_str, "HeartRate=") + 10;
        char* temp_str_ptr = strstr(temp_str, "Temperature=") + 12;

        int heart_rate = atoi(heart_rate_str);
        float temperature = atof(temp_str_ptr);

        // Checking and alerting for specific abnormal values
        int alert_flag = 0;

        if (heart_rate > 100) {
            printf("ALERT! Heart rate is high: %d bpm\n", heart_rate);
            alert_flag = 1;
        }
        if (temperature > 99.0) {
            printf("ALERT! Temperature is high: %.1f°F\n", temperature);
            alert_flag = 1;
        } else if (temperature < 97.0) {
            printf("ALERT! Temperature is low: %.1f°F\n", temperature);
            alert_flag = 1;
        }

        if (!alert_flag) {
            printf("All parameters are within normal range.\n");
        }

        // Simulate a delay between updates (for real-time effect)
#ifdef _WIN32
        Sleep(2000);  // Sleep for 2 seconds (Windows uses milliseconds)
#else
        sleep(2);  // Sleep for 2 seconds (POSIX systems use seconds)
#endif
    }
}
