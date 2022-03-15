#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Guruvu");
MODULE_DESCRIPTION("Basic Module");



static int __init Ass21_init(void) {

	printk(KERN_EMERG "Kernel Module Loaded\n");
	return 0;
}


static void __exit Ass21_exit(void) {

	printk(KERN_EMERG "Kernel Module Removed\n");
	//pr_emerg("Kernel Module Removed\n");
	
}
module_init(Ass21_init);
module_exit(Ass21_exit);
