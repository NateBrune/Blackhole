INCLUDE := src/include
C_SOURCES=$(wildcard src/*.c)
C_OBJECTS=$(C_SOURCES:.c=.o)
AS_SOURCES=$(wildcard src/*.s)
AS_OBJECTS=$(AS_SOURCES:.s=.o)
ASFLAGS=-felf32 -F dwarf
OBJECTS=$(C_OBJECTS) $(AS_OBJECTS)
WARNINGS := -Wall -Wextra
CFLAGS := -std=c11 -ffreestanding -g -nostdlib -I $(INCLUDE) $(WARNINGS)

.PHONY: all clean dist check testdrivers todolist

all: kernel.bin

kernel.bin: $(C_OBJECTS) $(AS_OBJECTS)
		i686-elf-gcc -T linker.ld -o build/$@ -nostdlib $(CFLAGS) $(OBJECTS)

%.o: %.s
		nasm $(ASFLAGS) $< -o $@

%.o: %.c
		i686-elf-gcc -c $< -o $@ $(CFLAGS)

clean:
		$(RM) src/*.o src/*.bin src/*~ build/*.bin build/*.iso build/grubfiles/boot/*.bin

run: kernel.bin
		qemu-system-i386 -kernel build/$<

iso: kernel.bin
		cp build/$< build/grubfiles/boot/kernel.bin
		grub-mkrescue -o build/kernel.iso build/grubfiles
runiso: iso
		qemu-system-i386 -cdrom build/kernel.iso
