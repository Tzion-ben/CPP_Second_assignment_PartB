#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"
#include "Board.hpp"


using namespace std;
using namespace ariel;

/*outLine empty constractor*/
Board :: Board (){
    _maxRow=0;
    _maxColumn=0;
}

/*outLine implementation to Board class*/

/*post every letter at the "toPost" string at the specific location in the rigth direction*/
void Board :: post(unsigned int row, unsigned int column, Direction direction, string toPost){
    u_int pos = 0;/*helps to run over the string to Post*/
    if(direction == Direction::Horizontal){
        for(u_int j = column ; j<(column+toPost.length()) ; j++){
            _noticeBoard[convertToKey(row,j)] = toPost.at(pos);
            pos++;
            if(_maxColumn < j){_maxColumn = j;}/*for the mas size of the board*/
        }
    }else{/*direction == Direction::Vertical*/
        for(u_int i = row ; i<(row+toPost.length()) ; i++){
            _noticeBoard[convertToKey(i,column)] = toPost.at(pos);
            pos++;
            if(_maxRow < i){_maxRow = i;}/*for the mas size of the board*/
        }
    }
}

/*create a string of the specific post at the board with a specific location*/
string Board :: read(unsigned int row, unsigned int column, Direction direction, unsigned int postLength){
    string toShow;
    if(direction == Direction::Horizontal){
        for(u_int j = column ; j<(column+postLength) ; j++){
            string key = convertToKey(row,j);
            if(_noticeBoard.count(key)==1)/*if there is a letter that part of massege*/
            {toShow+=_noticeBoard.at(convertToKey(row,j));}
            else{toShow+="_";}/*if there NOT is a letter that part of massege*/
        }
    }else{/*direction == Direction::Vertical*/
        for(u_int i = row ; i<(row+postLength) ; i++){
            string key = convertToKey(i,column);
            if(_noticeBoard.count(key)==1)/*if there is a letter that part of massege*/
            {toShow+=_noticeBoard.at(convertToKey(i,column));}
            else{toShow+="_";}/*if there NOT is a letter that part of massege*/
        }
    }
    return toShow;
    }

/*prints all the board with exact*/
void Board :: show(){
    string printBoard;
    for(u_int i = 1; i<=_maxRow ; i++){
        for(u_int j = 1 ; j<=_maxColumn ; j++){
            string keyAt_i_j = convertToKey(i,j);
            if(_noticeBoard.count(keyAt_i_j)==1){/*if there is a letter and not an empty posotion*/
                printBoard+=_noticeBoard.at(keyAt_i_j);
            }else{printBoard+="_";}
        }
        printBoard+="\n";
    }
    
    /*prints all the Board*/
    cout << printBoard << endl;
}

/*create a key for the Unsorted Map that represent the position of a letter at the board at: (i,j)*/
string Board ::convertToKey(unsigned int i,unsigned int j){
    return "("+to_string(i)+","+to_string(j)+")";
}