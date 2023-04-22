#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

bool game_end(int player_turn, int row1, int col1, int col, vector<vector<string> > &arr);
void winners(int score1, int score2);
void print_board(int player_turn, int row, vector<vector<string> > &arr, int col1, int row1);
void check_value_choosed(int player_turn, int row1, int col1, vector<vector<string> > &arr);
void insert_value(int row, vector<vector<string> > &arr);

int main()
{
    int row, col;
    srand(time(0));
    cout << "pls enter an int: ";
    cin >> row;
    col = row;
    vector<vector<string> > arr(row, vector<string>(col));

    insert_value(row, arr);

    int score1 = 0, score2 = 0, row1 = 0, col1 = 0, player_turn = 1;
    bool g_status = false;
    while (true)
    {
        print_board(player_turn, row, arr, col1, row1);
        cout << "player1 = " << score1 << setw(15) << "player2 = " << score2 << endl;
        if (player_turn == 1)
        {
            row1 = (1 + rand() % (col));
            cout << "row: " << row1 << endl;
            col1 = (1 + rand() % (col));
            cout << "column: " << col1 << endl;
            score1 = score1 + stoi(arr[row1 - 1][col1 - 1]);
            arr[row1 - 1][col1 - 1] = "";
            cout << "player1 = " << score1 << setw(15) << "player2 = " << score2 << endl;
            player_turn++;
        }
        else if (player_turn % 2 == 0)
        {
            cout << "enter a row: ";
            cin >> row1;
            //check_value_choosed(player_turn, row1, col1, arr);
            while(true)
            {
                if (row1 > col)
                {
                    cout << "This is invalid!! Please choose another one! from 1 to" << col << endl;
                    cout << "enter a row: ";
                    cin >> row1;
                }

                if (arr[row1 - 1][col1 - 1] == "")
                {
                    cout << "This value has been taken! Please choose another one!" << endl;
                    cout << "enter a row: ";
                    cin >> row1;
                }

                else 
                    break;
            }
            score2 = score2 + stoi(arr[row1 - 1][col1 - 1]);
            arr[row1 - 1][col1 - 1] = "";
            cout << "player1 = " << score1 << setw(15) << "player2 = " << score2 << endl;
            cout << "current player turn: " << player_turn << "\n";
            player_turn++;
            cout << "next player turn: " << player_turn << "\n";
            cout << "row1: " << row1 << endl;
            cout << "col1: " << col1 << endl;
            cout << "col: " << col << endl;
            if (player_turn >= 5)
            {
                g_status = game_end(player_turn, row1, col1, col, arr);
                cout << g_status;
                if (g_status)
                {
                    print_board(player_turn, row, arr, col1, row1);
                    break;
                }
            }
        }
        else
        {
            cout << "enter a column: ";
            cin >> col1;
            //check_value_choosed(player_turn, row1, col1, arr);
            while(true)
            {
                if (row1 > col)
                {
                    cout << "This is invalid!! Please choose another one! from 1 to" << col << endl;
                    cout << "enter a col: ";
                    cin >> col1;
                }

                if (arr[row1 - 1][col1 - 1] == "")
                {
                    cout << "This value has been taken! Please choose another one!" << endl;
                    cout << "enter a col: ";
                    cin >> col1;
                }

                else 
                    break;
            }
            score1 = score1 + stoi(arr[row1 - 1][col1 - 1]);
            arr[row1 - 1][col1 - 1] = "";
            cout << "player1 = " << score1 << setw(15) << "player2 = " << score2 << endl;
            cout << "current player turn: " << player_turn << "\n";
            player_turn++;
            cout << "next player turn: " << player_turn << "\n";
            cout << "row1: " << row1 << endl;
            cout << "col1: " << col1 << endl;
            cout << "col: " << col << endl;
            if (player_turn >= 5)
            {
                g_status = game_end(player_turn, row1, col1, col, arr);
                cout << g_status;
                if (g_status)
                {
                    print_board(player_turn, row, arr, col1, row1);
                    break;
                }
            }
        }
    }
    winners(score1, score2);
}

