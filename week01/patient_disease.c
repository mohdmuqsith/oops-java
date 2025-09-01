#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Patient {
    int id;
    char name[50];
    char disease[50];
    struct Date admission;
};

int main() {
    int n;
    printf("Enter number of patients: ");
    scanf("%d", &n);

    struct Patient p[n];
    for (int i = 0; i < n; i++) {
        printf("\nPatient %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &p[i].id);
        printf("Name: ");
        scanf("%s", p[i].name);
        printf("Disease: ");
        scanf("%s", p[i].disease);
        printf("Admission Date (dd mm yyyy): ");
        scanf("%d %d %d", &p[i].admission.day, &p[i].admission.month, &p[i].admission.year);
    }

    int searchMonth, searchYear;
    printf("\nEnter month and year to search: ");
    scanf("%d %d", &searchMonth, &searchYear);

    printf("\nPatients admitted in %02d/%d:\n", searchMonth, searchYear);
    for (int i = 0; i < n; i++) {
        if (p[i].admission.month == searchMonth && p[i].admission.year == searchYear) {
            printf("ID: %d, Name: %s, Disease: %s, Date: %02d-%02d-%d\n",
                   p[i].id, p[i].name, p[i].disease,
                   p[i].admission.day, p[i].admission.month, p[i].admission.year);
        }
    }
    return 0;
}
