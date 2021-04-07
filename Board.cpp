#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"
#include "Board.hpp"


using namespace std;
using namespace ariel;

/*outLine empty constractor*/
Board :: Board (){}

/*outLine implementation to Board class*/

/*post every letter at the "soPost" string at the specific location in teh rigth direction*/
void Board :: post(unsigned int row, unsigned int column, Direction direction, string toPost){
    u_int pos = 0;
    if(direction == Direction::Horizontal){
        for(u_int j = column ; j<(column+toPost.length()) ; j++){
            _noticeBoard[convertToKey(row,j)] = toPost.at(pos);
            pos++;
        }
    }else{/*direction == Direction::Vertical*/
        for(u_int i = row ; i<(row+toPost.length()) ; i++){
            _noticeBoard[convertToKey(i,column)] = toPost.at(pos);
            pos++;
        }
    }
}
string Board :: read(unsigned int row, unsigned int column, Direction direction, unsigned int postLength){
    string back;
    if(direction == Direction::Horizontal){
        for(u_int j = column ; j<(column+postLength) ; j++){
            string key = convertToKey(row,j);
            if(_noticeBoard.count(key)==1)
            {back+=_noticeBoard.at(convertToKey(row,j));}
            else{
                back+="_";
            }
        }
    }else{/*direction == Direction::Vertical*/
        for(u_int i = row ; i<(row+postLength) ; i++){
            string key = convertToKey(i,column);
            if(_noticeBoard.count(key)==1)
            {back+=_noticeBoard.at(convertToKey(i,column));}
            else{
                back+="_";
            }
        }
    }
    return back;
    }

/**/
void Board :: show(){
    u_int maxRow = 0;
    u_int maxColumn = 0;
    for(auto it=_noticeBoard.begin() ; it!=_noticeBoard.end() ; it++){
        string tempKey = it->first;
        u_char rowPos= (u_char)tempKey.at(1);
        u_char ColumnPos = (u_char)tempKey.at(3);
        if(maxRow < (u_int)rowPos){maxRow = (u_int)rowPos;}
        if(maxColumn < (u_int)ColumnPos){maxColumn = (u_int)ColumnPos;}
    }
    
    //DEBUG
    // cout << maxRow << endl; 
    // cout << maxColumn << endl; 

    string printBoard;
    for(u_int i= 0 ; i<maxRow+1 ; i++){
        for(u_int j = 0 ; j<maxColumn+1 ; j++){
            string keyAt_i_j = convertToKey(i,j);
            if(_noticeBoard.count(keyAt_i_j)==1){
                printBoard+=_noticeBoard.at(keyAt_i_j);
            }else{
                printBoard+="_";
            }
        }
        printBoard+="\n";
    }
    
    cout << printBoard << endl;
}

/*create a key for the Unsorted Map that represent the position at the board : (i,j)*/
string Board ::convertToKey(unsigned int i,unsigned int j){
    return "("+to_string(i)+","+to_string(j)+")";
}