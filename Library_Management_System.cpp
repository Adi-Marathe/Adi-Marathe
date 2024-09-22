#include <iostream>
#include <cstring>

using namespace std;

// Define the maximum number of books and users
const int MAX_BOOKS = 100;
const int MAX_USERS = 100;

// Book class definition
class Book {
public:
    int id;
    char title[100];
    char author[100];
    bool isIssued;

    Book() {
        id = 0;
        strcpy(title, "Unknown");
        strcpy(author, "Unknown");
        isIssued = false;
    }

    void addBook(int bookId, const char* bookTitle, const char* bookAuthor) {
        id = bookId;
        strcpy(title, bookTitle);
        strcpy(author, bookAuthor);
        isIssued = false;
    }

    void displayBook() {
        cout << "Book ID: " << id << ", Title: " << title << ", Author: " << author;
        if (isIssued)
            cout << " [Issued]" << endl;
        else
            cout << " [Available]" << endl;
    }
};

// User class definition
class User {
public:
    int id;
    char name[100];

    User() {
        id = 0;
        strcpy(name, "Unknown");
    }

    void addUser(int userId, const char* userName) {
        id = userId;
        strcpy(name, userName);
    }

    void displayUser() {
        cout << "User ID: " << id << ", Name: " << name << endl;
    }
};

// Library class to manage books and users
class Library {
private:
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    int bookCount;
    int userCount;

public:
    Library() {
        bookCount = 0;
        userCount = 0;
    }

    // Add a new book
    void addBook(int bookId, const char* bookTitle, const char* bookAuthor) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount].addBook(bookId, bookTitle, bookAuthor);
            bookCount++;
        } else {
            cout << "Library is full, cannot add more books!" << endl;
        }
    }

    // Add a new user
    void addUser(int userId, const char* userName) {
        if (userCount < MAX_USERS) {
            users[userCount].addUser(userId, userName);
            userCount++;
        } else {
            cout << "Cannot add more users!" << endl;
        }
    }

    // Search for a book by title
    void searchBookByTitle(const char* bookTitle) {
        for (int i = 0; i < bookCount; i++) {
            if (strcmp(books[i].title, bookTitle) == 0) {
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Issue a book
    void issueBook(int bookId) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookId) {
                if (!books[i].isIssued) {
                    books[i].isIssued = true;
                    cout << "Book issued successfully!" << endl;
                } else {
                    cout << "Book is already issued!" << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Return a book
    void returnBook(int bookId) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == bookId) {
                if (books[i].isIssued) {
                    books[i].isIssued = false;
                    cout << "Book returned successfully!" << endl;
                } else {
                    cout << "Book was not issued!" << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Display all books
    void displayAllBooks() {
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBook();
        }
    }

    // Display all users
    void displayAllUsers() {
        for (int i = 0; i < userCount; i++) {
            users[i].displayUser();
        }
    }
};

// Main function
int main() {
    Library library;
    int choice, bookId, userId;
    char bookTitle[100], bookAuthor[100], userName[100];

    while (true) {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add User\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Display All Users\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> bookId;
                cin.ignore(); // to ignore leftover newline from previous input
                cout << "Enter Book Title: ";
                cin.getline(bookTitle, 100);
                cout << "Enter Book Author: ";
                cin.getline(bookAuthor, 100);
                library.addBook(bookId, bookTitle, bookAuthor);
                break;

            case 2:
                cout << "Enter User ID: ";
                cin >> userId;
                cin.ignore();
                cout << "Enter User Name: ";
                cin.getline(userName, 100);
                library.addUser(userId, userName);
                break;

            case 3:
                cout << "Enter Book Title to Search: ";
                cin.ignore();
                cin.getline(bookTitle, 100);
                library.searchBookByTitle(bookTitle);
                break;

            case 4:
                cout << "Enter Book ID to Issue: ";
                cin >> bookId;
                library.issueBook(bookId);
                break;

            case 5:
                cout << "Enter Book ID to Return: ";
                cin >> bookId;
                library.returnBook(bookId);
                break;

            case 6:
                library.displayAllBooks();
                break;

            case 7:
                library.displayAllUsers();
                break;

            case 8:
                cout << "Exiting the program..." << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
  return 0;
}
