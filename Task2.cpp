#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    ofstream file;
    file.open("users.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error opening file for registration.\n";
    }
}

// Function to login
void loginUser() {
    string username, password, storedUser, storedPass;
    bool loginSuccess = false;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> storedUser >> storedPass) {
            if (storedUser == username && storedPass == password) {
                loginSuccess = true;
                break;
            }
        }
        file.close();

        if (loginSuccess) {
            cout << "Login successful. Welcome, " << username << "!\n";
        } else {
            cout << "Login failed. Incorrect username or password.\n";
        }
    } else {
        cout << "Error opening file for login.\n";
    }
}

int main() {
    int choice;

    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}
