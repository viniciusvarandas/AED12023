#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main() {
    unsigned short cases, numPeople;
    char current[21], previous[21];
    bool isEnglish;
    scanf("%hu", &cases);

    while (cases--) {
        scanf("%hu", &numPeople);
        scanf(" %s", current);

        numPeople--;
        isEnglish = false;
        strcpy(previous, current);

        while (numPeople--) {
            if (strcmp(current, previous) != 0 && isEnglish == false)
                isEnglish = true;
            else
                strcpy(previous, current);

            scanf(" %s", current);
        }

        if (isEnglish)
            printf("ingles\n");
        else
            printf("%s\n", current);

        isEnglish = false;
    }
}