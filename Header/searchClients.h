#pragma once 
#include <iostream>
#include <vector>
#include "clientInfo.h" // Assuming this is the header file for clClient
using namespace std;
using namespace clientInfo;
namespace searchClients {
    class clSearchClients {
        public:
        // Function to search for a client by account number
        static bool searchClientByAccountNumber(const vector<clClientInfo>& clients, const string& accountNumber) ;
        // Function to search for a client by name
        static bool searchClientByName(const vector<clClientInfo>& clients, const string& accountName) ;
        // function to display results of the search 
        static void displayResults (bool found, const string& searchType) ;


    };
} // namespace searchClients
