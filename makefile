# Makefile builds the executable for the linked list assignment by default
#
KUID = CHANGE_ME_TO_YOUR_KUID
LAB_NAME = linked_list

all: linkedList

linkedList: main.o Patient.o Doctor.o Hospital.o
	g++ -g main.o Doctor.o Patient.o Hospital.o -o linkedList

main.o: Hospital.h main.cpp
	g++ -g -c main.cpp

Hospital.o: Hospital.cpp Hospital.h Doctor.h
	g++ -g -c Hospital.cpp

Doctor.o: Doctor.cpp Doctor.h Patient.h
	g++ -g -c Doctor.cpp

Patient.o: Patient.cpp Patient.h
	g++ -g -c Patient.cpp

test1: all
	./linkedList infile.txt

test2: all
	./linkedList infile2.txt

tar-file: clean
	@if test -d ../$(KUID)_$(LAB_NAME) ; then \
		( cd .. ; \
		  tar cz $(KUID)_$(LAB_NAME) >$(KUID)_$(LAB_NAME).tar.gz ; \
	  	  echo ""; \
		  echo "**************************************************************"; \
		  echo "The TAR file for you to test and hand in "; \
		  echo "   has been made in the directory above:"; \
		  echo "     " $(KUID)_$(LAB_NAME).tar.gz ; \
		  echo "**************************************************************"; \
		) ; \
	else \
		( echo "*** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ***"; \
		  echo "The <your KUID>_<lab-name> directory was not found. "; \
		  echo "Remember that you should rename the "; \
		  echo "\"starter-code\" directory created by the "; \
		  echo "starter TAR file and set the KUID " ; \
		  echo "variable in the Makefile"; \
		) ; \
	fi




clean:
	rm *.o linkedList
