#include "../headers/userPermision.h"
#include "../headers/userInfo.h"
using namespace std;


namespace permission {
    // constructor
    User::User(int initialPermissions ) : permissions(initialPermissions) {}
    // إعداد صلاحية
    void User::grantPermission(int perm) {
        permissions |= perm;
    }

    // إزالة صلاحية
    void User::revokePermission(int perm) {
        permissions &= ~perm;
    }

    // التحقق من صلاحية
    bool User::hasPermission(int perm) const {
        return (permissions & perm) != 0;
    }

    int User::getPermissions() const {
        return permissions;
    }

    void User::setPermissions(int perm) {
        permissions = perm;
    }

    void User::displayPermissions() const {
        cout << "Permissions: " << permissions << endl;
    }
    // Function to ask for permission
    void User::askPermission() const {
        cout << "Current permissions: " << permissions << endl;
        cout << "Do you want to change permissions? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int newPerm;
            cout << "Enter new permissions (as an integer): ";
            cin >> newPerm;
            cout << "Permissions updated." << endl;
        } else {
            cout << "No changes made." << endl;
        }
    }
    void User::askAndGrant(const string &desc, int permCode, permission::User &usere) {
    char choice;
    cout << "Do you want add permission " << desc << "? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        usere.grantPermission(permCode);
    }
}
    int User::addAndAskkpermissonUser (){
        int permission = 0;
        permission::User user(permission);
        char choice;
        cout << "Do you want to add permission? (y/n): ";
        if (cin >> choice && (choice == 'y' || choice == 'Y')) {
            askAndGrant("to list users", PERM_LIST_USERS, user);
            askAndGrant("to add user", PERM_ADD_USER, user);
            askAndGrant("to delete user", PERM_DELETE_USER, user);
            askAndGrant("to update user", PERM_UPDATE_USER, user);
            askAndGrant("to Find user", PERM_FIND_USER, user);
            askAndGrant("to show clients", PERM_SHOW_CLIENTS, user);
            askAndGrant("to add client", PERM_ADD_CLIENT, user);
            askAndGrant("to delete client", PERM_DELETE_CLIENT, user);
            askAndGrant("to update client", PERM_UPDATE_CLIENT, user);
            askAndGrant("to search client", PERM_SEARCH_CLIENT, user);
            askAndGrant("to manage transactions", PERM_TRANSACTIONS, user);
            askAndGrant("to manage users", PERM_MANAGE_USERS, user);

        } else {
            cout << "No permission added." << endl;
        }
        return user.getPermissions();
    }
    void User::addAllPermissionUser (){
        int permission = 0;
        User::grantPermission(PERM_LIST_USERS);
        User::grantPermission(PERM_ADD_USER);
        User::grantPermission(PERM_DELETE_USER);
        User::grantPermission(PERM_UPDATE_USER);
        User::grantPermission(PERM_FIND_USER);
        User::grantPermission(PERM_SHOW_CLIENTS);
        User::grantPermission(PERM_ADD_CLIENT);
        User::grantPermission(PERM_DELETE_CLIENT);
        User::grantPermission(PERM_UPDATE_CLIENT);
        User::grantPermission(PERM_SEARCH_CLIENT);
        User::grantPermission(PERM_TRANSACTIONS);
        User::grantPermission(PERM_MANAGE_USERS);
    }
}
