 #### De mayor a menor

Resultados_hw4.pdf: Resultados_hw4.tex
	pdflatex Resultados_hw4.tex

## siguen las graficas que afectan el latex

Resultados_hw4.tex: Plots_hw4.py ODE.txt ODESANGULOS.txt
	python Plots_hw4.py

## siguen las cosas que afectan a cada archivo de datos

ODE.txt ODESANGULOS.txt: ODE.cpp
	g++ -o datosode ODE.cpp 
	./datosode

PDES.txt: PDE.cpp
	g++ -o datospde PDE.cpp 
	./datospde

### se borra todo. metodo implementado en mi lab 9 de metodos computacionales
clean:
	rm *pdf *.log *.aux *.txt *.out 