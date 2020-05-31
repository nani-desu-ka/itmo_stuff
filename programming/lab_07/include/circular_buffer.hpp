#pragma once
#include <vector>

template <class T>
class circular_buffer {
public:
//    using value_type = typename std::iterator<std::random_access_iterator_tag, T>::value_type;
    explicit circular_buffer() {circular_buffer(0);}
    explicit circular_buffer(int capacity): _capacity(capacity) {
        if (_capacity == 0) {
            return;
        }
        if (_capacity > 0) {
            _body = new T [_capacity];
            _begin = &_body[0];
            _end = &_body[0];
            return;
        }
        throw Exception("Incorrect capacity");
    }

    explicit circular_buffer(int capacity, T init_value): _capacity(capacity), _size(capacity) {
        if (_capacity == 0) {
            return;
        }
        if (_capacity > 0) {
            _body = new T [_capacity];
            _begin = &_body[0];
            _end = &_body[_size];
            for (int i = 0; i < _capacity; i++) {
                _body[i] = init_value;
            }
            return;
        }
        throw Exception("Incorrect capacity");
    }

    ~circular_buffer() {
        _begin = nullptr;
        _end = nullptr;
        delete [] _body;
    }

// 4. Доступ в конец, начало
    T *begin() { return _begin; }

    T *end() { return _end; }

    const T *begin() const { return _begin; }

    const T *end() const { return _end; }
//


    void push_back(T temp_value) {
        if (_capacity > 0) {
            if (_size == _capacity) resize(_capacity * 2);
            _body[_size] = temp_value;
            _size++;
            _end++;
        } else {
            resize(1);
            push_back(temp_value);
        }
    }

    void push_front(T temp_value) {
        push_back(temp_value);
        if (_size > 1) {
            int temp_1 = _size - 1;
            int temp_2 = _size - 2;
            while (temp_2 != -1) {
                std::swap(_body[temp_1], _body[temp_2]);
                temp_1--;
                temp_2--;
            }
        }
    }

    void pop_back() {
        if (_size > 0) {
            _end--;
            _size--;
        } else {
            std::cerr << "Nothing to pop\n";
        }
    }

    void pop_front() {
        if (_size > 0) {
            if (_size > 1) {
                int temp_1 = 0;
                int temp_2 = 1;
                while (temp_2 != _size) {
                    std::swap(_body[temp_1], _body[temp_2]);
                    temp_1++;
                    temp_2++;
                }
            }
            pop_back();
        } else {
            std::cerr << "Nothing to pop\n";
        }
    }

    void insert(int position, T temp_value) {
        if (position >= 0 && position < _size) {
            if (position == 0) push_front(temp_value);
            else if (position == _size - 1 || _size == 0) push_back(temp_value);
            else {
                push_back(temp_value);
                int temp_1 = _size - 1;
                int temp_2 = _size - 2;
                while (temp_1 != position) {
                    std::swap(_body[temp_1], _body[temp_2]);
                    temp_1--;
                    temp_2--;
                }
            }
        } else {
            std::cerr << "Incorrect position. Segfault possibility!\n";
        }
    }

    void erase(int position) {
        if (position >= 0 && position < _size) {
            if (_size > 0) {
                if (_size == 1 || position == _size - 1) pop_back();
                else {
                    int temp_1 = position;
                    int temp_2 = position + 1;
                    while (temp_2 != _size) {
                        std::swap(_body[temp_1], _body[temp_2]);
                        temp_1++;
                        temp_2++;
                    }
                    pop_back();
                }
            } else {
                std::cerr << "Nothing to erase\n";
            }
        } else {
            std::cerr << "Incorrect position. Segfault possibility!\n" << std::endl;
        }
    }

    void resize(int capacity) {
        if (capacity < 0) std::cerr << "Incorrect new capacity\n";
        else if (capacity == 0) {
            delete [] _body;
            _capacity = 0;
            _size = 0;
            _begin = nullptr;
            _end = nullptr;
        } else {
            T *temp_body;
            temp_body = new T [_capacity];
            for (int i = 0; i < _size; i++) {
                temp_body[i] = this->_body[i];
            }
            delete [] _body;
            _body = new T [capacity];
            if (capacity < _size) {
                for (int i = 0; i < capacity; i++) {
                    _body[i] = temp_body[i];
                }
                _capacity = capacity;
                _size = capacity;
                _end = &_body[_size];
            } else {
                for (int i = 0; i < _size; i++) {
                    _body[i] = temp_body[i];
                }
                _capacity = capacity;
                _end = &_body[_size];
            }
            _begin = &_body[0];
            delete [] temp_body;
        }
    }

    int size() { return _size; }

    void clear() {
        if (_capacity > 0) {
            _begin = nullptr;
            _end = _data;
            _size = 0;
        }
        _push_front_index = 0;
        _push_back_index = 0;
    }

    void print() {
        std::cout << "Capacity: " << _capacity << '\n';
        std::cout << "Size: " << _size << '\n';
        std::cout << "_begin: " << _begin << '\n';
        std::cout << "_end: " << _end << '\n';
        if (_size != 0) {
            for (int i = 0; i < _size; i++) {
                std::cout << "[" << _body[i] << "] ";
            }
            std::cout << '\n';
        } else {
            std::cout << "Empty_buff\n";
        }
    }

    T &operator[](int index) {
        if (index < _size) return _body[index];
        else std::cerr << "Incorrect index. Segfault possibility!\n";
    }
private:
    T *_begin = nullptr;
    T *_end = nullptr;
    T *_body = nullptr;
    int _capacity = 0;
    int _size = 0;
};