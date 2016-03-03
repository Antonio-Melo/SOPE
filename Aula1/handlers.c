/* atexit example */
#include <stdio.h>      /* puts */
#include <stdlib.h>     /* atexit */

void fnExit1 (void)
{
  puts ("Exit function 1.");
}

void fnExit2 (void)
{
  puts ("Exit function 2.");
}

int main ()
{
  atexit (fnExit1); // Fazem push para um pilha e ao sair executa tirando do topo
  atexit (fnExit1);
  atexit (fnExit2);
  //abort();
  puts ("Main function.");
  return 0;
}
