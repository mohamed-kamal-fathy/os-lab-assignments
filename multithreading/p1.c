#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include <time.h>

int random2(){
    return rand()%10;
}

void* random(void * param){
    int n=(int)param;
    printf(" - Number Generated = %d\n",n);
    return (void*) n;
}

int main()
{
     srand(time(0));
    int sum=0 , add=0 , x=0;
    pthread_t  t[5];
    //----------------------------
    for(int i=0; i<5; i++){
            x = random2();
            pthread_create(&t[i],0,&random,(void*)x);
    }

    for ( int i=0; i<5; i++ ){
pthread_join( t[i], (void**)&add );
sum+=add;
}
    printf("\n Sum = %d \n\n",sum);
    pthread_exit(0);

}
