PRACTICA=P6
AVRCC=avr-gcc
CC=gcc
MMCU=atmega328p
CFLAGS=-std=c99 -Os -fshort-enums -DF_CPU=16000000UL -mmcu=$(MMCU)
OBJCOPY=avr-objcopy -Oihex
OBJDUMP=avr-objdump -d
DEVICE=/dev/ttyACM0
AVR=sudo avrdude -c arduino -p $(MMCU) -P $(DEVICE) -U
OBJECTS= modulator.o mchar.o mtbl.o timer.o gpio_device.o control.o ether.o
SRC=queue.c timer.c mchar.c mtbl.c ether.c modulator.c serial_device.c blck_serial.c gpio_device.c lamp.c semaph.c control.c crossing.c
HEADERS=queue.h timer.h mchar.h mtbl.h ether.h modulator.h serial_device.h blck_serial.h gpio_device.h lamp.h semaph.h control.h
TESTS=test_timer.c test_control.c test_ether.c test_mchar.c test_modulator.c test_mtbl.c

.PHONY: all clean avr test_mchar test_mtbl test_modulator objd

all: main avr

objd:
	$(OBJDUMP) -S $(DUMP) > asm.s

main: $(SRC) $(HEADERS)
	$(AVRCC) $(CFLAGS) queue.c timer.c mchar.c mtbl.c ether.c modulator.c serial_device.c blck_serial.c gpio_device.c lamp.c semaph.c control.c crossing.c -o main
	$(OBJCOPY) main main.hex

avr: main.hex
	$(AVR) main.hex

clean:
	\rm -f *~ *.o *.hex

pico:
	sudo picocom /dev/ttyACM0

tar:
	tar zcvf $(PRACTICA).tar.gz $(HEADERS) $(SRC) $(TESTOS)

test_modulator:
	$(AVRCC) $(CFLAGS) -o modulator test_modulator.c modulator.c gpio_device.c
	$(OBJCOPY) modulator modulator.hex
	$(AVR) modulator.hex
	\rm -f modulator.hex modulator

test_mchar:
	$(CC) -o $@.o $@.c mchar.c
	./$@
	\rm -f $@


test_mtbl:
	$(CC) -o $@ $@.c mtbl.c mchar.c
	./$@
	\rm -f $@

test_timer:
	$(AVRCC) $(CFLAGS) -o timer test_timer.c timer.c lamp.c gpio_device.c modulator.c
	$(OBJCOPY) timer timer.hex
	$(AVR) timer.hex
	\rm -f timer.hex timer

test_ether:
	$(AVRCC) $(CFLAGS) -o ether test_ether.c ether.c timer.c queue.c modulator.c mchar.c mtbl.c blck_serial.c serial_device.c
	$(OBJCOPY) ether ether.hex
	$(AVR) ether.hex
	\rm -f ether.hex ether

test_control:
	$(AVRCC) $(CFLAGS) -o control test_control.c control.c timer.c lamp.c semaph.c gpio_device.c
	$(OBJCOPY) control control.hex
	$(AVR) control.hex
	\rm -f control.hex control







