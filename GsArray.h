//
// Created by Gleb Vorfolomeew on 03/08/2017.
//

#ifndef GTL_GSARRAY_H
#define GTL_GSARRAY_H

namespace gtl
{
    template <class T, size_t size>
    class GsArray
    {
    public:
        virtual ~GsArray() {}

        T& operator[](size_t size_in);
        const T& operator[](size_t size_in) const ;
        T& at(size_t size_in);
        const T& at(size_t size_in) const;

        T* getArray();

        void fill(const T& value);

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
    inline const size_t GsArray<T, size>::length() const { return size; }

    template <class T, size_t size>
    T* GsArray<T, size>::getArray() { return m_data; }

    template <class T, size_t size>
    T& GsArray<T, size>::operator[](size_t size_in)
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    const T& GsArray<T, size>::operator[](size_t size_in) const
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    T& GsArray<T, size>::at(size_t size_in)
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    const T& GsArray<T, size>::at(size_t size_in) const
    {
        return m_data[size_in];
    }

    template <class T, size_t size>
    void GsArray<T, size>::fill(const T& value)
    {
        for (ptrdiff_t index(0); index < length(); ++index)
            m_data[index] = value;
    }

    template <class T, size_t size>
    void GsArray<T, size>::reverse()
    {
        for (ptrdiff_t index(0); index < length() / 2; ++index)
            std::swap(m_data[index], m_data[length() - 1 - index]);
    }

    template <class T, size_t size>
    void GsArray<T, size>::swap(GsArray* array)
    {
        if (size != array->length())
            throw "arrays not fit each other";
        std::swap(this->m_data, array->m_data);
    }


    template<class T, size_t size>
    bool operator==(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        for (ptrdiff_t index(0); index < size; ++index)
            if (v1[index] != v2[index])
                return false;
        return true;
    }

    template<class T, size_t size>
    bool operator!=(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return !(v1 == v2);
    }

    template<class T, size_t size>
    bool operator<(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() < v2.length();
    }

    template<class T, size_t size>
    bool operator>(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() > v2.length();
    }

    template<class T, size_t size>
    bool operator<=(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() <= v2.length();
    }

    template<class T, size_t size>
    bool operator>=(const GsArray<T, size> &v1, const GsArray<T, size> &v2)
    {
        return v1.length() >= v2.length();
    }

}

#endif //GTL_GSARRAY_H
