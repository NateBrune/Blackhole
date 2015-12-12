CXX = i686-elf-gcc
ASM = i686-elf-as
LD  = i686-elf-gcc

TARGET = debug

KERNEL = osv.elf

override CXXINCLUDES += -Iinclude/
override CXXWARNINGS += -Wall -Wextra -Wunreachable-code -Wcast-qual -Wcast-align -Wswitch-enum -Wmissing-noreturn -Wwrite-strings -Wundef -Wpacked -Wredundant-decls -Winline -Wdisabled-optimization
override CXXFLAGS += -m32 -nostdinc -ffreestanding -fno-builtin -MMD
CXXACTION = -c

ifeq ($(TARGET),debug)
override CXXFLAGS += -ggdb -DDEBUG -O0
endif

override ASMFLAGS += #-f elf

override LDFLAGS += -ffreestanding -O2 -nostdlib -lgcc $(CXXINCLUDES) -T build/linker.ld

# Find all sources
CXXSOURCES := $(shell find src/ -name '*.c')
ASMSOURCES := $(shell find src/asm/ -name '*.s')

CXXOBJECTS := $(CXXSOURCES:%.c=%.o)
ASMOBJECTS := $(ASMSOURCES:%.s=%.o)

# Grab generated header dependencies
CXXDEPFILES := $(CXXOBJECTS:%.o=%.d)
-include $(CXXDEPFILES)

# No link
objects: $(ASMOBJECTS) $(CXXOBJECTS)

$(KERNEL): $(ASMOBJECTS) $(CXXOBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

src/asm/%.o: src/asm/%.s
	$(ASM) $(ASMFLAGS) $< -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) $(CXXWARNINGS) $(CXXINCLUDES) $(CXXACTION) $< -o $@
