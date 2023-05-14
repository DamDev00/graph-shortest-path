#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

struct _map {
    _map* next;
    int size_src;
    int x, y;
};

void print(struct _map **head);

int push(std::pair<int, int> item, struct _map** head, int&& size, int& sizeArray);

int remove(int index, struct _map** head, int& sizeArray);

std::pair<int, int> getFirst(struct _map** head, int& sizeArray);
