#pragma once

#include<iostream>
#include <unordered_map>
#include "Direction.hpp"


namespace ariel{
    class Board{
        public:

            /*empty constractor*/
            Board ();
        
            void post(unsigned int row, unsigned int column, Direction direction, std::string toPost);
            std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int postLength);
            void show();

        private :
            static std::string convertToKey(unsigned int i,unsigned int j);
            std::unordered_map<std::string , std::string> _noticeBoard;

            /*will help to print the exact size of the board*/
            u_int _maxColumn;
            u_int _maxRow;
    };
}