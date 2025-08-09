#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "clientInfo.h"

using namespace std;
using namespace clientInfo;

namespace transactionsWithAcc {
    class clTransactionsWithAcc {
    private:
        clClientInfo clientInfo;
        vector<clClientInfo> clientAccounts;
        // Helper function: Find account by number (returns pointer or nullptr)
        clClientInfo* findAccount(const string& accountNumber) {
            for (auto& account : clientAccounts) {
                if (account.getClientAccountNumber() == accountNumber) {
                    return &account; // Return pointer to found account
                }
            }
            return nullptr; // Account not found
        }
        // Helper function: Get balance as double
        double getAccountBalance(const clClientInfo& account) const {
            return stod(account.getClientAccountBalance());
        }
        // Helper function: Set balance from double
        void setAccountBalance(clClientInfo& account, double balance) {
            account.setClientAccountBalance(to_string(int(balance)));
        }
    public:
        // Constructor
        clTransactionsWithAcc(clClientInfo client , vector<clClientInfo> accounts) ;
        // Add accounts to the vector (you'll need this)
        void addAccount(const clClientInfo& account) ;
        // Check if account exists
        bool checkClientAccountExists(const string& accountNumber) ;
        // Deposit money
        bool depositMoney(const string& accountNumber, double amount) ;
        // Withdraw money
        bool withdrawMoney(const string& accountNumber, double amount) ;
        // quick withdraw money
        bool quickWithdraw (const string & accountNumber) ;
        // Get total balance
        double getTotalBalance() const ;
        // Get account count
        size_t getAccountCount() const ;
        // get vector 
        vector<clClientInfo> getClientAccounts() const ;
    };
}
