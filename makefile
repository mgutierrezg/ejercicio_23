grafica.pdf: datos.txt grafica.py
	python grafica.py
datos.txt: onda 
	./onda > datos.txt
onda: eq_onda.cpp
	c++ eq_onda.cpp -o onda
