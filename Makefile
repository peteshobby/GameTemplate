all:
	make -f Makefile.aqplus 
	make -f Makefile.cx16 
	make -f Makefile.next 
	c:\agdev\bin\make -f Makefile.agon V=1

clean:
	make -f Makefile.aqplus clean
	make -f Makefile.cx16 clean
	make -f Makefile.next clean
	c:\agdev\bin\make -f Makefile.agon clean