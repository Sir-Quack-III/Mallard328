# SRC=$(wildcard *.c)

# default: $(SRC)
# 	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -o ./bin/m328.bin ./src/*.c
# # avr-gcc -o bin/m328.bin bin/m328.o
# 	avr-objcopy -O ihex -R .eeprom bin/m328.bin bin/m328.hex
# 	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:bin/m328.hex
# # sh:w:led.hex

CC :=avr-gcc
CFLAGS :=-Os -DF_CPU=16000000UL -mmcu=atmega328p
LDFLAGS :=
C_SOURCES :=$(wildcard *.c)
# C_EXECUTABLE :=$(C_SOURCES:.c=)
C_EXECUTABLE :=m328.bin
 
all:$(C_EXECUTABLE)

$(C_EXECUTABLE):$(C_SOURCES)
	$(CC) src/*.c $(LDFLAGS) $(CFLAGS) -o bin/$@
	avr-objcopy -O ihex -R .eeprom bin/m328.bin bin/m328.hex
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:bin/m328.hex

clean:
	rm -rf $(EXECUTABLE)