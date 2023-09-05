#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    if(argc!= 2)
      {
        if (argc>2)
        printf("one file name please");
        else
        printf("invalid");
        exit(1); 

      }
    FILE *input_file, *output_file;
    int total_numbers = 0, min_number, max_number, sum_numbers = 0;
    float average;

    // Open input file for reading
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file.");
        return 1;
    }

    // Open output file for writing
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Unable to open output file.");
        return 1;
    }

    // Read input file line by line
    int num;
    while (fscanf(input_file, "%d", &num) == 1) {
        // Update variables
        total_numbers++;
        if (total_numbers == 1) {
            min_number = num;
            max_number = num;
        } else {
            if (num < min_number) {
                min_number = num;
            }
            if (num > max_number) {
                max_number = num;
            }
        }
        sum_numbers += num;
    }

    // Calculate average
    average = (float)sum_numbers / total_numbers;

    // Write output to file
    fprintf(output_file, "%d\n%d\n%d\n%d\n%.2f", total_numbers, min_number, max_number, sum_numbers, average);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Output file created successfully.\n");

    return 0;
}
