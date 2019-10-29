struct randnum {
	struct rb_node node;
	int num;
};


struct randnum *rb_search(struct rb_root *root, int findnum)
{
	struct rb_node *node = root->rb_node;
	while(node) {
		struct randnum *data = container_of(node, struct randnum, node);
		if (findnum > data->num)
			node = node->rb_left;
		else if (findnum < data->num)
			node = node->rb_right;
		else
			return data;
	}
	return NULL;
}

bool rb_insert(struct rb_root *root, struct randnum *data)
{
	struct rb_node **new = &(root->rb_node), *parent = NULL;
	while(*new) {
		struct randnum *this = container_of(*new, struct randnum, node);
		parent = *new;
		if(data->num > this->num)
			new = &((*new)->rb_left);
		else if(data->num < this->num)
			new = &((*new)->rb_right);
		else{
			printk("data: %d, this: %d", data->num, this->num);
			return false;

		}
	}
	rb_link_node(&data->node, parent, new);
	rb_insert_color(&data->node,root);
	return true;
}



void rbtree(int dstruct_size)
{
	struct rb_root mytree = RB_ROOT;
	struct rb_node *node;
	int i;

	//fill tree
	for(i=0;i<dstruct_size;i++)
	{
		struct randnum *tmp;
		tmp = kmalloc(sizeof(struct randnum), GFP_KERNEL);
		get_random_bytes(&tmp->num, sizeof(tmp->num));
		rb_insert(&mytree, tmp);

	}
	//print
	for(node = rb_first(&mytree); node; node = rb_next(node))
	{
		printk("RB Number: %d", rb_entry(node, struct randnum, node)->num);
	}	
	//delete
	for(node = rb_first(&mytree); node; node = rb_next(node))
	{
		rb_erase(node, &mytree);
		kfree(node);
	}

}
