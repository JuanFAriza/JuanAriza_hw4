cuerda.gif : animacion.py datos.dat # animacion.py crea la animación a partir de los datos en datos.dat
	python animacion.py
datos.dat : salidaCuerda.out # salidaCuerda.out genera los datos
	./salidaCuerda.out > datos.dat
salidaCuerda.out : cuerda.c # Compila cuerda.c en salidaCuerda.out
	gcc cuerda.c -lm -o salidaCuerda.out
clean: # Borra salidaCuerda.out y datos.dat
	rm salidaCuerda.out -r
	rm datos.dat -r
