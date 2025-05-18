// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    if (first == nullptr) {
        first = new Car;
        first->prev = first->next = first;
        first->light = light;
    } else {
        Car* last = new Car;
        last->prev = first->prev;
        last->next = first;
        last->light = light;
        first->prev->next = last;
        first->prev = last;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }
    Car* current = first;
    int step = 0;
    current->light = true;
    while (true) {
        current = current->next;
        step++;
        countOp++;
        while (!current->light) {
            current = current->next;
            countOp++;
            step++;
        }
        int length = step;
        current->light = false;
        while (step > 0) {
            current = current->prev;
            countOp++;
            step--;
        }
        if (!current->light) {
            return length;
        }
    }
}


int Train::getOpCount() {
    return countOp;
}
