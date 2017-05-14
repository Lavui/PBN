#!/usr/bin/env python
# -*- coding: utf-8 -*-

class interpret(object):

	def __init__(self):
		self.__prompt=""
		self.__dcom={}

	def set_prompt(self,p):
		self.__prompt=p

	def afegeix_ordre(self,nomc,ordre):
		if self.__dcom.has_key(nomc):
			print "Ordre ja llistada!"
		else:
			self.__dcom[nomc]=ordre

	def run(self):
		n=raw_input(self.__prompt+" ")
		ajuda=""
		while n!="surt":
			n=n.split(" ")
			if self.__dcom.has_key(n[0]):
				self.__dcom[n[0]]() 
			else:
				print "Entrada no llistada!"

			n=raw_input(self.__prompt+" ")
		return " "

	def llistar(self):
		return sorted([instruccions for instruccions in self.__dcom])
