
CC = g++
CFLAGS = -std=c++11 
PACKNAME = xklism00_xflekd00_xsladk09_xsirok09

all: 	
	 make makeProject
	 make profile
	 make -f qMakefile

profile:
	$(CC) $(CFLAGS) ./standard_deviation/stddev.cpp ./lib/Math.cpp -o stddev

run: all
	../build/Calculator

makeProject: ./Calculator.pro
	qmake -o qMakefile ./Calculator.pro

doc:
	doxygen ./Doxyfile

test:
	# ???

clean:
	rm -rf ../doc
	rm -rf ../build
	rm -rf ../../$(PACKNAME).zip
	rm -rf ../../$(PACKNAME)
	rm -f ./stddev
	rm -f ./qMakefile

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