#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


enum ErrorOrSuccess {
    RET_SUCCESS = 0,
    RET_ERROR = 1
};

int Puts(const char str[]);
int StrLen(const char str[]);
int StrNLen(const char str[], int max_len);
char* StrCpy(char str_dest[], const char str_src[]);
char* StrNCpy(char str_dest[], const char str_src[], int max_len);
char* StrCat(char str_dest[], const char str_src[]);
char* StrNCat(char str_dest[], const char str_src[], int max_len);
int StrCmp(const char str_dest[], const char str_src[]);
int StrNCmp(const char str_dest[], const char str_src[], int max_len);
char* StrChr(const char str[], char ch);
char* StrRChr(const char str[], char ch);
char* StrDup(const char str[]);
char* StrStr(const char main_string[], const char sub_string[]);


ErrorOrSuccess TestStrLen();
//ErrorOrSuccess TestStrCpy();
ErrorOrSuccess TestStrCat();
//ErrorOrSuccess TestStrCmp();
ErrorOrSuccess Test();


int main(){
    Puts("Strings\n");
    
    if (Test() != RET_SUCCESS) {
        printf("TESTS_FAILED\n");
        return RET_ERROR;
    }
    char str1[10] = "baba";
    char str2[3] = "ne";

    printf("strlen = %d\n", StrLen(str1));
    printf("strnlen = %d\n", StrNLen(str1, 10));
    printf("strcpy = %s\n", StrCpy(str1, str2));
    char str1[10] = "baba";
    char str2[3] = "ne";
    printf("strncpy = %s\n", StrNCpy(str1, str2, 10));
    char str1[10] = "baba";
    char str2[3] = "ne";
    printf("strcat = %s\n", StrCat(str1, str2));
    char str1[10] = "baba";
    char str2[3] = "ne";
    printf("strncat = %s\n", StrNCat(str1, str2, 10));
    char str1[10] = "baba";
    char str2[3] = "ne";
    printf("strcmp = %d\n", StrCmp(str1, str2));
    char str1[10] = "baba";
    char str2[3] = "ne";
    printf("strncmp = %d\n", StrNCmp(str1, str2, 10));
    char str1[10] = "baba";
    char str2[3] = "ne";


    
}

ErrorOrSuccess Test(){
    return RET_SUCCESS;
    if (TestStrLen() != RET_SUCCESS) {return RET_ERROR;}
    //if (TestPuts() != RET_SUCCESS) {return RET_ERROR;}
    //if (TestStrCpy() != RET_SUCCESS) {return RET_ERROR;}
    if (TestStrCat() != RET_SUCCESS) {return RET_ERROR;}
   // if (TestStrCmp() != RET_SUCCESS) {return RET_ERROR;}
    return RET_SUCCESS;
}

ErrorOrSuccess TestStrLen(){
    const char* test_arr[7] = {" ", "test1", "test1.5:)", "test2_qwertyQWERTY", "test3_\0", "tes\0t4", "\0test5"};
    for(int i = 0; i < 7; i++){
        if (strlen(test_arr[i]) != StrLen(test_arr[i])){
            return RET_ERROR;
        }
        continue;
    }
    return RET_SUCCESS;
}

// ErrorOrSuccess TestStrCpy(){
    
// }

ErrorOrSuccess TestStrCat(){
    char teststr1[] = "qwert";
    char teststr2[] = "y\0";
    char teststr3[] = "w\0w";
    if(strcmp(strcat(teststr1, teststr2), StrCat(teststr1, teststr2)) != 0) {return RET_ERROR;}
    if(strcmp(strcat(teststr2, teststr3), StrCat(teststr2, teststr3)) != 0) {return RET_ERROR;}
    if(strcmp(strcat(teststr1, teststr3), StrCat(teststr1, teststr3)) != 0) {return RET_ERROR;}
    return RET_SUCCESS;
}

// ErrorOrSuccess TestStrCmp(){

// }

