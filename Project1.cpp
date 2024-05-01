#include <iostream>
#include <windows.h>
// #include <unistd.h>
using namespace std;
int arr[4][4];
    char player1;
    char player2;
    bool x = false;
    bool o = false;
    bool flag = true;
void display(){
/*
                                     |  1   |  2    |  3    |    4    |
                                     ----------------------------------
                                   1 |      |       |       |         |
                                     ----------------------------------
                                   2 |      |       |       |         |
                                     ----------------------------------
                                   3 |      |       |       |         |
                                     ----------------------------------
                                   4 |      |       |       |         |
                                     ----------------------------------
*/

cout << "  |  1  |  2  |  3  |  4  |" << '\n';
cout << "  --------------------------" << endl;
for(int i = 0 ; i <4 ;i++){
        cout << i+1 << ' ' ;
        for(int j = 0 ; j < 4 ; j ++ ){
            if((char)arr[i][j] == 0)
                cout << "|  " << (char)arr[i][j] << "   " ;
            else{
                cout << "| " << (char)arr[i][j] << "   " ;

            }
        }
        cout << "|\n  --------------------------" << endl;
        
        // if(i == 0){
        //      for(int j = 0 ; j < 4 ;j ++){
        //          if(j == 3){
        //              cout << "|   "  << (char)arr[i][j] << " ";
        //              continue;
        //          }
        //          cout << "|  "  << (char)arr[i][j] << "  ";
        //      }
         
        // }
        // else{
        //     for(int j = 0 ; j < 4 ;j ++){
        //         if(j == 3){
        //             cout << "|   "  << (char)arr[i][j] << "  ";
        //             continue;
        //         }
        //         cout << "|  "  << (char)arr[i][j] << "  ";
        //     }
        // }
        // cout << " |" << endl;
        // cout << "  --------------------------" << endl;
    
    }
    Beep(400,100);
    


}
// void che(char P1 , char P2){
//     if(toupper(P1) != 'X'  || toupper(P1) != 'O'){
//         cout << "Player 1 -> You have to choose betwen X or Y ONLY" << endl; 
//         cin >> P1;
//         che(P1,P2);
//     }else if(toupper(P2) != 'X'  || toupper(P2) != 'O'){
//         cout << "Player 2 -> You have to choose betwen X or Y ONLY" << endl; 
//         cin >> P2;
//         che(P1,P2);
//     }else{
//         return;
//     }

// }
void the_game(){
    if(flag){
        cout << "  -----------------------" << '\n';
        cout << "  player 1 it's your turn" << "\n";
        cout << "  -----------------------" << "\n\n";
        cout << "--choose your Coordinates--" << '\n';
        int x,y;
        cin >> x >> y;
        if(arr[x-1][y-1] == 'X' || arr[x-1][y-1] == 'O' ){
            cout << "You have to choose another Coordinates \n";
            the_game();
            return;
        }
        if(x > 4 || y > 4){
            cout << "the number must be less than or equel 4" << '\n';
            the_game();
            return;
        }
        arr[x-1][y-1] = toupper(player1);
        flag = false;

    }else{
        cout << "  -----------------------" << '\n';
        cout << "  player 2 it's your turn" << "\n";
        cout << "  -----------------------" << '\n';
        cout << "--choose your Coordinates--" << '\n';
        int x,y;
        cin >> x >> y;
        if(arr[x-1][y-1] == 'X' || arr[x-1][y-1] == 'O' ){
            cout << "You have to choose another Coordinates \n";
            the_game();
            return;
        }        
        if(x > 4 || y > 4){
            cout << "the number must be less than or equel 4" << '\n';
            the_game();
            return;
        }
        arr[x-1][y-1] = toupper(player2);
        flag = true;

    }
}
void check(char P1, char P2){
    
    if( (toupper(P1) != 88) && toupper(P1) != 79){
        cout << "Player 1 -> You have to choose betwen X or O ONLY" << endl; 
        cin >> P1;
        check(P1,P2);
        return;
    }
    if(toupper(P2) != 88 && toupper(P2) != 79 ){
        cout << "Player 2 -> You have to choose betwen X or O ONLY" << endl; 
        cin >> P2;
        check(P1,P2);
        return;
    }
    if(P1 == P2){
    cout << "You can't choose " << P1 <<  " (player 1) have it choose something else" << '\n';
    cin >> P2;
    }else{
        player1 = P1;
        player2 = P2;
        return;
    }
    check(P1,P2);

    
}