bool game_end(int player_turn, int row1, int col1, int col, vector<vector<string> > &arr)
{
    if (player_turn % 2 == 0)
    {
        for (int i = 0; i < col; i++)
        {
            if (arr[i][col1 - 1] != "")
                return false;
        }
    }
    //if (player_turn % 2 == 1)
    else
    {
        for (int i = 0; i < col; i++)
        {
            cout << "hoooooooooo" << "\n";
            if (arr[row1 - 1][i] != "")
            {
                cout << "hhhhhhhhhhhh" << "\n";
                return false;
                cout << "heeeeeeeeeeee" << "\n";
            }
            cout << "hhaaaaaaaaa" << "\n";
        }
    }
    return true;
}

void winners(int score1, int score2)
{
    if (score1 > score2)
        cout << "Congrats!! Player 1 is the Winner !!!";
    else if ( score1 == score2)
        cout << "oh no! This is a draw game!!";
    else
        cout << "Congrats!! Player 2 is the Winner !!!";
}

void print_board(int player_turn, int row, vector<vector<string> > &arr, int col1, int row1)
{
    if (player_turn == 1)
    {
        cout << "-----------------------------------------" << endl;
        for (int i = 0; i < row; i++)
        {
            cout << "|";
            for (int j = 0; j < row; j++)
            {
                cout << setw(4) << arr[i][j] << setw(4) << "|";
            }
            cout << endl;
            cout << "-----------------------------------------" << endl;
        }
    }

    else if (player_turn % 2 == 0)
    {
        cout << "-----------------------------------------" << endl;
        for (int i = 0; i < row; i++)
        {
            if (col1 - 1 == 0)
            {
                cout << "*";
            }
            else
            {
                cout << "|";
            }
            for (int j = 0; j < row; j++)
            {
                if (j == col1 - 1 || j == col1 - 2)
                    cout << setw(4) << arr[i][j] << setw(4) << "*";
                else
                    cout << setw(4) << arr[i][j] << setw(4) << "|";
            }
            cout << endl;
            cout << "-----------------------------------------" << endl;
        }
    }

    else if (player_turn % 2 == 1)
    {
        if (row1 - 1 == 0)
            cout << "******************************************" << endl;
        else
            cout << "-----------------------------------------" << endl;
        for (int i = 0; i < row; i++)
        {
            cout << "|";
            for (int j = 0; j < row; j++)
            {
                cout << setw(4) << arr[i][j] << setw(4) << "|";
            }
            cout << endl;
            if (i == row1 - 1 || i == row1 - 2)
                cout << "******************************************" << endl;
            else
                cout << "-----------------------------------------" << endl;
        }
    }
}

void insert_value(int row, vector<vector<string> > &arr)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            arr[i][j] = to_string(1 + rand() % 30);
        }
    }
}

void check_value_choosed(int player_turn, int row1, int col1, vector<vector<string> > &arr)
{
    // while ((arr[row1 - 1][col1 - 1]) == "")
    // {
    //     cout << "This value has been taken! Please choose another one!" << endl;
    //     if(player_turn % 2 == 0)
    //     {
    //         cout << "enter a row: ";
    //         cin >> row1;
    //         if(arr[row1 - 1][col1 - 1] == "")
    //         {
    //             cout << "This value has been taken! Please choose another one!" << endl;
    //             cout << "enter a row: ";
    //             cin >> row1;
    //         }
    //         else 
    //             break;
    //     }
    
    //     else 
    //     {
    //         cout << "enter a col: ";
    //         cin >> col1;
    //         if(arr[row1 - 1][col1 - 1] == "")
    //         {
    //             cout << "This value has been taken! Please choose another one!" << endl;
    //             cout << "enter a col: ";
    //             cin >> col1;
    //         }
    //         else 
    //             break;
    //     }
    // }
    if(player_turn % 2 == 0)
    {
        while(arr[row1 - 1][col1 - 1] == "")
        {
            cout << "This value has been taken! Please choose another one!" << endl;
            cout << "enter a row: ";
            cin >> row1;
            if(arr[row1 - 1][col1 - 1] == "")
            {
                cout << "This value has been taken! Please choose another one!" << endl;
                cout << "enter a row: ";
                cin >> row1;
            }
            else 
                break;
        }
    }
    else 
    {
        while(arr[row1 - 1][col1 - 1] == "")
        {
            cout << "This value has been taken! Please choose another one!" << endl;
            cout << "enter a col: ";
            cin >> col1;
            if(arr[row1 - 1][col1 - 1] == "")
            {
                cout << "This value has been taken! Please choose another one!" << endl;
                cout << "enter a col: ";
                cin >> col1;
            }
            else 
                break;
        }
    }
    
}



