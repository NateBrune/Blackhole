QEMU = qemu-system-i386

QEMUFLAGS =#-serial stdio -soundhw pcspk

qemu: iso
	$(QEMU) $(QEMUFLAGS) -cdrom $(ISO)

qemu-kernel: kernel
	$(QEMU) $(QEMUFLAGS) -kernel $(KERNEL)
