###############################################################################
# Makefile for the project lcd+vt+12charctercode_disp_name
###############################################################################

## General Flags
PROJECT = lcd+vt+12charctercode_disp_name
MCU = atmega8
TARGET = lcd+vt+12charctercode_disp_name.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=lcd+vt+12charctercode_disp_name.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = lcd+vt+12charctercode_disp_name.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) lcd+vt+12charctercode_disp_name.hex lcd+vt+12charctercode_disp_name.eep lcd+vt+12charctercode_disp_name.lss size

## Compile
lcd+vt+12charctercode_disp_name.o: ../lcd+vt+12charctercode_disp_name.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) lcd+vt+12charctercode_disp_name.elf dep/* lcd+vt+12charctercode_disp_name.hex lcd+vt+12charctercode_disp_name.eep lcd+vt+12charctercode_disp_name.lss lcd+vt+12charctercode_disp_name.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

