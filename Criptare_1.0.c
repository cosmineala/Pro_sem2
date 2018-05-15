#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    int trans_asci_num [26] = { 10 , 23 , 21 , 12 , 2 , 13 , 14 , 15 , 7 , 16 , 17 , 18 , 25, 24 , 8 ,  9  , 0 ,  3  , 11 , 4 ,  6 ,  22 , 1 ,  20 , 5  , 19 }; //65-90   97--122
    int trans_mum_asci [26] = { 16 , 22 , 4 , 17 , 19 , 24 , 20 , 8 , 14 , 15 , 0 , 18 , 3 , 5 , 6 , 7 , 9 , 10 , 11 , 25 , 23 , 2 , 21 , 1 , 13 , 12 };//+97
    
    int p , a ;
    
    //----mem
    
    char *st_citire;
    char c = 'a';
    int j = 1;
    
    st_citire = (char*)malloc(sizeof(char));
    
    printf("Enter String : ");
    
    while (c != '\n') {
        
        c = getc(stdin);
        
        
        st_citire = (char*)realloc(st_citire, j * sizeof(char));
        
        
        st_citire[j-1] = c;
        
        
        j++;
    }
    
    st_citire[ j-1 ] = '\0';
    
    
    
    
    
    
    ////---mem
    
    
    int i = 1;
    
   // scanf("%[^\n]s", st_citire);//citire sir
    
    
    if ( st_citire[0] >= 'a' && st_citire[0] <= 'z') {
        a =trans_asci_num [ ( int ) st_citire[0] - 97] ;
        if ( a < 10 || a > 18) {
            printf("Mesaj incorect , incercati din nou\n");
            free(st_citire);
            return 0;
        }
    }else{
        if ( st_citire[0] >= 'A' && st_citire[0] <= 'Z' ){
            a =trans_asci_num [ ( int ) st_citire[0] - 65] ;
            if ( a < 10 || a > 18) {
                printf("Mesaj incorect , incercati din nou\n");
                free(st_citire);
                return 0;}
        }else{
            printf("Mesaj incorect , incercati din nou\n");
            free(st_citire);
            return 0;
            
        }
        
    }
    
    
    
    a-=10;
    
    
    
    for ( i = 1; i < strlen(st_citire); i++) {
        
        if ( st_citire[i] >= 'a' && st_citire[i] <= 'z' ) {//-------------litere mici
            
            p = trans_asci_num [ (( int ) st_citire[i]) - 97];
            //  printf(" >poz>%d<poz< \n",p);
            if ( p >= 0 && p <= 9 ) {/*--------rand 1*/
                if ( p + a > 9 ) {
                    p = p + a - 10;
                    st_citire[i] = (char)(trans_mum_asci[p] + 97);
                }
                else{
                    p = p + a;
                    st_citire[i] = (char)(trans_mum_asci[p] + 97);}
                
            }
            else{
                if ( p >= 10 && p <= 18 ) {//------rand 2
                    if ( p + a > 18) {
                        p = p + a - 9;
                        st_citire[i] = (char)(trans_mum_asci[p] + 97);
                    }
                    else{
                        p = p + a;
                        st_citire[i] = (char)(trans_mum_asci[p] + 97);
                    }
                }
                else{
                    if ( p >= 19 && p <= 25 ) {//------rand 3
                        if ( p + a > 25) {
                            p = p + a - 7;
                            st_citire[i] = (char)(trans_mum_asci[p] + 97);
                        }
                        else{
                            p = p + a;
                            st_citire[i] = (char)(trans_mum_asci[p] + 97);
                        }
                    }
                }
            }
            
            
        }
        else{                      // litere mari - end
            
            if ( st_citire[i] >= 'A' && st_citire[i] <= 'Z' ) {//-------------litere mari
                
                p = trans_asci_num [ (( int ) st_citire[i]) - 65];
                //  printf(" >poz>%d<poz< \n",p);
                if ( p >= 0 && p <= 9 ) {/*--------rand 1*/
                    if ( p + a > 9 ) {
                        p = p + a - 10;
                        st_citire[i] = (char)(trans_mum_asci[p] + 65);
                    }
                    else{
                        p = p + a;
                        st_citire[i] = (char)(trans_mum_asci[p] + 65);}
                    
                }
                else{
                    if ( p >= 10 && p <= 18 ) {//------rand 2
                        if ( p + a > 18) {
                            p = p + a - 9;
                            st_citire[i] = (char)(trans_mum_asci[p] + 65);
                        }
                        else{
                            p = p + a;
                            st_citire[i] = (char)(trans_mum_asci[p] + 65);
                        }
                    }
                    else{
                        if ( p >= 19 && p <= 25 ) {//------rand 3
                            if ( p + a > 25) {
                                p = p + a - 7;
                                st_citire[i] = (char)(trans_mum_asci[p] + 65);
                            }
                            else{
                                p = p + a;
                                st_citire[i] = (char)(trans_mum_asci[p] + 65);
                            }
                        }
                    }
                }
                
                
            }/*--------------------------------end-literemari*/
            
        }
        
    }                     // for-end
    
    printf(" \n%s\n",st_citire);
    
    free(st_citire);
    return 0;
    
}

