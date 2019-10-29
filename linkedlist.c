#pragma once

struct k_list {
	struct list_head list;
	int num;
};


void linked_list(int dstruct_size) {
	struct k_list *entry;
	struct list_head head;
	struct list_head *ptr,*t;

	INIT_LIST_HEAD(&head);

	int i = 0;
	for(i; i < dstruct_size; i++){
		struct k_list *temp;
		temp=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
		get_random_bytes(&temp->num, sizeof(temp->num));
		list_add(&temp->list,&head);
	}

	list_for_each(ptr,&head){
		entry=list_entry(ptr,struct k_list,list);
		printk(KERN_INFO "LL1 %d  ", entry->num);
	}


	list_for_each_safe(ptr,t,&head){
		entry=list_entry(ptr,struct k_list,list);
		list_del(ptr); 
		kfree(entry); 
	}
}