// void check_value_choosed(int player_turn, int row1, int col1, vector<vector<string> > &arr) 
// {
//     while (arr[row1 - 1][col1 - 1] == "") 
//     {
//         if(player_turn % 2 == 0)
//         {
//             cout << "This value has been taken! Please choose another one!" << endl;
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             while (true) {
//                 cout << "Enter a row: ";
//                 string input;
//                 getline(cin, input);
//                 if (!input.empty()) {
//                     try {
//                         row1 = stoi(input);
//                         break;
//                     }
//                     catch (const std::invalid_argument& e) {
//                         cout << "Invalid input! Please enter an integer." << endl;
//                     }
//                 }
//             }
//         }
//         else 
//         {
//             cout << "This value has been taken! Please choose another one!" << endl;
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             while (true) {
//                 cout << "Enter a col: ";
//                 string input;
//                 getline(cin, input);
//                 if (!input.empty()) {
//                     try {
//                         row1 = stoi(input);
//                         break;
//                     }
//                     catch (const std::invalid_argument& e) {
//                         cout << "Invalid input! Please enter an integer." << endl;
//                     }
//                 }
//             }
//         }
//     }
// }
        



// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <iomanip>
// using namespace std;

// class CrossingGame {
// private:
//     int row, col, row1, col1, player_turn, score1, score2;
//     string arr[10][10];
//     bool g_status;

//     void initBoard() {
//         for (int i = 0; i < row; i++) {
//             for (int j = 0; j < col; j++) {
//                 arr[i][j] = to_string(1 + rand() % 31);
//             }
//         }
//     }

//     void printBoard() {
//         cout << "-----------------------------------------" << endl;
//         for (int i = 0; i < row; i++) {
//             cout << "|";
//             for (int j = 0; j < col; j++) {
//                 cout << setw(4) << arr[i][j] << setw(4) << "|";
//             }
//             cout << endl;
//             cout << "-----------------------------------------" << endl;
//         }
//     }

// public:
//     CrossingGame(int r) : row(r), col(r), player_turn(1), score1(0), score2(0), g_status(false) {}

//     void startGame() {
//         srand(time(0));
//         initBoard();

//         while (!g_status) {
//             printBoard();
//             cout << "player1 = " << score1 << setw(15) << "player2 = " << score2 << endl;

//             if (player_turn == 1) {
//                 cout << "enter a row: ";
//                 cin >> row1;
//                 cout << "enter a column: ";
//                 cin >> col1;
//                 score1 = score1 + stoi(arr[row1 - 1][col1 - 1]);
//                 arr[row1 - 1][col1 - 1] = "";
//                 cout << "player1 = " << score1 << endl;
//                 player_turn++;
//             } else if (player_turn % 2 == 0) {
//                 cout << "enter a column: ";
//                 cin >> col1;
//                 score2 = score2 + stoi(arr[row1 - 1][col1 - 1]);
//                 arr[row1 - 1][col1 - 1] = "";
//                 cout << "player2 = " << score2 << endl;
//                 player_turn++;
//                 g_status = gameEnd();
//             } else {
//                 cout << "enter a row: ";
//                 cin >> row1;
//                 score1 = score1 + stoi(arr[row1 - 1][col1 - 1]);
//                 arr[row1 - 1][col1 - 1] = "";
//                 cout << "player1 = " << score1 << endl;
//                 player_turn++;
//                 g_status = gameEnd();
//             }
//         }
//     }

//     bool gameEnd() {
//         if (player_turn >= 5 && player_turn % 2 == 0) {
//             for (int i = 0; i < col; i++) {
//                 if (arr[col][i] != "") return false;
//             }
//         } else if (player_turn >= 5 && player_turn % 2 == 1) {
//             for (int i = 0; i < col; i++) {
//                 if (arr[i][col] != "") return false;
//             }
//         }
//         return true;
//     }
// };

// int main() {
//     int row;
//     cout << "pls enter an int: ";
//     cin >> row;

//     CrossingGame game(row);
//     game.startGame();

//     return 0;
// }
