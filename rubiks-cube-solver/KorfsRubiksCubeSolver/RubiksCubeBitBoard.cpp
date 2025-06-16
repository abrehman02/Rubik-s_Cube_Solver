#include "RubiksCube.h"
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

class RubiksCubeBitBoard : public RubiksCube
{
public:
    int arr[3][3] = {{0, 1, 2},
                     {7, 8, 3},
                     {6, 5, 4}};
    map<int, int> mp;
    ll cube[6]{};
    ll solver_side_config[6]{};
    ll ones8 = (1 << 8) - 1;
    ll ones24 = (1 << 24) - 1;
    RubiksCubeBitBoard()
    {
        for (int side = 0; side < 6; side++)
        {
            ll clr = 1 << side;
            cube[side] = 0;
            for (int faceIdx = 0; faceIdx < 8; faceIdx++)
            {
                cube[side] |= clr << (8 * faceIdx);
            }
            solver_side_config[side] = cube[side];
        }
        mp[1] = 0;
        mp[2] = 1;
        mp[4] = 2;
        mp[8] = 3;
        mp[16] = 4;
        mp[32] = 5;
    }
    void rotateSide(int s1, int s1_1, int s1_2, int s1_3, int s2, int s2_1, int s2_2, int s2_3)
    {
        uint64_t clr1 = (cube[s2] & (ones8 << (8 * s2_1))) >> (8 * s2_1);
        uint64_t clr2 = (cube[s2] & (ones8 << (8 * s2_2))) >> (8 * s2_2);
        uint64_t clr3 = (cube[s2] & (ones8 << (8 * s2_3))) >> (8 * s2_3);

        cube[s1] = (cube[s1] & ~(ones8 << (8 * s1_1))) | (clr1 << (8 * s1_1));
        cube[s1] = (cube[s1] & ~(ones8 << (8 * s1_2))) | (clr2 << (8 * s1_2));
        cube[s1] = (cube[s1] & ~(ones8 << (8 * s1_3))) | (clr3 << (8 * s1_3));
    }

    void rotateFace(FACE f)
    {
        int fR = static_cast<int>(f);
        ll side = cube[fR];
        side = side >> (8 * 6);
        cube[fR] = (cube[fR] << 16) | (side);
    }

