obj-m += datastructs.o
all:
	make -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules
clean:
	make -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean 
	
