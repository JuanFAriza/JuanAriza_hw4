cuerda.gif : animacion.py datos.dat # animacion.py crea la animación a partir de los datos en datos.dat
	python animacion.py
datos.dat : cuerda.out # cuerda.out genera los datos
	./cuerda.out > datos.dat
cuerda.out : cuerda.c # Compila cuerda.c en cuerda.out
	gcc cuerda.c -lm -o cuerda.out
clean: # Borra cuerda.out y datos.dat
	rm cuerda.out -r
	rm datos.dat -r
