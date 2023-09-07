#include <stdio.h>
#include <stdlib.h>

int numOfJobs;

struct job{
char jobName[20];
int startTime,endTime,compatibility;
}jobs[100],temp;

//void sort(struct job){

//}
void readInput(){

    scanf("%d",&numOfJobs);
    for(int i=0;i<numOfJobs;i++){
        scanf("%s %d %d",&jobs[i].jobName,&jobs[i].startTime,&jobs[i].endTime);
        jobs[i].compatibility=1;
    }

    for(int i=0;i<numOfJobs;i++){
        printf("%s %d %d %d\n",jobs[i].jobName,jobs[i].startTime,jobs[i].endTime,jobs[i].compatibility);
    }
    printf("\n");
}
int recursive_act(int i){
    int m=i+1;
    while(m<=numOfJobs && jobs[m].startTime<jobs[i].endTime){
        jobs[m].compatibility=0;
        m++;
    }
    if(m<=numOfJobs)
        recursive_act(m);
    return 0;
}

int main()
{

    freopen("input.txt","r",stdin);
    readInput();

    for(int i=0;i<numOfJobs-1;i++){
        for(int j=0;j<numOfJobs-i-1;j++){
            if(jobs[j].endTime>jobs[j+1].endTime){
                temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
            }
        }
    }
    for(int i=0;i<numOfJobs;i++){
                printf("%s %d %d %d\n",jobs[i].jobName,jobs[i].startTime,jobs[i].endTime,jobs[i].compatibility);

    }
    printf("\n");
     recursive_act(0);

        for(int j=0;j<numOfJobs;j++){
            if(jobs[j].compatibility==1){
                 printf("%s \n",jobs[j].jobName);
            }
        }

    return 0;
}
