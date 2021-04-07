#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include "Direction.hpp"
using ariel::Direction;
using namespace std;

// #define LEN 10000

namespace ariel{
    struct Board{
        struct newChar{
            char c = '_';
        };
        // char mat[LEN][LEN];
        map<unsigned int, map<unsigned int, struct newChar>> mat;
        // public:           
        //     Board() {     // Constructor

        //     }

        void post(unsigned int row, unsigned int col, ariel::Direction d, std::string msg);
        std::string read(unsigned int row, unsigned int col, ariel::Direction d, unsigned int len);
        void show();
    };
}
