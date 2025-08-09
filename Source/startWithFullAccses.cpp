#include "../headers/startWithFullAccses.h"
namespace fullAcc {
clStartFullAcc::clStartFullAcc(clScreenLogin sl, string USPath, string clPath, vector<clUserInfo> aLLUsers, 
                                 clClientInfo nClient, vector<clClientInfo> allClients, string accNumber)
    : screenLogin(sl), userPath(USPath), clientPath(clPath), users(aLLUsers), newClient(nClient), clients(allClients), accountNumber(accNumber) {}
// setter implementations
void clStartFullAcc::setScreenLogin(const clScreenLogin& sl) {
    screenLogin = sl;
}
void clStartFullAcc::setUserPath(const string& userPath) {
    this->userPath = userPath;
}
void clStartFullAcc::setClientPath(const string& clientPath) {
    this->clientPath = clientPath;
}
void clStartFullAcc::setUsers(const vector<clUserInfo>& users) {
    this->users = users;
}
void clStartFullAcc::setNewClient(const clClientInfo& newClient) {
    this->newClient = newClient;
}
void clStartFullAcc::setClients(const vector<clClientInfo>& clients) {
    this->clients = clients;
}
void clStartFullAcc::setAccountNumber(const string& accountNumber) {
    this->accountNumber = accountNumber;
}
// getter implementations
clScreenLogin clStartFullAcc::getScreenLogin() const {
    return screenLogin;
}
string clStartFullAcc::getUserPath() const {
    return userPath;
}
string clStartFullAcc::getClientPath() const {
    return clientPath;
}
vector<clUserInfo> clStartFullAcc::getUsers() const {
    return users;
}
clClientInfo clStartFullAcc::getNewClient() const {
    return newClient;
}
vector <clClientInfo> clStartFullAcc::getClients() const {
    return clients;
}
string clStartFullAcc::getAccountNumber() const {
    return accountNumber;
}
// main function to start the application
void clStartFullAcc::start() {
    permission::User usere(0);
    bool isLoggedIn {false};
    int count {0};
    while (count < 3) {
        screenLogin.login();
            if (screenLogin.validateUser(users, screenLogin.getUsername(), screenLogin.getPassword())) {
                while (true){
                    clStartApp::startApplication();
                    accountNumber = screenLogin.getAccountNumber() ;
                    for (auto &user : users) {
                        if (user.getAccountNumber() == accountNumber) {
                            usere.setPermissions(user.getUserPermission());
                        }
                    }
                    short choice ;
                    cin >> choice ;
                    if (choice == 1){
                        if (usere.hasPermission(PERM_SHOW_CLIENTS)){
                            clStartApp::showClients();
                        }
                        else {
                            cout << "You do not have permission to view clients." << endl;
                        }
                    }
                    else if (choice == 2){
                        if (usere.hasPermission(PERM_ADD_CLIENT)){
                            clStartApp::addNewClient(clients, newClient);
                            system("pause");
                        }
                        else {
                            cout << "You do not have permission to add clients." << endl;
                        }
                        
                    }
                    else if (choice == 3){
                        if (usere.hasPermission(PERM_DELETE_CLIENT)){
                            clStartApp::deleteClient(clients , clientPath);
                            system("pause");
                        }
                        else {
                            cout << "You do not have permission to delete clients." << endl;
                        }
                    
                    }
                    else if (choice == 4){
                        if (usere.hasPermission(PERM_UPDATE_CLIENT)){
                            string accNumber;
                            cout << "Enter client account number to update: ";
                            cin >> accNumber;
                            clStartApp::updateClient(clients, clientPath, accNumber);
                            system("pause"); // Pause to update client
                        }
                        else {
                            cout << "You do not have permission to update clients." << endl;
                        }
                    }
                    else if (choice == 5){
                        if (usere.hasPermission(PERM_SEARCH_CLIENT)){
                            string accNumber ;
                            cout << "Enter client account number: " ;
                            cin >> accNumber ;
                            clStartApp::searchClient(clients , accNumber);
                            system("pause"); // Pause to search client
                        }
                        else {
                            cout << "You do not have permission to search clients." << endl;
                        }
                    }
                    else if (choice == 6){
                        if (usere.hasPermission(PERM_TRANSACTIONS)){
                            cout << accountNumber << endl;
                            for (auto &client : clients) {
                                if (client.getClientAccountNumber() == accountNumber) {
                                    clStartApp::transactions(clients , clientPath , accountNumber , client);
                                    break;
                                }
                            }
                        }
                        else {
                            cout << "You do not have permission to make transactions." << endl;
                        }
                    }
                    else if (choice == 7){
                        if (usere.hasPermission(PERM_MANAGE_USERS)){
                            clStartApp::manageUsers(users , userPath  ,usere.getPermissions());
                        }
                        else {
                            cout << "You do not have permission to manage users." << endl;
                        }
                    }
                    else if (choice == 8){
                        cout << "Exiting the application." << endl;
                        isLoggedIn = true;
                        break;
                    }
                    else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
            }
            } else {
               if (!screenLogin.validateUsername(users, screenLogin.getUsername())){
                    cout << "Invalid username . Please try again." << endl;
                }
                else if (!screenLogin.validatePassword(users, screenLogin.getUsername(), screenLogin.getPassword())) {
                    cout << "Invalid password . Please try again." << endl;
                }
                count++;
            }
            if (isLoggedIn) {
                break;
            }
        }

}

}
