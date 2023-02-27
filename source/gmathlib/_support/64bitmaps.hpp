#pragma once

namespace gmathlib
{
    namespace _support
    {
        // 64 bits bitmap
        typedef unsigned long long int __64bitmap;

        // 64 bits bitmap constants

        // each digit of 64 bits bitmap

        constexpr __64bitmap digit__64bitmap[64] = {
            1ULL << 00,
            1ULL << 01,
            1ULL << 02,
            1ULL << 03,
            1ULL << 04,
            1ULL << 05,
            1ULL << 06,
            1ULL << 07,
            1ULL << 010,
            1ULL << 011,
            1ULL << 012,
            1ULL << 013,
            1ULL << 014,
            1ULL << 015,
            1ULL << 016,
            1ULL << 017,
            1ULL << 020,
            1ULL << 021,
            1ULL << 022,
            1ULL << 023,
            1ULL << 024,
            1ULL << 025,
            1ULL << 026,
            1ULL << 027,
            1ULL << 030,
            1ULL << 031,
            1ULL << 032,
            1ULL << 033,
            1ULL << 034,
            1ULL << 035,
            1ULL << 036,
            1ULL << 037,
            1ULL << 040,
            1ULL << 041,
            1ULL << 042,
            1ULL << 043,
            1ULL << 044,
            1ULL << 045,
            1ULL << 046,
            1ULL << 047,
            1ULL << 050,
            1ULL << 051,
            1ULL << 052,
            1ULL << 053,
            1ULL << 054,
            1ULL << 055,
            1ULL << 056,
            1ULL << 057,
            1ULL << 060,
            1ULL << 061,
            1ULL << 062,
            1ULL << 063,
            1ULL << 064,
            1ULL << 065,
            1ULL << 066,
            1ULL << 067,
            1ULL << 070,
            1ULL << 071,
            1ULL << 072,
            1ULL << 073,
            1ULL << 074,
            1ULL << 075,
            1ULL << 076,
            1ULL << 077,
        };
    }
}
