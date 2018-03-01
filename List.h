/*
  Tyler Monaghan
  List.h
  Creates Linked List Object
*/

#ifndef LIST_H
#define LIST_H

#include"Node.h"

struct List_t
{
	struct Node_t* head;
	size_t size;
};

struct List_t* makeList(struct List_t* it);
struct List_t* freeList(struct List_t* it);
size_t size(struct List_t* it);
struct Node_t* insert(struct List_t* it, int data);
size_t find(struct List_t* it, int data);
size_t traverse(struct List_t* it, char* data);
size_t removeItem(struct List_t* it, int data);
char* traverse2(struct List_t* it);

#endif
