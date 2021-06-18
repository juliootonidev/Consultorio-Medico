Menu: Menu.o medico.o paciente.o consulta.o
	gcc -o Menu Menu.o  medico.o paciente.o consulta.o
	
Menu.o: Menu.c medico.h paciente.h consulta.h
	gcc -c Menu.c

medico.o: medico.c medico.h
	gcc -c medico.c
	
paciente.o: paciente.c paciente.h
	gcc -c paciente.c

consulta.o: consulta.c consulta.h medico.h paciente.h 
	gcc -c consulta.c
