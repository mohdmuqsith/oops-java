#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks[5];
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);
        printf("Name: ");
        scanf("%s", &s[i].name);
        printf("Marks (5 subjects): ");
        for (int j = 0; j < 5; j++) {
            scanf("%f", &s[i].marks[j]);
        }
    }

    printf("\nStudents scoring above 75%%:\n");
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++) sum += s[i].marks[j];
        float avg = sum / 5;
        if (avg > 75) {
            printf("\nRoll No: %d\nName: %s\nAverage Marks: %.2f\n", 
                   s[i].roll_no, s[i].name, avg);
        }
    }
    return 0;
}
