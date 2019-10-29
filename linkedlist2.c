#include "linkedlist.c"

void linked_list2_print(struct list_head head)
{
	struct k_list *entry;
	struct list_head *ptr;
	list_for_each(ptr,&head){
		entry=list_entry(ptr,struct k_list,list);
	printk(KERN_INFO "LL2 %d  \n ", entry->num);

	}

}

void linked_list2_free(struct list_head head)
{
	struct k_list *entry;
	struct list_head *ptr,*t;
	list_for_each_safe(ptr,t,&head){
		entry=list_entry(ptr,struct k_list,list);
		list_del(ptr);
		kfree(entry);
	}
}

void linked_list2(int dstruct_size)
{
	struct list_head head;

	INIT_LIST_HEAD(&head);
	int i = 0;
	for(i; i < dstruct_size; i++){
		struct k_list *temp;
		temp=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
		get_random_bytes(&temp->num, sizeof(temp->num));
		list_add(&temp->list,&head);
	}
	linked_list2_print(head);
	linked_list2_free(head);
}


