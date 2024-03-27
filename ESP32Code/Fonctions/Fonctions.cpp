#include "Fonctions.h"

void Fonctions::delay_Retard(int a)
{
  for (int i = 0; i < 100000 * a; i++)
  {
    __asm__("nop\n\t");
  }
}