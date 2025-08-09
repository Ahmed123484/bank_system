#include "../headers/screenShowclients.h"
namespace screenShowClients {   
    void clScreenShowClients::displayHeader(const vector<clClientInfo> &clients) {
        cout << setw(45) << "Clients List (" << clients.size() << ")" << endl ;
        cout <<"-----------------------------------------------------------------------------------------"<<endl ;
        cout << '|' <<setw(15)<< "Account Number   " << '|' << setw(8)<< "Pin Code        "
        << '|' << setw(12) << "Client Name            " << '|' << setw(10) << "Phone Number      "
        << '|' << setw(8)<< "Balance " << endl ;
        cout <<"-----------------------------------------------------------------------------------------"<<endl ;

    }
    void clScreenShowClients::displayHeaderWithOneClient(const clClientInfo &clients) {
        cout << setw(45) << "Clients List (" << 1 << ")" << endl ;
        cout <<"-----------------------------------------------------------------------------------------"<<endl ;
        cout << '|' <<setw(15)<< "Account Number   " << '|' << setw(8)<< "Pin Code        "
        << '|' << setw(12) << "Client Name            " << '|' << setw(10) << "Phone Number      "
        << '|' << setw(8)<< "Balance " << endl ;
        cout <<"-----------------------------------------------------------------------------------------"<<endl ;

    }

    void clScreenShowClients::displayFooter(const clClientInfo &clients) {
        cout << '|' << clients.getClientAccountNumber() <<setw(18 - static_cast<int>(clients.getClientAccountNumber().size()))
        <<"|" << clients.getClientPinCode() <<setw(17 - static_cast<int>(clients.getClientPinCode().size())) <<"|"
        <<clients.getClientAccountName() << setw(24- static_cast<int>(clients.getClientAccountName().size()))
        <<"|" <<clients.getClientPhoneNumber() <<setw(19-static_cast<int>(clients.getClientPhoneNumber().size()))
        <<"|"<<clients.getClientAccountBalance() <<endl ;

    }

    void clScreenShowClients::printVector ( const vector<clClientInfo> &client) {
        displayHeader(client);
        for (auto &cl : client) {
            displayFooter(cl);
        }
    }
} // namespace screenTransactions
