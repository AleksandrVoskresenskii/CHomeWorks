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
        printf("Файл не найден. Начинаем с пустой базы данных.\n");
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
        printf("Ошибка при сохранении данных.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        fprintf(file, "%s %s\n", phonebook[i].name, phonebook[i].phone);
    }

    fclose(file);
    printf("Данные успешно сохранены.\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Телефонный справочник переполнен.\n");
        return;
    }

    printf("Введите имя: ");
    scanf("%s", phonebook[entryCount].name);

    printf("Введите номер телефона: ");
    scanf("%s", phonebook[entryCount].phone);

    entryCount++;
    printf("Запись добавлена.\n");
}

void printEntries() {
    if (entryCount == 0) {
        printf("Справочник пуст.\n");
        return;
    }

    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

void findPhoneByName() {
    char name[MAX_NAME_LENGTH];
    printf("Введите имя для поиска: ");
    scanf("%s", name);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Телефон: %s\n", phonebook[i].phone);
            return;
        }
    }

    printf("Запись с именем %s не найдена.\n", name);
}

void findNameByPhone() {
    char phone[MAX_PHONE_LENGTH];
    printf("Введите номер телефона для поиска: ");
    scanf("%s", phone);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(phonebook[i].phone, phone) == 0) {
            printf("Имя: %s\n", phonebook[i].name);
            return;
        }
    }

    printf("Запись с номером %s не найдена.\n", phone);
}

int main() {
    setlocale(LC_ALL, "Rus");
    loadPhonebook();

    int choice;

    printf("\nТелефонный справочник\n");
    printf("0 - выйти\n");
    printf("1 - добавить запись\n");
    printf("2 - распечатать все записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить данные в файл\n");

    do {
        printf("\nТелефонный справочник\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Выход.\n");
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
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}