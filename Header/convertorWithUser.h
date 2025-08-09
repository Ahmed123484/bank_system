#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"userInfo.h"
using namespace std ;
using namespace userInfo ;
namespace convertorWithUser {
    class clConvertorWithUser {
      private :
      vector<clUserInfo> users;
      public:
        // methods
        clUserInfo createUserFromWords(const vector<string>& words, clUserInfo userInfo);
        vector<string> parseLineToWords(const string& line);
        void validateUserData(const vector<string>& words);
        static vector<string> getWordsFromLine(const string& line);
        
        clUserInfo convertorWithUser(const string& line, clUserInfo userInfo);
        static string convertorDetailsToString(clUserInfo userInfo , string dim );
        // setters
        void setUsers(vector<clUserInfo> users);
        // getters
        vector<clUserInfo> getUsers();  
    };
}
