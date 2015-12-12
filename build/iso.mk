BOOTLOADER=grub
GENISOIMAGE=genisoimage
ISO=osv.iso

# Grub files
STAGE2=build/stage2_eltorito

# Isolinux files
ISOLINUXBIN=/usr/lib/syslinux/isolinux.bin
ISOLINUXMBOOTC32=/usr/lib/syslinux/mboot.c32

ifeq ($(BOOTLOADER),grub)
BOOTIMAGE = boot/grub/stage2_eltorito
BOOTFILES = iso/boot/grub/menu.lst
endif

ifeq ($(BOOTLOADER),isolinux)
BOOTIMAGE = boot/isolinux/isolinux.bin
BOOTFILES = iso/boot/isolinux/mboot.c32 iso/boot/isolinux/isolinux.cfg
endif

$(ISO): iso/boot/$(KERNEL) iso/$(BOOTIMAGE) $(BOOTFILES)
	$(GENISOIMAGE) -R -b $(BOOTIMAGE) -no-emul-boot -boot-load-size 4 -boot-info-table -o $(ISO) iso/

iso/boot/$(KERNEL): $(KERNEL)
	@mkdir -p iso/boot/
	cp $< $@

iso/boot/grub/stage2_eltorito: $(STAGE2)
	@mkdir -p iso/boot/grub/
	cp $< $@

iso/boot/grub/menu.lst: build/menu.lst
	@mkdir -p iso/boot/grub/
	cp $< $@
	echo "kernel /boot/$(KERNEL)" >> $@

iso/boot/isolinux/isolinux.bin: $(ISOLINUXBIN)
	@mkdir -p iso/boot/isolinux
	cp $< $@

iso/boot/isolinux/mboot.c32: $(ISOLINUXMBOOTC32)
	@mkdir -p iso/boot/isolinux
	cp $< $@

iso/boot/isolinux/isolinux.cfg: build/isolinux.cfg
	@mkdir -p iso/boot/isolinux
	cp $< $@
	echo "APPEND /boot/$(KERNEL)" >> $@
