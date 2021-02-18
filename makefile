all: myShell mul div rakam

myShell: myShell.c
	gcc myShell.c -o myShell

mul: mul.c
	gcc mul.c -o mul

div: div.c
	gcc div.c -o div

rakam: rakam.c
	gcc rakam.c -o rakam
