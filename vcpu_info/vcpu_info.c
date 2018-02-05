#include<linux/kernel.h>
#include<linux/syscalls.h>
#include<linux/init.h>
#include<linux/linkage.h>
#include "vcpu_info.h"
#include<uapi/linux/kvm_para.h>
#include<linux/cpumask.h>

asmlinkage long sys_vcpu_info(void) {
	// enumerate each of the online CPU
	// for each cpu:
	trace_printk("about to call kvm_hypercall1(KVM_HC_VCPU_INFO, 1)\n");
	int cpu;
	for_each_online_cpu(cpu)
		kvm_hypercall1(KVM_HC_VCPU_INFO, 1);
	trace_printk("finished calling kvm_hypercall1(KVM_HC_VCPU_INFO, 1)\n");		// trace_printk the result
	return 0;
}