bool check_If_Any_Player_win(){
    int tmp =0;
//--------------------------------------------------------------------
    for(int i =0 ; i < 4 ; i++){
        for(int j =0 ; j < 4 ;j++){
            
            if(arr[i][j] == 'X'){
                tmp++;
            }else if(arr[i][j] == 'O'){
                tmp--;
            }
        }                                                           // checking for the rows
        if(tmp == 4){
            x =true;
            return true;
        }else if(tmp == -4){
            o =true;
            return true;
        }tmp =0;
//--------------------------------------------------------------------
        for(int j =0 ; j < 4 ;j++){
            
            if(arr[j][i] == 'X'){
                tmp++;
            }else if(arr[j][i] == 'O'){
                tmp--;
            }
        }                                                           // checking for coulmns 
        if(tmp == 4){
            x =true;
            return true;
        }else if(tmp == -4){
            o =true;
            return true;
        }tmp =0;

    }
//--------------------------------------------------------------------
    for(int i = 0 ,j = 0 ;i <4 ;i++ ,j++){
            if(arr[j][i] == 'X'){
                tmp++;
            }else if(arr[j][i] == 'O'){
                tmp--;
            }
    }
        if(tmp == 4){
            x =true;
            return true;
        }else if(tmp == -4){
            o =true;
            return true;
        }tmp =0;
    for(int i = 3 ,j = 0 ;i >= 0 ;i-- ,j++){                            //checking for Diagnals 
            if(arr[j][i] == 'X'){
                tmp++;
            }else if(arr[j][i] == 'O'){
                tmp--;
            }
    }
        if(tmp == 4){
            x =true;
            return true;
        }else if(tmp == -4){
            o =true;
            return true;
        }tmp =0;

//--------------------------------------------------------------------
    return false;
}
int main(){
    display();
    // char player1;
    // char player2;
    cout << "Player 1: choose bewteen X and O" << '\n';
    cin >> player1;
    cout << "Player 2: choose bewteen X and O" << '\n';
    cin >> player2;

    check(player1,player2);
    for(int i = 0 ; i < 4*4 ;i ++){
        the_game();
        if(check_If_Any_Player_win()){
            if(x){
                if(toupper(player1) == 'X' ){
                    display();  
                    cout << "⋅˚₊‧ ୨ 𝑷𝑳𝑨𝒀𝑬𝑹 𝟏 𝑰𝑺 𝑻𝑯𝑬 𝑾𝑰𝑵𝑵𝑬𝑹 ୧ ‧₊˚ ⋅" << endl;
                }
                else if(toupper(player2) == 'X'){
                    display();  
                    cout << "⋅˚₊‧ ୨ 𝑷𝑳𝑨𝒀𝑬𝑹 𝟐 𝑰𝑺 𝑻𝑯𝑬 𝑾𝑰𝑵𝑵𝑬𝑹 ୧ ‧₊˚ ⋅r" << endl;
                }
            }else if(o){
                if(toupper(player1) == 'O' )
                    display();  
                    cout << "⋅˚₊‧ ୨ 𝑷𝑳𝑨𝒀𝑬𝑹 𝟏 𝑰𝑺 𝑻𝑯𝑬 𝑾𝑰𝑵𝑵𝑬𝑹 ୧ ‧₊˚ ⋅" << endl;
                if(toupper(player2) == 'O')
                    display();  
                    cout << "⋅˚₊‧ ୨ 𝑷𝑳𝑨𝒀𝑬𝑹 𝟐 𝑰𝑺 𝑻𝑯𝑬 𝑾𝑰𝑵𝑵𝑬𝑹 ୧ ‧₊˚ ⋅" << endl;


            }
            break;
        }
        display();
    }
    if(!check_If_Any_Player_win()){
        cout << "\n The Game was gone to DRAW" << "\n";
    }



}