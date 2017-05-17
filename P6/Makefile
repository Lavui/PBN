.PHONY: clean picocom

CC=avr-gcc
CFLAGS=-std=c99 -Os -mmcu=atmega328p -fshort-enums \-DF_CPU=16000000UL
OBJCOPY=avr-objcopy -Oihex
AVRDUDE=avrdude -c arduino -p atmega328p -P
DEVICE=/dev/ttyACM0
NOMARXIU = p5
ARXIUSPROJECTE = blck_serial_prova.c blck_serial.c blck_serial.h control_prova.c control.c control.h crossing.c gpio_device.c gpio_device.h interpret.py lamp_prova.c lamp.c lamp.h main.py Makefile prova_queue/ queue.c queue.h semaph_prova.c semaph.c semaph.h serial_device_prova.c serial_device.c serial_device.h

MAIN=semaph.o queue.o control.o lamp.o gpio_device.o crossing.o serial_device.o blck_serial.o
LAMP=lamp_prova.o gpio_device.o lamp.o
SEMAPH=semaph_prova.o lamp.o gpio_device.o semaph.o
SERIALDEVICE=queue.o serial_device.o serial_device_prova.o
BLCKSERIAL=queue.o serial_device.o blck_serial.o blck_serial_prova.o
CONTROL=semaph.o control.o lamp.o gpio_device.o control_prova.o

MODULATOR=modulator.o
MCHAR=mchar.o
TIMER=timer.o
MODULATOR=modulator.o
ETHER=ether.o


test_ether:$(ETHER)
	$(CC) $(CFLAGS) gpio_device.c test_ether.c modulator.c timer.c mtbl.c queue.c mchar.c -o test_ether
	$(OBJCOPY) test_ether test_ether.hex
	$(AVRDUDE) $(DEVICE) -U test_ether.hex

test_modulator:$(MODULATOR)
	$(CC) $(CFLAGS) gpio_device.c test_modulator.c modulator.c -o test_timer
	$(OBJCOPY) test_modulator test_modulator.hex
	$(AVRDUDE) $(DEVICE) -U test_modulator.hex


test_timer: $(TIMER)
	$(CC) $(CFLAGS) timer.c test_timer.c -o test_timer
	$(OBJCOPY) test_timer test_timer.hex
	$(AVRDUDE) $(DEVICE) -U test_timer.hex

test_mchar: $(MCHAR)
	$(CC) $(CFLAGS) -o test_mchar $(MCHAR)
	$(OBJCOPY) test_mchar test_mchar.hex
	$(AVRDUDE) $(DEVICE) -U test_mchar.hex

mchar: $(MCHAR)
	$(CC) $(CFLAGS) -o mchar $(MCHAR)
	$(OBJCOPY) mchar mchar.hex
	$(AVRDUDE) $(DEVICE) -U mchar.hex


main: $(MAIN)
	$(CC) $(CFLAGS) -o main $(MAIN)
	$(OBJCOPY) main main.hex
	$(AVRDUDE) $(DEVICE) -U main.hex
	@echo Obrint interpret...
	python main.py

lamp_prova: $(LAMP)
	$(CC) $(CFLAGS) -o lamp_prova $(LAMP)
	$(OBJCOPY) lamp_prova lamp_prova.hex
	$(AVRDUDE) $(DEVICE) -U lamp_prova.hex


semaph_prova: $(SEMAPH)
	$(CC) $(CFLAGS) -o semaph_prova $(SEMAPH)
	$(OBJCOPY) semaph_prova semaph_prova.hex
	$(AVRDUDE) $(DEVICE) -U semaph_prova.hex

serial_device_prova: $(SERIALDEVICE)
	$(CC) $(CFLAGS) -o serial_device_prova $(SERIALDEVICE)
	$(OBJCOPY) serial_device_prova serial_device_prova.hex
	$(AVRDUDE) $(DEVICE) -U serial_device_prova.hex
	picocom $(DEVICE)


blck_serial_prova: $(BLCKSERIAL)
	$(CC) $(CFLAGS) -o blck_serial_prova $(BLCKSERIAL)
	$(OBJCOPY) blck_serial_prova blck_serial_prova.hex
	$(AVRDUDE) $(DEVICE) -U blck_serial_prova.hex
	picocom $(DEVICE)

control_prova: $(CONTROL)
	$(CC) $(CFLAGS) -o control_prova $(CONTROL)
	$(OBJCOPY) control_prova control_prova.hex
	$(AVRDUDE) $(DEVICE) -U control_prova.hex


picocom:
	picocom $(DEVICE)

tar: $(ARXIUSPROJECTE)
	tar zcvf $(NOMARXIU).tar.gz $(ARXIUSPROJECTE)

clean:
	rm *.o
	rm *.hex
