//mystring.h
#ifndef MYSTRING_H
#define MYSTRING_H

//对一个字符串中的字符计数
//例如：my_strlen("foo")应该是3
int my_strlen(const char* str);

//------------------------------------------
//对在一个字符串中的特定字符c的出现次数进行计数
//例如：my_countchar("foo",o)应该是2
int my_countchar(const char* str,char c);

//-------------------------------------------
//把一个字符串变成大写
//只有字母表中的字符会被转换
//例如：char *str="foobar"
//my_strupper(str)是“FOOBAR”
void my_strupper(char *str);

//------------------------------------------
//把指针返回到字符第一次出现的位置
//如果字符串中没有此字符，则返回NULL
//例如：char *str="foodar"
//my_strchr(str,'b')是str[3]的地址
char* my_strchr(const char* str,char ch);
#endif /*MYSTRING_H*/
