#include "../headers/startWithTran.h"
namespace withTran {
clStartWithTran::clStartWithTran(clScreenLogin sl, string USPath, string clPath, vector<clUserInfo> aLLUsers, 
                                 clClientInfo nClient, vector<clClientInfo> allClients, string accNumber)
    : screenLogin(sl), userPath(USPath), clientPath(clPath), users(aLLUsers), newClient(nClient), clients(allClients), accountNumber(accNumber) {}
// setter implementations
void clStartWithTran::setScreenLogin(const clScreenLogin& sl) {
    screenLogin = sl;
}
void clStartWithTran::setUserPath(const string& userPath) {
    this->userPath = userPath;
}
void clStartWithTran::setClientPath(const string& clientPath) {
    this->clientPath = clientPath;
}
void clStartWithTran::setUsers(const vector<clUserInfo>& users) {
    this->users = users;
}
void clStartWithTran::setNewClient(const clClientInfo& newClient) {
    this->newClient = newClient;
}
void clStartWithTran::setClients(const vector<clClientInfo>& clients) {
    this->clients = clients;
}
void clStartWithTran::setAccountNumber(const string& accountNumber) {
    this->accountNumber = accountNumber;
}
// getter implementations
clScreenLogin clStartWithTran::getScreenLogin() const {
    return screenLogin;
}
string clStartWithTran::getUserPath() const {
    return userPath;
}
string clStartWithTran::getClientPath() const {
    return clientPath;
}
vector<clUserInfo> clStartWithTran::getUsers() const {
    return users;
}
clClientInfo clStartWithTran::getNewClient() const {
    return newClient;
}
vector <clClientInfo> clStartWithTran::getClients() const {
    return clients;
}
string clStartWithTran::getAccountNumber() const {
    return accountNumber;
}
// main function to start the application
void clStartWithTran::start() {
    permission::User usere(0);
    bool isLoggedIn {false};
    int count {0};
    while (count < 3) {
        screenLogin.login();
            if (screenLogin.validateUser(users, screenLogin.getUsername(), screenLogin.getPassword())) {
                    accountNumber = screenLogin.getAccountNumber() ;
                    for (auto &user : users) {
                        if (user.getAccountNumber() == accountNumber) {
                            usere.setPermissions(user.getUserPermission());
                        }
                    }
                    clStartApp::transactionsOnly(clients,clientPath,accountNumber,newClient);
                    isLoggedIn = true ;
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