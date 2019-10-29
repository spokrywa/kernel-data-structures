#include "linkedlist.c"

void queue(int dstruct_size)
{
	struct k_list *entry;
	struct list_head head;
	struct list_head *ptr,*t;
	INIT_LIST_HEAD(&head);
	int i = 0;
	for(i; i < dstruct_size; i++){
		struct k_list *temp;
		temp=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
		get_random_bytes(&temp->num, sizeof(temp->num));
		list_add_tail(&temp->list,&head);
	}
	list_for_each_safe(ptr,t,&head){
		entry=list_entry(ptr,struct k_list,list);
		printk(KERN_INFO "Queue %d  ", entry->num);
		list_del(ptr);
		kfree(entry);
	}

}


