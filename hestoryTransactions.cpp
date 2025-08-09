#include "../headers/hestoryTransactions.h"
namespace historyTransactions {
           // sets the transaction details
            void clHistoryTransactions::addTransaction(int id, const string& type, double amt) {
                stTransaction newTransaction;
                newTransaction.transactionId = id;
                newTransaction.transactionType = type;
                newTransaction.amount = amt;
                newTransaction.timestamp = time(nullptr); // Current time
                transactions.push_back(newTransaction);
            }
            // set the transaction ID
            void clHistoryTransactions::setTransactionId(int id, int index) {
                if (index >= 0 && index < transactions.size()) {
                    transactions[index].transactionId = id;
                } else {
                    cout << "Invalid transaction index." << endl;
                }
            }
            // set the transaction type
            void clHistoryTransactions::setTransactionType(const string& type, int index) {
                if (index >= 0 && index < transactions.size()) {
                    transactions[index].transactionType = type;
                } else {
                    cout << "Invalid transaction index." << endl;
                }
            }
            // set the transaction amount
            void clHistoryTransactions::setTransactionAmount(double amt, int index) {
                if (index >= 0 && index < transactions.size()) {
                    transactions[index].amount = amt;
                } else {
                    cout << "Invalid transaction index." << endl;
                }
            }
            // set the transaction timestamp
            void clHistoryTransactions::setTransactionTimestamp(time_t ts, int index) {
                if (index >= 0 && index < transactions.size()) {
                    transactions[index].timestamp = ts;
                } else {
                    cout << "Invalid transaction index." << endl;
                }
            }
            // Gets the transaction ID
            int clHistoryTransactions::getTransactionId(int index) const {
                if (index >= 0 && index < transactions.size()) {
                    return transactions[index].transactionId;
                } else {
                    cout << "Invalid transaction index." << endl;
                    return -1; // Indicating an error
                }
            }
            // Gets the transaction type
            string clHistoryTransactions::getTransactionType(int index) const {
                if (index >= 0 && index < transactions.size()) {
                    return transactions[index].transactionType;
                } else {
                    cout << "Invalid transaction index." << endl;
                    return ""; // Indicating an error
                }
            }
            // Gets the transaction amount
            double clHistoryTransactions::getTransactionAmount(int index) const {
                if (index >= 0 && index < transactions.size()) {
                    return transactions[index].amount;
                } else {
                    cout << "Invalid transaction index." << endl;
                    return -1.0; // Indicating an error
                }
            }
            // Gets the transaction timestamp
            time_t clHistoryTransactions::getTransactionTimestamp(int index) const {
                if (index >= 0 && index < transactions.size()) {
                    return transactions[index].timestamp;
                } else {
                    cout << "Invalid transaction index." << endl;
                    return -1; // Indicating an error
                }
            }
            // Gets the total structure of transactions
            vector<clHistoryTransactions::Transaction> clHistoryTransactions::getAllTransactions() const {
                return transactions;
            }
} // namespace historyTransactions
