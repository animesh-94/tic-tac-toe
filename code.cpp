#include<iostream>
using namespace std;
char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int col;
char token = 'x';
bool tie = false;
string n1;
string n2;

void inputFunction(){    
    cout<<"     |     |     "<<endl;
    cout<<"  "<<matrix[0][0]<<"  |  "<<matrix[0][1]<<"  |  "<<matrix[0][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<" "<<matrix[1][0]<<"   |   "<<matrix[1][1]<<" |  "<<matrix[1][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<" "<<matrix[2][0]<<"   |   "<<matrix[2][1]<<" |  "<<matrix[2][2]<<endl;
    cout<<"     |     |     "<<endl;
}

void codeLogic(){
    int digit;
    if(token == 'x'){
        cout<< n1 <<" please enter";
        cin>>digit;
    }
    if(token == 'O'){
        cout<< n2 <<" please enter";
        cin>>digit;
    }

    if(digit == 1){
        row = 0;
        col = 0;
    }
    if(digit == 2){
        row = 0;
        col = 1;
    }
    if(digit == 3){
        row = 0;
        col = 2;
    }
    if(digit == 4){
        row = 1;
        col = 0;
    }
    if(digit == 5){
        row = 1;
        col = 1;
    }
    if(digit == 6){
        row = 1;
        col = 2;
    }
    if(digit == 7){
        row = 2;
        col = 0;
    }
    if(digit == 8){
        row = 2;
        col = 1;
    }
    if(digit == 9){
        row = 2;
        col = 2;
    }
    else{
        cout<<"Invalid Number"<<endl;
    }

    if(token == 'x' && matrix[row][col] != 'x' && matrix[row][col] != 'O'){
        matrix[row][col] = 'x';
        token = 'O';
    }
    else if(token == 'O' && matrix[row][col] != 'O' && matrix[row][col] != 'x'){
        matrix[row][col] = 'O';
        token = 'x';
    }
    else{
        cout<<"Game is over"<<endl;
        codeLogic();
    }
}

bool matchingRowAndCol(){
    for(int i=0; i<3; i++){
        if((matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) || (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])){
            return true;
        }
        if((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) || (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0])){
            return true;
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j] != 'x' && matrix[i][j] != 'O'){
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main(){
    cout<<"Enter the name of player 1: "<<endl;
    cin>>n1;
    cout<<"Enter the name of player 2: "<<endl;
    cin>>n2;

    cout<< n1 <<" is player one"<<endl;
    cout<< n2 <<" is player two"<<endl;


    while(matchingRowAndCol != false){
        inputFunction();
        codeLogic();
        matchingRowAndCol();
    }

    if(token=='x' && tie == false){
        cout<<n2<<" Wins!!"<<endl;
    }
    else if(token=='O' && tie == false){
        cout<<n1<<" Wins!!"<<endl;
    }
    else{
        cout<<"Its a draw"<<endl;
    }
}