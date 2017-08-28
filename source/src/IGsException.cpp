//
// Created by Gleb Vorfolomeew on 24/08/2017.
//

#include "../headers/IGsException.h"

namespace gtl
{
    GsException::GsException() {}
    GsException::~GsException() {}
    const char* GsException::what() const
    {
        return "Exception";
    }



    GsConteinerUnderflow::GsConteinerUnderflow(const std::string &exception_definition)
            : m_exeption_message{exception_definition} {}

    GsConteinerUnderflow::GsConteinerUnderflow(const char *exception_definition)
            : m_exeption_message{exception_definition} {}

    GsConteinerUnderflow::GsConteinerUnderflow(const GsConteinerUnderflow &gsConteinerUnderflow)
            : m_exeption_message{gsConteinerUnderflow.m_exeption_message} {}

    GsConteinerUnderflow::~GsConteinerUnderflow() {}

    const char *
    GsConteinerUnderflow::what() const
    {
        return m_exeption_message.c_str();
    }
}