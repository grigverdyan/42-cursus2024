#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename Func>
void iter(T* arr, size_t length, Func func)
{
    for (size_t i = 0; i < length; ++i) 
    {
        func(arr[i]);
    }
}

#endif // ITER_HPP