#pragma once
// Project: Screen Home Page
#include<iostream>
#include<vector>
#include<iomanip>
#include "clientInfo.h" // Assuming this is the header file for clClient
using namespace std;
using namespace clientInfo;
namespace screenShowClients {
class clScreenShowClients {
    public:   
    static void displayHeader(const vector<clClientInfo> &clients) ;
    static void displayHeaderWithOneClient(const clClientInfo &clients) ;
    static void displayFooter(const clClientInfo &clients) ;
    static void printVector ( const vector<clClientInfo> &client) ;
};
} // namespace screenTransactions
// End of file: include/screenTransactions.h
// This file defines the clScreenTransactions class which is responsible for displaying transaction-related screens and information.
// It includes methods for printing headers and footers for the transactions screen, as well as displaying a list of clients.