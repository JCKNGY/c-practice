#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 100
#define FILE_NAME "tasks.txt"

typedef struct {
    char text[MAX_LEN];
    int done;
} Task;

Task tasks[MAX_TASKS];
int count = 0;

void load_tasks() {
    FILE *f = fopen(FILE_NAME, "r");
    if (!f) return;

    while (fscanf(f, "%d|%99[^\n]\n", &tasks[count].done, tasks[count].text) == 2) {
        count++;
    }

    fclose(f);
}

void save_tasks() {
    FILE *f = fopen(FILE_NAME, "w");

    for (int i = 0; i < count; i++) {
        fprintf(f, "%d|%s\n", tasks[i].done, tasks[i].text);
    }

    fclose(f);
}

void list_tasks() {
    for (int i = 0; i < count; i++) {
        printf("%d. [%c] %s\n", i + 1, tasks[i].done ? 'x' : ' ', tasks[i].text);
    }
}

void add_task(char *text) {
    if (count >= MAX_TASKS) return;

    strcpy(tasks[count].text, text);
    tasks[count].done = 0;
    count++;
}

void toggle_task(int index) {
    if (index < 0 || index >= count) return;
    tasks[index].done = !tasks[index].done;
}

int main(int argc, char *argv[]) {
    load_tasks();

    if (argc < 2) {
        printf("Usage:\n");
        printf("  ./todo add \"task\"\n");
        printf("  ./todo list\n");
        printf("  ./todo done <number>\n");
        return 0;
    }

    if (strcmp(argv[1], "add") == 0 && argc > 2) {
        add_task(argv[2]);
        save_tasks();
    }
    else if (strcmp(argv[1], "list") == 0) {
        list_tasks();
    }
    else if (strcmp(argv[1], "done") == 0 && argc > 2) {
        toggle_task(atoi(argv[2]) - 1);
        save_tasks();
    }

    return 0;
}
