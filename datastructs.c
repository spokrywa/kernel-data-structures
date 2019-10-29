#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/list.h>
#include<linux/random.h>
#include<linux/slab.h>
#include<linux/idr.h>
#include<linux/rbtree.h>

#include "linkedlist.c"
#include "map.c"
#include "queue.c"
#include "linkedlist2.c"
#include "rbtree.c"

MODULE_LICENSE("GPL");

static int dstruct_size = 19;
module_param(dstruct_size, int, 0);

int init_module(void){
	linked_list(dstruct_size);
	queue(dstruct_size);
	//linked_list2(dstruct_size);
	map(dstruct_size);
	rbtree(dstruct_size);
	return 0;
}
void cleanup_module(void){
}

