/*
 * Group 8: Yiming Lu, Adam Khalil, Kevin Hernandez, TJ Vasquez
 * CS 2600 Section 1
 * Instructor: Danica Cariaga
 * Caesar Cipher Encoder/Decoder Project
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define max_length 1024

// Function prototypes
void encodeMessage(char *message, int shift);
void decodeMessage(char *message, int shift);
int getShiftValue();
void getMessage(char *message);
char shiftChar(char c, int shift);

int main() {
    char message[max_length];
    int choice;
    int shift;

    printf("\n--- Caesar Cipher Encoder/Decoder ---\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Encode a message\n");
        printf("2. Decode a message\n");
        printf("3. Quit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) == 1) {
            while (getchar() != '\n'); // Clear input buffer
            break; // Exit loop - valid input
        } else {
            printf("Invalid input. Only enter a number please.\n");
            while (getchar() != '\n'); // Clear invalid input
        }


        if (choice == 1) {
            getMessage(message);
            shift = getShiftValue();
            encodeMessage(message, shift);
            printf("\nEncoded message: %s\n", message);

        } else if (choice == 2) {
            getMessage(message);
            shift = getShiftValue();
            decodeMessage(message, shift);
            printf("\nDecoded message: %s\n", message);

        } else if (choice == 3) {
            printf("Exiting program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void getMessage(char *message) {
    printf("\nEnter your message (max %d characters): ", max_length-1);
    fgets(message, max_length, stdin);
    // Remove trailing newline if exists
    size_t len = strlen(message);
    if (len > 0 && message[len-1] == '\n') {
        message[len-1] = '\0';
    }
}

int getShiftValue() {
    int shift;
    printf("Enter shift value (integer 0-25): ");
    while (scanf("%d", &shift) != 1 || shift < 0 || shift > 25) {
        printf("Invalid input. Please enter an integer between 0 and 25: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    getchar(); // Consume leftover newline
    return shift;
}

void encodeMessage(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = shiftChar(message[i], shift);
    }
}

void decodeMessage(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = shiftChar(message[i], -shift);
    }
}

char shiftChar(char c, int shift) {
    if (isupper(c)) {
        return (char)(((c - 'A' + shift + 26) % 26) + 'A');
    } else if (islower(c)) {
        return (char)(((c - 'a' + shift + 26) % 26) + 'a');
    } else {
        return c; // Leave non-alphabet characters unchanged
    }
}
