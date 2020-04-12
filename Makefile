all: makeProject
	make -f qMakefile

profle:
	# g++ 

run: all
	./build/Calculator

makeProject: ./src/Calculator.pro
	qmake -o qMakefile ./src/Calculator.pro

doc:
	doxygen doc/Doxyfile

test:
	#

clean:
	# 

pack: clean
	# zip -r xklism00_xflekd00_xsladk09_xsirok09.zip