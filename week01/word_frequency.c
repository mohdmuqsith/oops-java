#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_LEN];
    int count[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter paragraph:\n");
    getchar(); // clear newline
    fgets(paragraph, sizeof(paragraph), stdin);

    char temp[MAX_LEN];
    int k = 0;
    for (int i = 0; paragraph[i] != '\0'; i++) {
        char c = tolower(paragraph[i]);
        if (isalpha(c)) {
            temp[k++] = c;
        } else if (k > 0) {
            temp[k] = '\0';
            int found = -1;
            for (int j = 0; j < wordCount; j++) {
                if (strcmp(words[j], temp) == 0) {
                    found = j;
                    break;
                }
            }
            if (found == -1) {
                strcpy(words[wordCount], temp);
                count[wordCount] = 1;
                wordCount++;
            } else {
                count[found]++;
            }
            k = 0;
        }
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s - %d\n", words[i], count[i]);
    }
    return 0;
}
