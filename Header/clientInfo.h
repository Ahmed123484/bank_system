#pragma once
// Project: Client Information
#include <iostream>
#include <string>
namespace  clientInfo 
 {
    
    class clClientInfo {
    private:
        struct stClientInfo {
            std::string clientAccountNumber;
            std::string clientPinCode;
            std::string clientAccountName;
            std::string clientPhoneNumber;
            std::string clientAccountBalance;
        };
    
    public:
        stClientInfo clientInfo;
        
        // Constructor
        clClientInfo() = default;
        
        // Function to set client information
        void setClientInfo(const std::string& accountNumber, const std::string& pinCode, 
                          const std::string& accountName, const std::string& phoneNumber, 
                          const std::string& accountBalance);
        
        // Individual setters
        void setClientAccountNumber(const std::string& accountNumber);
        void setClientPinCode(const std::string& pinCode);
        void setClientAccountName(const std::string& accountName);
        void setClientPhoneNumber(const std::string& phoneNumber);
        void setClientAccountBalance(const std::string& accountBalance);
    
        // Getters
        std::string getClientAccountNumber() const;
        std::string getClientPinCode() const;
        std::string getClientAccountName() const;
        std::string getClientPhoneNumber() const;
        std::string getClientAccountBalance() const;
        
        // Display function
        void displayClientInfo() const;
    };
}
