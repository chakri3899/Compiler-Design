/*Implementation of Lexical Analyser using C program*/


#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int checkkeyword( char buffer[])
{
	int i;
    char dec[5][20]={
              "int","float","bool","char","struct"
    };
    char loop[3][20]={
        "do","for","while"
    };
    char decis[4][20]={
        "if","else","switch","case"
    };
    char keywords[23][10]={ "auto","break","continue","default","double","enum","extern","goto","long","register",
                            "return","short","signed","sizeof","static","typeof","union","unsigned","void","volatile",
                            "define","main","printf"

    };
    char ident[26][10]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","x","y","z"};
    if((strcmp(buffer," ")==0)||(strcmp(buffer,"")==0))
        return 0;
    for(i=0;i<23;i++){
        if(strcmp(keywords[i],buffer)==0){
         printf("%s is a keyword\n",buffer);
         return 0;
        }
    }
    for(i=0;i<4;i++){
        if(strcmp(decis[i],buffer)==0){
         printf("%s is a decision making word\n",buffer);
         return 0;
        }
    }
    for(i=0;i<3;i++){
        if(strcmp(loop[i],buffer)==0){
         printf("%s is a looping keyword\n",buffer);
         return 0;
        }
    }
    for(i=0;i<5;i++){
        if(strcmp(dec[i],buffer)==0){
         printf("%s is a data type\n",buffer);
         return 0;
        }
    }
    for(i=0;i<26;i++){
        if(strcmp(ident[i],buffer)==0){
         printf("%s is a identifier\n",buffer);
         return 0;
        }
    }
    printf("%s is not defined \n",buffer);
}
int main(void) {
    char ch, buffer[150],arith_op[]="+-*/%";
    int i;
    FILE *fp;
    int j=0;
    fp = fopen("program.txt","r");
    if (fp==NULL)
    {
        printf("error opening\n");
        exit(0);
    }
    printf("file opened\n");
    while((ch=fgetc(fp))!=EOF){
        for (i =0;i<5;i++)
        {
            if(ch==arith_op[i])
            printf("%c is an arith operator\n",ch);
        }
        if((ch=='>')||(ch=='<'))
        printf("%c is a relational operator\n",ch);
        if(ch == '#')
        printf("#include is preprocessing directive\n");
        if (isalnum(ch)){
            buffer[j++]=ch;
        }
        if ((ch==' ')||(ch=='\n')){
            buffer[j]='\0';
            j=0;
            checkkeyword(buffer);

        }
    }


fclose(fp);
return 0;
}
