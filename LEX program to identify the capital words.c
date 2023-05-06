#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char input[1000];
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    char* word = strtok(input, " ");
    while (word != NULL) {
        if (isupper(word[0])) {
            printf("Capital word: %s\n", word);
        }
        word = strtok(NULL, " ");
    }
    return 0;
}

