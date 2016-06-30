#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
import sys

DEBUG=False

def get_data(file_name):
	data=[]
	for line in open(file_name):
		item={}
		l=line.split('|')
		if DEBUG:
			print("DEBUG:",len(l))
			print("DEBUG:",l)

		if len(l)>17:
			item["uchastok"]=l[4]
			item["potrebitel"]=l[7]
			item["tochka_postavki"]=l[8]
			item["tochka_ucheta"]=l[9]
			item["nas_punkt"]=l[10]
			item["ulitsa"]=l[11]
			item["dom"]=l[12]
			item["korpus"]=l[13]
			item["kvartira"]=l[14]
			item["podstanciya"]=l[15]
			item["fider"]=l[16]
			item["tp"]=l[17]
			item["fider04"]=l[18]
			item["zavodskoy_nomer"]=l[19]
			data.append(item)	
	return data

def fix_names(data):
	for item in data:
		for name in item:
			value=item[name]
			fixed_value=""
			prev=" "
			for char in value:
				if char=='"' and prev=='"':
					prev=" "
					fixed_value+=char
					continue
				if char=='"':
					prev=char
					continue
				if char=='\n':
					prev=char
					continue
				fixed_value+=char
				prev=char
			item[name]=fixed_value
			
			


def serialize2xml(data):
	print("""<?xml version="1.0" encoding="UTF-8"?>
   <root>""")
	for item in data:
		print("""      <item>""")
		for name in item:
			print("""         <%(name)s>%(value)s</%(name)s>""" % {"name":name, "value":item[name]})
		print("""      </item>""")
		
	print("""</root>""")
		


if len(sys.argv) < 2:
	print("Необходим один параметр - имя файла!")
	print("Выход")
	raise SystemExit(1)

data=get_data(sys.argv[1])
fix_names(data)
if DEBUG:
	print(data)

# Выводим имена и телефоны:
#for item in data:
#	print("Данные: ", item)

serialize2xml(data)
	
