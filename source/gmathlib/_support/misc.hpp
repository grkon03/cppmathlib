#pragma once

#include "exception.hpp"

namespace gmathlib
{
    namespace _support
    {
        using namespace gmathlib::exception;

        char IntToNumberChar(int num)
        {
            if (num < 0 || 36 <= num)
                throw GMathLogicException("Unknown Error: A integer has no corresponding char in IntToNumberChar().");
            else if (num <= 9)
                return char('0' + num);
            else
                return char('a' + num - 10);

            return '-';
        }

        int NumberCharToInt(char c)
        {
            if ('0' <= c && c <= '9')
                return int(c - '0');
            else if ('a' <= c && c <= 'z')
                return int(c - 'a') + 10;
            else if ('A' <= c && c <= 'Z')
                return int(c - 'A') + 10;

            throw GMathLogicException("Unknown Error: A char has no corresponding integer in NumberCharToInt().");
        }
    }
}