#pragma once
#include <iostream>
using namespace std;
enum Permissione {
    PERM_LIST_USERS       = 1 << 0,   // 000000000001
    PERM_ADD_USER         = 1 << 1,   // 000000000010
    PERM_DELETE_USER      = 1 << 2,   // 000000000100
    PERM_UPDATE_USER      = 1 << 3,   // 000000001000
    PERM_FIND_USER        = 1 << 4,   // 000000010000
    PERM_SHOW_CLIENTS     = 1 << 5,   // 000000100000
    PERM_ADD_CLIENT       = 1 << 6,   // 000001000000
    PERM_DELETE_CLIENT    = 1 << 7,   // 000010000000
    PERM_UPDATE_CLIENT    = 1 << 8,   // 000100000000
    PERM_SEARCH_CLIENT    = 1 << 9,   // 001000000000
    PERM_TRANSACTIONS     = 1 << 10,  // 010000000000
    PERM_MANAGE_USERS     = 1 << 11   // 100000000000
};
namespace permission {
class User {
private:
    int permissions = 0; // رقم يحتوي كل الصلاحيات
public:
    // constructor
    User(int initialPermissions );
    // إعداد صلاحية
    void grantPermission(int perm) ;

    // إزالة صلاحية
    void revokePermission(int perm);

    // التحقق من صلاحية
    bool hasPermission(int perm) const ;

    int getPermissions() const ;

    void setPermissions(int perm) ;

    void displayPermissions() const ;
    // Function to ask for permission
    void askPermission()const ;
    // function to ask delete permission
    void askDeletePermission() const;
    void askAndGrant(const string &desc, int permCode, User &usere) ;
    int addAndAskkpermissonUser();
    void addAllPermissionUser();
};
}
