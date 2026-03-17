#include <stdio.h>
#include <string.h> // Required for string functions

int main() {
    // 1. Fixed-size character array
    char city1[7] = "Kumasi"; // size must include '\0' (null terminator)
    printf("Fixed array: %s\n", city1);

    // 2. Automatic-size array
    char city2[] = "Accra"; // compiler determines size automatically
    printf("Automatic-size array: %s\n", city2);

    // 3. Pointer to string literal
    char *city3 = "Tamale"; // points to read-only memory
    printf("Pointer to literal: %s\n", city3);
    // city3[0] = 'T'; // ❌ modifying string literal is undefined behavior

    // 4. Copying strings
    char city4[20]; 
    strcpy(city4, city2); // copy city2 into city4
    printf("After strcpy: %s\n", city4);

    // 5. Concatenating strings
    char first[20] = "New";
    char second[] = " Town";
    strcat(first, second); // combines first + second
    printf("After strcat: %s\n", first);

    // 6. String length
    printf("Length of city1: %zu\n", strlen(city1)); // excludes '\0'

    // 7. Comparing strings
    if (strcmp(city1, city2) == 0)
        printf("city1 and city2 are the same.\n");
    else
        printf("city1 and city2 are different.\n");

    // 8. Reading strings from user
    char name[50];
    printf("Enter your full name: ");
    fgets(name, 50, stdin); // safer than scanf, reads spaces
    printf("You entered: %s\n", name);

    // Notes on strings:
    /*
    1. Strings in C are arrays of characters ending with '\0'.
    2. Always ensure enough space in arrays to store the null terminator.
    3. String literals (e.g., "Tamale") are stored in read-only memory.
    4. Use <string.h> functions for copying, concatenating, comparing, etc.
    5. fgets() is safer than scanf() for input because it avoids buffer overflow.
    */

    return 0;
}
