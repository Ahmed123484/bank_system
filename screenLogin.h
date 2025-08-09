#pragma once
#include <iostream>
#include <vector>
#include"userInfo.h"
using namespace std;
using namespace userInfo;
namespace screenLogin {
    class clScreenLogin {
      private:
      string username;
      string password;
      string accountNumber;
      public:
        void login();
        bool validateUser(const vector<clUserInfo>& users, const string& username, const string& password) ; 
        // setters
        void setUsername(const string& name) ;
        void setPassword(const string& password) ;
        void setAccountNumber(const string& accountNumber) ;
        // getters
        string getUsername() const ;
        string getPassword() const ;
        string getAccountNumber() const ;
        // display user information
        void displayUserInfo() ; 
        bool userExists(const vector<clUserInfo>& users, const string& username) ;
        bool validatePassword(const vector<clUserInfo>& users, const string& username, const string& password) ;
        bool validateUsername(const vector<clUserInfo>& users, const string& username) ;
    };
}