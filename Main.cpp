#include "Board.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <chrono>
#include <thread>


using namespace ariel;
using namespace std;

/*this main function will print a few boards*/
int main (){
    Board board;

    string post_1 = "ariel";
    board.post(/*row=*/10, /*column=*/5, Direction::Horizontal, post_1);
    string post_2 = "is";
    board.post(/*row=*/15, /*column=*/3, Direction::Horizontal, post_2);
    string post_3 = "a good university";
    board.post(/*row=*/1, /*column=*/5, Direction::Horizontal, post_3);
    string post_4 = "C.S";
    board.post(/*row=*/10, /*column=*/30, Direction::Vertical, post_4);
    string post_5 = "is";
    board.post(/*row=*/19, /*column=*/40, Direction::Horizontal, post_5);
    string post_6 = "the Best degree";
    board.post(/*row=*/18, /*column=*/8, Direction::Vertical, post_6);


    string post_7 = "kkkkkkkkkkkkkkkkkk";
    board.post(/*row=*/1, /*column=*/7, Direction::Vertical, post_7);
    board.show();

    
   
    
    return 0;
}