#include<linux/kernel.h>
#include<linux/syscalls.h>
#include<linux/init.h>
#include<linux/linkage.h>
#include "vcpu_info.h"
#include<uapi/linux/kvm_para.h>
#include<linux/cpumask.h>

asmlinkage long sys_vcpu_info(void) {
	// call hypercall for each of the online CPU
	int cpu;
	for_each_online_cpu(cpu)
		kvm_hypercall1(KVM_HC_VCPU_INFO, 1);
	return 0;
}
