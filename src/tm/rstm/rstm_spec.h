#include "api/library.hpp"

#define TX_DATA

#define TX_START printf("TX START is obsolete should not be called\n");\
  abort();\

#define TX_COMMIT printf("TX COMMIT is obsolete should not be called\n");\
  abort();\

/*stm::TxThread* rstm_start(jmp_buf _jmpbuf, int abort_flags){
  stm::TxThread* tx = (stm::TxThread*)stm::Self;
  //jmp_buf _jmpbuf;				    
  //uint32_t abort_flags = setjmp(_jmpbuf);		    
  stm::begin(tx, &_jmpbuf, abort_flags);                  
  CFENCE;
  return tx;
} 

void rstm_end(stm::TxThread* tx){
   stm::commit(tx);                             
}
*/
//#define TX_COMMIT TM_END

#define TX_ABORT 

inline void sb7::global_init_tm() {
	TM_SYS_INIT();
}

inline void sb7::thread_init_tm() {
	TM_THREAD_INIT();
}

inline void sb7::global_clean_tm() {
	TM_SYS_SHUTDOWN();
}

inline void sb7::thread_clean_tm() {
	TM_THREAD_SHUTDOWN();
}

inline void *sb7::tm_read_word(void *addr) {
	//uint64_t val = *(uint64_t*)addr;
	//void * valp = (void*)val;
//			printf("in tm read word trx addr %p, valp %p\n", (uint64_t*)addr, (uint64_t*)valp);	
 TM_GET_THREAD(); 
 return (void *)stm::stm_read((uint64_t*) addr, tx);// TM_READ(addr);
}

inline void sb7::tm_write_word(void *addr, void *val) {
	//uint64_t valderef = *(uint64_t*)addr;
	//void * valp = (void*)valderef;
  	TM_GET_THREAD();
  	//TM_WRITE(valp, val);
	stm::stm_write((uint64_t*)addr, (uint64_t)val, tx);
}


