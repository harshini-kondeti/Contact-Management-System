#include <iostream>
#include <cstring>
using namespace std;

#define CONTACTS 30

struct Contact {
   char name[50], email[50], phone[50];
};

struct Contact contacts[CONTACTS];
int count = 0;

void menu() {
    cout << "1. Add Contact\n";
    cout << "2. View Contacts\n";
    cout << "3. Delete Contact\n";
    cout << "4. Edit Contact\n";
    cout << "5. Find Contact\n";
    cout << "6. Exit\n";
    cout << "\n";
}

void add() {
    if (count >= CONTACTS) {
        cout << "Contact list is full\n";
        return;
    }
    struct Contact c;
    cout << "Enter name: ";
    cin >> c.name;
    cout << "Enter phone number: ";
    cin >> c.phone;
    if (strlen(c.phone) != 10) {
        cout << "Entered number is invalid. Re-enter the phone number: ";
        cin >> c.phone;
    }
    cout << "Enter email: ";
   cin >> c.email;
    if (strlen(c.phone) == 10) {
        contacts[count++] = c;
    }
    cout << "\n";
}

void view() {
    if (count != 0) {
        for (int i = 0; i < count; i++) {
            cout << "Name: " << contacts[i].name << "\n";
            cout << "Email: " << contacts[i].email << "\n";
            cout << "Phone: " << contacts[i].phone << "\n";
            cout << "\n";
        }
    } else {
        cout << "No contacts are there\n";
    }
    cout << "\n";
}

void del() {
    char name[50];
    cout << "Enter name to delete: ";
    cin >> name;
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            found = 1;
            cout << "Contact deleted successfully\n";
            break;
        }
    }
    if (!found) {
        cout << "Contact not found\n";
    }
    cout << "\n";
}

void edit() {
    char name[50];
    cout << "Enter name to edit: ";
    cin >> name;
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            cout << "Enter new name: ";
            cin >> contacts[i].name;
            cout << "Enter new phone number: ";
            cin >> contacts[i].phone;
            if (strlen(contacts[i].phone) != 10) {
                cout << "Entered number is invalid. Re-enter the phone number: ";
                cin >> contacts[i].phone;
            }
            cout << "Enter new email: ";
            cin >> contacts[i].email;
            found = 1;
            cout << "Contact edited successfully\n";
            break;
        }
    }
    if (!found) {
        cout << "Contact not found\n";
    }
    cout << "\n";
}

void find() {
    cout << "Enter 1 to find by name or 2 to find by number: ";
    int ch;
    cin >> ch;

    char name[50], number[15];
    if (ch == 1) {
        cout << "Enter name: ";
        cin >> name;
    } else if (ch == 2) {
        cout << "Enter number: ";
        cin >> number;
    } else {
        cout << "Invalid choice\n";
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0 || std::strcmp(contacts[i].phone, number) == 0) {
            cout << "Contact was found\n";
            cout << "Name: " << contacts[i].name << "\n";
            cout << "Email: " << contacts[i].email << "\n";
            cout << "Phone: " << contacts[i].phone << "\n";
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << "Contact not found\n";
    }
   cout << "\n";
}

int main() {
    int choice;
    do {
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                view();
                break;
            case 3:
                del();
                break;
            case 4:
                edit();
                break;
            case 5:
                find();
                break;
            case 6:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice\n";
                cout << "\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
