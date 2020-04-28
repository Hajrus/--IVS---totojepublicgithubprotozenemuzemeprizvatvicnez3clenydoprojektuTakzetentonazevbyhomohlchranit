#/**
# * @file maniwindow.h
# * @author Kliš Michal (xklism00)
# * @author Flek David (xflekd00)
# * @author Široký Ondřej (xsirok09)
# * @author Sladký Jan (xsladk09)
# *
# * @brief Makefile
# */


#Pomocné proměnné

# Název QT projektu
PROJECT = Calculator
# Kompilator pro profiler
CC = g++
# Přepínače pro kompilaci profileru
CFLAGS = -std=c++11 
# Jméno archívu
PACKNAME = xklism00_xflekd00_xsladk09_xsirok09
# Nazev profileru
PROF = stddev

#Zkompiluje aplikaci a profiler
all: 	
	 make makeProject
	 make profile
	 make -f qMakefile

# Kompilace profileru
profile:
	$(CC) $(CFLAGS) ./standard_deviation/stddev.cpp ./lib/Math.cpp -o $(PROF)

# Spuštění aplikace
run: all
	../build/Calculator

# Zkompiluje QT projekt dle jeho nastavení
makeProject: ./$(PROJECT).pro
	qmake -o qMakefile ./$(PROJECT).pro

# Vytvoří dokumentaci
doc:
	doxygen ./Doxyfile

# Spustí testy. Pokud spustitelné testy neexistují dojde k jejich kompilaci
test:
	if [ ! -f ./tests/build_tests/MathTest ]; then make buildTests; fi
	./tests/build_tests/MathTest

# Kompilace Google testů
buildTests: 
	@echo "BUILDING TESTS..."
	@cd ./tests && mkdir build_tests && cd ./build_tests && cmake ..  $2> /dev/null
	@cd ./tests/build_tests && make $2 > /dev/null

# Vymažeš vše co nemá být odevzdáno
clean:
	make cleanTests
	make cleanRepo
	make cleanPack

#Vymaže nechtěnné soubory v repozitáři
cleanRepo:
	rm -rf ../doc
	rm -rf ../build
	rm -f ./stddev
	rm -f ./qMakefile

# Vymaže vyrvořený balíček
cleanPackZip:
	rm -rf ../../$(PACKNAME).zip

# Vymaže složku s odevzdáním
cleanPackFolder:
	rm -rf ../../$(PACKNAME)

# Smaže zkompilované testy
cleanTests:
	rm -rf ./tests/build_tests


# Vytvoří zip s příslušnou strukturou
pack:
	make clean
	mkdir ../../$(PACKNAME)
	mkdir ../../$(PACKNAME)/repo
	mkdir ../../$(PACKNAME)/doc
	mkdir ../../$(PACKNAME)/install
	make doc
	cp -r ../doc/ ../../$(PACKNAME)/
	cp -r ../ ../../$(PACKNAME)/repo/
	cp -r ../install ../../$(PACKNAME)/
	cd ../.. && zip -qr $(PACKNAME).zip $(PACKNAME)/
	make cleanPackFolder