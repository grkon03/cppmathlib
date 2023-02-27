/*
arbuint.hpp

Begin developing: 2023-02-19

developer github: @grkon03
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../_support/64bitmaps.hpp"
#include "../_support/misc.hpp"
#include "../_support/exception.hpp"

namespace gmathlib
{
    namespace arbtype
    {
        using namespace gmathlib::exception;

        using gmathlib::_support::__64bitmap;
        using std::string;

        /***
         * Declarations
         ***/

        class arbuint
        {
            // data
            __64bitmap bits;
            arbuint *next;
            arbuint *prev;

        public:
            //// constructors

            arbuint();
            arbuint(int);
            arbuint(const arbuint &);

            //// destructors

            ~arbuint();

            //// operators

            arbuint operator<<(int);
            arbuint &operator<<=(int);
            arbuint operator>>(int);
            arbuint &operator>>=(int);

            //// functions

            string ToString();
            string ToString(int);

            arbuint *last();

            //// dangers
            /*
                Dangerous functions, use ONLY for tests or special usages.
            */

            void __danger__SetBits(__64bitmap);
            void __danger__SetNext(arbuint *);
            void __danger__SetPrev(arbuint *);
        };

        //// ostream

        std::ostream &operator<<(std::ostream &os, arbuint au)
        {
            os << au.ToString();
            return os;
        }

        /***
         * Definitions
         ***/

        //// constructors

        arbuint::arbuint() : bits(0), next(nullptr), prev(nullptr){};
        arbuint::arbuint(int num) : bits(num), next(nullptr), prev(nullptr){};
        arbuint::arbuint(const arbuint &au) : bits(au.bits)
        {
            next = nullptr;
            if (au.next != nullptr)
            {
                next = new arbuint(*au.next);
                next->prev = this;
            }
            if (au.prev == nullptr)
                prev = nullptr;
        }

        //// destructors

        arbuint::~arbuint()
        {
            delete next;
        }

        //// operators

        arbuint arbuint::operator<<(int exponent)
        {
            arbuint r;
        }

        arbuint &arbuint::operator<<(int exponent)
        {
        }

        //// functions

        string arbuint::ToString()
        {
            return ToString(10);
        }

        string arbuint::ToString(int base)
        {
            if (base < 1 || base > 36)
                throw GMathArbuintException("Base is out of range in ToString(int base).");

            int i, j, k;
            __64bitmap digits;
            string retstr;

            // 2^2^n-adic process
            for (i = 2, j = 1; i <= 32; i *= i, j *= 2)
            {
                // variable 'j' express size of (2-adic) digits corresponding to a digit of 2^2^i-adic
                if (base == i)
                {
                    // init digits
                    digits = 0;
                    for (k = 0; k < j; ++k)
                    {
                        digits += gmathlib::_support::digit__64bitmap[k];
                    }
                    // make return value
                    for (k = 0; k <= 64; k += j)
                    {
                        retstr = gmathlib::_support::IntToNumberChar(
                                     (bits & digits) / gmathlib::_support::digit__64bitmap[k]) +
                                 retstr;
                        digits <<= j;
                    }

                    if (next != nullptr)
                        retstr = next->ToString() + retstr;
                }
            }

            // other process

            // ToDo: here

            // delete 0s in the head of retstr
            while (true)
            {
                if (retstr[0] == '0')
                    retstr.erase(0, 1);
                else
                    break;
            }

            // add base infomation
            retstr = std::to_string(base) + "|" + retstr;

            return retstr;
        }

        arbuint *arbuint::last()
        {
            if (next == nullptr)
                return this;
            else
                return next->last();
        }

        //// dangers

        void arbuint::__danger__SetBits(__64bitmap b) { bits = b; }
        void arbuint::__danger__SetNext(arbuint *n) { next = n; }
        void arbuint::__danger__SetPrev(arbuint *p) { prev = p; }
    }
}
