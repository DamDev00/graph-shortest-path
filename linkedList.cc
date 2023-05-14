#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <linkedList.h>

std::pair<int, int> getFirst(struct _map** head, int& sizeArray){

    if((*head) == NULL) exit(1);

    int index = 0;

    std::pair<int, int> item;

    item.first = (*head)->x;
    item.second = (*head)->y;

    remove(index, head, sizeArray);

    return item;

}
int remove(int index, struct _map** head, int& sizeArray){

    struct _map* node = (_map*)malloc(sizeof(_map));

    if(index == 0 && (*head) != NULL){
        node = (*head)->next;
        (*head) = node;
        sizeArray--;
        return 1;
    }

    struct _map* prec = (*head);
    struct _map* succ = (*head)->next;
    struct _map* temp = (*head);
    int count = 0;

    while(temp != NULL){
		if(index == count){
			prec->next = temp->next;
			return 0;
		}
		prec = temp;
		temp = temp->next;
        count++;
	}
  
    delete[] node;
    sizeArray--;

    return 1;


}

void print(struct _map **head)
{
	
	struct _map *n = (*head);
	
	while(n != NULL){
		std::cout << n->x << " " << n->y << "\n";
		n = n->next;
	}
	
}

int push(std::pair<int, int> item, struct _map** head, int&& size, int& sizeArray){

    struct _map* node = (_map*)malloc(sizeof(_map));

    node->x = item.first;
    node->y = item.second;
    node->size_src = size;
    node->next = NULL;
   
	
    if((*head) == NULL){
        (*head) = node;
        sizeArray++;
        return 1;
    } 

    struct _map* current = (*head);

    while(current->next != NULL){
        current = current->next;
    }

    current->next = node;
    sizeArray++;

}
