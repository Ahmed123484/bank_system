#pragma once
#include "startApp.h"
#include "screenLogin.h"
#include "userInfo.h"
#include "convertorWithUser.h"
#include "operationsWithFileWithUser.h"
#include "operationsWithFileWIthClients.h"
#include "clientInfo.h"
#include "screenManageUser.h"
#include "userPermision.h"
#include "transactionsWithAcc.h"
using namespace transactionsWithAcc;
using namespace clientInfo;
using namespace operationsWithFile;
using namespace startApp;
using namespace userInfo;
using namespace convertorWithUser;
using namespace operationsWithFileWithUser;
using namespace screenLogin;
using namespace permission ;

namespace withTran {
class clStartWithTran{
    private :
    clScreenLogin screenLogin;
    string userPath ;
    string clientPath ;
    vector<clUserInfo> users ;
    clClientInfo newClient;
    vector<clClientInfo> clients ;
    string accountNumber ;
    public:
    clStartWithTran (clScreenLogin sl , string USPath , string clPath , vector<clUserInfo> aLLUsers , clClientInfo nClient ,
    vector<clClientInfo> allClients , string accNumber );
    // setter 
    void setScreenLogin(const clScreenLogin& sl);
    void setUserPath(const string& userPath);
    void setClientPath(const string& clientPath);
    void setUsers(const vector<clUserInfo>& users);
    void setNewClient(const clClientInfo& newClient);
    void setClients(const vector<clClientInfo>& clients);
    void setAccountNumber(const string& accountNumber);
    // getter
    clScreenLogin getScreenLogin() const;
    string getUserPath() const;
    string getClientPath() const;
    vector<clUserInfo> getUsers() const;
    clClientInfo getNewClient() const;
    vector<clClientInfo> getClients() const;
    string getAccountNumber() const;
    // main function to start the application
    void start();

    };
}