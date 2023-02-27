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

            // bit shift (limited unsigned int)

            arbuint operator<<(unsigned int);
            arbuint &operator<<=(unsigned int);
            arbuint operator>>(unsigned int);
            arbuint &operator>>=(unsigned int);

            // add

            arbuint operator+(unsigned int);
            arbuint operator+(unsigned long long);
            arbuint operator+(arbuint);
            arbuint operator+=(unsigned int);
            arbuint operator+=(unsigned long long);
            arbuint operator+=(arbuint);
            arbuint operator++();

            // sub

            arbuint operator-(unsigned int);
            arbuint operator-(unsigned long long);
            arbuint operator-(arbuint);
            arbuint operator-=(unsigned int);
            arbuint operator-=(unsigned long long);
            arbuint operator-=(arbuint);
            arbuint operator--();

            //// functions

            string ToString();
            string ToString(int);

            arbuint *last();
            arbuint *GetNthNext(unsigned int); // now limited to unsigned int

            __64bitmap GetBits();
            arbuint *GetNext();
            arbuint *GetPrev();

            //// dangers
            /*
                Dangerous functions, use ONLY for tests or special usages.
            */

            void __danger__SetBits(__64bitmap);
            void __danger__SetNext(arbuint *);
            void __danger__SetPrev(arbuint *);

            void __danger__ConnectToTopDigit(arbuint);
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

        arbuint arbuint::operator<<(unsigned int exponent)
        {
            arbuint ret = *this;
            return (ret <<= exponent);
        }

        arbuint &arbuint::operator<<=(unsigned int exponent)
        {
            unsigned int zerofills = exponent / 64;
            unsigned int essexponent = exponent % 64;
            __64bitmap moveup;

            // first, calculate essentially exponential

            moveup = bits / _support::digit__64bitmap[essexponent];
            bits << essexponent;
            *next <<= essexponent;
            *next += moveup;

            // second, add zerofill bits

            arbuint zeros = 0;

            int i;

            if (zerofills >= 1)
            {
                for (i = 1; i < zerofills; ++i)
                {
                    zeros.__danger__ConnectToTopDigit(zeros);
                }
                zeros.__danger__ConnectToTopDigit(*this);
                *this = zeros;
            }

            return *this;
        }

        arbuint arbuint::operator>>(unsigned int inverseExponent)
        {
            arbuint ret = *this;
            return (ret >>= inverseExponent);
        }

        arbuint &arbuint::operator>>=(unsigned int inverseExponent)
        {
            unsigned int willdeleted = inverseExponent / 64;
            unsigned int essinverse = inverseExponent % 64;

            // first, delete some lists

            arbuint *nth = GetNthNext(willdeleted);
            nth->__danger__SetPrev(nullptr);

            *this = *nth;

            // second, calculate essentially inverse exponential

            if (essinverse == 0)
                return *this;

            __64bitmap movedown;

            bits >>= essinverse;
            if (next != nullptr)
            {
                movedown = next->GetBits() % _support::digit__64bitmap[essinverse];
                this->bits += movedown * _support::digit__64bitmap[64 - essinverse];
            }
            *next >>= essinverse;

            return *this;
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
                        retstr = next->ToString(base) + retstr;
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
            if (next == nullptr)
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

        arbuint *arbuint::GetNthNext(unsigned int num)
        {
            unsigned int i;
            arbuint *retp = this;
            for (i = 0; i < num; ++i)
            {
                retp = retp->GetNext();
            }

            return retp;
        }

        __64bitmap arbuint::GetBits() { return bits; }
        arbuint *arbuint::GetNext() { return next; }
        arbuint *arbuint::GetPrev() { return prev; }

        //// dangers

        void arbuint::__danger__SetBits(__64bitmap b) { bits = b; }
        void arbuint::__danger__SetNext(arbuint *n) { next = n; }
        void arbuint::__danger__SetPrev(arbuint *p) { prev = p; }

        void arbuint::__danger__ConnectToTopDigit(arbuint pau)
        {
            arbuint *p = last();
            p->__danger__SetNext(new arbuint(pau));
            p->GetNext()->__danger__SetPrev(p);
        }
    }
}
