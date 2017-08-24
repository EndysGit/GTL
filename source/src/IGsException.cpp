//
// Created by Gleb Vorfolomeew on 24/08/2017.
//

#include "../headers/IGsException.h"

namespace gtl
{
    IGsException::IGsException() {}
    IGsException::~IGsException() {}

    GsConteinerUnderflow::GsConteinerUnderflow(const std::string &exception_definition)
            : m_exeption_definition{exception_definition} {}

    GsConteinerUnderflow::GsConteinerUnderflow(const char *exception_definition)
            : m_exeption_definition{exception_definition} {}

    GsConteinerUnderflow::GsConteinerUnderflow(const GsConteinerUnderflow &gsConteinerUnderflow)
            : m_exeption_definition{gsConteinerUnderflow.m_exeption_definition} {}

    GsConteinerUnderflow::~GsConteinerUnderflow() {}

    const char *
    GsConteinerUnderflow::what() const {
        printf("%s", m_exeption_definition.c_str());
    }
}