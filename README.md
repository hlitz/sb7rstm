sb7rstm
=======

STMbench7 port for RSTM 

1. Edit RSTM src and build dirs in Makefile.in 
2. make
3. run

Files that have been modified in the sb7 source code:

Makefile.in
Added RSTM PATH vars

tm_tx.cc (/src/tm/tm_tx.cc)
Create new case in run_tx function to support the rstm framework 

tm_spec.h (/src/tm/tm_spec.h)
Added rstm_spec.h file

tm_spec.cc (/src/tm/tm_spec.cc)
Added rstm_spec.cc file

thread_fun.cc (/src/thread/thread_fun.cc)
Added new case for the sb7 worker__thread(void *data) function to support rstm

 