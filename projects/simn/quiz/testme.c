#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char inputChar()
{
    
    char randChar;
    randChar = (char)rand() % 128; // extended ascii codes not relevant here
    //the character must be either one of these chars -> [({ ax})]
    return randChar;

}

char *inputString()
{
	
	int str_count = 0;
    static char randChars[6];
    char charArray[] = "helloreset";
    //the char string must have likelihood to become 'reset' in a timely manner
	memset(randChars, '\0', sizeof(randChars));//null out

    while(str_count < 5)
   {
       randChars[str_count] = charArray[rand() % 10];
       str_count++;
   }
   return randChars;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
