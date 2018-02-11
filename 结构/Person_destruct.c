#include"person.h"
#include<stdlib.h>
void Person_destruct(Person *p)
{
     free(p->name);
     free(p);
}
