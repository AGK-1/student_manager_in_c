#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    int id;
    char name[50];
    char surname[50];
    int age;
} Student;

int c = 0;

int isValidName(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            return 0; // есть цифра → ошибка
        }
    }
    return 1; // всё ок
}

int isValidNumber(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0; // есть не цифра
        }
    }
    return 1;
}
 // new grp

Student* search(char name[], Student students[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(name, students[i].name) == 0) {
            return &students[i];
        }
    }
    return NULL;
}

void deleteStudentById(Student students[], int *count, int id) {
    int index = -1;

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Not found\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;
}



int main(void) {
    int index = 0;

    Student students[100];
    printf("\n Welcome to student managment system \n");
    char ch;

    while (1) {
       // while ((getchar()) != '\n'); // clear buffer

        printf("a for add students\n");
        printf("d for delete students\n");
        printf("s for show students\n");
        printf("u for update students\n");
        printf("q for quit\n");
        printf("Select option: ");
        ch = getchar();
        while ((getchar()) != '\n');

        if (ch == 'a') {
            while (1) {
                printf("Name: ");
                scanf("%49s", students[c].name);

                if (!isValidName(students[c].name)) {
                    printf("Error: name must not contain numbers!\n");
                } else {
                    break; // всё ок → выходим из цикла
                }
            }


            while (1) {
                printf("Surname: ");
                scanf("%49s", students[c].surname);

                if (!isValidName(students[c].surname)) {
                    printf("Error: surname must not contain numbers!\n");
                } else {
                    break;
                }
            }

            while (1) {
                printf("Age: ");
                if (scanf("%d", &students[c].age) != 1) {
                    printf("Error: age must be a number!\n");
                    while (getchar() != '\n'); // очистка буфера
                } else {
                    break;
                }
            }

            while ((getchar()) != '\n'); // sraf cl
            students[c].id = index;
            index++;
            c++;
            printf("Student added\n");

        } else if (ch == 'd') {
            printf("Add id who you want delete...\n");
            char name[50];
            printf("Enter name: ");
            scanf("%49s", name);
            Student* st = search(name, students, c);

            if (st != NULL) {
                deleteStudentById(students, &c, st->id);
                printf("Deleted!\n");
            } else {
                printf("Student not found\n");
            }

        } else if (ch == 's') {
            if (c == 0) {
                printf("List is empty!\n");
            } else {
                for (int i = 0; i < c; i++) {
                    printf("ID: %d | Name: %s | Surname: %s | Age: %d\n",
                           students[i].id,     // ID
                           students[i].name,
                           students[i].surname,// name
                           students[i].age   // agge
                           ); // group
                }
            }
            printf("Showing students...\n");
        } else if (ch == 'u') {
            char name[50];
            char newName[50];    // new nam
            char surname[50];
            int newAge;          // new ag

            printf("Add name who you want update...\n");

            printf("Enter name: ");
            scanf("%49s", name);
            Student* st = search(name, students, c);
            if (st != NULL) {
                printf("Enter new name: ");
                scanf("%49s", newName);
                strcpy(st->name, newName);  //copy lin
                printf("Enter new surname: ");
                scanf("%49s", surname);
                strcpy(st->surname, surname);
                printf("Enter new age: ");
                scanf("%d", &newAge);       // necesary int
                st->age = newAge;

                printf("Student updated!\n");
            }
            while ((getchar()) != '\n');
            } else if (ch == 'q') {
                printf("Exit...\n");
                break;
            } else {
                printf("Unknown option: '%c'\n", ch);
            }
        }

        return 0;
    }
