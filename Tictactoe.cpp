
#include <iostream>

using namespace std;

//display board
void board () {
    cout << "[ ] [ ] [ ]" << endl;
    cout << "[ ] [ ] [ ]" << endl;
    cout << "[ ] [ ] [ ]" << endl;


    }
//user choice for row
int choiceColumm (){

    int columm = 0;
    cout << "User's Turn" << endl;
    cout << "Choose a columm 0-1-2" << endl;
    cin >> columm;
    //Vaild number check
    if (columm != 0 && columm !=1 && columm != 2) {
        cout << "Invaild Number" << endl;
        cout << "Please enter agian" << endl;
        return 0;
        }

    return columm;
    }
//User choice for row
int choiceRow (){

    int row = 0;

    cout << "Choose a row 0-1-2" << endl;
    cin >> row;
    //Vaild number check
    if (row != 0 && row !=1 && row != 2) {
        cout << "Invaild Number" << endl;
        cout << "Please enter again" << endl;
        return 0;
        }


    return row;
    }


//Random number for columm
int computerTurnColumm(){
    int columm=0;

    columm =rand()%3; //generate random number

    return columm;
    }
//Random number for row
int computerTurnRow (){
    int row=0;

    row =rand()%3;

    return row;
    }


int main() {

    srand(time(NULL));
    int whoseTurn; //determine who starts first
    char metrix [3][3];
    int x= 0;
    int start;
    int columm = 0;
    int row = 0;

    //Initialize array
    for (int r =0; r <3 ; r++) {
        for (int l =0; l < 3; l ++) {
            metrix[l][r] = ' ';
            }
        }


    cout << "-----------------------WELCOME TO TIC TAC TOE--------------------\n";
    board();
    cout << "Press 1 to start" << endl;
    cin >> start;

    if (start == 1) {
        cout << "\t\t_-_-_-_-_-_-_ START! -_-_-_-_-_-_-_-_-_\n\n";
        cout << "Whose going first (0 for Computer) or press any number \n\n";
        cin >> whoseTurn;

        if (whoseTurn == 0) {
            cout << "Computer will start first\n";
            columm = computerTurnColumm();
            row = computerTurnRow();
            metrix [row][columm] = 'O';
            }
        else{
            cout << "User's Turn\n";
            }
        for (x = 0; x < 5; x++) {
            cout << "["<<  metrix [0][0] << "] ["<<metrix[0][1] << "] [" << metrix[0][2] << "]"<< endl;
            cout << "["<<  metrix [1][0] << "] ["<<metrix[1][1] << "] [" << metrix[1][2] << "]"<< endl;
            cout << "["<<  metrix [2][0] << "] ["<<metrix[2][1] << "] [" << metrix[2][2] << "]"<< endl;
            cout << "-----------------------" << endl;
            //Winner check for Computer
            //row check
            if (metrix[0][0]== 'O' && metrix [0][1]== 'O' && metrix [0][2] == 'O'){
                cout << "Lost!\n";
                return 0;
                }
            if (metrix[1][0]== 'O' && metrix [1][1]== 'O' && metrix [1][2] == 'O'){
                cout << "Lost!\n";
                return 0;
                }
            if (metrix[2][0]== 'O' && metrix [2][1]== 'O' && metrix [2][2] == 'O'){
                cout << "Lost!\n";
                return 0;
                }
            //Vertical Check
            if (metrix[0][0]== 'O' && metrix [1][0]== 'O' && metrix [2][0] == 'O'){
                cout << "Lost!\n";
                return 0;
                }
            if (metrix[0][1]== 'O' && metrix [1][1]== 'O' && metrix [2][1] == 'O'){
                cout << "Lost!\n";
                return 0;
                }
            //Cross Check
            if (metrix[0][0] == 'O' && metrix [1][1]== 'O' && metrix [2][2] == 'O'){
                cout << "Lost!\n";
                return 0;
                }
            if (metrix[0][2]== 'O' && metrix [1][1]== 'O' && metrix [2][0] == 'O'){
                cout << "Lost!\n";
                return 0;
                }
            if (x == 4) {
                cout << "Game Tie" << endl;
                return 0;
                }

            //Call out the row and columm choice fucntions
            columm = choiceColumm();
            row = choiceRow();

            //Check for availablity of space
            if (metrix[row][columm] == 'X' || metrix [row][columm] == 'O') {
                while (metrix[row][columm] == 'X' || metrix [row][columm] == 'O') {
                    cout << "The space is already taken" << endl;
                    columm = choiceColumm();
                    row = choiceRow();
                    }
                }

            metrix[row][columm] = 'X';

            cout << "["<<  metrix [0][0] << "] ["<<metrix[0][1] << "] [" << metrix[0][2] << "]"<< endl;
            cout << "["<<  metrix [1][0] << "] ["<<metrix[1][1] << "] [" << metrix[1][2] << "]"<< endl;
            cout << "["<<  metrix [2][0] << "] ["<<metrix[2][1] << "] [" << metrix[2][2] << "]"<< endl;
            cout << "-----------------------" << endl;
            //Winner Check for user
            // Row Check
            if (metrix[0][0] =='X' && metrix [0][1]=='X' && metrix [0][2] == 'X'){
                cout << "Victory!\n";
                return 0;
                }
            if (metrix[1][0]=='X' && metrix [1][1]=='X' && metrix [1][2] == 'X'){
                cout << "Victory!\n";
                return 0;
                }
            if (metrix[2][0]=='X' && metrix [2][1]=='X' && metrix [2][2] == 'X'){
                cout << "Victory!\n";
                return 0;
                }
            //Vertical Check
            if (metrix[0][0] =='X' && metrix [1][0] =='X' && metrix [2][0] == 'X'){
                cout << "Victory!\n";
                return 0;
                }
            if (metrix[0][1]=='X' && metrix [1][1]=='X' && metrix [2][1] == 'X'){
                cout << "Victory!\n";
                return 0;
                }
            //Cross Check
            if (metrix[0][0]=='X' && metrix [1][1]=='X' && metrix [2][2] == 'X'){
                cout << "Victory!\n";
                return 0;
                }
            if (metrix[0][2]=='X' && metrix [1][1]=='X' && metrix [2][0] == 'X'){
                cout << "Victory!\n";
                return 0;
            }

            //Computer turn
            cout << "Computer Turn" << endl;
            //loops untill computer finds a vaild spot
            while (metrix[row][columm] == 'X'|| metrix[row][columm] == 'O'){
                columm = computerTurnColumm();
                row = computerTurnRow();
                }

            metrix [row][columm] = 'O';

        }

    }



    return 0;
}
