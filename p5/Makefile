.PHONY: clean picocom

CC=avr-gcc
CFLAGS=-std=c99 -Os -mmcu=atmega328p -fshort-enums \-DF_CPU=16000000UL
OBJCOPY=avr-objcopy -Oihex
AVRDUDE=sudo avrdude -c arduino -p atmega328p -P
DEVICE=/dev/tty.usbmodem1411
NOMARXIU = PR5_Galan_Moreno
ARXIUSPROJECTE = blck_serial_prova.c blck_serial.c blck_serial.h control_prova.c control.c control.h crossing.c gpio_device.c gpio_device.h interpret.py lamp_prova.c lamp.c lamp.h main.py Makefile prova_queue/ queue.c queue.h semaph_prova.c semaph.c semaph.h serial_device_prova.c serial_device.c serial_device.h

MAIN=semaph.o queue.o control.o lamp.o gpio_device.o crossing.o serial_device.o blck_serial.o
LAMP=lamp_prova.o gpio_device.o lamp.o
SEMAPH=semaph_prova.o lamp.o gpio_device.o semaph.o
SERIALDEVICE=queue.o serial_device.o serial_device_prova.o
BLCKSERIAL=queue.o serial_device.o blck_serial.o blck_serial_prova.o
CONTROL=semaph.o control.o lamp.o gpio_device.o control_prova.o

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
