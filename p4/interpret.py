#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""

===================
Classe intèrpret
===================

Aquesta classe d'objectes abstreu un intèrpret d'ordres senzill. Recordeu que un intèrpret d'ordres
és un programa que, de forma interactiva, llegeix ordres de l'usuari i les va executant una a una.

Ja coneixeu alguns intèrprets d'ordres, en particular:

*1. La shell de UNIX, que us aten en la terminal d'ordres del sistema operatiu.*

*2. L'intèrpret interactiu de Python, que us permet executar ordres Python interactivament i
usar-lo com una calculadora.*

Un objecte de la classe Interpret és un interpret d'ordres configurable. Això significa que per
usar-lo primer cal configurar-lo. Configurar-lo consisteix a dir-li quines ordres ha de conèixer i
què han de fer.

Exemple d'execució
--------------------
	
	>>> def c1(l): print "executo l’ordre 1: {0}".format(l[0])	
	>>> def c2(l): print "executo l’ordre 2: {0}".format(l[0])
	>>>
	>>> i=interpret()
	>>> i.set_prompt("**")
	>>> i.afegeix_ordre("menja",c1)
	>>> i.afegeix_ordre("beu",c2)
	>>>
	>>> i.run()
	** menja caramel
	executo l'ordre 1: caramel
	** beu xocolata
	executo l'odre 2: xocolata
	** surt
	
Mètodes
----------

"""

class interpret(object):

	def __init__(self):
		"""
		Constructor. Crea un interpret buit, sense ordres.
		"""
		self.__prompt=""
		self.__dcom={}

	def set_prompt(self,p):
		"""
		Modificador. Fixa l’string p com el prompt de l’intèrpret.

		:param str p: Nom del prompt.
		"""
		self.__prompt=p

	def afegeix_ordre(self,nomc,ordre):
		"""
		Modificador. Afegeix a l’intèrpret una ordre de nom nomc associada a la funció ordre. 
		Si ja existia una ordre amb aquest nom, es queixa.
		Noteu que el tercer paràmetre del mètode  és una funció!
		La funció de nom ordre  és una funció que té com a únic paràmetre una llista de strings.

		:param str nomc: Nom de l'ordre.
		:param str ordre: Ordre per afegir al intèrpret.
		"""
		if self.__dcom.has_key(nomc):
			print "Ordre ja llistada!"
		else:
			self.__dcom[nomc]=ordre

	def run(self):
		"""
		Arrenca l’execució d’aquest intèrpret d’ordres. L’intèrpret s’executa indefinidament fins que l’usuari escriu l’ordre surt.
		A cada cicle d’interpretació, l’intèrpret escriu el prompt, llegeix un string del teclat, l’analitza separant els mots que el formen. 
		El primer mot considera que  és un nom d’ordre i la resta de mots els paràmetres d’aquesta ordre. 
		Finalment executa la funció corresponent a l’ordre i li passa com a paràmetre la resta de mots en una llista.
		"""
		n=raw_input(self.__prompt+" ")
		ajuda=""
		while n!="surt":
			n=n.split(" ")
			if self.__dcom.has_key(n[0]):
				self.__dcom[n[0]]() #Petita modificació, el programa executava la funció amb un paràmetre que era un espai buit
			else:
				print "Entrada no llistada!"

			n=raw_input(self.__prompt+" ")
		return " "

	def llistar(self):
		"""
		Llista totes les funcions que hi ha guardades al intèrpret.
		"""
		return sorted([instruccions for instruccions in self.__dcom])