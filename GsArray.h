//
// Created by Gleb Vorfolomeew on 03/08/2017.
//

#ifndef GTL_GSARRAY_H
#define GTL_GSARRAY_H

#include <array>


std::array<int, 3> arr {1,2,3};

namespace gtl
{
    template <class T, size_t size>
    class GsArray
    {
    public:
        GsArray(const GsArray& array);
        GsArray(GsArray&& array);

        T& operator[](size_t size_in);
        const T& operator[](size_t size_in) const ;
        T& at(size_t size_in);
        const T& at(size_t size_in) const;

        void fill(const T& value);

        size_t length();

        void reverse();

        void swap(const GsArray& array);
        void swap(GsArray&& array);

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
    GsArray<T, size>::GsArray(const GsArray& array)
    {

    }

    template <class T, size_t size>
    GsArray<T, size>::GsArray(GsArray&& array)
    {

    }

    template <class T, size_t size>
    inline size_t GsArray<T, size>::length() { return size; }


}

#endif //GTL_GSARRAY_H
