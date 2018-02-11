#ifndef PERSON_H
#define PERSON_H
typedef struct
{
   int age;
   char* name;
}Person;

typedef struct
{
    int number;//人数
    Person** person;
}PersonDatabase;

PersonDatabase* Person_read(char* filename);

void Person_sortByName(PersonDatabase *perdb);
void Person_sortByAge(PersonDatabase *perdb);

int Person_write(char *filename,PersonDatabase *perdb);

void Person_print(PersonDatabase *perdb);

void Person_destruct(PersonDatabase *perdb);

#endif
