#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int msv;
    char name[100];
    float a, b, c;
    struct Student* next;
} Student;
void add(Student** head, int* nextID, int n) {
    for (int i = 0; i < n; i++) {
        Student* sv = (Student*)malloc(sizeof(Student));
        sv->msv = (*nextID)++;
        
        scanf("\n");
        fgets(sv->name, sizeof(sv->name), stdin);
        sv->name[strcspn(sv->name, "\n")] = '\0';
        
        scanf("%f %f %f", &sv->a, &sv->b, &sv->c);
        sv->next = NULL;

        if (*head == NULL) {
            *head = sv;
        } else {
            Student* temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = sv;
        }
    }
    printf("%d\n", n);
}
void change(Student* head, int id) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->msv == id) {
            scanf("\n");
            fgets(temp->name, sizeof(temp->name), stdin);
            temp->name[strcspn(temp->name, "\n")] = '\0';
            scanf("%f %f %f", &temp->a, &temp->b, &temp->c);
            printf("%d\n", id);
            return;
        }
        temp = temp->next;
    }
}
void show(Student* sv) {
    printf("%d %s %.1f %.1f %.1f\n", sv->msv, sv->name, sv->a, sv->b, sv->c);
}
void check(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->a < temp->b && temp->b < temp->c) {
            show(temp);
        }
        temp = temp->next;
    }
}
void process() {
    Student* head = NULL;
    int nextID = 1;
    int command;
    while (scanf("%d", &command) != EOF) {
        if (command == 1) {
            int n;
            scanf("%d", &n);
            add(&head, &nextID, n);
        } else if (command == 2) {
            int id;
            scanf("%d", &id);
            change(head, id);
        } else if (command == 3) {
            check(head);
            break;
        }
    }
}

int main() {
    process();
    return 0;
}
