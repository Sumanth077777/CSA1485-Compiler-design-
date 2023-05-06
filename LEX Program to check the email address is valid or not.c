#include <stdio.h>
int main() {
    char email[1000];
    regex_t regex;

    // read email address from user
    printf("Enter email address: ");
    scanf("%s", email);

    // compile regular expression for email validation
    int ret = regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", REG_EXTENDED);

    if (ret) {
        printf("Error compiling regular expression\n");
        return 1;
    }

    // match email address against regular expression
    ret = regexec(&regex, email, 0, NULL, 0);

    if (!ret) {
        printf("Valid email address\n");
    } else if (ret == REG_NOMATCH) {
        printf("Invalid email address\n");
    } else {
        printf("Error matching regular expression\n");
    }

    // free memory used by regular expression
    regfree(&regex);

    return 0;
}

