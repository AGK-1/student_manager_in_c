#include <stdio.h>
#include <time.h>

int main(void) {
    char ch;
    char adc;
    while (1) {
        // Сначала показываем меню
        printf("\na for add students\n");
        printf("d for delete students\n");
        printf("s for show students\n");
        printf("u for update students\n");
        printf("q for quit\n");
        printf("Select option: ");

        // Потом ждём ввод
        ch = getchar();
        if (ch == '\n') continue;

        // Очищаем буфер от Enter
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (ch == 'a') {
            printf("Add user name...\n");
            adc = getchar();
        } else if (ch == 'd') {
            printf("Deleting student...\n");
        } else if (ch == 's') {
            printf("Showing students...\n");
        } else if (ch == 'u') {
            printf("Updating student...\n");
        } else if (ch == 'q') {
            printf("Exit...\n");
            break;
        } else {
            printf("Unknown option: '%c'\n", ch);
        }
    }

    return 0;
}