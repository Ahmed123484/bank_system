#include "../headers/screenManageUser.h"
namespace screenManageUser {
    void clScreenManageUser::printMainPageHeader () {
        cout << "============================================================"<< endl;
        cout << setw(40)<<"Manage Users Menu Screen" << endl ;
        cout << "============================================================" << endl ;
    }
    void clScreenManageUser::printMainPageFooter () {
        cout << setw(15)<<""<<"[1] list Users\n" ;
        cout << setw(15)<< ""<<"[2] Add new User \n" ;
        cout << setw(15)<<""<<"[3] Delete User \n" ;
        cout << setw(15)<<""<<"[4] update User Info\n";
        cout << setw(15)<<""<<"[5] Find User \n" ;
        cout << setw(15)<<""<<"[6] update User permission \n" ;
        cout << setw(15)<<""<<"[7] Main Home \n" ;
        cout << "============================================================" << endl ;

    }
}
