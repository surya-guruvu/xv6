#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Guruvu Surya Sai Prakash");
MODULE_DESCRIPTION("Listing Running Process LKM");

static int __init Ass2_start(void)
{

	struct task_struct *task;
	
	//this is a macro which is defined in signal.h, which loops over the circular linked list.
	 
	for_each_process(task){
		if(task->state == TASK_RUNNING){
			printk("task-command: %s , pid: %d , state: TASK_RUNNING \n",task->comm, task->pid);
		}
		//task++;
	}

	return 0;
}

static void __exit Ass2_end(void)
{
    printk(KERN_NOTICE "removed Ass22 module\n");
}
  
module_init(Ass2_start);
module_exit(Ass2_end);
