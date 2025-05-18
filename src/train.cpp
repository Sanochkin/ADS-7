// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0),first(nullptr) {}

void Train::addCar(bool light) {
    if (first == nullptr) {
        first = new Car;
        first->prev = first->next = first;
        first->light = light;
    }
    else {
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
    Car* temp = first;
    int length;
    int step = 1;
    temp->light = true;
    while (true) {
        temp = temp->next;
        countOp++;
        while (!temp->light) {
            temp = temp->next;
            countOp++;
            step++;
        }
        length = step;
        temp->light = false;
        while (step > 0) {
            temp = temp->prev;
            countOp++;
            step--;
        }
        if (!temp->light) {
            return length;
        }
    }
}


int Train::getOpCount() {
    return countOp;
}
