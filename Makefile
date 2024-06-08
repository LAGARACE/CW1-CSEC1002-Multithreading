a.out:
	gcc multithread.c

testavg: a.out
	bash testavg.sh
	
testmin: a.out
	bash testmin.sh
	
testmax: a.out
	bash testmax.sh
