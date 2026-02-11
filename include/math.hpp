#ifndef MIKE_MATH_HPP
#define MIKE_MATH_HPP

#include <vector>

namespace mikelib
{
        int factorial(int n)
        {
                if (n <= 1)
                        return 1;
                return n * factorial(n - 1);
        }

        template <typename T>
        std::vector<T> sumVector(std::vector<T> numbers)
        {
                std::vector<int> temp = {};
                int temp1 = 0;

                for (int i = 0; i < numbers.size(); i++)
                {
                        if (numbers[i] % 2 == 0)
                        {
                                temp.push_back(numbers[i]);
                        }
                }

                for (int i = 0; i < temp.size(); i++)
                {
                        temp1 += temp[i];
                }

                return temp1;
        }
}

#endif