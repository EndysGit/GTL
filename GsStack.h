//
// Created by Gleb Vorfolomeew on 03/08/2017.
//

#ifndef GTL_GSSTACK_H
#define GTL_GSSTACK_H

#include <iostream>
#include <vector>

namespace gtl {
    template<class T>
    struct Node {
        T data;
        Node<T> *next_node = nullptr;
        Node<T> *previous_node = nullptr;
    };

    template<class T>
    class GsStack {
    public:
        typedef T value_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef Node<T> node_value;
        typedef Node<T> *node_pointer;


        GsStack();

        GsStack(const GsStack<value_type> &stack);

        virtual ~GsStack() {
            if (!isEmpty()) {
                delete m_begin;
                delete m_end;
            }
        }

        GsStack<value_type> &operator=(GsStack stack);

        GsStack<value_type> &operator=(GsStack &&stack);

        reference top() const;

        inline bool isEmpty() const;

        inline size_t size() const;

        void pop();

        void push(const_reference value);

        void swap(GsStack<value_type> &gsstack);

    private:
        node_pointer m_begin;
        node_pointer m_end;
        size_t m_size;
    };

    template<class T>
    GsStack<T>::GsStack() : m_begin{nullptr}, m_end{nullptr}, m_size{0} {}

    template<class T>
    GsStack<T>::GsStack(const GsStack &stack) {
        m_size = 0;

        for (node_pointer element(stack.m_begin); element != stack.m_end; element = element->next_node)
        {
            this->push(element->data);
        }
    }

    template<class T>
    GsStack<T>&
    GsStack<T>::operator=(GsStack stack) {
        this->swap(stack);
        return *this;
    }

    template<class T>
    GsStack<T>&
    GsStack<T>::operator=(GsStack &&stack) {
        this->m_begin = stack.m_begin;
        stack.m_begin = nullptr;

        this->m_begin = stack.m_end;
        stack.m_end = nullptr;

        this->m_size = stack.m_size;
        stack.m_size = 0;

        return *this;

    }

    template<class T>
    typename GsStack<T>::reference
    GsStack<T>::top() const {
        if (isEmpty())
            throw "Stack is already empty";
        return m_end->data;
    }

    template<class T>
    bool
    GsStack<T>::isEmpty() const { return !static_cast<bool>(m_size); }

    template<class T>
    inline
    size_t GsStack<T>::size() const { return m_size; }

    template<class T>
    void
    GsStack<T>::pop() {
        if (isEmpty()) {
            throw "Stack is already empty\n";
        }

        --m_size;

        if (!m_end->previous_node) {
            delete m_end;
            m_end = nullptr;
            m_begin = nullptr;
            return;
        }

        m_end = m_end->previous_node;
        delete m_end->next_node;
        m_end->next_node = nullptr;
    }

    template<class T>
    void
    GsStack<T>::push(const_reference value) {
        if (isEmpty()) {
            m_begin = new(std::nothrow) node_value;
            if (!m_begin)
                throw "Failed to allocate memory";

            m_begin->data = value;
            m_begin->next_node = nullptr;
            m_begin->previous_node = nullptr;

            m_end = m_begin;

            ++m_size;
        } else {
            m_end->next_node = new(std::nothrow) node_value;
            if (!m_end->next_node)
                throw "Failed to allocate memory";

            m_end->next_node->data = value;
            m_end->next_node->next_node = nullptr;
            m_end->next_node->previous_node = m_end;

            m_end = m_end->next_node;

            ++m_size;
        }
    }

    template<class T>
    void
    GsStack<T>::swap(GsStack &gsstack) {
        GsStack::node_pointer temp;

        temp = gsstack.m_begin;
        gsstack.m_begin = this->m_begin;
        this->m_begin = temp;

        temp = gsstack.m_end;
        gsstack.m_end = this->m_end;
        this->m_end = temp;

        std::swap(this->m_size, gsstack.m_size);
    }
}
#endif //GTL_GSSTACK_H
