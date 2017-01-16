## Lab 1 Submission
Syed Hussain and Anson Li

#### How to run
Input the following commands:

* make all
* ./check.sh
* make clear

#### Project Description

Overview:
There are three groups in this kit

-----
    Data generating program:
    matrixgen.c      source file for the input data generation program

-----
    Important functions:
    timer.h          macro definition for time measurement
    lab1_IO.h        header for the lab1_IO.c, need to be included if call the IOs directly from lab1_IO.c
    lab1_IO.c        source file for the IO functions, need to be referred in the compiler line if the functions are called in the program

-----
    Verification program:
    serialtester.c   source file for the testing program, depending on the lab1_IO.c
	check.sh	the script used for in-lab marking, should be in the same directory as the exacutables (matrixgen, serialtester and main).
	

