#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"userPermision.h"
using namespace std;

namespace userInfo {
    class clUserInfo {
        private :
           struct stUserInfo{
               string userName;
               string userPassword;
               int userPermission;
               string accountNumber;
           };
           public:
           stUserInfo userInfo;
           clUserInfo() = default;
    
              // Function to set user information
              void setUserInfo(const string& name, const string& password = "", int permission = 0 , const string& accountNumber = "") ;
              // Function to set user name
              void setUserName(const string& name);
                // Function to set user password
              void setUserPassword(const string& password) ;
              // Function to set user permission
              void setUserPermission(int permission);
              // Function to set user account number
              void setAccountNumber(const string& accountNumber) ;
              // Function to get user name
              string getUserName() const ;
              // Function to get user password
              string getUserPassword() const ;
                // Function to get user permission
                int getUserPermission() const ;
                // Function to get user account number
                string getAccountNumber() const ;
              // Function to display user information
              void displayUserInfo() const;
              void askAndGrant(const string &desc, int permCode, permission::User &usere) ;
              void updateUserPermission(vector <clUserInfo> &users , int permission);
              void updateOneUserPermission(vector <clUserInfo> &users , string userName)  ;
    };
}
