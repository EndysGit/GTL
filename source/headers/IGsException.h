//
// Created by Gleb Vorfolomeew on 17/08/2017.
//

#ifndef GTL_GSEXCEPTION_H
#define GTL_GSEXCEPTION_H

#include <exception>
#include <string>
#include <iostream>

namespace gtl {

    // ?: Mayby inheret from std::exception
    class IGsException
    {
    public:
        virtual const char *what() const = 0;
    };

    class GsException : public IGsException
    {
    public:
        GsException();

        virtual ~GsException();

        virtual const char *what() const ;
    };

    class GsConteinerUnderflow : public GsException
    {
    public:
        explicit GsConteinerUnderflow(const std::string &exception_definition);
        explicit GsConteinerUnderflow(const char *exception_definition);

        GsConteinerUnderflow(const GsConteinerUnderflow &gsConteinerUnderflow);

        virtual ~GsConteinerUnderflow();

        virtual const char * what() const;

    private:
        std::string m_exeption_message;
    };

}

#endif //GTL_GSEXCEPTION_H
