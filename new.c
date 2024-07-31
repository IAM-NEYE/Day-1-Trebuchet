#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *file = fopen("input.txt", "r");  // Open your input file
    char line[MAX_LINE_LENGTH];
    int totalSum = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        int firstDigit = -1, lastDigit = -1;
        int i = 0;
        while (line[i] != '\0' && firstDigit == -1) { // Find first digit/spelled-out
            if (line[i] >= '0' && line[i] <= '9') { 
                firstDigit = line[i] - '0';
            } else {
                // Check for spelled-out numbers (first 3 letters are enough)
                if (strncmp(line + i, "one", 3) == 0) firstDigit = 1;
                else if (strncmp(line + i, "two", 3) == 0) firstDigit = 2;
                else if (strncmp(line + i, "three", 5) == 0) firstDigit = 3;
                else if (strncmp(line + i, "four", 4) == 0) firstDigit = 4;
                else if (strncmp(line + i, "five", 4) == 0) firstDigit = 5;
                else if (strncmp(line + i, "six", 3) == 0) firstDigit = 6;
                else if (strncmp(line + i, "seven", 5) == 0) firstDigit = 7;
                else if (strncmp(line + i, "eight", 5) == 0) firstDigit = 8;
                else if (strncmp(line + i, "nine", 4) == 0) firstDigit = 9;
            }
            i++;
        }

        i = strlen(line) - 2; // Start from the end of the line (excluding newline)
        while (i >= 0 && lastDigit == -1) { // Find last digit/spelled-out (reverse)
            if (line[i] >= '0' && line[i] <= '9') {
                lastDigit = line[i] - '0';
            } else {
                // Check for spelled-out numbers in reverse (last 3 letters)
                if (strncmp(line + i, "eno", 3) == 0) lastDigit = 1;
                else if (strncmp(line + i, "owt", 3) == 0) lastDigit = 2;
                else if (strncmp(line + i, "eerht", 5) == 0) lastDigit = 3;
                else if (strncmp(line + i, "ruof", 4) == 0) lastDigit = 4;
                else if (strncmp(line + i, "evif", 4) == 0) lastDigit = 5;
                else if (strncmp(line + i, "xis", 3) == 0) lastDigit = 6;
                else if (strncmp(line + i, "neves", 5) == 0) lastDigit = 7;
                else if (strncmp(line + i, "thgie", 5) == 0) lastDigit = 8;
                else if (strncmp(line + i, "enin", 4) == 0) lastDigit = 9;
            }
            i--;
        }

        totalSum += firstDigit * 10 + lastDigit; // Combine digits and add to sum
    }
    printf("Total sum of calibration values: %d\n", totalSum);

    return 0;
}
