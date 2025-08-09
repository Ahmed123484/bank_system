#include "../headers/userInfo.h"

namespace userInfo {
  // Function to set user information
  void clUserInfo::setUserInfo(const string& name, const string& password , int permission , const string& accountNumber) {
    userInfo.userName = name;
    userInfo.userPassword = password;
    userInfo.userPermission = permission;
  }
  // Function to set user name
  void clUserInfo::setUserName(const string& name) {
    userInfo.userName = name;
  }
    // Function to set user password
    void clUserInfo::setUserPassword(const string& password) {
      userInfo.userPassword = password;
    }
    // Function to set user permission
    void clUserInfo::setUserPermission(int permission) {
      userInfo.userPermission = permission;
    }
    // Function to set user account number
    void clUserInfo::setAccountNumber(const string& accountNumber) {
      userInfo.accountNumber = accountNumber;
    }
  // Function to get user name
  string clUserInfo::getUserName() const {
    return userInfo.userName;
  }
  // Function to get user password
  string clUserInfo::getUserPassword() const {
    return userInfo.userPassword;
  }
    // Function to get user permission
    int clUserInfo::getUserPermission() const {
      return userInfo.userPermission;
    }     
    // Function to get user account number
    string clUserInfo::getAccountNumber() const {
      return userInfo.accountNumber;
    }
  // Function to display user information
  void clUserInfo::displayUserInfo() const {
    cout << "User Name: " << userInfo.userName << endl;
    cout << "User Password: " << userInfo.userPassword << endl;
    cout << "User Permission: " << userInfo.userPermission << endl;
    cout << "Account Number: " << userInfo.accountNumber << endl;
  }
  void clUserInfo::askAndGrant(const string &desc, int permCode, permission::User &usere) {
    char choice;
    cout << "Do you want add permission " << desc << "? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        usere.grantPermission(permCode);
    }
}
   void clUserInfo::updateUserPermission(vector <clUserInfo> &users , int permission) {
    char choice;
    for (auto &user : users) {
        permission::User usere(0) ;
        user.setUserPermission(0);
        cout << "Updating permission for user: " << user.getUserName() << endl;
        askAndGrant("show users", PERM_LIST_USERS, usere);
        askAndGrant("add user", PERM_ADD_USER, usere);
        askAndGrant("delete user", PERM_DELETE_USER, usere);
        askAndGrant("update user", PERM_UPDATE_USER, usere);
        askAndGrant("add client", PERM_ADD_CLIENT, usere);
        askAndGrant("delete client", PERM_DELETE_CLIENT, usere);
        askAndGrant("update client", PERM_UPDATE_CLIENT, usere);
        askAndGrant("search client", PERM_SEARCH_CLIENT, usere);
        askAndGrant("show clients", PERM_SHOW_CLIENTS, usere);
        askAndGrant("transactions", PERM_TRANSACTIONS, usere);
        askAndGrant("manage users", PERM_MANAGE_USERS, usere);
        user.setUserPermission(usere.getPermissions());
        cout << "Updated permissions for user: " << user.getUserName() << endl;
    }
  }
  void clUserInfo::updateOneUserPermission(vector <clUserInfo> &users , string userName)  {
    for (auto &user : users) {
        if (user.getUserName() == userName) {
            permission::User usere(0);
            user.setUserPermission(0);
            cout << "Updating permission for user: " << user.getUserName() << endl;
            askAndGrant("show users", PERM_LIST_USERS, usere);
            askAndGrant("add user", PERM_ADD_USER, usere);
            askAndGrant("delete user", PERM_DELETE_USER, usere);
            askAndGrant("update user", PERM_UPDATE_USER, usere);
            askAndGrant("add client", PERM_ADD_CLIENT, usere);
            askAndGrant("delete client", PERM_DELETE_CLIENT, usere);
            askAndGrant("update client", PERM_UPDATE_CLIENT, usere);
            askAndGrant("search client", PERM_SEARCH_CLIENT, usere);
            askAndGrant("show clients", PERM_SHOW_CLIENTS, usere);
            askAndGrant("transactions", PERM_TRANSACTIONS, usere);
            askAndGrant("manage users", PERM_MANAGE_USERS, usere);
            user.setUserPermission(usere.getPermissions());
            cout << "Updated permissions for user: " << user.getUserName() << endl;
        }
    }
  }
}
