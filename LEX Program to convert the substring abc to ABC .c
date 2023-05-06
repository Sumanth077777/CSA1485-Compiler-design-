#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char output[1000];
    int i, j;

    // read input string from user
    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);

    // remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // convert substring "abc" to "ABC"
    i = j = 0;

    while (i < strlen(input)) {
        if (input[i] == 'a' && input[i+1] == 'b' && input[i+2] == 'c') {
            output[j] = 'A';
            output[j+1] = 'B';
            output[j+2] = 'C';
            j += 3;
            i += 3;
        } else {
            output[j] = input[i];
            i++;
            j++;
        }
    }

    output[j] = '\0';

    // print output string
    printf("Output string: %s\n", output);

    return 0;
}
