#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;

class Book {
public:
    string author;
    string title;
    float price;
    int stock;

    // Constructor to input book details
    Book() {
        cout << "Author: ";
        cin >> author;
        cout << "Title: ";
        cin >> title;
        cout << "Price (INR): ";
        cin >> price;
        cout << "Stock: ";
        cin >> stock;
        system("cls");
    }

    // Function to display book details
    void displayDetails() {
        cout << "Details:\n";
        cout << "Author: " << author << "\nTitle: " << title << "\nPrice (INR): ₹" << price << "\nStock: " << stock << "\n";
    }

    // Function to check if the book is available
    bool isBookAvailable(const string& searchTitle) {
        return (title == searchTitle && stock > 0);
    }

    // Function to sell a book
    bool sellBook(int requestedCopies) {
        if (requestedCopies <= stock) {
            float totalCost = requestedCopies * price;
            cout << "Total cost: ₹" << totalCost << "\n";
            stock -= requestedCopies; // Update the stock position
            return true;              // Sale successful
        } else {
            cout << "Required copies not in stock.\n";
            return false; // Sale unsuccessful
        }
    }
};

int main() {
    int n;
    cout<<"How Many Books Are present In Lib: ";
    cin>>n;
    Book books[n];

    int opt = 0;
    while (opt != 2) {
        cout << "\nEnter 1 For Search Book\n";
        cout << "Enter 2 For Exit\n";
        cin >> opt;

        if (opt == 1) 
        {
            cout << "Enter Book Title: ";
            string searchTitle;
            cin >> searchTitle;

            bool bookFound = false;
            for (int i = 0; i < n; ++i) {
                if (books[i].isBookAvailable(searchTitle)) {
                    bookFound = true;
                    books[i].displayDetails();

                    int requestedCopies;
                    cout << "Enter number of copies required: ";
                    cin >> requestedCopies;

                    if (books[i].sellBook(requestedCopies)) {
                        cout << "Thank you for your purchase!\n";
                    } else {
                        cout << "Sale unsuccessful. Check stock and try again.\n";
                    }

                    break; // Stop searching after finding the book
                }
            }

            if (!bookFound) {
                cout << "Book not available or out of stock.\n";
            }
        }
    }

    return 0;
}
