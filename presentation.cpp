#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;
using std::cout;
using std::endl;

const Direction HOR = Direction::Horizontal;
const Direction VER = Direction::Vertical;

int main(){
    ariel::Board b;
    b.post(5,2, HOR, "a new message");
    b.post(2,5, VER, "announcement");
    b.post(15,5, HOR, "Supercalifragilisticexpialidocious");
    b.show();
    return 0;
}