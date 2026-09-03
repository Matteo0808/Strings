#include <stdio.h>
#include <string.h>

enum ErrorOrSuccess {
    RET_SUCCESS = 0,
    RET_ERROR = 1
};

int StrLen(const char str[]);
int Puts(const char str[]);
char* StrCpy(char str_dest[], const char str_src[]);
char* StrCat(char str_dest[], const char str_src[]);
int StrCmp(const char str_dest[], const char str_src[]);


ErrorOrSuccess TestStrLen();
//int TestPuts();
ErrorOrSuccess TestStrCpy();
ErrorOrSuccess TestStrCat();
ErrorOrSuccess TestStrCmp();
ErrorOrSuccess Test();


int main(){
    
    if (Test() != RET_SUCCESS) {
        printf("TESTS_FAILED\n");
        return RET_ERROR;
    }
    
    char str[] = "lavashgovyadina";
    int len = StrLen(str);
    printf("%d\n", len);
    int test = Puts(str);
    char tw[] = "tvoya mama";
    StrCpy(str, tw);
    //printf("%d\n", test);
    printf("%s\n", str);
    char str1[50] = "gucci ";
    char str2[] = "burger";
    StrCat(str1, str2);
    printf("%s\n", str1);
    char str3[] = "abcd1";
    char str4[] = "abcd2";
    int y = StrCmp(str3, str4);
    printf("%d\n", y);
    return 0;
}

ErrorOrSuccess Test(){
    if (TestStrLen() != RET_SUCCESS) {return RET_ERROR;}
    //if (TestPuts() != RET_SUCCESS) {return RET_ERROR;}
    if (TestStrCpy() != RET_SUCCESS) {return RET_ERROR;}
    if (TestStrCat() != RET_SUCCESS) {return RET_ERROR;}
    if (TestStrCmp() != RET_SUCCESS) {return RET_ERROR;}
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

ErrorOrSuccess TestStrCpy(){
    char test_arr1[][] = {" ", "test1", "test1.5:)", "test2_qwertyQWERTY", "test3_\0", "tes\0t4", "\0test5"};
    test_arr1[1][4] = '2';
    const char* test_arr2[] = {" ", "test1", "test1.5:)", "test2_qwertyQWERTY", "test3_\0", "tes\0t4", "\0test5"};
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if (strcmp(strcpy(test_arr1[i], test_arr2[j]), StrCpy(test_arr1[i], test_arr2[j])) != 0){
                return RET_ERROR;
            }
            continue;
        }
    }
    return RET_SUCCESS;

}

ErrorOrSuccess TestStrCat(){
    
}

ErrorOrSuccess TestStrCmp(){
    
}

int StrLen(const char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int Puts(const char str[]){
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

char* StrCat(char str_dest[], const char str_src[]){
    int i = 0;
    int len_str_dest = StrLen(str_dest);
    while(str_src[i] != '\0'){
        str_dest[i+len_str_dest] = str_src[i];
        i++;
    }
    str_dest[i+len_str_dest] = '\0';
    return str_dest;
}
//TODO

int StrCmp(const char str_dest[], const char str_src[]){
    int i = 0;
    while(1){
        if(str_dest[i] != str_src[i]){
            return str_dest[i] - str_src[i];
        }
        i++;
        continue;
    }
}

// int TestStrLen();
// int TestPuts();
// int TestStrCpy();
// int TestStrCat();
// int TestStrCmp();



