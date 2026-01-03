#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <chrono>
#include <random>

namespace Random
{
    
    inline std::mt19937 generate()
    {
        std::random_device rd{};

        
        std::seed_seq ss{
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
                rd(), rd(), rd(), rd(), rd(), rd(), rd() };

        return std::mt19937{ ss };
    }

    
    inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

    // Generate a random int between [min, max] (inclusive)
    inline int get(int min, int max)
    {
        return std::uniform_int_distribution{min, max}(mt);
    }

    // Generate a random value between [min, max] (inclusive)
    // * min and max must have the same type
    // * return value has same type as min and max
    // * Supported integer types:
    // *    short, int, long, long long
    // *    unsigned short, unsigned int, unsigned long, or unsigned long long
    template <typename T>
    typename std::enable_if<std::is_integral<T>::value, T>::type
    get(T min, T max)
    {
        return std::uniform_int_distribution<T>{min, max}(mt);
    }

    // Generate a random floating-point value between [min, max] (inclusive)
    // * min and max must have the same type
    // * return value has same type as min and max
    // * Supported floating-point types:
    // *    float, double, long double
    template <typename T>
    typename std::enable_if<std::is_floating_point<T>::value, T>::type
    get(T min, T max)
    {
        return std::uniform_real_distribution<T>{min, max}(mt);
    }

    template <typename R, typename S, typename T>
    R get(S min, T max)
    {
        return get<R>(static_cast<R>(min), static_cast<R>(max));
    }
}

#endif