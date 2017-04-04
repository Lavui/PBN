#!/usr/bin/env python
# -*- coding: utf-8 -*-

from interpret import *

import sys
import serial
import platform

ser = serial.Serial('/dev/ttyACM0')

def start():
	ser.write('R')
	print ser.readline()[:-1]
	return''

def stop():
	ser.write('S')
	print ser.readline()[:-1]
	return''

def emergency():
	ser.write('E')
	print ser.readline()[:-1]
	return''


def main():
	inter=interpret()
	inter.set_prompt("==>")
	
	inter.afegeix_ordre("start",start)
	inter.afegeix_ordre("stop",stop)
	inter.afegeix_ordre("emergency",emergency)

	print "Llistat de comandes: ",
	for i in inter.llistar():
		print i+" ",
	print "   surt"
	
	inter.run()
	ser.close()

main()




