#include <stdio.h>

// Function to read and display a string
void readAndDisplayNewString(char *newStr)
{
    printf("Enter a string: ");
    scanf("%s", newStr);
    printf("Entered String: %s\n", newStr);
}

// Function to calculate the string length without using string built-in functions
int calculateNewStringLength(char *newStr)
{
    int newLength = 0;
    while (newStr[newLength] != '\0')
    {
        newLength++;
    }
    return newLength;
}

// Function to reverse the string without using string built-in functions
void reverseNewString(char *newStr)
{
    int newLength = calculateNewStringLength(newStr);
    int i, j;
    char temp;
    for (i = 0, j = newLength - 1; i < j; i++, j--)
    {
        temp = newStr[i];
        newStr[i] = newStr[j];
        newStr[j] = temp;
    }
}

// Function to copy one string into another without using string built-in functions
void copyNewString(char *destStr, char *srcStr)
{
    while (*srcStr != '\0')
    {
        *destStr = *srcStr;
        destStr++;
        srcStr++;
    }
    *destStr = '\0';
}

// Function to read a character and count its occurrences in the string
int countCharacterInString(char *newStr, char newChar)
{
    int charCount = 0;
    while (*newStr != '\0')
    {
        if (*newStr == newChar)
        {
            charCount++;
        }
        newStr++;
    }
    return charCount;
}

int main()
{
    char inputStr[100];
    char reversedString[100];
    char copiedString[100];
    char searchChar;

    readAndDisplayNewString(inputStr);

    int stringLength = calculateNewStringLength(inputStr);
    printf("String Length: %d\n", stringLength);

    copyNewString(copiedString, inputStr);
    printf("Copied String: %s\n", copiedString);

    printf("Enter a character to search: ");
    scanf(" %c", &searchChar);
    int charCount = countCharacterInString(inputStr, searchChar);
    printf("Character '%c' appears %d times in the string.\n", searchChar, charCount);

    reverseNewString(inputStr);
    printf("Reversed String: %s\n", inputStr);

    return 0;
}
