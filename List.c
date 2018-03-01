/*
  Tyler Monaghan
  List.c
  Creates a linked list with nodes from class Node.c
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"List.h"

/** Makes list with default values head = NULL and size = 0 */
struct List_t* makeList(struct List_t* it)
{
	it->head = NULL;
    it->size = 0;
    return it;
}

/** Frees the list and all of its nodes */
struct List_t* freeList(struct List_t* it)
{
    struct Node_t* current = it->head;
    while (getNext(current) != NULL)
    {
		it->head = getNext(current);
		freeNode(current);
		current = NULL;
		current = it->head;
    }
    
    free(current);
    it->head = NULL;
    it->size = 0;
    free(it);
    it = NULL;
    return it;
}

/** getter for size of the list */
size_t size(struct List_t* it)
{
    return it->size;
}

/** inserts a node at the end of the list */
struct Node_t* insert(struct List_t* it, int data)
{
    struct Node_t* newNode = (struct Node_t*)malloc(sizeof(struct Node_t));
    newNode = makeNode2(newNode, data);
    struct Node_t* current = it->head;
    if (current == NULL)
    {
		it->head = newNode;
    }
    else
    {
		while (getNext(current) != NULL)
		{
			current = getNext(current);
		}
		setNext(current, newNode);
    }
    it->size = it->size + 1;
    return newNode;
}

/** finds values equal to input value and returns how many match it */
size_t find(struct List_t* it, int data)
{
    size_t numMatch = 0;
    struct Node_t* current = it->head;
    while(getNext(current) != NULL)
    {
		if (getData(current) == data)
		{
			numMatch++;
		}
		current = getNext(current);
    }    
    return numMatch;
}

/** takes all the data from each node and puts it in a string. returns
 * length of the string */
size_t traverse(struct List_t* it, char* data)
{
    struct Node_t* current = it->head;
    if (current == NULL)
    {
		return 0;
    }
    
    while (current != NULL && getNext(current) != NULL)
    {
		char buffer[20];
		sprintf(buffer, "%d, ", getData(current));
		strcat(data, buffer);
		current = getNext(current);
    }
    char buffer[20];
    sprintf(buffer, "%d", getData(current));
    strcat(data, buffer);
    current = getNext(current);
    
    return strlen(data);
}

/** removes all items with the specified data value */
size_t removeItem(struct List_t* it, int data)
{
    if (it->head == NULL)
    {
		return 0;
    }
    size_t numRem = 0;
    struct Node_t* last;
    struct Node_t* current = it->head;

	//find if the first one (or few) are equal. make new head.
    while (current == it->head)
    {
		if (getData(current) == data)
		{
			if (current == NULL)
			{
				break;
			}
			
			it->head = getNext(current);
			freeNode(current);
			current = it->head;
			numRem++;
		}
		else
		{
			break;
		}
    }
    
    last = current;
    current = getNext(current);

	//take out all instances of the node
    while(current != NULL)
    {
		if (getData(current) == data)
		{
			struct Node_t* next = getNext(current);
			setNext(last, next);
			freeNode(current);
			current = getNext(last);
			numRem++;
		}
		else
		{
			last = current;
			current = getNext(current);
		}
    }
    it->size -= numRem;
    return numRem;
}

/** Same as traverse but string is not given */
char* traverse2(struct List_t* it)
{
    if (it->size == 0)
    {
		return NULL;
    }
    char* data = (char*)calloc(1, 5 * it->size * sizeof(char));
    traverse(it, data);
    return data;
}
