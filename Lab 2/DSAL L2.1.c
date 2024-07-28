// write a c program to count the number of occourences of EACH word in a given Text.

#include <stdio.h>
#include <string.h>


// In this process, we will run Two Loop, one for the word and another for the text.
// Loop 1
// We will compare the word with the text and if it matches, we will increase the count of the word.
// Loop 2
// We will run the loop for the text and compare the word with the text.
// If it matches, we will increase the count of the word.

// We will use the strcmp() function to compare the word with the text.
// We will implement NESTED LISTS to store the word and its count.

int main() {

    char text[1000], word[100], temp[100];
    int i, j, k, n, count;

    printf("Enter the text: ");
    gets(text);

    n = strlen(text);
    
    for(i = 0; i < n; i++) {
        k = 0;
        while(text[i] != ' ' && text[i] != '\0') {
            word[k++] = text[i++];
        }
        word[k] = '\0';
        count = 1;

        for(j = i + 1; j < n; j++) {
            k = 0;
            while(text[j] != ' ' && text[j] != '\0') {
                temp[k++] = text[j++];
            }
            temp[k] = '\0';

            if(strcmp(word, temp) == 0) {
                count++;
            }
        }

        printf("%s: %d\n", word, count);
    }

    
}






