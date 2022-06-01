#include <linux/kernel.h>       
#include <linux/module.h>      
#include <linux/init.h>        
#include <linux/sched/task.h>  
#include <linux/sched/signal.h> 
#include <linux/sched/mm.h>     
#include <linux/mm.h>          

static int processID = 1;

module_param(processID, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

static int __init modinit(void)
{
    struct task_struct *tsk;
    struct mm_struct *mm;
    unsigned long rss;

#ifndef CONFIG_MMU
    pr_err("Error\n");
    return -EINVAL;
#endif

    for_each_process(tsk) {
        get_task_struct(tsk);
        mm = get_task_mm(tsk);

        if(tsk->pid == processID){
		if (mm) {
            		rss = get_mm_rss(mm) << PAGE_SHIFT;
            		pr_info("PID %d (\"%s\") VmRSS = %lu bytes\n", tsk->pid, tsk->comm, rss);
        } 	else {
            		pr_info("PID %d (\"%s\") is an anonymous process\n", tsk->pid, tsk->comm);
        	}
        }
        

    }

    return 0;
}

static void __exit modexit(void)
{
    printk(KERN_INFO "Process has finished !\n");
}

module_init(modinit);
module_exit(modexit);
MODULE_VERSION("0.1");
MODULE_DESCRIPTION("Dynamic Kernel Module");
MODULE_AUTHOR("Nurbala Heybatov");
MODULE_LICENSE("GPL");

