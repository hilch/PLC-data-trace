#include <sys/types.h>
#include <sys/stat.h>

char heap[1000];
char *heapstart=heap;
char *heapend=&heap[1000];


void abort(void)
{
}



int fstat(int file, struct stat *st) {
  st->st_mode = S_IFCHR;
  return 0;
}

int close(int file){
    return -1;
}

int lseek(int file, int ptr, int dir){
    return 0;
}

int read(int file, char *ptr, int len){
    return 0;
}
int isatty(int file){
   return 1;
}

int writechar(char a)
{
	return 0;
}

int write(int file, char *ptr, int len){
    int todo;
  
    for (todo = 0; todo < len; todo++) {
        writechar(*ptr++);
    }
    return len;
}

caddr_t sbrk(int incr){
  static char *heap_end;
  char *prev_heap_end;
 
  if (heap_end == 0) {
    heap_end = heapstart;
  }
  prev_heap_end = heap_end;
  if (heap_end + incr > heapend)
    {
/*      _write (1, "Heap and stack collision\n", 25);*/
      abort ();
    }

  heap_end += incr;
  return (caddr_t) prev_heap_end;
}


