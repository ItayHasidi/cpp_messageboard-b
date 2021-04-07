#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
#include <string>
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>

using namespace std;
using namespace ariel;
using std::cout;
using std::endl;

constexpr int TEN = 10, HUNDREND = 100, ZERO = 0, THREE = 3, TWO = 2, ONE = 1;

unsigned int MAX_COL = 0, MAX_ROW = 0, MIN_COL = __INT_MAX__, MIN_ROW = __INT_MAX__;

void Board::post(unsigned int row, unsigned int col, ariel::Direction d, std::string msg){
    unsigned int len = msg.size();
    // cout << "msg len:" << len << ", msg: " << msg << endl;
    if(d == ariel::Direction::Horizontal){
        for(unsigned int i = 0; i < len; i++){
            mat[row][i+col].c = msg[i];
            if(row > MAX_ROW){
                MAX_ROW = row;
            }
            if(col + i > MAX_COL){
                MAX_COL = col + i;
            }
            if(row < MIN_ROW){
                MIN_ROW = row;
            }
            if(col + i < MIN_COL){
                MIN_COL = col + i;
            }
            // cout << msg[i];
        }
    }
    else{
        for(unsigned int i = 0; i < len; i++){
            mat[i+row][col].c = msg[i];
            if(row + i > MAX_ROW){
                MAX_ROW = row + i;
            }
            if(col > MAX_COL){
                MAX_COL = col;
            }
            if(row + i < MIN_ROW){
                MIN_ROW = row + i;
            }
            if(col < MIN_COL){
                MIN_COL = col;
            }
        }
    }
}

std::string Board::read(unsigned int row, unsigned int col, ariel::Direction d, unsigned int len){
    std::string msg;
    if(d == ariel::Direction::Horizontal){
        for(unsigned int i = ZERO; i < len; i++){
            msg += mat[row][i + col].c;
        }
        // msg += '\n';
    }
    else{
        for(unsigned int i = ZERO; i < len; i++){
            msg += mat[i + row][col].c;
        }
        // msg += '\n';
    }
    return msg;
}

void Board::show(){
    unsigned int row_start=MIN_ROW;
    unsigned int row_end=MAX_ROW + THREE;
    unsigned int col_start=MIN_COL;
    unsigned int col_end=MAX_COL + THREE;
    if(row_start > TWO){
        row_start -= THREE;
    } 
    else{
        row_start = ZERO;
    } 
    if(col_start > TWO){ 
        col_start -= THREE;
    }
    else{
        col_start = ZERO;
    } 
    if(row_end - row_start > HUNDREND){
        row_end = row_start + HUNDREND;
    } 
    if(col_end - col_start > HUNDREND){
        col_end = col_start + HUNDREND;
    } 
    for(unsigned int i = row_start; i <= row_end; i++){
        if(i < TEN){
            cout << " " << i << ": " << Board::read(i, col_start, ariel::Direction::Horizontal, col_end - col_start + ONE) << endl;
        }
        else{
            cout << i << ": " << Board::read(i, col_start, ariel::Direction::Horizontal, col_end - col_start + ONE) << endl;
        }
    }
            
}
