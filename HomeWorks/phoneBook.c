#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define FILENAME "phonebook.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Entry;

Entry phonebook[MAX_ENTRIES];
int entryCount = 0;

void loadPhonebook() {
    FILE* file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("���� �� ������. �������� � ������ ���� ������.\n");
        return;
    }

    while (fscanf(file, "%s %s", phonebook[entryCount].name, phonebook[entryCount].phone) == 2) {
        entryCount++;
        if (entryCount >= MAX_ENTRIES) break;
    }

    fclose(file);
}

void savePhonebook() {
    FILE* file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("������ ��� ���������� ������.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s\n", phonebook[i].name, phonebook[i].phone);
    }

    fclose(file);
    printf("������ ������� ���������.\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("���������� ���������� ����������.\n");
        return;
    }

    printf("������� ���: ");
    scanf("%s", phonebook[entryCount].name);

    printf("������� ����� ��������: ");
    scanf("%s", phonebook[entryCount].phone);

    entryCount++;
    printf("������ ���������.\n");
}

void printEntries() {
    if (entryCount == 0) {
        printf("���������� ����.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void findPhoneByName() {
    char name[MAX_NAME_LENGTH];
    printf("������� ��� ��� ������: ");
    scanf("%s", name);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("�������: %s\n", phonebook[i].phone);
            return;
        }
    }

    printf("������ � ������ %s �� �������.\n", name);
}

void findNameByPhone() {
    char phone[MAX_PHONE_LENGTH];
    printf("������� ����� �������� ��� ������: ");
    scanf("%s", phone);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phonebook[i].phone, phone) == 0) {
            printf("���: %s\n", phonebook[i].name);
            return;
        }
    }

    printf("������ � ������� %s �� �������.\n", phone);
}

int main() {
    setlocale(LC_ALL, "Rus");
    loadPhonebook();

    int choice;

    printf("\n���������� ����������\n");
    printf("0 - �����\n");
    printf("1 - �������� ������\n");
    printf("2 - ����������� ��� ������\n");
    printf("3 - ����� ������� �� �����\n");
    printf("4 - ����� ��� �� ��������\n");
    printf("5 - ��������� ������ � ����\n");

    do {
        printf("\n���������� ����������\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("�����.\n");
            break;
        case 1:
            addEntry();
            break;
        case 2:
            printEntries();
            break;
        case 3:
            findPhoneByName();
            break;
        case 4:
            findNameByPhone();
            break;
        case 5:
            savePhonebook();
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
        }
    } while (choice != 0);

    return 0;
}