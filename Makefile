#         .             .              .		  
#         |             |              |           .	  
# ,-. ,-. |-. ,-. . ,-. |  ,_, ,-. ,-. |-. ,-,-. . |- ,_, 
# | | ,-| | | |   | |-' |   /  `-. |   | | | | | | |   /  
# `-| `-^ ^-' '   ' `-' `' '"' `-' `-' ' ' ' ' ' ' `' '"' 
#  ,|							  
#  `'							  

# Paths
DIR = /usr/local/bin/
MANDIR = /usr/local/share/man
ARTDIR = /usr/share/cfetch/

cfetch:
	gcc cfetch.c -IX11 -lX11 -lm -g -o cfetch
	mv ./cfetch ${DIR}
	mkdir -p ${ARTDIR}
	cp ./coffee.art ${ARTDIR}

