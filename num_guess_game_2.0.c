#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void easyMode();
void intermediateMode();
void sufferingMode();

int main() {
    char username[50];
    int difficulty;
    int decision1;
    char difficulty_level[20];

    srand(time(NULL));

    printf("Welcome to the number guessing game!\n");
    printf("Enter your username: ");
    scanf("%49s", username);
    printf("========================================\n");

    printf("Choose a difficulty level:\n 1-Easy 2-Intermediate 3-Suffering\n");
    scanf("%d", &difficulty);

    // Set difficulty level
    if (difficulty == 1) strcpy(difficulty_level, "Easy");
    else if (difficulty == 2) strcpy(difficulty_level, "Intermediate");
    else if (difficulty == 3) strcpy(difficulty_level, "Suffering");
    else {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    printf("You are %s and you chose the %s difficulty\n", username, difficulty_level);
    printf("Enter 1 to continue and 2 to close the application\n");
    scanf("%d", &decision1);

    if (decision1 == 2) {
        printf("....Closing the program.......\n");
        exit(0);
    }

    // Game modes
    if (decision1 == 1) {
        if (difficulty == 1) easyMode();
        else if (difficulty == 2) intermediateMode();
        else if (difficulty == 3) sufferingMode();
    }

    return 0;
}

// EASY MODE
void easyMode() {
    int target = rand() % 100 + 1;
    int guess;

    printf("Guess the number (1-100): ");
    scanf("%d", &guess);

    while (guess != target) {
        if (guess == 0) {
            printf("You quit. The number was %d\n", target);
            return;
        }

        if (guess > target) {
            printf("Too high! Go lower.\n");
        } else {
            printf("Too low! Go higher.\n");
        }

        printf("Try again: ");
        scanf("%d", &guess);
    }

    printf("Correct! You guessed it!\n");
}

// INTERMEDIATE MODE
void intermediateMode() {
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;
    int guess1, guess2;

    printf("Guess the two numbers (1-100):\n");
    scanf("%d %d", &guess1, &guess2);

    // First number
    while (guess1 != num1) {
        if (guess1 == 0) {
            printf("You quit. The first number was %d\n", num1);
            break;
        }

        if (guess1 > num1) {
            printf("First number too high! Go lower.\n");
        } else {
            printf("First number too low! Go higher.\n");
        }

        printf("Try again: ");
        scanf("%d", &guess1);
    }

    // Second number
    while (guess2 != num2) {
        if (guess2 == 0) {
            printf("You quit. The second number was %d\n", num2);
            break;
        }

        if (guess2 > num2) {
            printf("Second number too high! Go lower.\n");
        } else {
            printf("Second number too low! Go higher.\n");
        }

        printf("Try again: ");
        scanf("%d", &guess2);
    }

    if (guess1 == num1 && guess2 == num2) {
        printf("Congrats! You guessed both!\n");
    }
}

// SUFFERING MODE
void sufferingMode() {
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;
    int num3 = rand() % 100 + 1;
    int guess1, guess2, guess3;

    printf("Guess the three numbers (1-100):\n");
    scanf("%d %d %d", &guess1, &guess2, &guess3);

    // First number
    while (guess1 != num1) {
        if (guess1 == 0) {
            printf("You quit. The first number was %d\n", num1);
            break;
        }

        if (guess1 > num1) {
            printf("First number too high! Go lower.\n");
        } else {
            printf("First number too low! Go higher.\n");
        }

        printf("Try again: ");
        scanf("%d", &guess1);
    }

    // Second number
    while (guess2 != num2) {
        if (guess2 == 0) {
            printf("You quit. The second number was %d\n", num2);
            break;
        }

        if (guess2 > num2) {
            printf("Second number too high! Go lower.\n");
        } else {
            printf("Second number too low! Go higher.\n");
        }

        printf("Try again: ");
        scanf("%d", &guess2);
    }

    // Third number
    while (guess3 != num3) {
        if (guess3 == 0) {
            printf("You quit. The third number was %d\n", num3);
            break;
        }

        if (guess3 > num3) {
            printf("Third number too high! Go lower.\n");
        } else {
            printf("Third number too low! Go higher.\n");
        }

        printf("Try again: ");
        scanf("%d", &guess3);
    }

    if (guess1 == num1 && guess2 == num2 && guess3 == num3) {
        printf("Congrats! You guessed all three!\n");
    }
}
