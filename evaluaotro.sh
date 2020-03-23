#Si tus ficheros de prueba no comienzan por "tad", cambia "tad*.cpp" por el prefijo de tus ficheros, por ejemplo "prueba*.cpp":
#for FILE in *PRUEBA/tad*.cpp ; do 
for FILE in *PRUEBA/tad*.cpp ; do 
	echo "Evaluando $FILE"
	#Si tu Makefile espera que el fichero que contiene el programa principal se llame tad.cpp, cambia la siguiente línea por: cp $FILE src/tad.cpp
	cp $FILE src/tad.cpp 
	make
	./tad> $FILE.out
	if [ -f $FILE.all ]; then 
		rm $FILE.all 
	fi
	diff -b -B -i $FILE.out $FILE.sal 
	if [ "$?" == "0" ]; then

		echo "OK"
	else 
		touch $FILE.all;
	  diff -b -B -i $FILE.out $FILE.sal >> $FILE.all
		echo "-----------------------------------------------\n" >> $FILE.all
		cat $FILE >> $FILE.all
	fi
done;
make clean
echo ""; echo "" 
for FILE in *PRUEBA; do
	echo "ERRORES EN $FILE = $(ls $FILE/*.all 2> /dev/null | wc -l )" 
done;
