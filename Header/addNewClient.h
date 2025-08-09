#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"clientInfo.h" // Assuming this is the header file for clClient
using namespace std;
using namespace clientInfo;
namespace addNewClient {
    class clAddNewClient{
        private :
        clClientInfo &newClient ;
        vector<clClientInfo> &clients ;
        public:
            // constructor
            clAddNewClient(clClientInfo &newClient, vector<clClientInfo> &clients);
            // setter
            void setClientAccountNumber(string &accountNumber);
            void setClientPinCode(string &pinCode);
            void setClientAccountName(string &accountName);
            void setClientPhoneNumber(string &phoneNumber);
            void setClientAccountBalance(string &accountBalance);
            void setAllClientInfo(string &accountNumber, string &pinCode, string &accountName, string &phoneNumber, string &accountBalance);
            // getter
            string getClientAccountNumber();
            string getClientPinCode();
            string getClientAccountName();
            string getClientPhoneNumber();
            string getClientAccountBalance();
            clClientInfo &getClientInfo();
            // add client in vector
            void addClientInVector();
            // add new client
            void addNewClient();
            //display info
            void displayClientInfo();
            // confirmation
            bool confirmation();

    };
}
