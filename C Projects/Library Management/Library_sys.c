#include <stdio.h>

#define MAX_BOOKS 100

struct Book {
    int code;
    char name[50];
    char author[50];
    int pages;
    int price;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook();
void displayBooks();
void searchBook();
void deleteBook();

int main()
{
    int choice;

    do {
        printf("\n---- Library Menu ----\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            printf("\nLibrary Closed. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

/* ---------------- ADD BOOK ---------------- */

void addBook()
{
    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }

    struct Book b;

    printf("\nEnter Book Code: ");
    scanf("%d", &b.code);

    printf("Enter Book Name: ");
    scanf(" %49[^\n]", b.name);

    printf("Enter Author Name: ");
    scanf(" %49[^\n]", b.author);

    printf("Enter Pages: ");
    scanf("%d", &b.pages);

    printf("Enter Price: ");
    scanf("%d", &b.price);

    library[bookCount] = b;
    bookCount++;

    printf("\nBook added successfully!\n");
}

/* ---------------- DISPLAY BOOKS ---------------- */

void displayBooks()
{
    if (bookCount == 0) {
        printf("\nNo books available!\n");
        return;
    }

    printf("\n---- Book List ----\n");

    for (int i = 0; i < bookCount; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Code   : %d\n", library[i].code);
        printf("Name   : %s\n", library[i].name);
        printf("Author : %s\n", library[i].author);
        printf("Pages  : %d\n", library[i].pages);
        printf("Price  : %d\n", library[i].price);
    }
}

/* ---------------- SEARCH BOOK ---------------- */

void searchBook()
{
    if (bookCount == 0) {
        printf("\nLibrary is empty!\n");
        return;
    }

    int code, found = 0;

    printf("\nEnter book code to search: ");
    scanf("%d", &code);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].code == code) {
            printf("\nBook Found!\n");
            printf("Code   : %d\n", library[i].code);
            printf("Name   : %s\n", library[i].name);
            printf("Author : %s\n", library[i].author);
            printf("Pages  : %d\n", library[i].pages);
            printf("Price  : %d\n", library[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }
}

/* ---------------- DELETE BOOK ---------------- */

void deleteBook()
{
    if (bookCount == 0) {
        printf("\nLibrary is empty! Nothing to delete.\n");
        return;
    }

    int code, foundIndex = -1;

    printf("\nEnter book code to delete: ");
    scanf("%d", &code);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].code == code) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("\nBook not found!\n");
        return;
    }

    /* Shift books left */
    for (int i = foundIndex; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }

    bookCount--;

    printf("\nBook deleted successfully!\n");
}
