//
// Created by Gleb Vorfolomeew on 02/08/2017.
//

#ifndef GTL_GSVECTOR_H
#define GTL_GSVECTOR_H

/*

 GsVector sinopsis

namespace gtl
{
   template<class T>
    class GsVector {
    public:
        typedef T                   value_type;
        typedef T*                  pointer;
        typedef const pointer       const_pointer;
        typedef T&                  reference;
        typedef const T&            const_reference;
        typedef T&&                 r_reference;

        explicit GsVector(size_t length = 0)
                : m_length{length},
                  m_capacity{length + length / 2},
                  m_data{(length) ? (new value_type[length + length / 2]) : nullptr} {}

        GsVector(const GsVector &vector);

        GsVector(GsVector &&vector);

        GsVector(const std::initializer_list<T> &list);

        virtual ~GsVector() { delete[] m_data; }

        GsVector &operator=(GsVector vector);

        GsVector &operator=(GsVector &&vector);

        GsVector &operator=(const std::initializer_list<T> &list);

        reference operator[](size_t size);

        const_reference operator[](size_t size) const;

        reference at(size_t size);

        const_reference at(size_t size) const;

        size_t size() const;

        void resize(size_t size);

        size_t capacity() const;

        void reserve(size_t size);

        void insert(size_t into, const_reference inserted);

        void insert(size_t into, r_reference inserted);

        void erase(size_t size);

        void reverse();

        bool isEmpty();

        friend void gsSwap<value_type >(GsVector &v1, GsVector &v2);

        friend void swap(GsVector &&v1, GsVector &&v2);

        void push_back(const_reference element);

        void push_back(r_reference element);

        value_type pop_back();

    private:
        size_t m_length;
        size_t m_capacity;
        value_type *m_data;
    };
}
*/

#include <iostream>
#include <initializer_list>

namespace gtl {
    template<class T>
    class GsVector;

    template<typename T>
    void gsSwap(GsVector<T> &v1, GsVector<T> &v2);


    template<class T>
    class GsVector {
    public:
        typedef T                   value_type;
        typedef T*                  pointer;
        typedef const pointer       const_pointer;
        typedef T&                  reference;
        typedef const T&            const_reference;
        typedef T&&                 r_reference;

        explicit GsVector(size_t length = 0)
                : m_length{length},
                  m_capacity{length + length / 2},
                  m_data{(length) ? (new value_type[length + length / 2]) : nullptr} {}

        GsVector(const GsVector &vector);

        GsVector(GsVector &&vector);

        GsVector(const std::initializer_list<T> &list);

        virtual ~GsVector() { delete[] m_data; }

        GsVector &operator=(GsVector vector);

        GsVector &operator=(GsVector &&vector);

        GsVector &operator=(const std::initializer_list<T> &list);

        reference operator[](size_t size);

        const_reference operator[](size_t size) const;

        reference at(size_t size);

        const_reference at(size_t size) const;

        size_t size() const;

        void resize(size_t size);

        size_t capacity() const;

        void reserve(size_t size);

        void insert(size_t into, const_reference inserted);

        void insert(size_t into, r_reference inserted);

        void erase(size_t size);

        void reverse();

        bool isEmpty();

        void clear();

        friend void gsSwap<value_type >(GsVector &v1, GsVector &v2);

       // friend void swap(GsVector &&v1, GsVector &&v2);

        void push_back(const_reference element);

        void push_back(r_reference element);

        value_type pop_back();

    private:
        size_t m_length;
        size_t m_capacity;
        value_type *m_data;
    };

    template<class T>
    bool operator==(const GsVector<T> &v1, const GsVector<T> &v2);

    template<class T>
    bool operator!=(const GsVector<T> &v1, const GsVector<T> &v2);

    template<class T>
    bool operator<(const GsVector<T> &v1, const GsVector<T> &v2);

    template<class T>
    bool operator>(const GsVector<T> &v1, const GsVector<T> &v2);

    template<class T>
    bool operator<=(const GsVector<T> &v1, const GsVector<T> &v2);

    template<class T>
    bool operator>=(const GsVector<T> &v1, const GsVector<T> &v2);


    template<class T>
    GsVector<T>::GsVector(const GsVector &vector) {
        m_length = vector.m_length;
        m_capacity = vector.m_capacity;
        m_data = new T[m_length];
        for (ptrdiff_t index(0); index < m_length; ++index)
            m_data[index] = vector.m_data[index];

    }

    template<class T>
    GsVector<T>::GsVector(GsVector &&vector) : GsVector() {
        gsSwap(*this, vector);
    }

    template<class T>
    GsVector<T>::GsVector(const std::initializer_list<T> &list) {
        m_data = new T[list.size()];
        m_length = list.size();

        ptrdiff_t count = 0;
        for (const auto &element : list) {
            m_data[count] = element;
            ++count;
        }
    }

    template<class T>
    GsVector<T> &GsVector<T>::operator=(GsVector vector) {
        gsSwap(*this, vector);
        return *this;
    }

    template<class T>
    GsVector<T> &GsVector<T>::operator=(GsVector &&vector) {
        gsSwap(*this, vector);
        return *this;
    }

    template<class T>
    GsVector<T> &GsVector<T>::operator=(const std::initializer_list<T> &list) {
        if (m_data)
            delete[] m_data;

        m_data = new T[list.size()];
        m_length = list.size();

        ptrdiff_t count = 0;
        for (const auto &element : list) {
            m_data[count] = element;
            ++count;
        }

        return *this;
    }

    template<class T>
    typename GsVector<T>::reference GsVector<T>::operator[](size_t size) {
        if (size < 0 && size >= m_length)
            throw std::out_of_range("Index out of range");

        return m_data[size];
    }

