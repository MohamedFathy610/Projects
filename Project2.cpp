/*
-> function th check if the input is equal to (x-o) only or not                 (DONE)
-> function to check if the place of the element is empty or not                (DONE)
-> function to check if every row in the back of the array is complete or not   (DONE)
-> fniction to add new element to the array                                     (DONE)
-> function to check if any player is winning or not (*diagnol*)                (DONE)
-> function to print the table and                                              (DONE) 
-> function to the turn in who                                                  (DONE)

                                     | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
                                     -----------------------------
                                   1 |   |   |   |   |   |   |   |  
                                     -----------------------------
                                   2 |   |   |   |   |   |   |   |  
                                     -----------------------------
                                   3 |   |   |   |   |   |   |   |  
                                     -----------------------------
                                   4 |   |   |   |   |   |   |   |  
                                     -----------------------------
                                   5 |   |   |   |   |   |   |   |  
                                     -----------------------------
                                   6 |   |   |   |   |   |   |   |  
                                     -----------------------------
                                   7 |   |   |   |   |   |   |   |  
                                     -----------------------------


*/
#include <iostream>
using namespace std;

char arr[7][7];
char player1,player2;
int the_row = 6;
bool flag = true;

bool x = false;
bool o = false;
void display(){
    cout << "    1 | 2 | 3 | 4 | 5 | 6 | 7 |" << '\n';
    cout << "  -----------------------------" << '\n';
    for(int i =0 ; i < 7 ; i++){
        cout << i+1 << ' ';
        for(int j = 0 ; j < 7 ; j++){
            if(!arr[i][j]){
            cout << "| " << ' ' << ' ';
            continue;
            }
            cout << "| " << arr[i][j] << ' ';
        }
        cout << '|' << '\n';
        cout << "  -----------------------------\n" ;
    }
}

