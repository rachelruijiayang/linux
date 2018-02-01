#include<linux/kernel.h>
#include<linux/syscalls.h>
#include<linux/init.h>
#include<linux/linkage.h>
#include "vcpu_info.h"
#include<uapi/linux/kvm_para.h>

asmlinkage long sys_vcpu_info(void) {
	// enumerate each of the online CPU
	// for each cpu:
	printk("about to call kvm_hypercall1(KVM_HC_VCPU_INFO, 1)");
	trace_printk("about to call hypercall");
	long struct_ptr = kvm_hypercall1(KVM_HC_VCPU_INFO, 1);
	printk("finished calling kvm_hypercall1(KVM_HC_VCPU_INFO, 1)");
	trace_printk("finished calling hypercall");
		// trace_printk the result
	return 0;
}
