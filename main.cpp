#include <iostream>
#include <vector>
#include "GsVector.h"
#include "GsArray.h"
#include <chrono>


using namespace gtl;

class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void testGsVector()
{
    GsVector<int> vec {1,2,3};
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec[i] << ' ';
    std::cout << '\n';
    GsVector<int> vec1{vec};
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec1[i] << ' ';
    std::cout << '\n';
    GsVector<int> vec2;
    vec2 = vec1;
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec2[i] << ' ';
    vec2.reverse();
    std::cout << '\n';
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec2[i] << ' ';
    vec2.resize(4);
    std::cout << '\n';
    for (int i(0); i < vec2.size(); ++i)
        std::cout << vec2[i] << ' ';
    std::cout << vec2.capacity();
    std::cout << '\n';
    vec2.resize(2);
    for (int i(0); i < vec2.size(); ++i)
        std::cout << vec2[i] << ' ';
    std::cout << '\n';
    for (int i(0); i < vec1.size(); ++i)
        std::cout << vec1[i] << ' ';
    std::cout << '\n';
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec[i] << ' ';
    std::cout << '\n';
    GsVector<int> vec {1,2,3};
    for (size_t index(0); index < vec.size(); ++index)
        std::cout << vec[index] << ' ';
    int x = 2;
    vec.insert(1, x);
    std::cout << '\n';
    for (size_t index(0); index < vec.size(); ++index)
        std::cout << vec[index] << ' ';
    std::cout << '\n';
    vec.push_back(x);
    for (size_t index(0); index < vec.size(); ++index)
        std::cout << vec[index] << ' ';
    std::cout << '\n';
    vec.erase(4);
    for (size_t index(0); index < vec.size(); ++index)
        std::cout << vec[index] << ' ';
    std::cout << '\n';
    vec.pop_back();
}

int main() {
    Timer t;
    
    std::cout << t.elapsed();
    return 0;
}