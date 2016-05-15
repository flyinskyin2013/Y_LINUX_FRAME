/*
*	FileName:Y_List.h
*	Version: 1.0
*	Description: The file defines some macroes about list of data-structure.many codes come from 
*	linux kernel list
*	Created On:2016-5-15
*	Modified date:
*	Author:Sky
*
*/

#ifndef _Y_LIST_IMPL_H
#define _Y_LIST_IMPL_H

//list struct
typedef struct y_list_head {

	struct y_list_head *next;
	struct y_list_head *prev;
} Y_LISTHEAD;



//***************************************************



//caculate offset-value about member to start of the struct 
#define OFFSET(type, member) ((unsigned int) &((type *)0)->member)

#define GET_ENTRY(ptr, type, member) \
({    					\
    const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
    (type *)( (char *)__mptr - OFFSET(type,member) );		\
})




//***************************************************
//init head node 
#define LIST_HEAD_INIT(name) {&(name),&(name)}


//***************************************************

//init a head of list defineded
static inline void INIT_LIST_HEAD(Y_LISTHEAD *list)
{
    list->next = list;
    list->prev = list;
}


//***************************************************


/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(Y_LISTHEAD *new,
                  Y_LISTHEAD *prev,
                  Y_LISTHEAD *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(Y_LISTHEAD *new, Y_LISTHEAD *head)
{
    __list_add(new, head, head->next);
}

/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void list_add_tail(Y_LISTHEAD *new, Y_LISTHEAD *head)
{
	__list_add(new, head->prev, head);
}





//***************************************************


/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_del(Y_LISTHEAD * prev, Y_LISTHEAD * next)
{
	next->prev = prev;
	prev->next = next;
}


/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
static inline void __list_del_entry(Y_LISTHEAD *entry)
{
	__list_del(entry->prev, entry->next);
}





//***************************************************




/**
 * node_is_last - tests whether @node is the last entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
static inline int node_is_last(const Y_LISTHEAD *node,
				const Y_LISTHEAD *head)
{
	return (node->next == head);
}

//***************************************************


#endif //_Y_LIST_IMPL_H
