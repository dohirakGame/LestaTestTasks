#include <iostream>
#include <vector>

using namespace std;

class CircularBufferV1 {
private:
    int* buffer;
    size_t head;
    size_t tail;
    size_t max_size;
    size_t current_size;

public:
    CircularBufferV1(size_t max_size) : head(0), tail(0), max_size(max_size), current_size(0) {
        buffer = new int[max_size];
    }

    ~CircularBufferV1() {
        delete[] buffer;
    }

    bool push(int item) {
        if (IsFull()) {
            cout << "Buffer is full";
            return false;
        }
        buffer[tail] = item;
        tail = (tail + 1) % max_size;
        current_size++;
        return true;
    }

    bool pop() {
        if (IsEmpty()) {
            cout << "Buffer is empty";
            return false;
        }

        int item = buffer[head];
        head = (head + 1) % max_size;
        current_size--;
        return true;
    }

    bool IsFull() const {
        return current_size == max_size;
    }

    bool IsEmpty() const {
        return current_size == 0;
    }
};

class CircularBufferV2 {
private:
    vector<int> buffer;
    size_t head;
    size_t tail;
    size_t current_size;
public:
    CircularBufferV2(size_t size) : buffer(size), head(0), tail(0), current_size(0) {}

    bool push(int item) {
        if (IsFull()) {
            cout << "Buffer is full";
            return false;
        }
        buffer[tail] = item;
        tail = (tail + 1) % buffer.size();
        current_size++;
        return true;
    }

    bool pop() {
        if (IsEmpty()) {
            cout << "Buffer is empty";
            return false;
        }

        int item = buffer[head];
        head = (head + 1) % buffer.size();
        current_size--;
        return true;
    }

    bool IsFull() const {
        return current_size == buffer.size();
    }

    bool IsEmpty() const {
        return current_size == 0;
    }
};

int main() {

    return 0;
}
