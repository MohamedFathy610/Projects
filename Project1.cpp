#include <iostream>
#include <windows.h>
using namespace std;
int arr[4][4];                    //x-oالارراي اللي هيبقي جواها ال
    char player1;                //حرف اللاعب الاول
    char player2;                //حرف اللاعب الثاني
    bool x = false;               // trueلو اللاعب اللي مختار اكس كسب دا يبقي ب
    bool o = false;
    bool flag = true;               // دا هنحتاجو عشان نغير الادوار هتعرفو بعدين
void display(){                    //فانكشن بتظهر الشبكه
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
 system("cls");
cout << "  |  1  |  2  |  3  |  4  |" << '\n';
cout << "  --------------------------" << endl;
for(int i = 0 ; i <4 ;i++){
        cout << i+1 << ' ' ;                    //عشان يطبع الرقم اللي جنب كل صف زي مانتا شايف كده
        for(int j = 0 ; j < 4 ; j ++ ){
            if((char)arr[i][j] == 0)
                cout << "|  " << (char)arr[i][j] << "   " ;
            else{
                cout << "| " << (char)arr[i][j] << "   " ;

            }
        }
        cout << "|\n  --------------------------" << endl;
        
    }



}

void the_game(){                //دي بقا المسووله عن اللعب بقا هي اللي بتحدد مين اللي عليه الدور وتشوف لو في شخص حط في مكان مينفعش
    if(flag){                    //عشان يقولي ان كده دور اللاعب التانيfalse اللاعب الاولي هو اللي عليه الدور وبعد اللاعب الاول م بيخلص بيتعمل trueاللي عاملو فوق دا لما بيكون ب boolاللي جوا دي ف دا الflag بالنسبة ل
        //اللي انا كاتبها دي بس انا بختصرflag هي هي  flag == true ملحوظه 
        cout << "  -----------------------" << '\n';
        cout << "  player 1 it's your turn" << "\n";
        cout << "  -----------------------" << "\n\n";
        cout << "--choose your Coordinates--" << '\n';
        int x,y;
        cin >> x >> y;
        if(arr[x-1][y-1] == 'X' || arr[x-1][y-1] == 'O' ){            //بشوف لو المكان اللي اختارو اللاعب حد اختارو قبل كده ولا لا
            cout << "You have to choose another Coordinates \n";
            the_game();
            return;
        }
        if(x > 4 || y > 4){                                //لو الرقم الللي اختارو اكبر من 4
            cout << "the number must be less than or equel 4" << '\n';
            the_game();
            return;
        }
        arr[x-1][y-1] = toupper(player1);            //لو الرقم اللي حطو الشحص كان صح وعدي من كل اللي فات هيحطو في الارري بقا
       //ف هتحولو لكابتلsmallدي بتخلي الحرف كابتل حتى لو الشخص مدخلو toupper ملحوظه فانكشن ال
        flag = false;               // عشان المره الجايه يبقى عارف ان اللي عليه الدور هو اللاعب التاني falseدا يبقى boolهنا بيخلي ال

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
void check(char P1, char P2){            //دي فانكشن بتشتغل لما اللاعب يدخل الحرف بتاعو عشان تشوف هو مظبوط ولا لا
    
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


bool check_If_Any_Player_win(){        //دي بقا بتشوف كل مره في لاعب كسب ولا لا
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
                    cout << "player 1 is the winner " << endl;
                }
                else if(toupper(player2) == 'X'){
                    display();  
                    cout << "player 2 is the winner" << endl;
                }
            }else if(o){
                if(toupper(player1) == 'O' ){
                    display();  
                    cout << "player 1 is the winner" << endl;}
                if(toupper(player2) == 'O'){
                    display();  
                    cout << "player 2 is the winner" << endl;}


            }
            break;
        }
        display();
    }
    if(!check_If_Any_Player_win()){            //ويبقي كده الجيم خلص تعادل false لو مفيش لعيبه كسبو بعد ما المربعات كلها اتملت ف كده معناه ان الفانكشن هترجع 
        cout << "\n The Game was gone to DRAW" << "\n";
    }

cout<< "if you want to play again press W" <<'\n' ;
char t;
    cin>>t;
    if(toupper(t) == 'W' ){
			main() ;
    } 
        
return 0;
}