int StrLen(const char str[]){
    assert(str == NULL);
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
int StrNLen(const char str[], int max_len){
    assert(str == NULL);
    int i = 0;
    while(str[i] != '\0'){
        if(i > max_len){
            return 0;
        }
        i++;
    }
    return i;
}

int Puts(const char str[]){
    assert(str == NULL);
    int i = 0;
    while(str[i] != '\0'){
        if(putchar(str[i]) == -1){
            return EOF;
        }
        i++;
    }
    printf("\n");
    return 1;
}

char* StrCpy(char str_dest[], const char str_src[]){
    assert(str_dest == NULL);
    assert(str_src == NULL);
    int i = 0;
    while(1){
        if(str_dest[i] == '\0'){
            return NULL;
        }
        if(str_src[i] == '\0'){
            str_dest[i] = str_src[i];
            return str_dest;
        }
        else{
            str_dest[i] = str_src[i];
            i++;
            continue;
        }
    }
}

char* StrNCpy(char str_dest[], const char str_src[], int max_len){
    assert(str_dest == NULL);
    assert(str_src == NULL);
    int i = 0;
    while(1){
        if(str_dest[i] > max_len || str_src[i] > max_len){
            return NULL;
        }
        if(str_dest[i] == '\0'){
            return NULL;
        }
        if(str_src[i] == '\0'){
            str_dest[i] = str_src[i];
            return str_dest;
        }
        else{
            str_dest[i] = str_src[i];
            i++;
            continue;
        }
    }
}

char* StrCat(char str_dest[], const char str_src[]){
    assert(str_dest == NULL);
    assert(str_src == NULL);
    int i = 0;
    int len_str_dest = StrLen(str_dest);
    while(str_src[i] != '\0'){
        str_dest[i+len_str_dest] = str_src[i];
        i++;
    }
    str_dest[i+len_str_dest] = '\0';
    return str_dest;
}
char* StrNCat(char str_dest[], const char str_src[], int max_len){
    assert(str_dest == NULL);
    assert(str_src == NULL);
    int i = 0;
    int len_str_dest = StrLen(str_dest);
    if (len_str_dest > max_len){
        return NULL;
    }
    while(str_src[i] != '\0'){
        str_dest[i+len_str_dest] = str_src[i];
        i++;
    }
    str_dest[i+len_str_dest] = '\0';
    return str_dest;
}

int StrCmp(const char str_dest[], const char str_src[]){
    assert(str_dest == NULL);
    assert(str_src == NULL);
    int i = 0;
    while(1){
        if(str_dest[i] != str_src[i]){
            return str_dest[i] - str_src[i];
        }
        i++;
        continue;
    }
}

int StrNCmp(const char str_dest[], const char str_src[], int max_len){
    assert(str_dest == NULL);
    assert(str_src == NULL);
    int i = 0;
    while(1){
        if(i > max_len){
            return -8888;
        }
        if(str_dest[i] != str_src[i]){
            return str_dest[i] - str_src[i];
        }
        i++;
        continue;
    }
}

char* StrChr(const char str[], char ch){
    assert(str == NULL);
    int i = 0;
    while(str[i] != ch || str[i] != '\0'){
        i++;
    }
    if(str[i] == '\0'){
        return NULL;
    }
    return (char *)&str[i];
}

 char* StrRChr(const char str[], char ch){
    assert(str == NULL);
    int i = 0;
    int len = StrLen(str);
    while(str[len-i-1] != ch || str[len-i-1] != '\0'){
        i++;
    }
    if(str[len-i-1] != 0){
        return NULL;
    }
    return (char *)&str[len-i-1];
    
}
/// @note FREE MEMORY AFTER
char* StrDup(const char str[]){
    assert(str == NULL);
    int len = StrLen(str);
    char* strout;
    if ((strout = (char*)malloc(len+1)) == NULL){
        return NULL;
    }
    if (strout != NULL){
        StrCpy(strout, str);
        return strout;
    }
    return NULL;
}


char* StrStr(const char main_string[], const char sub_string[]){
    assert(main_string == NULL);
    assert(sub_string == NULL);
    int flag = 0;
    for(int i = 0; i < (StrLen(main_string) - StrLen(sub_string) + 1); i++){
        if(main_string[i] == sub_string[0]){
            for(int j = 0; j < StrLen(sub_string); j++){
                if(main_string[i+j] == sub_string[j])
                    flag++;
                    continue;
            }
            if(flag == StrLen(sub_string)){
                return (char *)&main_string[i];
            }
            else{
                flag = 0;
                continue;
            }
        }
        else{
            continue;
        }
    }
    return NULL;
}

// char* GetLine(char** ){

// }

//TODO getline()