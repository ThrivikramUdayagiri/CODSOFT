#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available = true;
    string borrower = "";
    int dueDay = 0; // Due in days (just for example)
};

const int MAX_BOOKS = 100;
Book library[MAX_BOOKS];
int bookCount = 0;

// Add a book
void addBook(string title, string author, string isbn) {
    library[bookCount++] = {title, author, isbn, true, "", 0};
}

// Search books
void searchBook(string keyword) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].title == keyword || library[i].author == keyword || library[i].isbn == keyword) {
            found = true;
            cout << "Title: " << library[i].title
                 << ", Author: " << library[i].author
                 << ", ISBN: " << library[i].isbn
                 << ", Status: " << (library[i].available ? "Available" : "Checked out by " + library[i].borrower)
                 << endl;
        }
    }
    if (!found) cout << "Book not found.\n";
}

// Checkout book
void checkoutBook(string isbn, string borrower) {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            if (library[i].available) {
                library[i].available = false;
                library[i].borrower = borrower;
                library[i].dueDay = 7; // book is due in 7 days
                cout << "Book checked out to " << borrower << ". Due in 7 days.\n";
            } else {
                cout << "Book already checked out.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Return book
void returnBook(string isbn, int daysPassed) {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isbn == isbn) {
            if (!library[i].available) {
                library[i].available = true;
                int fine = 0;
                if (daysPassed > library[i].dueDay) {
                    fine = (daysPassed - library[i].dueDay) * 1;
                    cout << "Book is overdue. Fine = " << fine << " units.\n";
                } else {
                    cout << "Book returned on time. No fine.\n";
                }
                library[i].borrower = "";
                library[i].dueDay = 0;
            } else {
                cout << "Book is not checked out.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Main Menu
int main() {
    addBook("1984", "George Orwell", "111");
    addBook("The Alchemist", "Paulo Coelho", "222");

    int choice;
    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Search Book\n";
        cout << "2. Checkout Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string key;
            cout << "Enter title/author/ISBN: ";
            getline(cin, key);
            searchBook(key);
        } else if (choice == 2) {
            string isbn, name;
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter borrower name: ";
            getline(cin, name);
            checkoutBook(isbn, name);
        } else if (choice == 3) {
            string isbn;
            int days;
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "How many days passed since checkout? ";
            cin >> days;
            cin.ignore();
            returnBook(isbn, days);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}