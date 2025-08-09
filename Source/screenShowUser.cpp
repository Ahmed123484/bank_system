#include "../headers/screenShowUser.h"
namespace screenShowUser {
        void clScreenShowUser::displayHeaderPage(const vector<clUserInfo> &users) {
            cout << setw(45) << "Users List (" << users.size() << ")" << endl ;
            cout <<"-----------------------------------------------------------------------------------------"<<endl ;
        }

        void clScreenShowUser::displayHeader() {
            cout << '|' <<setw(15)<< " User Name  " << '|' << setw(8)<< " User password "
            << '|' << setw(12) << " User permission "<< '|' <<setw(12) <<"User account number " << endl ;
            cout <<"-----------------------------------------------------------------------------------------"<<endl ;
        }

        void clScreenShowUser::displayFooter(const clUserInfo &users) {
                cout << '|'
                << left << setw(15) << users.getUserName() << '|'
                << left << setw(15) << users.getUserPassword() << '|'
                << left << setw(17) << users.getUserPermission() << '|'
                << left << setw(20) << users.getAccountNumber() 
                << endl;
        }


        void clScreenShowUser::printVector ( const vector<clUserInfo>&users) {
            displayHeaderPage(users);
            displayHeader();
            for (auto &user : users) {
                displayFooter(user);
            }
        }
}
