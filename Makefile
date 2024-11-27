all: memtest_sys memtest_dev

memtest_sys: Test_Mem.c
	gcc -o memtest_sys -DSYSTEM_MALLOC Test_Mem.c

memtest_dev: Test_Mem.c MemAlloc.c MemAlloc.h
	gcc -o memtest_dev Test_Mem.c MemAlloc.c

memtest_mal: Test_Mem2.c MemAlloc.c MemAlloc.h
	gcc -o memtest_dev Test_Mem2.c MemAlloc.h
clean:
	rm -f memtest_sys memtest_dev 