bool is_this_row_in_turn(int num1 , int num2){
    int tmp =0;
    if(num1 != 7){
        for(int i = 6 ; i > (num1-1) ;i--){
            if(arr[i][num2-1] == 0){
                return false;
            }
        }        
    }
    return true;

    // return tmp > 1 ? false : true;

}
void check(char C1,char C2){
    if( (toupper(C1) != 88) && toupper(C1) != 79){
        cout << "Player 1 -> You have to choose betwen X or O ONLY" << endl; 
        cin >> C1;
        check(C1,C2);
        return;
    }
    if(toupper(C2) != 88 && toupper(C2) != 79 ){
        cout << "Player 2 -> You have to choose betwen X or O ONLY" << endl; 
        cin >> C2;
        check(C1,C2);
        return;
    }
    if(C1 == C2){
    cout << "You can't choose " << C1 <<  " (player 1) have it choose something else" << '\n';
    cin >> C2;
    }else{
        player1 = C1;
        player2 = C2;
        return;
    }
    check(C1,C2);
}
void game(){
    if(flag){
        cout << "  -----------------------" << '\n';
        cout << "  player 1 it's your turn" << "\n";
        cout << "  -----------------------" << "\n\n";
        cout << "--choose your Coordinates--" << '\n';
        int x,y;
        cin >> x >> y;
        if(!is_this_row_in_turn(x,y)){
            cout << "The Coordinates You Choose Is Invaild \n";
            game();
            return;
        }
        if(x > 7 || y > 7){
            cout << "The number must be less than or equel 7" << '\n';
            game();
            return;
        }
        
        if(arr[x-1][y-1] == 'X' || arr[x-1][y-1] == 'O'){
            cout << "the place you choose must be empty" << '\n';
            game();
            return;
        }
        arr[x-1][y-1] = toupper(player1);
        flag = !flag;
    }else{
        cout << "  -----------------------" << '\n';
        cout << "  player 2 it's your turn" << "\n";
        cout << "  -----------------------" << '\n';
        cout << "--choose your Coordinates--" << '\n';
        int x,y;
        cin >> x >> y;
        if(!is_this_row_in_turn(x,y)){
            cout << "The Coordinates You Choose Is Invaild \n";
            game();
            return;
        }
        if(x > 7 || y > 7){
            cout << "the number must be less than or equel 7" << '\n';
            game();
            return;
        }
        if(arr[x-1][y-1] == 'X' || arr[x-1][y-1] == 'O'){
            cout << "the place you choose must be empty" << '\n';
            game();
            return;
        }
        arr[x-1][y-1] = toupper(player2);
        flag = !flag;
    }
}
bool checkDIagnol(){

    for(int i = 6 ; i >=0 ; i--){
        for(int j = 0 ; j < 7 ; j++){
            int tmp = 0 ;
            int counter = 0;
            int k = i , z = j ;
//-----------------------------------
            int tmp2 = 0;
            int num1 = i , num2 = j;
            
            while (counter != 4){
                    if(arr[k][z] == 'X'){
                        tmp ++;
                    }if(arr[k][z] == 'O'){
                        tmp--;
                    }if(tmp == 4){
                        x = true;
                        return true;
                    }if(tmp == -4 ){
                        o = true;
                        return true;
                    }            
//-----------------------------------------------------------------

                    if(arr[num1][num2] == 'X'){
                        tmp2 ++;
                    }if(arr[num1][num2] == 'O'){
                        tmp2--;
                    }if(tmp2 == 4){
                        x = true;
                        return true;
                    }if(tmp2 == -4 ){
                        o = true;
                        return true;
                    }
                    num2++;
                    num1--;            
                    
                    
//---------------------------------                    
                    
                    counter++;
                    k--;
                    z--;

            }
        
        }
    }


    // for(int k = 6 ; k >= 0 ; k--){

    //     for(int i =6 , j = 0 ; i <= 7-4 ;i-- , j ++){
    //         int tmp = 0 ;
                
    //                 if(arr[i][j] == 'X'){

    //                 }
    //     }
    // }
    return false;
}
bool any_player_win(){
    for(int i =6 ; i >= 0 ; i--){
        int tmp = 1;
        for(int j= 1 ; j < 7 ; j++){

            if(arr[i][j] == arr[i][j-1] && arr[i][j] != 0 ){
                tmp++;
            }
            if(arr[i][j] != arr[i][j-1]){
                tmp = 1;
            }
            if(tmp == 4){
                if(arr[i][j] == 'X')
                    x = true;
                if(arr[i][j] == 'O')
                    o = true;
                
                return true;
            }
            
        }
        for(int j= 1 ; j < 7 ; j++){

            if(arr[j][i] == arr[j-1][i] && arr[j][i] != 0 ){
                tmp++;
            }
            if(arr[j][i] != arr[j-1][i]){
                tmp = 1;
            }
            if(tmp == 4){
                if(arr[j][i] == 'X')
                    x = true;
                if(arr[j][i] == 'O')
                    o = true;
                
                return true;
            }
            
        }
        if(checkDIagnol())
        {
            return true;
        }
    }











        // int tmp1 =0;
        // for(int j = 0 ; j < 7 ; j++){
    //         if(is_equal(arr[i][j],arr[i][j+1],arr[i][j+2],arr[i][j+3])){
    //             if(arr[i][j] == 'X'){
    //                 x =true;
    //             }
    //             else if(arr[i][j] == 'O'){
    //                 o = true;
    //             }
    //             else{
    //                 continue;
    //             }
    //             return true;
    //         }
    //         else if(is_equal(arr[i][j],arr[i-1][j],arr[i-2][j],arr[i-3][j])){
    //             if(arr[i][j] == 'X'){
    //                 x =true;
    //             }
    //             else if(arr[i][j] == 'O'){
    //                 o = true;
    //             }
    //             else{
    //                 continue;
    //             }
    //             return true;
    //         }
    //         else if(is_equal(arr[i][j],arr[i-1][j+1],arr[i-2][j+2],arr[i-3][j+3])){
    //             if(arr[i][j] == 'X'){
    //                 x =true;
    //             }
    //             else if(arr[i][j] == 'O'){
    //                 o = true;
    //             }
    //             else{
    //                 continue;
    //             }
    //             return true;
    //         }
                
    //         else if(is_equal(arr[i][j],arr[i+1][j-1],arr[i+2][j-2],arr[i+3][j-3])){
    //             if(arr[i][j] == 'X'){
    //                 x =true;
    //             }
    //             else if(arr[i][j] == 'O'){
    //                 o = true;
    //             }
    //             else{
    //                 continue;
    //             }
    //             return true;
    //         }
    //     }
    // }
    return false;
}
int main(){
    char arr[10];
    cout << "Player 1: choose bewteen X and O" << '\n';
    cin >> player1;
    cout << "Player 2: choose bewteen X and O" << '\n';
    cin >> player2;

    check(player1,player2);
    display();
    for(int i =0 ; i < 7*7 ; i++){
        game();
        if(any_player_win()){
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


}







