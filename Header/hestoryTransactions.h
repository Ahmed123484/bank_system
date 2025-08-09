#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
using namespace std;
namespace historyTransactions {
    class clHistoryTransactions {
        private:
    struct stTransaction {
                // Define the structure for a transaction
                int transactionId; // Unique identifier for the transaction
                string transactionType;
                double amount;
                time_t timestamp;
            };            
            vector<stTransaction> transactions;
            stTransaction transaction;
            public:
            // Define the type alias
            using Transaction = stTransaction;

            // Constructor
            clHistoryTransactions() = default;
           // sets the transaction details
            void addTransaction(int id, const string& type, double amt);
            // set the transaction ID
            void setTransactionId(int id, int index) ;
            // set the transaction type
            void setTransactionType(const string& type, int index) ;
            // set the transaction amount
            void setTransactionAmount(double amt, int index);
            // set the transaction timestamp
            void setTransactionTimestamp(time_t ts, int index);
            // Gets the transaction ID
            int getTransactionId(int index) const ;
            // Gets the transaction type
            string getTransactionType(int index) const;
            // Gets the transaction amount
            double getTransactionAmount(int index) const ;
            // Gets the transaction timestamp
            time_t getTransactionTimestamp(int index) const;
            // Gets the total structure of transactions
            vector<stTransaction> getAllTransactions() const ;
            // Displays all transactions
            void displayTransactions() const ;
    };
} // namespace historyTransactions
