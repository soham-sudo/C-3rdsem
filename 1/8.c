//002210501077

/*8. Consider an array that stores roll, name, and score of number of students. Develop a function to sort the array. User of sort() will develop the comparison function for sorting on roll/score and ascending or descending order and reuse the same sort() function*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Name_length 30
#define No_of_subjects 2

typedef struct student{
    int roll;
    char name[Name_length];
    float score[No_of_subjects];
}student;

//void sort(student[],int ,int (*)(student,student));
void Display(student* ,int );
student* Allocate_data(int );
void Sort(student*,int);
int main(){
    int numb_stdn,n,i,j;
    printf("No of Students: ");
    scanf("%d",&numb_stdn);
    student* stdn = Allocate_data(numb_stdn);
    printf("0.choices\n1.Sort\n2.Display\n3.Exit\n");
    do{
        printf("Input: ");
        scanf("%d",&n);
        if(!(n>=0 || n<=3)){
            printf("Wrong input try Again\n");
        }
        else{
            switch(n){
                case 0:printf("0.choices\n1.Sort\n2.Display\n3.Exit\n");break;
                case 1:Sort(stdn,numb_stdn);break;
                case 2:Display(stdn,numb_stdn);break;
                case 3:printf("Programme Ended");break;
            }
        }
    }while(n!=3);

}

student* Allocate_data(int n){
    student* p =(student*)malloc(sizeof(student)*n);
    for(int i=0;i<n;i++){
        printf("%d.Roll: ",i+1);
        scanf("%d",&(p[i].roll));
        getchar();
        printf("%d.Name: ",i+1);
        fgets(p[i].name,sizeof(char)*Name_length,stdin);
        *strchr(p[i].name,'\n')='\0';
        for(int j=0;j<No_of_subjects;j++){
            printf("%d.Score%d: ",i+1,j+1);
            scanf("%f",&(p[i].score[j]));
        }
    }
    return p;
}

void Display(student* p,int n){
    printf("Roll  Name\t  ");
    for(int i=0;i<No_of_subjects;i++){
        printf("Score%d  ",i+1);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%-6d%-12s",p[i].roll,p[i].name);
        for(int j=0;j<No_of_subjects;j++){
            printf("%-8.2f",p[i].score[j]);
        }
        printf("\n");
    }
}

int roll_asc(student a, student b){
    if(a.roll>b.roll)return 1;
    else return 0;
}

int roll_desc(student a,student b){
    if(a.roll<b.roll)return 1;
    else return 0;
}

int score_asc(student a,student b){
    int i;
    printf("Which Score(1 to %d)\n",No_of_subjects);
    do{
        printf("Input: ");
        scanf("%d",&i);
        if(!(i>=1 && i<=No_of_subjects))printf("Wrong Input,Try Again!! Score(1 to %d)\n",No_of_subjects);
        else break;
    }while(1);  
    i=i-1;
    if(a.score[i]>b.score[i])return 1;
    else return 0;  
}

int score_desc(student a,student b){
    int i;
    printf("Which Score(1 to %d)\n",No_of_subjects);
    do{
        printf("Input: ");
        scanf("%d",&i);
        if(!(i>=1 && i<=No_of_subjects))printf("Wrong Input,Try Again!! Score(1 to %d)\n",No_of_subjects);
        else break;
    }while(1);  
    i=i-1;
    if(a.score[i] < b.score[i])return 1;
    else return 0;  
}

void Sort(student* stdn,int Numb_stdn){
    int n;
    printf("1.Roll_asc\n2.Roll_desc\n3.Score_asc\n4.Score_desc\n");
    do{
        printf("Input: ");
        scanf("%d",&n);
        if(!(n>=1 && n<=4)){
            printf("Wrong Input, Try Again");
            printf("1.Roll_asc\n2.Roll_desc\n3.Score_asc\n4.Score_desc\n");
        }
        else break;
    }while(1);
    n=n-1;
    int (*compare[]) (student a, student b)={roll_asc,roll_desc,score_asc,score_desc};
    //bubble sort
    for(int i=0;i<Numb_stdn;i++){
        int cnt=0;
        for(int j=0;j<Numb_stdn-i-1;j++){
            student temp;
            if(compare[n](stdn[j],stdn[j+1])){
                temp=stdn[j];
                stdn[j]=stdn[j+1];
                stdn[j+1]=temp;
                cnt++;
            }
        }
        if(cnt==0)return;
    }
}