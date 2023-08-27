#pragma once

#ifndef SIMPLE_RANDOM_HPP
#define SIMPLE_RANDOM_HPP 1
#include <random>
#include "coordinates.hpp"

namespace math_expansion
{
    namespace
    {
        std::minstd_rand rand_engine;
        int seed = std::random_device()();
    }

    void seed(int seed)
    {
        rand_engine.seed(seed);
    }


    int_fast32_t randRange(int_fast32_t min, int_fast32_t max)
    {
        // use 64 bit to prevent overflow
        int_fast64_t got = (int_fast64_t)rand_engine();
        return (int_fast64_t)min + (got % ((int_fast64_t)max - (int_fast64_t)min));
    }

    int_fast32_t randRange(int_fast32_t max)
    {
        return randRange(0, max);
    }
}
#endif