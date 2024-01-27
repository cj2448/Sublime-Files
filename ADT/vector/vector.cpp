#include "vector.h"
#include <initializer_list>

template <typename E>
std::vector<E>::vector() {  }


template <typename E>
std::vector<E>::vector(std::initializer_list<E> ilist) {
    arr = new E[ilist.size()];
    auto i = 0;
    n = ilist.size();
    for (const auto& obj : ilist)
        arr[i++] = obj;
}


template <typename E>
std::vector<E>::vector(size_t count, const E& value) {
    arr = new E[count];
    n = count;
    for (auto i = 0; i < count; ++i)
        arr[i] = value;
}


template <typename E>
std::vector<E>::vector(size_t count, E&& value) {
    arr = new E[count];
    n = count;
    for (auto i = 0; i < count; ++i)
        arr[i] = value;
}



template <typename E>
std::vector<E>::vector(iterator first, iterator last) {
    auto i = 0;
    while (first != last) {
        arr[i++] = *first;
        ++first;
    }
    n = i;
}


template <typename E>
std::vector<E>::~vector() { delete arr; }


// template <typename E>
// constexpr E& at(size_t pos);


// template <typename E>
// constexpr const E& at(size_t pos) const;


template <typename E>
constexpr E& operator[](size_t pos) { return arr[pos]; }


// template <typename E>
// constexpr const E& operator[](size_t pos) const { return arr[pos]; }

// constexpr E& front();
// constexpr const E& front() const;

// constexpr E& back();
// constexpr const E& back() const;

// constexpr E* data() noexcept;
// constexpr const E* data() const;