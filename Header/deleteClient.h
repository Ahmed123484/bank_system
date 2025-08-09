#pragma once
#include <iostream>
#include <vector>
#include"clientInfo.h" // Assuming this is the header file for clClient
#include "userInfo.h"
using namespace std;
using namespace userInfo;
using namespace clientInfo;
namespace deleteClientAndUser {
    class clDeleteClientAndUser {
        public:
            // Constructor
            clDeleteClientAndUser();
            // Function to delete a client by account number
            static bool deleteClientByAccountNumber(vector<clClientInfo>& clients, const string& accountNumber);
            static bool deleteClientByAccountName(vector<clClientInfo>& Clients, const string& accountName);
            static bool deleteUserByAccountName(vector<clUserInfo>& users, const string& accountNumber);
    };
}
