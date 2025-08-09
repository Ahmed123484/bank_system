#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "userInfo.h"
#include "convertorWithUser.h"
using namespace convertorWithUser;
using namespace userInfo;
using namespace std;

namespace operationsWithFileWithUser {
    class clOperationsWithFileWithUser {
    public:
        // Save single user
        static bool saveUser(const clUserInfo &userInfo, const string &fileName) ;
        // Save multiple users (replaces file content)
        static bool saveUsers(const vector<clUserInfo> &userInfos, const string &fileName);
        
        // Load users from file
        static vector<clUserInfo> loadUsers(const string &fileName);
        
        // Check if file exists
        static bool fileExists(const string &fileName) ;
    };
}
