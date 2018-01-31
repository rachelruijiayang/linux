#include<linux/kernel.h>
#include<linux/syscalls.h>
#include "vcpu_info.h"
#include<uapi/linux/kvm_para.h>

asmlinkage long sys_vcpu_info(void) {
	// enumerate each of the online CPU
	// for each cpu:
		long struct_ptr = kvm_hypercall1(KVM_HC_VCPU_INFO, 1);
		// trace_printk the result
	return 0;
}
