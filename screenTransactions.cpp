#include"../headers/screenTransactions.h"
namespace screenTransactions {
    void clScreenTransactions::printHeaderScreenTransactions () {
        cout << "-------------------------------------------------------"<< endl;
        cout << setw(30)<<"Transactions Menu Screen " << endl ;
        cout << "--------------------------------------------------------" << endl ;
    }
    void clScreenTransactions::printFooterScreenTransactions () {
        cout << setw(15)<<""<<"[1] Deposit\n" ;
        cout << setw(15)<< ""<<"[2] WithDraw \n" ;
        cout << setw(15)<<""<<"[3] TotalBalance \n" ;
        cout << setw(15)<<""<<"[4] Main Home Info\n";
        cout << "--------------------------------------------------------" << endl ;
    }  
       void clScreenTransactions::printFooter () {
        cout << setw(15)<< ""<<"[1] quick WithDraw \n" ;
        cout << setw(15)<< ""<<"[2] WithDraw \n" ;
        cout << setw(15)<<""<<"[3] Deposit\n" ;
        cout << setw(15)<<""<<"[4] TotalBalance \n" ;
        cout << setw(15)<<""<<"[5] Exit\n";
        cout << "--------------------------------------------------------" << endl ;
    }  
} 
