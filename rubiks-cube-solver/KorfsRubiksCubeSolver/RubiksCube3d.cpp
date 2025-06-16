//
// Created by heisenberg on 12/13/24.
//
#include "RubiksCube.h"
#include <bits/stdc++.h>
using namespace std;
class RubiksCube3d : public RubiksCube
{

    void rotateFace(FACE f)
    {
        int temp[3][3]{};
        int fR = static_cast<int>(f);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[i][j] = cube[fR][i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cube[fR][j][2 - i] = temp[i][j];
            }
        }
    }
    void rotateFace(int f)
    {
        int temp[3][3]{};
        int fR = f;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[i][j] = cube[fR][i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cube[fR][j][2 - i] = temp[i][j];
            }
        }
    }

public:
    char cube[6][3][3]{};
    // constructor
    RubiksCube3d()
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }
    bool isSolved() const override
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (this->cube[i][j][k] == getColorLetter(COLOR(i)))
                    continue;
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}
    COLOR getColor(FACE face, unsigned row, unsigned col) const override
    {
        char c = cube[(int(face))][row][col];
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
    RubiksCube &RotateF()
    {
        rotateFace(FACE::FRONT);
        int temp[3]{};
        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[3][i][0];
            cube[3][i][0] = cube[0][2][i];
            cube[0][2][i] = cube[1][2 - i][2];
            cube[1][2 - i][2] = cube[5][0][2 - i];
            cube[5][0][2 - i] = temp[i];
        }
        return *this;
    }
    RubiksCube &F() override
    {
        // cout << "Rotating Front face clockwise" << std::endl;
        return RotateF();
    };
    RubiksCube &FPRIME() override
    {
        // cout << "Rotating Front face anti-clockwise\n";
        RotateF();
        RotateF();
        RotateF();
        return *this;
    };
    RubiksCube &F2() override
    {
        // cout << "Rotating Front face twice\n";
        RotateF();
        RotateF();
        return *this;
    }
    RubiksCube &RotateU()
    {
        rotateFace(FACE::UP);
        int temp[3]{};

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[1][0][i];
        }

        // Update the top row of adjacent faces
        for (int i = 0; i < 3; i++)
        {
            cube[1][0][i] = cube[2][0][i];
            cube[2][0][i] = cube[3][0][i];
            cube[3][0][i] = cube[4][0][i];
            cube[4][0][i] = temp[i];
        }

        return *this;
    }

    RubiksCube &U() override
    {
        // cout << "Rotating UP face clockwise" << std::endl;
        return RotateU();
    }

    RubiksCube &UPRIME() override
    {
        // cout << "Rotating UP face counterclockwise" << std::endl;

        RotateU();
        RotateU();
        RotateU();
        return *this;
    }

    RubiksCube &U2() override
    {
        // cout << "Rotating UP face twice" << std::endl;

        RotateU();
        RotateU();
        return *this;
    }
    RubiksCube &RotateD()
    {
        rotateFace(FACE::DOWN);
        int temp[3]{};

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[1][2][i];
        }

        for (int i = 0; i < 3; i++)
        {
            cube[1][2][i] = cube[4][2][i];
            cube[4][2][i] = cube[3][2][i];
            cube[3][2][i] = cube[2][2][i];
            cube[2][2][i] = temp[i];
        }

        return *this;
    }

    RubiksCube &D() override
    {
        // cout << "Rotating DOWN face clockwise" << std::endl;
        RotateD();
        RotateD();
        RotateD();
        return *this;
    }

    RubiksCube &DPRIME() override
    {
        // cout << "Rotating DOWN face Anti-clockwise" << std::endl;

        return RotateD();
    }

    RubiksCube &D2() override
    {
        // cout << "Rotating DOWN face twice" << std::endl;

        RotateD();
        RotateD();
        return *this;
    }
    RubiksCube &RotateB()
    {
        rotateFace(FACE::BACK);
        int temp[3]{};

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[0][0][i];
        }

        for (int i = 0; i < 3; i++)
        {
            cube[0][0][i] = cube[1][2 - i][0];
            cube[1][2 - i][0] = cube[5][2][2 - i];
            cube[5][2][2 - i] = cube[3][i][2];
            cube[3][i][2] = temp[i];
        }

        return *this;
    }

    RubiksCube &B() override
    {
        // cout << "Rotating BACK face clockwise" << std::endl;
        return RotateB();
    }

    RubiksCube &BPRIME() override
    {
        // cout << "Rotating BACK face counterclockwise" << std::endl;
        RotateB();
        RotateB();
        RotateB();
        return *this;
    }

    RubiksCube &B2() override
    {
        // cout << "Rotating BACK face twice" << std::endl;
        RotateB();
        RotateB();
        return *this;
    }
    RubiksCube &RotateR()
    {
        rotateFace(FACE::RIGHT);
        int temp[3]{};

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[0][i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[0][i][2] = cube[2][i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[2][i][2] = cube[5][i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[5][i][2] = cube[4][2 - i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[4][2 - i][0] = temp[i];
        }

        return *this;
    }

    RubiksCube &R() override
    {
        // cout << "Rotating RIGHT face clockwise" << std::endl;    
        return RotateR();
    }

    RubiksCube &RPRIME() override
    {
        // cout << "Rotating RIGHT face counterclockwise" << std::endl;
        RotateR();
        RotateR();
        RotateR();
        return *this;
    }

    RubiksCube &R2() override
    {
        // cout << "Rotating RIGHT face twice" << std::endl;
        RotateR();
        RotateR();
        return *this;
    }
    RubiksCube &RotateL()
    {
        rotateFace(FACE::LEFT);
        int temp[3]{};

        for (int i = 0; i < 3; i++)
        {
            temp[i] = cube[5][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[5][i][0] = cube[2][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[2][i][0] = cube[0][i][0];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[0][i][0] = cube[4][2 - i][2];
        }
        for (int i = 0; i < 3; i++)
        {
            cube[4][2 - i][2] = temp[i];
        }

        return *this;
    }

    RubiksCube &L() override
    {
        // cout << "Rotating LEFT face clockwise" << std::endl;
        return RotateL();
    }

    RubiksCube &LPRIME() override
    {
        // cout << "Rotating LEFT face counterclockwise" << std::endl;
        RotateL();
        RotateL();
        RotateL();
        return *this;
    }

    RubiksCube &L2() override
    {
        // cout << "Rotating LEFT face twice" << std::endl;
        RotateL();
        RotateL();
        return *this;
    }
    bool operator==(const RubiksCube3d &r1) const
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (r1.cube[i][j][k] != cube[i][j][k])
                        return false;
                }
            }
        }
        return true;
    }
    RubiksCube3d &operator=(const RubiksCube3d &r1)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};
struct Hash3D
{
    size_t operator()(const RubiksCube3d &r1) const
    {
        string str = "";
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};