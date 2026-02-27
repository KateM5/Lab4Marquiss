#include <stdio.h>

// This links to your lab4.s file
extern int sum_array(int* arr, int n);

int main() {
    char *filename = "data.txt";
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    int count;
    fscanf(file, "%d", &count); // Read the count from the first line

    // SIMPLE WAY: Just declare a fixed array size
    // Make sure it's big enough for your data.txt
    int numbers[100]; 

    // Fill the array
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d", &numbers[i]);
    }
    fclose(file);

    // Call your assembly function
    // 'numbers' automatically acts as a pointer to the start of the array
    int total = sum_array(numbers, count);

    printf("The sum is: %d\n", total);

    return 0;
}