    COLOR getColor(FACE f, unsigned row, unsigned col) const override
    {
        if (arr[row][col] == 8)
        {
            return COLOR((int)f);
        }
        int fn = static_cast<int>(f);
        ll temp = cube[fn];
        int idx = arr[row][col];
        int coloring = ((temp >> (8 * idx)) & ones8);
        return COLOR(mp.at(coloring));
    }
     bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            if (cube[i] != solver_side_config[i]) {
                return false;
            }
        }
        return true;
    }

    RubiksCube &U() override
    {
        rotateFace(FACE::UP);
        ll temp = ones24 & cube[1];
        cube[1] = (cube[1] & ~ones24) | (ones24 & cube[2]);
        cube[2] = (cube[2] & ~ones24) | (ones24 & cube[3]);
        cube[3] = (cube[3] & ~ones24) | (ones24 & cube[4]);
        cube[4] = (cube[4] & ~ones24) | (ones24 & temp);
        return *this;
    }
    RubiksCube &UPRIME() override
    {
        this->U();
        this->U();
        this->U();
        return *this;
    }
    RubiksCube &U2() override
    {
        this->U();
        this->U();

        return *this;
    }
    RubiksCube &L() override
    {
        rotateFace(FACE::LEFT);
        uint64_t clr1 = (cube[2] & (ones8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (cube[2] & (ones8 << (8 * 6))) >> (8 * 6);
        uint64_t clr3 = (cube[2] & (ones8 << (8 * 7))) >> (8 * 7);

        this->rotateSide(2, 0, 7, 6, 0, 0, 7, 6);
        this->rotateSide(0, 0, 7, 6, 4, 4, 3, 2);
        this->rotateSide(4, 4, 3, 2, 5, 0, 7, 6);

        cube[5] = (cube[5] & ~(ones8 << (8 * 0))) | (clr1 << (8 * 0));
        cube[5] = (cube[5] & ~(ones8 << (8 * 6))) | (clr2 << (8 * 6));
        cube[5] = (cube[5] & ~(ones8 << (8 * 7))) | (clr3 << (8 * 7));

        return *this;
    }
    RubiksCube &LPRIME() override
    {
        this->L();
        this->L();
        this->L();
        return *this;
    }
    RubiksCube &L2() override
    {
        this->L();
        this->L();

        return *this;
    }
    RubiksCube &F() override
    {
        this->rotateFace(FACE::FRONT);

        uint64_t clr1 = (cube[0] & (ones8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (cube[0] & (ones8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (cube[0] & (ones8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(0, 4, 5, 6, 1, 2, 3, 4);
        this->rotateSide(1, 2, 3, 4, 5, 0, 1, 2);
        this->rotateSide(5, 0, 1, 2, 3, 6, 7, 0);

        cube[3] = (cube[3] & ~(ones8 << (8 * 6))) | (clr1 << (8 * 6));
        cube[3] = (cube[3] & ~(ones8 << (8 * 7))) | (clr2 << (8 * 7));
        cube[3] = (cube[3] & ~(ones8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };
    RubiksCube &FPRIME() override
    {
        this->F();
        this->F();
        this->F();
        return *this;
    }
    RubiksCube &F2() override
    {
        this->F();
        this->F();

        return *this;
    }
    RubiksCube &R() override
    {
        this->rotateFace(FACE::RIGHT);
        uint64_t clr1 = (cube[0] & (ones8 << (8 * 2))) >> (8 * 2);
        uint64_t clr2 = (cube[0] & (ones8 << (8 * 3))) >> (8 * 3);
        uint64_t clr3 = (cube[0] & (ones8 << (8 * 4))) >> (8 * 4);

        this->rotateSide(0, 2, 3, 4, 2, 2, 3, 4);
        this->rotateSide(2, 2, 3, 4, 5, 2, 3, 4);
        this->rotateSide(5, 2, 3, 4, 4, 7, 6, 0);

        cube[4] = (cube[4] & ~(ones8 << (8 * 7))) | (clr1 << (8 * 7));
        cube[4] = (cube[4] & ~(ones8 << (8 * 6))) | (clr2 << (8 * 6));
        cube[4] = (cube[4] & ~(ones8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube &RPRIME() override
    {
        this->R();
        this->R();
        this->R();

        return *this;
    };

    RubiksCube &R2() override
    {
        this->R();
        this->R();

        return *this;
    };

    RubiksCube &B() override
    {
        this->rotateFace(FACE::BACK);

        uint64_t clr1 = (cube[0] & (ones8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (cube[0] & (ones8 << (8 * 1))) >> (8 * 1);
        uint64_t clr3 = (cube[0] & (ones8 << (8 * 2))) >> (8 * 2);

        this->rotateSide(0, 0, 1, 2, 3, 2, 3, 4);
        this->rotateSide(3, 2, 3, 4, 5, 4, 5, 6);
        this->rotateSide(5, 4, 5, 6, 1, 6, 7, 0);

        cube[1] = (cube[1] & ~(ones8 << (8 * 6))) | (clr1 << (8 * 6));
        cube[1] = (cube[1] & ~(ones8 << (8 * 7))) | (clr2 << (8 * 7));
        cube[1] = (cube[1] & ~(ones8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube &BPRIME() override
    {
        this->B();
        this->B();
        this->B();

        return *this;
    };

    RubiksCube &B2() override
    {
        this->B();
        this->B();

        return *this;
    };

    RubiksCube &D() override
    {
        this->rotateFace(FACE::DOWN);

        uint64_t clr1 = (cube[2] & (ones8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (cube[2] & (ones8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (cube[2] & (ones8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(2, 4, 5, 6, 1, 4, 5, 6);
        this->rotateSide(1, 4, 5, 6, 4, 4, 5, 6);
        this->rotateSide(4, 4, 5, 6, 3, 4, 5, 6);

        cube[3] = (cube[3] & ~(ones8 << (8 * 4))) | (clr1 << (8 * 4));
        cube[3] = (cube[3] & ~(ones8 << (8 * 5))) | (clr2 << (8 * 5));
        cube[3] = (cube[3] & ~(ones8 << (8 * 6))) | (clr3 << (8 * 6));

        return *this;
    };

    RubiksCube &DPRIME() override
    {
        this->D();
        this->D();
        this->D();

        return *this;
    };

    RubiksCube &D2() override
    {
        this->D();
        this->D();

        return *this;
    }
    bool operator==(const RubiksCubeBitBoard &r1) const
    {
        for (int i = 0; i < 6; i++)
        {
            if (cube[i] != r1.cube[i])
                return false;
        }
        return true;
    }

    RubiksCubeBitBoard &operator=(const RubiksCubeBitBoard &r1)
    {
        for (int i = 0; i < 6; i++)
        {
            cube[i] = r1.cube[i];
        }
        return *this;
    }
};
struct HashBitBoard
{
    size_t operator()(const RubiksCubeBitBoard &r1) const
    {
        ll ans = 0;
        for (int i = 0; i < 6; i++)
            ans ^= r1.cube[i];
        return size_t(ans);
    }
};