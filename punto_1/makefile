placas.pdf : grafica.py datos.dat # grafica.py crea la imagen a partir de los datos en datos.dat
	python grafica.py
datos.dat : placas.out # placas.out genera los datos
	./placas.out > datos.dat
placas.out : placas.c # Se compila placas.c en placas.out
	gcc placas.c -lm -o placas.out
clean: # Borra placas.out y datos.dat
	rm placas.out -r
	rm datos.dat -r
