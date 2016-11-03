placas.pdf : grafica.py datos.dat # grafica.py crea la imagen a partir de los datos en datos.dat
	python grafica.py
datos.dat : salidaPlacas.out # placas.out genera los datos
	./salidaPlacas.out > datos.dat
salidaPlacas.out : placas.c # Se compila placas.c en placas.out
	gcc placas.c -lm -o salidaPlacas.out
clean: # Borra placas.out y datos.dat
	rm salidaPlacas.out -r
	rm datos.dat -r
