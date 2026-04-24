// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Item {
        T data;
        Item* next;
        explicit Item(const T& d) : data(d), next(nullptr) {}
    };

    Item* head;

 public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (head) {
            Item* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void push(const T& elem) {
        Item* item = new Item(elem);

        if (!head || elem.prior > head->data.prior) {
            item->next = head;
            head = item;
            return;
        }

        Item* cur = head;
        while (cur->next && cur->next->data.prior >= elem.prior) {
            cur = cur->next;
        }

        item->next = cur->next;
        cur->next = item;
    }

    T pop() {
        if (!head) {
            return T();
        }
        Item* tmp = head;
        T result = head->data;
        head = head->next;
        delete tmp;
        return result;
    }
};

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
