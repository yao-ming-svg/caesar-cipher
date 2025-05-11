# Caesar Cipher Encoder/Decoder

A simple command-line C program that encodes and decodes messages using the classic Caesar Cipher technique.

## Overview

This project was developed for CS 2600 Section 1 under the instruction of Danica Cariaga.

**Contributors**:  
Group 8  
- Kevin Hernandez
- Adam Khalil  
- Yiming Lu  
- TJ Vasquez

## How It Works

The Caesar Cipher works by shifting each letter in a message by a fixed number of positions in the alphabet.  
This program allows the user to:
- Encode a message with a shift of 0–25
- Decode a message with a shift of 0–25
- Quit the program

Non-alphabetic characters (like punctuation and numbers) are preserved.

## Features

- Input validation for numeric choices and shift values
- Supports both uppercase and lowercase letters
- Preserves original formatting and non-alphabet characters
- Repeats the menu until the user decides to exit

## How to Use

1. **Compile the program** (assuming file is named `main.c`):
    ```bash
    gcc main.c -o caesar
    ```

2. **Run the executable**:
    ```bash
    ./caesar
    ```

3. **Follow the prompts**:
    - Choose to encode or decode
    - Enter your message
    - Enter a shift value between 0 and 25
    - View your result

## Example
```bash
--- Caesar Cipher Encoder/Decoder ---

Select an option:
1. Encode a message
2. Decode a message
3. Quit
Choice: 1

Enter your message (max 1023 characters): Hello World!
Enter shift value (integer 0-25): 3

Encoded message: Khoor Zruog!
```

## File Structure

- `main.c`: Contains the entire Caesar cipher program logic, including input handling, encoding/decoding, and character shifting.

## Input Validation

- If non-numeric input is provided for the menu or shift value, the program notifies the user and re-prompts.
- Shift value is constrained between 0 and 25.

## Notes

- The `max_length` is defined as `1024` characters.
- The program clears the input buffer after each numeric input to avoid accidental input issues.

## License

This project is submitted as coursework. Do we need a liscense?
