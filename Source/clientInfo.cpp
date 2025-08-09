#include "../headers/clientInfo.h"
using namespace std;

// Function to set client information
namespace clientInfo {
    
    void clClientInfo::setClientInfo(const string& accountNumber, const string& pinCode, 
                                    const string& accountName, const string& phoneNumber, 
                                    const string& accountBalance) {
        clientInfo.clientAccountNumber = accountNumber;
        clientInfo.clientPinCode = pinCode;
        clientInfo.clientAccountName = accountName;
        clientInfo.clientPhoneNumber = phoneNumber;
        clientInfo.clientAccountBalance = accountBalance;
    }
    
    // Function to set client account number
    void clClientInfo::setClientAccountNumber(const string& accountNumber) {
        clientInfo.clientAccountNumber = accountNumber;
    }
    
    // Function to set client pin code
    void clClientInfo::setClientPinCode(const string& pinCode) {
        clientInfo.clientPinCode = pinCode;
    }
    
    // Function to set client account name
    void clClientInfo::setClientAccountName(const string& accountName) {
        clientInfo.clientAccountName = accountName;
    }
    
    // Function to set client phone number
    void clClientInfo::setClientPhoneNumber(const string& phoneNumber) {
        clientInfo.clientPhoneNumber = phoneNumber;
    }
    
    // Function to set client account balance
    void clClientInfo::setClientAccountBalance(const string& accountBalance) {
        clientInfo.clientAccountBalance = accountBalance;
    }
    
    // Function to get client account number
    string clClientInfo::getClientAccountNumber() const {
        return clientInfo.clientAccountNumber;
    }
    
    // Function to get client pin code
    string clClientInfo::getClientPinCode() const {
        return clientInfo.clientPinCode;
    }
    
    // Function to get client account name
    string clClientInfo::getClientAccountName() const {
        return clientInfo.clientAccountName;
    }
    
    // Function to get client phone number
    string clClientInfo::getClientPhoneNumber() const {
        return clientInfo.clientPhoneNumber;
    }
    
    // Function to get client account balance
    string clClientInfo::getClientAccountBalance() const {
        return clientInfo.clientAccountBalance;
    }
    
    // Function to display client information
    void clClientInfo::displayClientInfo() const {
        cout << "Client Account Number: " << clientInfo.clientAccountNumber << endl;
        cout << "Client Pin Code: " << clientInfo.clientPinCode << endl;
        cout << "Client Account Name: " << clientInfo.clientAccountName << endl;
        cout << "Client Phone Number: " << clientInfo.clientPhoneNumber << endl;
        cout << "Client Account Balance: " << clientInfo.clientAccountBalance << endl;
    }
}
