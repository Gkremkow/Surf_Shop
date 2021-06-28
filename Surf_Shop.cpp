// Surf_Shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype> //allows the use of toupper() and tolower()

using namespace std;



//A function, when called, will re-display this first block of text explaining all the commands.
void ShowUsage() {
    cout << "\nTo show program usage \'S\'" << endl;
    cout << "To purchase a surfboard press \'p\'" << endl;
    cout << "To display current purchases press \'C'" << endl;
    cout << "To display total amount due press \'T\'" << endl;
    cout << "To quit the program press \'Q\'" ;
}

//A function, when called, will store the number and type of surfboards the user wishes to purchase.
void MakePurchase(int& iTotalXXXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge) {
    //Establishes local variables to be modified by user input.
    int boardNum = 0;
    char boardType = ' ';
    //Prompts the user for their input and accepted options.
    cout << "\nPlease enter the quantity and type (X=XXXS, S=Small, M=medium, L=large) of the surfboard you would like to purchase: ";
    if (cin >> boardNum) {
        //Nothing to happen if call is good.
    } else {
        //Will alert the user of their invalid entry and will terminate the program to prevent security errors.
        cout << "Invalid number of boards. Exiting Program." << endl;
        system("pause");
        exit(-1);
    }
    //User input for board type and converted to uppercase for ease of comparison.
    cin >> boardType;
    boardType = toupper(boardType);
    if (boardType == 'X') {
        iTotalXXXS = iTotalXXXS + boardNum;
    }else if (boardType == 'S') {
        iTotalSmall = iTotalSmall + boardNum;
    }
    else if (boardType == 'M') {
        iTotalMedium = iTotalMedium + boardNum;
    }
    else if (boardType == 'L') {
        iTotalLarge = iTotalLarge + boardNum;
    }
    else {
        //Exits program upon improper board type entry after alerting the user
        cout << "Invalid board type entered. Exiting Program." << endl;
        system("pause");
        exit(-1);
    }


}
//A function to display the total number of surfboards that are currently in the user's cart, broken up into their individual numbers.
void DisplayPurchase(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {
    if (iTotalXXXS == 0 and iTotalSmall == 0 and iTotalMedium == 0 and iTotalLarge == 0) {
        cout << "No purchases made yet.";
    }
    else {
        if (iTotalXXXS > 0) {
            cout << "The total number of XXXS surfboards is " << iTotalXXXS << endl;
        }
        if (iTotalSmall > 0) {
            cout << "The total number of small surfboards is " << iTotalSmall << endl;
        }
        if (iTotalMedium > 0) {
            cout << "The total number of medium surfboards is " << iTotalMedium << endl;
        }
        if (iTotalLarge > 0) {
            cout << "The total number of large surfboards is " << iTotalLarge << endl;
        }
    }
}
//Alerts the user of the number of each board, when called, the price of each group and the total price overall.
void DisplayTotal(const int iTotalXXXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge) {
    //Local constant variables to establish board prices.
    const double XXXSPRICE = 20.00;
    const double SMALLPRICE = 175.00;
    const double MEDPRICE = 190.00;
    const double LARGEPRICE = 200.00;

    //Local variables established for ease of reuse and only have to change price here should things change.
    double totalXXXS = iTotalXXXS * XXXSPRICE;
    double totalSmall = iTotalSmall * SMALLPRICE;
    double totalMed = iTotalMedium * MEDPRICE;
    double totalLarge = iTotalLarge * LARGEPRICE;
    //Alerts the user of no purchases yet, or displayes number of boards and their costs along with the total price.
    if (iTotalXXXS == 0 and iTotalSmall == 0 and iTotalMedium == 0 and iTotalLarge == 0) {
        cout << "No purchases made yet.";
    }
    else {
        if (iTotalXXXS > 0) {
            cout << "The total number of XXXS surfboards is " << iTotalXXXS << " at a total of $" << totalXXXS << endl;
        }
        if (iTotalSmall > 0) {
            cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << totalSmall << endl;
        }
        if (iTotalMedium > 0) {
            cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << totalMed << endl;
        }
        if (iTotalLarge > 0) {
            cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << totalLarge << endl;
        }
        cout << "Amount due: $" << totalXXXS + totalSmall + totalMed + totalLarge;
    }
}




int main()
{  
    //Sets to display two decimal places always for monitary concerns.
    cout << setprecision(2) << fixed;
    //Establishes the variables for the number of large, medium, and small surfboards in the main function to be referenced by all other functions.
    int iTotalXXXS = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    char userAnswer = ' ';

    //Top intro message
    cout << setfill('*') << setw(60) << '*' << endl;
    cout << setw(5) << "" << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << "" << endl;
    cout << setfill('*') << setw(60) << '*' << endl << endl;

    //First call of ShowUsage to explain the program to the user
    ShowUsage();
    
    //As long as the user doesn't enter Q it will infinately loop through this part of the program, prompting for user entry
    while (userAnswer != 'Q') {
        cout << "\n\nPlease enter selection: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);
        if (userAnswer == 'P') {
            //Calls our MakePurchase function using the local variables as the input arguements
            MakePurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
        }
        if (userAnswer == 'C') {
            //Calls our DisplayPurchase function using the local variables as the input arguements
            DisplayPurchase(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
        }
        if (userAnswer == 'T') {
            //Calls our DisplayTotal function using the local variables as the input arguements
            DisplayTotal(iTotalXXXS, iTotalSmall, iTotalMedium, iTotalLarge);
        }
        if (userAnswer == 'S') {
            //Calls the ShowUsage function to give the user the proper commands
            ShowUsage();
        }
    }

    //A thnk you message prior to the program ending
    cout << "Thank you!" << endl;
    system("pause");
    return 0;
}


