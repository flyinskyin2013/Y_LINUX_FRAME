
/*
*	FileName:Y_List.h
*	Version: 1.0
*	Description: The file defines some macroes about some List-APIs 
*	Created On:2016-5-15
*	Modified date:
*	Author:Sky
*
*/

#ifndef _Y_LIST_H
#define _Y_LIST_H

#include "Y_List/Y_List_Impl.h"



//declare a node for head of list .
#define LIST_HEAD(name) \
	Y_LISTHEAD name = LIST_HEAD_INIT(name)

//init a head of list defineded
#define INIT_LIST_HEAD(list)\
	init_list_head(list)


/**
 * LIST_ADD - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
#define LIST_ADD(new, head)\
	list_add(new,head)



/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
#define LIST_ADD_TAIL(new,head) \
	list_add_tail(new,head)


/**
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
#define LIST_DEL_ENTRY(entry) \
	__list_del_entry(entry)


/**
 * node_is_last - tests whether @node is the last entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
#define NODE_IS_LAST(node,head) \
	node_is_last(node,head)




/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 */
#define LIST_ENTRY(ptr, type, member) \
    GET_ENTRY(ptr, type, member)



/**
 * list_first_entry - get the first element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define list_first_entry(ptr, type, member) \
	LIST_ENTRY((ptr)->next, type, member)


/**
 * list_last_entry - get the last element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define list_last_entry(ptr, type, member) \
	LIST_ENTRY((ptr)->prev, type, member)

/**
 * list_next_entry - get the next element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
#define list_next_entry(pos, member) \
	LIST_ENTRY((pos)->member.next, typeof(*(pos)), member)

/**
 * list_prev_entry - get the prev element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
#define list_prev_entry(pos, member) \
	LIST_ENTRY((pos)->member.prev, typeof(*(pos)), member)


/**
 * list_for_each	-	iterate over a list
 * @pos:	the &struct list_head to use as a loop cursor.
 * @head:	the head for your list.
 */
#define LIST_FOR_EACH(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)
#endif //_Y_LIST_H
