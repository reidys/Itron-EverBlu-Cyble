# Makefile

main:
	gcc everblu_meters-Data.c -o everblu_meters-Data -lwiringPi -lmosquitto -lpthread -Wall
