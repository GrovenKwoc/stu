#include"person.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Person* Person_copy(Person *p);
Person* Person_assign(Person *p1,Person *p2);

Person* Person_copy(Person *p)
{
    return Person_construct(p->year,p->month,p->date,p->name);
}

Person* Person_assign(Person *p1,Person *p2)
{
     free(p1->name);
     p1->year=p2->year;
     p1->month=p2->month;
     p1->date=p2->date;
     p1->name=strdup(p2->name);
     return p1;
}

int main(int argc,char *argv[])
{
    Person *p1=Person_construct(1989,8,21,"Amy");
    Person *p2=Person_construct(1991,2,17,"Jennifer");
    Person *p3=Person_copy(p1);

    Person_print(p1);
    Person_print(p2);
    Person_print(p3);
    
    p3=Person_assign(p3,p2);
    Person_print(p3);
    Person_destruct(p1);
    Person_destruct(p2);
    Person_destruct(p3);
    return EXIT_SUCCESS;
}
