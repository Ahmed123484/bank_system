#include "../headers/screenHomePage.h"
namespace screenHomePage {
    // Function to display the home page
     void clScreenHomePage::printMainPageHeader () {
        cout << "-------------------------------------------------------"<< endl;
        cout << setw(30)<<"Main Page" << endl ;
        cout << "--------------------------------------------------------" << endl ;
    }
    void clScreenHomePage::printMainPageFooter () {
        cout << setw(15)<<""<<"[1] Show client list \n" ;
        cout << setw(15)<< ""<<"[2] Add new client \n" ;
        cout << setw(15)<<""<<"[3] Delete client \n" ;
        cout << setw(15)<<""<<"[4] update client Info\n";
        cout << setw(15)<<""<<"[5] search client \n" ;
        cout << setw(15)<<""<<"[6] transactions \n" ;
        cout << setw(15)<<""<<"[7] Mange Users \n" ;
        cout << setw(15)<<""<<"[8] Exit \n" ;
        cout << "--------------------------------------------------------" << endl ;

    }   
}
