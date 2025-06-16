#include <bits/stdc++.h>
using namespace std;
#include "RubiksCube.h"
char RubiksCube::getColorLetter(COLOR color)const
{
    switch (color)
    {
    case COLOR::WHITE:
        return 'W';
    case COLOR::GREEN:
        return 'G';
    case COLOR::RED:
        return 'R';
    case COLOR::BLUE:
        return 'B';
    case COLOR::ORANGE:
        return 'O';
    case COLOR::YELLOW:
        return 'Y';
    default:
        return '?';
    }
}
std::string RubiksCube::getMoveLetter(MOVE m)
{
    // cout << "Here" << " ";
    switch (m)
    {
    case MOVE::F: // Front face clockwise
        return "F";
    case MOVE::FPRIME: // Front face counterclockwise
        return "FPRIME";
    case MOVE::F2: // Front face 180 degrees
        return "F2";
    case MOVE::U: // Up face clockwise
        return "U";
    case MOVE::UPRIME: // Up face counterclockwise
        return "UPRIME";
    case MOVE::U2: // Up face 180 degrees
        return "U2";
    case MOVE::D: // Down face clockwise
        return "D";
    case MOVE::DPRIME: // Down face counterclockwise
        return "DPRIME";
    case MOVE::D2: // Down face 180 degrees
        return "D2";
    case MOVE::R: // Right face clockwise
        return "R";
    case MOVE::RPRIME: // Right face counterclockwise
        return "RPRIME";
    case MOVE::R2: // Right face 180 degrees
        return "R2";
    case MOVE::L: // Left face clockwise
        return "L";
    case MOVE::LPRIME: // Left face counterclockwise
        return "LPRIME";
    case MOVE::L2: // Left face 180 degrees
        return "L2";
    case MOVE::B: // Back face clockwise
        return "B";
    case MOVE::BPRIME: // Back face counterclockwise
        return "BPRIME";
    case MOVE::B2: // Back face 180 degrees
        return "B2";
    default:
        return "?";
    }
}

void RubiksCube::printColor(char color)
{
    switch (color)
    {
    case 'W':
        std::cout << "\033[38;2;255;255;255mW\033[0m ";
        break; // Bright White
    case 'G':
        std::cout << "\033[38;2;0;255;0mG\033[0m ";
        break; // Bright Green (Lime Green)
    case 'R':
        std::cout << "\033[1;31mR\033[0m ";
        break; // Bright Red
    case 'B':
        std::cout << "\033[1;34mB\033[0m ";
        break; // Bright Blue
    case 'O':
        std::cout << "\033[38;2;255;165;0mO\033[0m ";
        break; // Bright Orange (RGB: 255, 165, 0)
    case 'Y':
        std::cout << "\033[38;2;255;255;0mY\033[0m ";
        break; // Bright Yellow
    default:
        std::cout << "\033[0m? ";
        break; // Reset
    }
}
void RubiksCube::print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (j >= 3 && j <= 5 && i >= 0 && i <= 2)
            {
                printColor(getColorLetter(getColor(FACE::UP, i - 0, j - 3)));
                // cout<<i<<","<<j-3;
            }
            else if (i >= 3 && i <= 5 && j >= 0 && j <= 2)
            {
                printColor(getColorLetter(getColor(FACE::LEFT, i - 3, j - 0)));
                // cout<<i-3<<","<<j;
            }
            else if (i >= 3 && i <= 5 && j >= 3 && j <= 5)
            {
                printColor(getColorLetter(getColor(FACE::FRONT, i - 3, j - 3)));
                // cout<<i-3<<","<<j-3;
            }
            else if (i >= 3 && i <= 5 && j >= 6 && j <= 8)
            {
                printColor(getColorLetter(getColor(FACE::RIGHT, i - 3, j - 6)));
                // cout<<i-3<<","<<j-6;
            }
            else if (i >= 3 && i <= 5 && j >= 9 && j <= 11)
            {
                printColor(getColorLetter(getColor(FACE::BACK, i - 3, j - 9)));
                // cout<<i-3<<","<<j-9;
            }
            else if (j >= 3 && j <= 5 && i >= 6 && i <= 8)
            {
                printColor(getColorLetter(getColor(FACE::DOWN, i - 6, j - 3)));
                // cout<<i-6<<","<<j-3;
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "---------------------------------------\n";
}
RubiksCube &RubiksCube::move(MOVE ind)
{
    switch (ind)
    {
    case MOVE::U:
        return this->U();
    case MOVE::U2:
        return this->U2();
    case MOVE::UPRIME:
        return this->UPRIME();
    case MOVE::L:
        return this->L();
    case MOVE::L2:
        return this->L2();
    case MOVE::LPRIME:
        return this->LPRIME();
    case MOVE::F:
        return this->F();
    case MOVE::F2:
        return this->F2();
    case MOVE::FPRIME:
        return this->FPRIME();
    case MOVE::R:
        return this->R();
    case MOVE::R2:
        return this->R2();
    case MOVE::RPRIME:
        return this->RPRIME();
    case MOVE::B:
        return this->B();
    case MOVE::B2:
        return this->B2();
    case MOVE::BPRIME:
        return this->BPRIME();
    case MOVE::D:
        return this->D();
    case MOVE::D2:
        return this->D2();
    case MOVE::DPRIME:
        return this->DPRIME();
    }
}

RubiksCube &RubiksCube::invert(MOVE ind)
{
    switch (ind)
    {
    case MOVE::U:
        return this->UPRIME();
    case MOVE::U2:
        return this->U2();
    case MOVE::UPRIME:
        return this->U();
    case MOVE::L:
        return this->LPRIME();
    case MOVE::L2:
        return this->L2();
    case MOVE::LPRIME:
        return this->L();
    case MOVE::F:
        return this->FPRIME();
    case MOVE::F2:
        return this->F2();
    case MOVE::FPRIME:
        return this->F();
    case MOVE::R:
        return this->RPRIME();
    case MOVE::R2:
        return this->R2();
    case MOVE::RPRIME:
        return this->R();
    case MOVE::B:
        return this->BPRIME();
    case MOVE::B2:
        return this->B2();
    case MOVE::BPRIME:
        return this->B();
    case MOVE::D:
        return this->DPRIME();
    case MOVE::D2:
        return this->D2();
    case MOVE::DPRIME:
        return this->D();
    }
}
// static cast is used to convert from number to move or move to number
vector<RubiksCube::MOVE> RubiksCube::randomShuffle(int times)
{
    srand(time(0));
    vector<MOVE> moves_made;
    for (int i = 0; i < times; i++)
    {
        int num = rand() % 18;
        moves_made.push_back(static_cast<MOVE>(num));
        this->move(static_cast<MOVE>(num));
        // this->print();
    }
    return moves_made;
}
//Helper function returns string of corner
string RubiksCube::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
//        UFR
        case 0:
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}

uint8_t RubiksCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}