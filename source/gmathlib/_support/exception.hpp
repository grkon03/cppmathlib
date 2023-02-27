#pragma once

#include <string>
#include <stdexcept>

namespace gmathlib
{
    namespace exception
    {
        using std::logic_error;
        using std::string;

        // Parent
        class GMathLogicException : public logic_error
        {
        public:
            GMathLogicException(string mes) : logic_error("GMATHLIB Exception :" + mes){};
        };

        // arbuint
        class GMathArbuintException : public GMathLogicException
        {
        public:
            GMathArbuintException(string mes) : GMathLogicException("arbuint: "){};
        };
    }
}