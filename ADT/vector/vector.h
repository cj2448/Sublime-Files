#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

namespace std {
    template <typename E>
    class vector {
    //  Member Types
    private:
        E* arr;
        size_t n;

    //  Member classes
    public:
        class iterator {
        private:
            E* pos;

        public:
            iterator() : pos{nullptr} {  }
            void operator = (const iterator &other) { this->pos = other.pos; }
            E& operator * () { return *pos; }
            iterator& operator ++ () { ++pos; return *this; }
            iterator operator ++ (int) { iterator temp = *this; ++*this; return temp; }
            iterator& operator -- () { --pos; return *this; }
            iterator operator -- (int) { iterator temp = *this; --*this; return temp; }
            iterator& operator += (int n) { this->pos += n; return *this; }
            iterator& operator -= (int n) { this->pos -= n; return *this; }
         };

        class const_iterator {

        };
        //  class reverse_iterator;
        //  class const_reverse_iterator;


    //  Constructor/Destructor
    public:
        vector();
        vector(std::initializer_list<E> ilist);
        vector(size_t count, const E& value);
        vector(size_t count, E&& value);
        // vector(E* first, E* last);
        vector(iterator first, iterator last);
        ~vector();


    //  Element Access
    public:
        constexpr E& at(size_t pos);
        constexpr const E& at(size_t pos) const;

        constexpr E& operator[](size_t pos);
        constexpr const E& operator[](size_t pos) const;

        constexpr E& front();
        constexpr const E& front() const;

        constexpr E& back();
        constexpr const E& back() const;

        constexpr E* data() noexcept;
        constexpr const E* data() const;


    //  Iterators
    public:
        constexpr iterator begin() noexcept;
        constexpr const_iterator begin() const noexcept;
        constexpr const_iterator cbegin() const noexcept;

        constexpr iterator end() noexcept;
        constexpr const_iterator end() const noexcept;
        constexpr const_iterator cend() const noexcept;

        // constexpr reverse_iterator rbegin() noexcept;
        // constexpr const_reverse_iterator rbegin() const noexcept;
        // constexpr const_reverse_iterator crbegin() const noexcept;

        // constexpr reverse_iterator rend() noexcept;
        // constexpr const_reverse_iterator rend() const noexcept;
        // constexpr const_reverse_iterator crend() const noexcept;


    //  Capacity
    public:
        [[nodiscard]] constexpr bool empty() const noexcept;
        constexpr size_t size() const noexcept;
        constexpr size_t max_size() const noexcept;
        constexpr void reserve(size_t new_cap);
        constexpr size_t capacity() const noexcept;
        constexpr void shrink_to_fit();


    //  Modifiers
    public:
        constexpr void clear() noexcept;
        constexpr iterator insert(const_iterator pos, const E& value);
        constexpr iterator insert(const_iterator pos, E&& value);
        constexpr iterator insert(const_iterator pos, size_t count, const E& value);
        constexpr iterator insert(const_iterator pos, iterator first, iterator last);
        constexpr iterator insert(const_iterator pos, std::initializer_list<E> ilist);
        constexpr iterator erase(const_iterator pos);
        constexpr iterator erase(const_iterator first, const_iterator last);
        constexpr void push_back(const E& value);
        constexpr void push_back(E&& value);
        constexpr void pop_back();
        constexpr void resize(size_t count);
        constexpr void resize(size_t count, const size_t& value);
        // constexpr void swap(vector& other) noexcept;
    };
}
#include "vector.cpp"
#endif