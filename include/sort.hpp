#ifndef MIKELIB_SORT_HPP
#define MIKELIB_SORT_HPP

#include <vector>

namespace mikelib
{

        template <typename T>
        void bubble_sort(std::vector<T> &arr)
        {
                int n = arr.size();
                for (int i = 0; i < n - 1; i++)
                {
                        for (int j = 0; j < n - i - 1; j++)
                        {
                                if (arr[j] > arr[j + 1])
                                {
                                        std::swap(arr[j], arr[j + 1]);
                                }
                        }
                }
        }

}

#endif