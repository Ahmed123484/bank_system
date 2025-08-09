#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<sstream>
#include "clientInfo.h" // Assuming this is the header file for clClient
#include "convertorWithClients.h"
using namespace convertorWithClients;
using namespace std;
using namespace clientInfo;
namespace operationsWithFile {
    class clOperationsWithFile {
        public:
            // Function to save client information to a file
            static void saveClientInfoToFile(const vector<clClientInfo>& clients, const string& filename) ;
            // Function to load client information from a file
            static vector<clClientInfo> loadClientInfoFromFile(const string& filename) ;
         
    };

}