    template<class T>
    typename GsVector<T>::const_reference GsVector<T>::operator[](size_t size) const {
        if (size < 0 && size >= m_length)
            throw std::out_of_range("Index out of range");

        return m_data[size];
    }

    template<class T>
    typename GsVector<T>::reference GsVector<T>::at(size_t size) {
        if (size < 0 && size >= m_length)
            throw std::out_of_range("Index out of range");

        return m_data[size];
    }

    template<class T>
    typename GsVector<T>::const_reference GsVector<T>::at(size_t size) const {
        if (size < 0 && size >= m_length)
            throw std::out_of_range("Index out of range");

        return m_data[size];
    }

    template<class T>
    size_t GsVector<T>::size() const { return m_length; }

    template<class T>
    void GsVector<T>::resize(size_t size) {
        if (size > m_capacity) {
            GsVector<T> temp(size);

            for (ptrdiff_t index(0); index < m_length; ++index)
                temp[index] = m_data[index];

            gsSwap(*this, temp);
        } else
            m_length = size;
    }

    template<class T>
    size_t GsVector<T>::capacity() const { return m_capacity; }

// TODO : Refactor
    template<class T>
    void GsVector<T>::reserve(size_t size) {
        m_capacity = size;

        T *temp = new T[size];

        for (ptrdiff_t index(0); index < m_length; ++index)
            temp[index] = m_data[index];

        if (m_data)
            delete[] m_data;

        m_data = temp;
        temp = nullptr;
    }

    template<class T>
    void GsVector<T>::insert(size_t into, typename GsVector<T>::const_reference inserted) {
        if (into > m_length)
            throw std::out_of_range("Index out of range");

        ++m_length;

        if (m_length > m_capacity) {
            GsVector temp(m_length);

            for (ptrdiff_t index(0); index < into; ++index)
                temp[index] = m_data[index];

            temp[into++] = inserted;            // in this case called operator=() copy semantic

            for (ptrdiff_t index(into); index < m_length; ++index)
                temp[index] = m_data[index - 1];

            gsSwap(*this, temp);

            return;
        } else {
            for (ptrdiff_t index(into + 1); index < m_length; ++index)
                m_data[index] = m_data[index - 1];

            m_data[into] = inserted;

            return;
        }

    }

// TODO : complete
    template<class T>
    void GsVector<T>::insert(size_t into, typename GsVector<T>::r_reference inserted)
    {
        if (into > m_length)
            throw std::out_of_range("Index out of range");

        if (++m_length >= m_capacity) {
            GsVector temp(m_length);

            for (ptrdiff_t index(0); index < into; ++index)
                temp[index] = m_data[index];

            temp[into++] = inserted;            // in this case calls operator=()
                                                // with move semantic
            for (ptrdiff_t index(into); index < m_length; ++index)
                temp[index] = m_data[index - 1];

            gsSwap(*this, temp);

            return;
        } else {
            for (ptrdiff_t index(into + 1); index < m_length; ++index)
                m_data[index] = m_data[index - 1];

            m_data[into] = inserted;

            return;
        }
    }

    template<class T>
    void GsVector<T>::erase(size_t size) {
        if (size >= m_length)
            throw std::out_of_range("Out of range");

       // Check !!!
        --m_length;
        if (m_length == 0)
        {
            clear();
            return;
        }

        for (ptrdiff_t index(size); index < m_length; ++index)
            m_data[index] = m_data[index + 1];
    }

    template<class T>
    void GsVector<T>::reverse() {
        for (ptrdiff_t index = 0; index < m_length / 2; ++index)
            std::swap(m_data[index], m_data[m_length - 1 - index]);
    }

    template<class T>
    bool GsVector<T>::isEmpty() { return (!m_length) ? true : false; }

    template <class T>
    void GsVector<T>::clear()
    {
        m_length = 0;
        m_capacity = 0;

        if (m_data)
            delete [] m_data;

        m_data = nullptr;
    }

    template<class T>
    void gsSwap(GsVector<T> &v1, GsVector<T> &v2) {
        std::swap(v1.m_length, v2.m_length);
        std::swap(v1.m_capacity, v2.m_capacity);
        std::swap(v1.m_data, v2.m_data);
    }

    template<class T>
    void GsVector<T>::push_back(typename GsVector<T>::const_reference element) {
        insert(m_length, element);
    }

    template<class T>
    void GsVector<T>::push_back(typename GsVector<T>::r_reference element) {
        insert(m_length, element);
    }

    template<class T>
    T GsVector<T>::pop_back() {
        if (isEmpty())
            throw std::out_of_range("GsVector is empty");

        if (m_length == 1) {

            T&& temp = std::move(m_data[0]);

            clear();

            return temp;
        }

        --m_length;

        return m_data[m_length];
    }


    template<class T>
    bool operator==(const GsVector<T> &v1, const GsVector<T> &v2) {
        if (v1.size() == v2.size())
            for (ptrdiff_t index(0); index < v1.size(); ++index)
                if (v1[index] != v2[index])
                    return false;
        return true;
    }

    template<class T>
    bool operator!=(const GsVector<T> &v1, const GsVector<T> &v2) {
        return !(v1 == v2);
    }

    template<class T>
    bool operator<(const GsVector<T> &v1, const GsVector<T> &v2) {
        return v1.size() < v2.size();
    }

    template<class T>
    bool operator>(const GsVector<T> &v1, const GsVector<T> &v2) {
        return v1.size() > v2.size();
    }

    template<class T>
    bool operator<=(const GsVector<T> &v1, const GsVector<T> &v2) {
        return v1.size() <= v2.size();
    }

    template<class T>
    bool operator>=(const GsVector<T> &v1, const GsVector<T> &v2) {
        return v1.size() >= v2.size();
    }
} // gtl
#endif //GTL_GSVECTOR_H
