#include "../headers/hestoryTransactions.h"
using namespace std;
namespace historyTransactions {
           // sets the transaction details
            // Displays all transactions
            void clHistoryTransactions::displayTransactions() const {
                cout << "-------------------------------------------------------" << endl;
                cout << setw(30) << "Transaction History" << endl;
                cout << "-------------------------------------------------------" << endl;
                for (const auto& transaction : transactions) {
                    cout << "ID: " << transaction.transactionId 
                         << ", Type: " << transaction.transactionType 
                         << ", Amount: " << fixed << setprecision(2) << transaction.amount 
                         << ", Date: " << ctime(&transaction.timestamp);
                }
                cout << "-------------------------------------------------------" << endl;
            }
    
} // namespace historyTransactions
