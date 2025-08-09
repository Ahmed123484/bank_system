#include"../headers/screenLogin.h"
#include<limits>
namespace screenLogin {
void clScreenLogin::login() {
    cout << "Enter username: ";
    getline(cin,username);
    // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    cout << "Enter password: ";
    getline(cin,password);
}
bool clScreenLogin::validateUser(const vector<clUserInfo>& users, const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.getUserName() == username && user.getUserPassword() == password) {
            accountNumber =user.getAccountNumber();
            return true; // User found and password matches

        }
    }
    if (username == "admin" && password == "admin") {
        return true; // Admin user found and password matches
    }
    return false; // User not found or password does not match
}
void clScreenLogin::setUsername(const string& name) {
    username = name;
}
void clScreenLogin::setPassword(const string& password) {
    this->password = password;
}
void clScreenLogin::setAccountNumber(const string& accountNumber) {
    this->accountNumber = accountNumber;
}
string clScreenLogin::getAccountNumber() const {
    return accountNumber;
}
string clScreenLogin::getUsername() const {
    return username;
}
string clScreenLogin::getPassword() const {
    return password;
}
void clScreenLogin::displayUserInfo() {
    cout << "User Name: " << username << endl;
    cout << "User Password: " << password << endl;
}
bool clScreenLogin::userExists(const vector<clUserInfo>& users, const string& username) {
    for (const auto& user : users) {
        if (user.getUserName() == username) {
            return true; // User found
        }
    }
    return false; // User not found
}
bool clScreenLogin::validatePassword(const vector<clUserInfo>& users, const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.getUserName() == username && user.getUserPassword() == password) {
            return true; // Password matches
        }
    }
    return false; // Password does not match
}
bool clScreenLogin::validateUsername(const vector<clUserInfo>& users, const string& username) {
    for (const auto& user : users) {
        if (user.getUserName() == username) {
            return true; // User found
        }
    }
    return false; // User not found
}
}