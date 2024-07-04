#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void registerUser();
bool loginUser();
bool checkUserExists(const string& username);
void saveCredentials(const string& username, const string& password);
bool verifyCredentials(const string& username, const string& password);

// Main function
int main() {
    int choice;
	
	do{
	cout << "Welcome to the Login and Registration System" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        if (loginUser()) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password!" << endl;
        }
    } else if(choice == 3){
    	exit(0);
	}else {
        cout << "Invalid choice!" << endl;
    }
	}while(true);
	
    return 0;
}

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    if (checkUserExists(username)) {
        cout << "Username already exists! Try another one." << endl;
        return;
    }

    saveCredentials(username, password);
    cout << "Registration successful!" << endl;
}

// Function to check if a user exists
bool checkUserExists(const string& username) {
    ifstream file("database.txt");
    string line;
    while (getline(file, line)) {
        if (line.find(username + " ") == 0) {
            return true;
        }
    }
    return false;
}

// Function to save credentials to a file
void saveCredentials(const string& username, const string& password) {
    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;
}

// Function to login a user
bool loginUser() {
    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    return verifyCredentials(username, password);
}

// Function to verify credentials
bool verifyCredentials(const string& username, const string& password) {
    ifstream file("database.txt");
    string line;
    while (getline(file, line)) {
        if (line == username + " " + password) {
            return true;
        }
    }
    return false;
}

