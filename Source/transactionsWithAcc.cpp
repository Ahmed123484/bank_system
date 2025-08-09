#include "../headers/transactionsWithAcc.h"
namespace transactionsWithAcc {
    // Constructor
    clTransactionsWithAcc::clTransactionsWithAcc(clClientInfo client , vector<clClientInfo> accounts) : clientInfo(client) , clientAccounts(accounts) {}

    // Add accounts to the vector (you'll need this)
    void clTransactionsWithAcc::addAccount(const clClientInfo& account) {
    clientAccounts.push_back(account);
    }
    // Check if account exists
    bool clTransactionsWithAcc::checkClientAccountExists(const string& accountNumber) {
    return findAccount(accountNumber) != nullptr;
    }

    // Deposit money
    bool clTransactionsWithAcc::depositMoney(const string& accountNumber, double amount) {
    if (amount <= 0) {
        cout << "Invalid deposit amount." << endl;
        return false;
    }

    clClientInfo* account = findAccount(accountNumber);
    if (account == nullptr) {
        cout << "Account not found." << endl;
        return false;
    }

    double currentBalance = getAccountBalance(*account);
    double newBalance = currentBalance + amount;
    setAccountBalance(*account, int(newBalance));

    cout << "Deposit successful. New balance: " << newBalance << endl;
    return true;
    }

    // Withdraw money
    bool clTransactionsWithAcc::withdrawMoney(const string& accountNumber, double amount) {
    if (amount <= 0) {
        cout << "Invalid withdrawal amount." << endl;
        return false;
    }

    clClientInfo* account = findAccount(accountNumber);
    if (account == nullptr) {
        cout << "Account not found." << endl;
        return false;
    }

    double currentBalance = getAccountBalance(*account);
    if (currentBalance < amount) {
        cout << "Insufficient funds for withdrawal." << endl;
        return false;
    }

    double newBalance = currentBalance - amount;
    setAccountBalance(*account, newBalance);

    cout << "Withdrawal successful. New balance: " << newBalance << endl;
    return true;
    }
    // quick withdraw
    bool clTransactionsWithAcc::quickWithdraw(const string & accountNumber ){
        cout << "=====================================\n";
        cout << setw(25) << "Quick withdraw\n";
        cout << "=====================================\n";
        cout <<  "[1] 20 " << setw(11) << "[2] 50 \n";
        cout <<  "[3] 100 " << setw(10) << "[4] 200 \n";
        cout <<  "[5] 400 " << setw(10) << "[6] 600 \n";
        cout <<  "[7] 800 " << setw(10) << "[8] 1000 \n";
        cout <<  "[9] Exit\n";
        cout << "=====================================\n";
        double arr[8] = {20,50,100,200,400,600,800,1000};
        clClientInfo* account = findAccount(accountNumber);
        if (account == nullptr) {
        cout << "Account not found." << endl;
        return false;
        }
        cout << "Your Balance is :" << account->getClientAccountBalance() << endl;
        cout << "Pls choose what to withdraw form [1] to [8] ? " ;
        short input ;
        cin >> input ;
        if (input >= 1 && input <=8){
            if (withdrawMoney(accountNumber ,arr[input-1])){
                return true ;
            }
            
        }
        else if (input == 9){
            return false ;
        }
        else {
            cout << "Wrong input\n";
            return false ;
        }
        return false ;
    }
    // Get total balance
    double clTransactionsWithAcc::getTotalBalance() const {
    double totalBalance = 0;
    for (const auto& account : clientAccounts) {
        totalBalance += getAccountBalance(account);
    }
    return totalBalance;
    }

    // Get account count
    size_t clTransactionsWithAcc::getAccountCount() const {
    return clientAccounts.size();
    }
    // get vector 
    vector<clClientInfo> clTransactionsWithAcc::getClientAccounts() const {
    return clientAccounts;
    }

}
