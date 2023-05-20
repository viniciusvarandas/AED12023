#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100000

int main() {
    char input[MAX_LENGTH + 1];

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    char *substring = strstr(input, "zelda");
    if (substring != NULL) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}