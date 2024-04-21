#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;
};

struct Borrower {
    int id;
    string name;
};

class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;

public:
    Library() {
        loadBooks();
        loadBorrowers();
    }
    void addBook(const Book& book) {
        books.push_back(book);
        saveBooks();
    }
    void listBooks() {
        cout << "All Books:" << endl;
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Available: " << (book.isAvailable ? "Yes" : "No") << endl;
        }
    }
    void listAvailableBooks() {
        cout << "Available Books:" << endl;
        for (const auto& book : books) {
            if (book.isAvailable) {
                cout << "ID: " << book.id << " - Title: " << book.title << endl;
            }
        }
    }
    void borrowBook(int bookId, int borrowerId) {
        for (auto& book : books) {
            if (book.id == bookId && book.isAvailable) {
                book.isAvailable = false;
                cout << "Book '" << book.title << "' has been borrowed by " << getBorrowerName(borrowerId) << "." << endl;
                saveBooks();
                return;
            }
        }
        cout << "Book not available or does not exist." << endl;
    }
    string getBorrowerName(int borrowerId) {
        for (const auto& borrower : borrowers) {
            if (borrower.id == borrowerId) {
                return borrower.name;
            }
        }
        return "Unknown Borrower";
    }
    void listBorrowers() {
        cout << "List of Borrowers:" << endl;
        for (const auto& borrower : borrowers) {
            cout << "ID: " << borrower.id << " - Name: " << borrower.name << endl;
        }
    }
    void loadBooks() {
        ifstream file("books.txt");
        if (!file) {
            cerr << "Unable to open books file!" << endl;
            return;
        }
        Book book;
        string availability;
        while (file >> book.id >> book.title >> book.author >> availability) {
            replace(book.title.begin(), book.title.end(), '_', ' ');
            replace(book.author.begin(), book.author.end(), '_', ' ');
            book.isAvailable = (availability == "1");
            books.push_back(book);
        }
        file.close();
    }
    void loadBorrowers() {
        ifstream file("borrowers.txt");
        if (!file) {
            cerr << "Unable to open borrowers file!" << endl;
            return;
        }
        Borrower borrower;
        while (file >> borrower.id >> borrower.name) {
            replace(borrower.name.begin(), borrower.name.end(), '_', ' ');
            borrowers.push_back(borrower);
        }
        file.close();
    }
    void saveBooks() {
        ofstream file("books.txt");
        for (const auto& book : books) {
            string title = book.title;
            string author = book.author;
            replace(title.begin(), title.end(), ' ', '_');
            replace(author.begin(), author.end(), ' ', '_');
            file << book.id << " " << title << " " << author << " " << (book.isAvailable ? 1 : 0) << "\n";
        }
        file.close();
    }
    void saveBorrowers() {
        ofstream file("borrowers.txt");
        for (const auto& borrower : borrowers) {
            string name = borrower.name;
            replace(name.begin(), name.end(), ' ', '_');
            file << borrower.id << " " << name << "\n";
        }
        file.close();
    }
};

int main() {
    Library library;
    cout << "Full Book List:" << endl;
    library.listBooks();  // List all books to verify data

    cout << endl << "Available Books to Borrow:" << endl;
    library.listAvailableBooks();

    cout << endl << "List of Borrowers:" << endl;
    library.listBorrowers();  // List all borrowers

    int selectedBookId, borrowerId;
    cout << "Enter Book ID to borrow: ";
    cin >> selectedBookId;
    cout << "Enter Your Borrower ID: ";
    cin >> borrowerId;

    library.borrowBook(selectedBookId, borrowerId);
    return 0;
}
