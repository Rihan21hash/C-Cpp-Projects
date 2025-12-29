#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
};

vector<User> loadUsers() {
    vector<User> users;
    ifstream file("users.txt");

    User u;
    while (file >> u.username >> u.password) {
        users.push_back(u);
    }

    file.close();
    return users;
}

void saveUsers(const vector<User>& users) {
    ofstream file("users.txt");
    for (const auto& u : users) {
        file << u.username << " " << u.password << endl;
    }
    file.close();
}

// ================= CORE LOGIC =================
int findUser(const vector<User>& users, const string& name) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].username == name)
            return i;
    }
    return -1;
}

void registerUser() {
    vector<User> users = loadUsers();
    User u;

    cout << "Enter username: ";
    cin >> u.username;

    if (findUser(users, u.username) != -1) {
        cout << "User already exists.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> u.password;

    users.push_back(u);
    saveUsers(users);

    cout << "Registration successful.\n";
}

void loginUser() {
    vector<User> users = loadUsers();
    string name, pw;

    cout << "Enter username: ";
    cin >> name;

    cout << "Enter password: ";
    cin >> pw;

    int idx = findUser(users, name);
    if (idx != -1 && users[idx].password == pw) {
        cout << "Login successful. Welcome " << name << "!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

void changePassword() {
    vector<User> users = loadUsers();
    string name, newPw;

    cout << "Enter username: ";
    cin >> name;

    int idx = findUser(users, name);
    if (idx == -1) {
        cout << "User not found.\n";
        return;
    }

    cout << "Enter new password: ";
    cin >> newPw;

    users[idx].password = newPw;
    saveUsers(users);

    cout << "Password changed successfully.\n";
}

void deleteUser() {
    vector<User> users = loadUsers();
    string name;

    cout << "Enter username to delete: ";
    cin >> name;

    int idx = findUser(users, name);
    if (idx == -1) {
        cout << "User not found.\n";
        return;
    }

    users.erase(users.begin() + idx);
    saveUsers(users);

    cout << "User deleted successfully.\n";
}

int main() {
    while (true) {
        cout << "\n==== USER SYSTEM ====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Change Password\n";
        cout << "4. Delete User\n";
        cout << "5. Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: changePassword(); break;
            case 4: deleteUser(); break;
            case 5: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
