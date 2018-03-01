/*
  Tyler Monaghan
  Node.c
  This program creates nodes for a linked list
*/

#include"Node.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/** Creates node with default values next = NULL and data = 0 */
struct Node_t* makeNode1(struct Node_t* it)
{
    it->next = NULL;
    it->data = 0;
    return it;
}

/* Creates node with specified data value */
struct Node_t* makeNode2(struct Node_t* it, int data)
{
    it->next = NULL;
    it->data = data;
    return it;
}

/** Creates node with specified data value and pointer to next */ 
struct Node_t* makeNode4(struct Node_t* it, int data, struct Node_t* next)
{
    it->next = next;
    it->data = data;
    return it;
}

/** Frees a node */
struct Node_t* freeNode(struct Node_t* it)
{
    if (it != NULL)
    {
		free(it);
		it = NULL;
    }
    return NULL;
}

/** Setter for data */
int setData(struct Node_t* it, int data)
{
    it->data = data;
    return data;
}

/* Setter for next */
struct Node_t* setNext(struct Node_t* it, struct Node_t* next)
{
	if (it == NULL)
	{
		it = next;
	}
	else
	{
		it->next = next;
	}
	return next;
}

/** Getter for data */
int getData(struct Node_t* it)
{
	if (it == NULL)
	{
		return 0;
	}
	return it->data;
}

/** Getter for next */
struct Node_t* getNext(struct Node_t* it)
{
    if (it == NULL)
    {
		return NULL;
    }
    return it->next;
}
