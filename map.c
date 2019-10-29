void map(int dstruct_size)
{
	struct idr map;
	int i, start, end;
	int arr[dstruct_size];
	start = 0;
	end = 512;
	idr_init(&map);	
	
	for(i=0;i<dstruct_size;i++)
	{
		int *tmp;
		tmp = kmalloc(sizeof(tmp), GFP_KERNEL);
		get_random_bytes(&tmp, sizeof(tmp));
		printk("id: %d, num: %d", i, tmp);
		arr[i] = idr_alloc(&map, &tmp, start, end, GFP_KERNEL);
	}
	for(i=0;i<dstruct_size;i++)
	{
		int *num;
	        num = idr_find(&map, arr[i]);
		printk(KERN_INFO "Map ID: %d, Number: %d", arr[i], *num);
		idr_remove(&map, arr[i]);
	}
	idr_destroy(&map);
}


