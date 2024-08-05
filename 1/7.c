//Roll - 002210501077

/*7. Maintain a list to store roll, name and score of students. As and when required student record may be added or deleted. Also, the list has to be displayed. Design suitable functions for different operations. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Name_length 30
#define No_of_subjects 3

typedef struct student{
    int roll;
    char name[Name_length];
    float score[No_of_subjects];
}student;

typedef struct node{
    student s;
    struct node* next;
}node;

void Add_node(node**);
void Insert_before(node**);
void Insert_after(node*);
void Display_node(node*);
void Display_all(node*);
void Delete_node(node**);

int main(){
    node*head=NULL;
    int n;
    printf("0.Choices\n1.Add_node\n2.Insert_before\n3.Insert_after\n4.Dispaly_node\n5.Display_all\n6.Delete_node\n7.Exit\n");
    do{
        printf("Input: ");
        scanf("%d",&n);
        if(!(n>=0 || n<=7))printf("Wrong Input, TryAgain (0.Choices)\n");
        else{
            switch(n){
                case 0:printf("0.Choices\n1.Add_node\n2.Insert_before\n3.insert_after\n4.Dispaly_node\n5.Display_all\n6.Delete_node\n7.Exit\n");break;
                case 1:Add_node(&head);break;
                case 2:Insert_before(&head);break;
                case 3:Insert_after(head);break;
                case 4:Display_node(head);break; 
                case 5:Display_all(head);break;
                case 6:Delete_node(&head);break;
                case 7: printf("Programme Ended\n");break;
            }
        }
    }while(n!=7);
}

node* allocate_data(){
    node* p = (node*)malloc(sizeof(node));
    printf("Roll: ");
    scanf("%d",&p->s.roll);
    getchar();
    printf("Name: ");
    fgets(p->s.name,sizeof(char)*Name_length,stdin);
    *strchr(p->s.name,'\n')='\0';
    for(int i=0;i<No_of_subjects;i++){
        printf("score %d : ",i+1);
        scanf("%f",&p->s.score[i]);
    }
    p->next=NULL;
    return p;
}

void Add_node(node**hp){
    node *p = allocate_data(), *h;
    if(*hp==NULL){
        *hp=p;
    }
    else{
        h= *hp;
        while(h!=NULL){
            h=h->next;
        }
        h=p;
    }
}

void Insert_before(node**hp){
    int r;
    node*p,*h;
    printf("Input Roll before which record to add: ");
    scanf("%d",&r);
    if(*hp==NULL){
        printf("Empty List\n");
        return;
    }
    if((*hp)->s.roll==r){
        p=allocate_data();
        p->next=(*hp);
        *hp = p;
        return;
    }
    else{
        h = *hp;
        while(h !=NULL){
            if(h->next->s.roll==r){
                p=allocate_data();
                p->next=h->next;
                h->next=p;
                return;
            }
            else if(h->next==NULL){
                printf("Record with roll: %d does not exist",r);
            }
            h=h->next;
        }
    }
}

void Insert_after(node *h)
{
    node *p;
    int r;
    printf("Roll after which record to insert: ");
    scanf("%d", &r);
    if (h == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (h->next != NULL)
    {
        if (h->s.roll == r)
        {
            p = allocate_data();
            p->next = h->next;
            h->next = p;
            return;
        }
        h = h->next;
        if (h->next == NULL)
            printf("Record with roll %d is not present\n", r);
    }
}

void Display_node(node*h){
    if(h==NULL){
        printf("Empty list\n");
        return;
    }
    int r;
    printf("Roll of the Record to be Displayed: ");
    scanf("%d",&r);
    while(h!=NULL){
        if(h->s.roll==r){
            printf("Roll: %d\nName: %s\n",h->s.roll,h->s.name);
            for(int i=0;i<No_of_subjects;i++){
                printf("Score%d : %.2f\n",i+1,h->s.score[i]);
            }
            return;
        }
        h=h->next;
        if(h==NULL){
            printf("Record Do not exist\n");
        }
    }
}

void Display_all(node *h)
{
    if (h == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while(h!=NULL){
        printf("Roll: %d\nName: %s\n",h->s.roll,h->s.name);
        for(int i=0;i<No_of_subjects;i++){
            printf("Score%d : %.2f\n",i+1,h->s.score[i]);
        }
        h=h->next;
        if(h==NULL){
            printf("End of List\n");
        }
    }
}

void Delete_node(node** hp){
    node *h,*temp;
    int r;
    printf("Roll of which record to delete: ");
    scanf("%d", &r);
    if (*hp == NULL)
    {
        printf("Empty list\n");
        return;
    }
    // head points to record
    if ((*hp)->s.roll == r)
    {
        //store add of next record in temp
        temp = (*hp)->next;
        free((*hp));
        *hp=temp;
        return;
    }
    h = *hp;
    while (h->next != NULL)
    {
        if (h->next->s.roll == r)
        {
            temp=h->next->next;
            free(h->next);
            h->next = temp;
            return;
        }
        h = h->next;
        if (h->next == NULL)
            printf("Roll %d not present in list\n", r);
    }
}

