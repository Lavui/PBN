#!/usr/bin/env python
# -*- coding: utf-8 -*-

from interpret import *
import serial
import platform
import sys

def run():
        ser.write('R\n')
        print ser.readline()[:-1]
        return ''

def halt():
        ser.write('H\n')
        print ser.readline()[:-1]
        return ''

def FA():
        ser.write('FA')
        print ser.readline()[:-1]
        return ''

def FB():
        ser.write('FB')
        print ser.readline()[:-1]
        return ''

def stateA():
        ser.write('?A')
        print ser.readline()[:-1]
        return ''

def stateB():
        ser.write('?B')
        print ser.readline()[:-1]
        return ''

def main():
        interp = interpret()
        interp.set_prompt("->")
        interp.afegeix_ordre("R",run)
        interp.afegeix_ordre("H",halt)
        interp.afegeix_ordre("FA",FA)
        interp.afegeix_ordre("FB",FB)
        interp.afegeix_ordre("?A",stateA)
        interp.afegeix_ordre("?B",stateB)


	print "Port utilitzat: "+ser.name+"\nComandes disponibles: "+str(interp.llistar())
        print "Sortir: surt"

	print "Esperant el missatge de START..."
        print ser.readline()[:-1]
        interp.run()
        ser.close()

ser = serial.Serial('/dev/ttyACM0')
main()


