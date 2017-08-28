//
// Created by Gleb Vorfolomeew on 03/08/2017.
//

#ifndef GTL_GSARRAY_H
#define GTL_GSARRAY_H

/*

        GsArray sinopsis

  template <class T, size_t size>
    class GsArray
    {
    public:
        typedef T                   value_type;
        typedef T*                  pointer;
        typedef const pointer       const_pointer;
        typedef T&                  reference;
        typedef const T&            const_reference;
        typedef T&&                 r_reference;


        GsArray(const std::initializer_list<T>& list);
        virtual ~GsArray() {}

        reference operator[](size_t size_in);
        const_reference operator[](size_t size_in) const ;
        reference at(size_t size_in);
        const_reference at(size_t size_in) const;

        pointer getArray();

        void fill(const_reference value);

        const size_t length() const;

        void reverse();

        void swap(GsArray* array);

    private:
        T m_data[size];
    };

    template<class T, size_t size>
    bool operator==(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator!=(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator<(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator>(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator<=(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator>=(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

 */

#include <initializer_list>
#include "GsArray.h"

namespace gtl
{
    class GsArrayAssignException : public IGsException
    {
    public:
        GsArrayAssignException() {}

        explicit GsArrayAssignException(const std::string &);
        explicit GsArrayAssignException(const char *);

        GsArrayAssignException(const GsArrayAssignException &);

        virtual ~GsArrayAssignException() {}

        virtual const char *what() const;

    private:
        std::string m_exception_message;
    };

    GsArrayAssignException::GsArrayAssignException(const std::string &exception_definition)
            : m_exception_message{exception_definition}
    {}

    GsArrayAssignException::GsArrayAssignException(const char *exception_definition)
            : m_exception_message{exception_definition}
    {}

    GsArrayAssignException::GsArrayAssignException(const GsArrayAssignException &gsArrayAssignException)
            : m_exception_message{gsArrayAssignException.m_exception_message}
    {}

    const char*
    GsArrayAssignException::what() const
    {
        return m_exception_message.c_str();
    }



    template <class T, size_t size>
    class GsArray
    {
    public:
        typedef T                   value_type;
        typedef T*                  pointer;
        typedef T&                  reference;
        typedef const T&            const_reference;
        typedef T&&                 r_reference;


        GsArray(const std::initializer_list<T>& list);
        virtual ~GsArray() {}

        reference operator[](size_t size_in);
        const_reference operator[](size_t size_in) const ;
        reference at(size_t size_in);
        const_reference at(size_t size_in) const;

        pointer getArray();

        void fill(const_reference value);

        const size_t length() const;

        void reverse();

        void swap(GsArray* array);

    private:
        T m_data[size];
    };

    template<class T, size_t size>
    bool operator==(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator!=(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator<(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator>(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator<=(const GsArray<T, size> &v1, const GsArray<T, size> &v2);

    template<class T, size_t size>
    bool operator>=(const GsArray<T, size> &v1, const GsArray<T, size> &v2);


    template <class T, size_t size>
    GsArray<T, size>::GsArray(const std::initializer_list<value_type > &list)
    {
        if (list.size() > size)
            throw GsArrayAssignException("Initializer list larger than array");
        size_t counter = 0;
        for (const auto &element : list )
        {
            m_data[counter] = element;
            ++counter;
        }
    }
    template <class T, size_t size>
    inline
    const size_t
    GsArray<T, size>::length() const { return size; }

    template <class T, size_t size>
    inline
    typename GsArray<T, size>::pointer
    GsArray<T, size>::getArray() { return m_data; }

    template <class T, size_t size>
    inline
    typename GsArray<T, size>::reference
    GsArray<T, size>::operator[](size_t size_in)
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    inline
    typename GsArray<T, size>::const_reference
    GsArray<T, size>::operator[](size_t size_in) const
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    inline
    typename GsArray<T, size>::reference
    GsArray<T, size>::at(size_t size_in)
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    inline
    typename GsArray<T, size>::const_reference
    GsArray<T, size>::at(size_t size_in) const
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    void
    GsArray<T, size>::fill(const_reference value)
    {
        for (ptrdiff_t index(0); index < length(); ++index)
            m_data[index] = value;
    }

    template <class T, size_t size>
    void
    GsArray<T, size>::reverse()
    {
        for (ptrdiff_t index(0); index < length() / 2; ++index)
            std::swap(m_data[index], m_data[length() - 1 - index]);
    }

    template <class T, size_t size>
    void
    GsArray<T, size>::swap(GsArray* array)
    {
        if (size != array->length())
            throw GsArrayAssignException("Arrays not fit each other");
        std::swap(this->m_data, array->m_data);
    }


    template<class T, size_t size>
    inline
    bool
    operator==(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        for (ptrdiff_t index(0); index < size; ++index)
            if (v1[index] != v2[index])
                return false;
        return true;
    }

    template<class T, size_t size>
    inline
    bool
    operator!=(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return !(v1 == v2);
    }

    template<class T, size_t size>
    inline
    bool
    operator<(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() < v2.length();
    }

    template<class T, size_t size>
    inline
    bool
    operator>(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() > v2.length();
    }

    template<class T, size_t size>
    inline
    bool
    operator<=(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() <= v2.length();
    }

    template<class T, size_t size>
    inline
    bool
    operator>=(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() >= v2.length();
    }

}

#endif //GTL_GSARRAY_H
