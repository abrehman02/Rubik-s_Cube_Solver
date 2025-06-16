#include "RubiksCube.h"

class RubiksCube1D : public RubiksCube
{

    int C_3D_to_1D(int face, int row, int col) const
    {
        return face * 9 + row * 3 + col;
    }
    void rotateFace(FACE face)
    {
        int temp[9];
        int f = static_cast<int>(face);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[3 * i + j] = cube[C_3D_to_1D(f, i, j)];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cube[C_3D_to_1D(f, j, 2 - i)] = temp[3 * i + j];
            }
        }
    }

public:
    char cube[54]{};
    RubiksCube1D()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cube[C_3D_to_1D(i, j, k)] = getColorLetter(COLOR(i));
                }
            }
        }
    }
    COLOR getColor(FACE face, unsigned row, unsigned col) const override
    {
        char c = cube[C_3D_to_1D(int(face), row, col)];
        switch (c)
        {
        case 'W':
            return COLOR::WHITE;
        case 'G':
            return COLOR::GREEN;
        case 'R':
            return COLOR::RED;
        case 'B':
            return COLOR::BLUE;
        case 'O':
            return COLOR::ORANGE;
        case 'Y':
            return COLOR::YELLOW;
        }
    };
    RubiksCube &F() override
    {
        
        rotateFace(FACE::FRONT);

        int temp[3] = {};

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(3, i, 0)];
        }

        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 0)] = cube[C_3D_to_1D(0, 2, i)];
        }

        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 2, i)] = cube[C_3D_to_1D(1, 2 - i, 2)];
        }

        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 2)] = cube[C_3D_to_1D(5, 0, 2 - i)];
        }

        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 0, 2 - i)] = cube[C_3D_to_1D(3, i, 0)];
        }

        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 0)] = temp[i];
        }

        return *this;
    }
    RubiksCube &FPRIME() override
    {
    rotateFace(FACE::FRONT);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(3, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 0)] = cube[C_3D_to_1D(0, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 2, i)] = cube[C_3D_to_1D(1, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 2)] = cube[C_3D_to_1D(5, 0, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 0, 2 - i)] = temp[i];
        }

        rotateFace(FACE::FRONT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(3, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 0)] = cube[C_3D_to_1D(0, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 2, i)] = cube[C_3D_to_1D(1, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 2)] = cube[C_3D_to_1D(5, 0, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 0, 2 - i)] = temp[i];
        }

        rotateFace(FACE::FRONT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(3, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 0)] = cube[C_3D_to_1D(0, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 2, i)] = cube[C_3D_to_1D(1, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 2)] = cube[C_3D_to_1D(5, 0, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 0, 2 - i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &F2() override
    {
    
        rotateFace(FACE::FRONT);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(3, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 0)] = cube[C_3D_to_1D(0, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 2, i)] = cube[C_3D_to_1D(1, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 2)] = cube[C_3D_to_1D(5, 0, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 0, 2 - i)] = temp[i];
        }

        rotateFace(FACE::FRONT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(3, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 0)] = cube[C_3D_to_1D(0, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 2, i)] = cube[C_3D_to_1D(1, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 2)] = cube[C_3D_to_1D(5, 0, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 0, 2 - i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &U() override
    {
    rotateFace(FACE::UP);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 0, i)] = cube[C_3D_to_1D(2, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 0, i)] = cube[C_3D_to_1D(3, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 0, i)] = cube[C_3D_to_1D(4, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 0, i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &UPRIME() override
    {
   rotateFace(FACE::UP);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 0, i)] = cube[C_3D_to_1D(2, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 0, i)] = cube[C_3D_to_1D(3, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 0, i)] = cube[C_3D_to_1D(4, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 0, i)] = temp[i];
        }

        rotateFace(FACE::UP);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 0, i)] = cube[C_3D_to_1D(2, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 0, i)] = cube[C_3D_to_1D(3, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 0, i)] = cube[C_3D_to_1D(4, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 0, i)] = temp[i];
        }

        rotateFace(FACE::UP);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 0, i)] = cube[C_3D_to_1D(2, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 0, i)] = cube[C_3D_to_1D(3, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 0, i)] = cube[C_3D_to_1D(4, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 0, i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &DPRIME() override
    {
        rotateFace(FACE::DOWN);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2, i)] = cube[C_3D_to_1D(2, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 2, i)] = cube[C_3D_to_1D(3, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 2, i)] = cube[C_3D_to_1D(4, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2, i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &U2() override
    {
    
        rotateFace(FACE::UP);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 0, i)] = cube[C_3D_to_1D(2, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 0, i)] = cube[C_3D_to_1D(3, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 0, i)] = cube[C_3D_to_1D(4, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 0, i)] = temp[i];
        }

        rotateFace(FACE::UP);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 0, i)] = cube[C_3D_to_1D(2, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 0, i)] = cube[C_3D_to_1D(3, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 0, i)] = cube[C_3D_to_1D(4, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 0, i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &D2() override
    {
           rotateFace(FACE::DOWN);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2, i)] = cube[C_3D_to_1D(2, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 2, i)] = cube[C_3D_to_1D(3, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 2, i)] = cube[C_3D_to_1D(4, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2, i)] = temp[i];
        }

        rotateFace(FACE::DOWN);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2, i)] = cube[C_3D_to_1D(2, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 2, i)] = cube[C_3D_to_1D(3, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 2, i)] = cube[C_3D_to_1D(4, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2, i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &D() override
    {
        rotateFace(FACE::DOWN);

        int temp[3] = {};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2, i)] = cube[C_3D_to_1D(2, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 2, i)] = cube[C_3D_to_1D(3, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 2, i)] = cube[C_3D_to_1D(4, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2, i)] = temp[i];
        }

        rotateFace(FACE::DOWN);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2, i)] = cube[C_3D_to_1D(2, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 2, i)] = cube[C_3D_to_1D(3, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 2, i)] = cube[C_3D_to_1D(4, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2, i)] = temp[i];
        }

        rotateFace(FACE::DOWN);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(1, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2, i)] = cube[C_3D_to_1D(2, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, 2, i)] = cube[C_3D_to_1D(3, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, 2, i)] = cube[C_3D_to_1D(4, 2, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2, i)] = temp[i];
        }

        return *this;
    }
    RubiksCube &B() override
    {
int temp[3] = {};
        rotateFace(FACE::BACK);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 0, i)] = cube[C_3D_to_1D(3, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 2)] = cube[C_3D_to_1D(5, 2, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 2, 2 - i)] = cube[C_3D_to_1D(1, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 0)] = temp[i];
        }

        return *this;
    }
    RubiksCube &B2() override
    {
            int temp[3] = {};
        rotateFace(FACE::BACK);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 0, i)] = cube[C_3D_to_1D(3, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 2)] = cube[C_3D_to_1D(5, 2, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 2, 2 - i)] = cube[C_3D_to_1D(1, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 0)] = temp[i];
        }

        rotateFace(FACE::BACK);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 0, i)] = cube[C_3D_to_1D(3, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 2)] = cube[C_3D_to_1D(5, 2, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 2, 2 - i)] = cube[C_3D_to_1D(1, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 0)] = temp[i];
        }

        return *this;
    }
    RubiksCube &BPRIME() override
    {
     int temp[3] = {};
        rotateFace(FACE::BACK);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 0, i)] = cube[C_3D_to_1D(3, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 2)] = cube[C_3D_to_1D(5, 2, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 2, 2 - i)] = cube[C_3D_to_1D(1, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 0)] = temp[i];
        }

        rotateFace(FACE::BACK);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 0, i)] = cube[C_3D_to_1D(3, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 2)] = cube[C_3D_to_1D(5, 2, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 2, 2 - i)] = cube[C_3D_to_1D(1, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 0)] = temp[i];
        }

        rotateFace(FACE::BACK);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, 0, i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, 0, i)] = cube[C_3D_to_1D(3, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(3, i, 2)] = cube[C_3D_to_1D(5, 2, 2 - i)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, 2, 2 - i)] = cube[C_3D_to_1D(1, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(1, 2 - i, 0)] = temp[i];
        }

        return *this;
    }
    RubiksCube &R() override
    {
 int temp[3] = {};

        rotateFace(FACE::RIGHT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 2)] = cube[C_3D_to_1D(2, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 2)] = cube[C_3D_to_1D(5, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 2)] = cube[C_3D_to_1D(4, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 0)] = temp[i];
        }

        return *this;
    }
    RubiksCube &R2() override
    {
    
        int temp[3] = {};

        rotateFace(FACE::RIGHT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 2)] = cube[C_3D_to_1D(2, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 2)] = cube[C_3D_to_1D(5, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 2)] = cube[C_3D_to_1D(4, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 0)] = temp[i];
        }

        rotateFace(FACE::RIGHT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 2)] = cube[C_3D_to_1D(2, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 2)] = cube[C_3D_to_1D(5, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 2)] = cube[C_3D_to_1D(4, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 0)] = temp[i];
        }

        return *this;
    }
    RubiksCube &RPRIME() override
    {
         int temp[3] = {};

        rotateFace(FACE::RIGHT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 2)] = cube[C_3D_to_1D(2, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 2)] = cube[C_3D_to_1D(5, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 2)] = cube[C_3D_to_1D(4, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 0)] = temp[i];
        }

        rotateFace(FACE::RIGHT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 2)] = cube[C_3D_to_1D(2, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 2)] = cube[C_3D_to_1D(5, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 2)] = cube[C_3D_to_1D(4, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 0)] = temp[i];
        }

        rotateFace(FACE::RIGHT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(0, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 2)] = cube[C_3D_to_1D(2, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 2)] = cube[C_3D_to_1D(5, i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 2)] = cube[C_3D_to_1D(4, 2 - i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 0)] = temp[i];
        }

        return *this;
    }
    RubiksCube &L() override
    {
        cout << "Rotating Left face clockwise" << std::endl;
        int temp[3]{};
        rotateFace(FACE::LEFT);

        // Save the left column from the 5th face (BACK)
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(5, i, 0)];
        }

        // Shift the columns
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 0)] = cube[C_3D_to_1D(2, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 0)] = cube[C_3D_to_1D(0, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 0)] = cube[C_3D_to_1D(4, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 2)] = temp[i];
        }

        return *this;
    }
    RubiksCube &L2() override
    {
        cout << "Rotating LEFT face clockwise 2 times" << std::endl;
        int temp[3]{};

        // Rotate the LEFT face first time
        rotateFace(FACE::LEFT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(5, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 0)] = cube[C_3D_to_1D(2, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 0)] = cube[C_3D_to_1D(0, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 0)] = cube[C_3D_to_1D(4, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 2)] = temp[i];
        }

        // Rotate the LEFT face second time
        rotateFace(FACE::LEFT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(5, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 0)] = cube[C_3D_to_1D(2, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 0)] = cube[C_3D_to_1D(0, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 0)] = cube[C_3D_to_1D(4, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 2)] = temp[i];
        }

        return *this;
    }
    RubiksCube &LPRIME() override
    {
        cout << "Rotating LEFT face ANTI-clockwise" << std::endl;

        int temp[3]{};

        // Rotate the LEFT face first time
        rotateFace(FACE::LEFT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(5, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 0)] = cube[C_3D_to_1D(2, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 0)] = cube[C_3D_to_1D(0, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 0)] = cube[C_3D_to_1D(4, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 2)] = temp[i];
        }

        // Rotate the LEFT face second time
        rotateFace(FACE::LEFT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(5, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 0)] = cube[C_3D_to_1D(2, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 0)] = cube[C_3D_to_1D(0, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 0)] = cube[C_3D_to_1D(4, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 2)] = temp[i];
        }

        // Rotate the LEFT face third time
        rotateFace(FACE::LEFT);

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[C_3D_to_1D(5, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(5, i, 0)] = cube[C_3D_to_1D(2, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(2, i, 0)] = cube[C_3D_to_1D(0, i, 0)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(0, i, 0)] = cube[C_3D_to_1D(4, 2 - i, 2)];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[C_3D_to_1D(4, 2 - i, 2)] = temp[i];
        }

        return *this;
    }
    bool operator==(const RubiksCube1D &r1) const
    {
        for (int i = 0; i < 54; i++)
        {
            if (cube[i] != r1.cube[i])
                return false;
        }
        return true;
    }

    RubiksCube1D &operator=(const RubiksCube1D &r1)
    {
        for (int i = 0; i < 54; i++)
        {
            cube[i] = r1.cube[i];
        }
        return *this;
    }
};
struct Hash1D
{
    size_t operator()(const RubiksCube1D &r1) const
    {
        string str = "";
        for (int i = 0; i < 54; i++)
            str += r1.cube[i];
        return hash<string>()(str);
    }
};