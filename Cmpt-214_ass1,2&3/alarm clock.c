#include<stdio.h>
#include<stdlib.h>

int main(){
    // now create file pointer
    FILE* fp;
    fp = fopen("/Users/francis/CLionProjects/Workouts/treasure_journals.txt","r");
    if (fp == NULL){
        printf("NO FILE");
        return 0;
    }

    // READ N
    int n;
    fscanf(fp,"%d",&n);

    // to store all the array counts
    //now find min max and avg

    int a;
    fscanf(fp,"%d",&a);

    int max = a;
    int min = a;
    double sum = a;

    // now sum all
    for(int i=0;i<(n-1);i++){
        int a;
        fscanf(fp,"%d",&a);
        sum += a;

        // max
        if(max < a){
            max = a;
        }

        // min
        if(min>a){
            min = a;
        }
    }


    // print
    printf("Maximum =%d\n",max);
    printf("Minimum =%d\n",min);
    printf("Average = %lf\n",(sum/n));

    // close file
    fclose(fp);

    return 0;
}

