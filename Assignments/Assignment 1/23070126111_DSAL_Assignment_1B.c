// 1B. Problem: Write a C program to count the occurrences of each word in a given text. 
// Description: Your program should take a text string as input and count the occurrences of each word 
// in the text. Words are separated by spaces or punctuation marks (such as commas or periods). 
// The program should then display the results, listing each unique word along with its corresponding count.

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void countWords(char *text) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int numWords = 0;

    // Tokenization of the text into words
    char *token = strtok(text, " ,.");
    while (token != NULL) {
        // Checking if the word already exists in the words array
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                break;
            }
        }

        // Noww, If the word doesn't exist,then add it to the words array.
        if (i == numWords) {
            strcpy(words[numWords], token);
            count[numWords]++;
            numWords++;
        }

        token = strtok(NULL, " ,.");
    }

    printf("Word\t\tCount\n");
    printf("\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", words[i], count[i]);
    }
}

int main() {
    char text[1000];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    // Remove the trailing newline character from fgets
    text[strcspn(text, "\n")] = '\0';

    countWords(text);

    return 0;
}

// Algorithm:
// 1. Define a function countWords that takes a text string as input.
// 2. Declare two arrays: words to store the unique words and count to store the count of each word.
// 3. Initialize the number of words to 0.
// 4. Tokenize the text string into words using strtok.
// 5. For each word, check if it already exists in the words array.
// 6. If the word exists, increment the count for that word.
// 7. If the word doesn't exist, add it to the words array and set the count to 1.
// 8. Display the results by printing each word along with its count.
// 9. In the main function, read the text input from the user.
// 10. Call the countWords function with the input text.

// Example:
// Input: "Do not try and bend the spoon. That's impossible. 
// Instead only try to realize the truth. What truth? 'There is no spoon.', he said. 
// 'There is no spoon?', I asked. 'You'll see that it is not the spoon that bends, it is only yourself.'"

// Output:
// Word		Count
//
// Do		1
// not		2
// try		2
// and		1
// bend		1
// the		3
// spoon		3
// That's		1
// impossible		1
// Instead		1
// only		2
// to		1
// realize		1
// truth		1
// What		1
// truth?		1
// 'There		2
// is		4
// no		2
// '		2
// he		1
// said		1
// spoon?'		1
// I		1
// asked		1
// 'You'll		1
// see		1
// that		2
// it		2
// bends		1
// yourself		1



// Time Complexity: (according to chatgpt)
// The time complexity of this program is O(n^2) where n is the number of words in the input text.

// Space Complexity: (according to chatgpt)
// The space complexity of this program is O(n) where n is the number of unique words in the input text.

