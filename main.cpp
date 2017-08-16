#include <iostream>
#include <vector>
#include "GsVector.h"
#include <iomanip>
#include "GsArray.h"
#include "GsStack.h"
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
    std::cout << "Vector1" << '\n';
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec[i] << ' ';
    std::cout << '\n';
    GsVector<int> vec1{vec};
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec1[i] << ' ';
    std::cout << '\n';
    std::cout << "Vector 2" << '\n';
    GsVector<int> vec2;
    vec2 = vec1;
    std::cout << "Vector 2 after copy assignment with vector1" << '\n';
    for (int i(0); i < vec.size(); ++i)
        std::cout << vec2[i] << ' ';
    std::cout << '\n';
    std::cout << "Vector1 after move assignment with vector2" << '\n';
    for (int i(0); i < vec1.size(); ++i)
        std::cout << vec1[i] << ' ';
    std::cout << '\n';
    GsVector<int> vec4 {std::move(vec1)};
    std::cout << "Vector2 after move assignment with vector1" << '\n';
    for (int i(0); i < vec4.size(); ++i)
        std::cout << vec4[i] << ' ';
    std::cout << '\n';
    std::cout << "Vector1 after move assignment with vector2" << '\n';
    for (int i(0); i < vec1.size(); ++i)
        std::cout << vec1[i] << ' ';
    vec2.reverse();
    std::cout << '\n';
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
    GsVector<int> vec3 {1,2,3};
    for (size_t index(0); index < vec3.size(); ++index)
        std::cout << vec3[index] << ' ';
    int x = 2;
    vec3.insert(1, x);
    std::cout << '\n';
    for (size_t index(0); index < vec3.size(); ++index)
        std::cout << vec3[index] << ' ';
    std::cout << '\n';
    vec3.push_back(x);
    for (size_t index(0); index < vec3.size(); ++index)
        std::cout << vec3[index] << ' ';
    std::cout << '\n';
    vec3.erase(4);
    for (size_t index(0); index < vec3.size(); ++index)
        std::cout << vec3[index] << ' ';
    std::cout << '\n';
    vec3.pop_back();
}

int main() {
    testGsVector();
    GsStack<int> gsstack;

    std::cout << std::boolalpha << gsstack.isEmpty() << ' ' << gsstack.size() << '\n';

    for (int i(0); i < 10; ++i)
        gsstack.push(i + 1);
    std::cout << gsstack.top() << '\n';
    std::cout << std::boolalpha << gsstack.isEmpty() << ' ' << gsstack.size() <<  '\n';

    for (int i(0); i < 10; ++i)
        gsstack.pop();
    std::cout << std::boolalpha << gsstack.isEmpty() << ' ' << gsstack.size() <<  '\n';

    return 0;
}