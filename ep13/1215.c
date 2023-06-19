#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char words[201];
}
string;

bool searchStr(char*, string*, unsigned);
void qSortPartialAlpha(string* dictionary, int size);
void qSortPartialAlphaInternal(string* dictionary, int start, int end);

int main() {
    unsigned i, j, k = 0;
    char tempInput[201], tempOutput[201];
    string dictionary[5050];

    memset(dictionary, 0, sizeof(dictionary));
    while (scanf(" %[^\n]", tempInput) != EOF) {
        i = j = 0;
        while (tempInput[i]) {
            while (isalpha(tempInput[i]))
                tempOutput[j++] = tolower(tempInput[i++]);

            if (tempInput[i] == '\0') {
                tempOutput[j] = '\0';

                if (!searchStr(tempOutput, dictionary, k))
                    strcpy(dictionary[k++].words, tempOutput);

                j = 0;

                memset(tempOutput, 0, sizeof(tempOutput));
                break;
            }

            tempOutput[j] = '\0';

            while (!isalpha(tempInput[i])) {
                i++;
                if (tempInput[i] == '\0')
                    break;
            }

            if (!searchStr(tempOutput, dictionary, k))
                strcpy(dictionary[k++].words, tempOutput);

            j = 0;
            memset(tempOutput, 0, sizeof(tempOutput));
        }

        memset(tempInput, 0, sizeof(tempInput));
    }

    qSortPartialAlpha(dictionary, k);

    j = 0;
    if (strcmp(dictionary[0].words, "\0") == 0)
        j = 1;

    for (; j < k; j++)
        printf("%s\n", dictionary[j].words);
}

bool searchStr(char* str, string* dictionary, unsigned size) {
    unsigned i;
    for (i = 0; i < size; i++)
        if (strcmp(dictionary[i].words, str) == 0)
            return true;

    return false;
}

void qSortPartialAlphaInternal(string* dictionary, int start, int end) {
    string pivot;
    string temp;
    int i, j;
    if (end - start > 0) {
        if (start < end) {
            i = start;
            j = end;
            pivot = dictionary[(i + j) / 2];

            do {
                while (strcmp(dictionary[i].words, pivot.words) < 0)
                    i++;
                while (strcmp(dictionary[j].words, pivot.words) > 0)
                    j--;

                if (i <= j) {
                    temp = dictionary[i];
                    dictionary[i] = dictionary[j];
                    dictionary[j] = temp;
                    i++;
                    j--;
                }

            } while (i <= j);

            qSortPartialAlphaInternal(dictionary, start, j);
            qSortPartialAlphaInternal(dictionary, i, end);
        }
    }
}

void qSortPartialAlpha(string* dictionary, int size) {
    qSortPartialAlphaInternal(dictionary, 0, size - 1);
}