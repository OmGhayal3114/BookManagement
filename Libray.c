#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct node
{
    char name[N];
    int id,no;            // nook ID and no. of avability
    float price;
    struct node *next;
}node;
typedef struct LL
{
    node *start;
}LL;
void insert(LL *l,char name[N],int id,float price,int no)
{
    node *p,*newrec;
    newrec = (node*)malloc(sizeof(node));
    strcpy(newrec->name,name);
    newrec->id=id;
    newrec->price=price;
    newrec->no=no;
    newrec->next=NULL;
    if(l->start==NULL)
    l->start=newrec;
    else{
        p=l->start;
        while (p->next!=NULL)   
        {
            p=p->next;
        }
        p->next=newrec;
        
    }
}
void delete(LL *l)
{
    char n[N];
    node *p,*q=NULL;
    int add,f=0;
    printf("Enter name of book u want to Remove : ");
    scanf("%[^\n]",n);
    
    p=l->start;
    while(p!=NULL)
    {
        if(strcasecmp(p->name,n)==0)
        {
            if(l->start==p)
            {
                q=l->start;
                l->start=NULL;
            }
            else{
                q->next=p->next;
            }
            
            f=1;
            free(p);
            printf("Book is Remove Succesfully");
            break;
        }
        q=p;
        p=p->next;
        
    }
    if(f==0)
    printf("Book is not found");
    
}
void sort(LL*l)
{
    node*i,*j;
     node temp;
    if(l->start==NULL)
    {
        printf("\nNo nodes to sort");
        return;
    }
    for(i=l->start;i->next!=NULL;i=i->next)
        {
            for(j=l->start;j->next!=NULL;j=j->next)
                {
                    if(j->id > j->next->id)
                    {
                        temp=*j;
                        *j=*(j->next);
                        *(j->next)=temp;
                    }
                }
        }
}
int search(LL*l, char a[])
{  
node*p;
p= p->start;
while(p!=NULL)
{
    if(strcasecmp((p->name, a)==0) && (no>0))
    {
    printf("Book details \nBook name: %[^\n]\tBook id: %d
    \tNumber of copies: %d",p->name,p->id,p->no);
    return 1;
    }
    else
    p=l->next;
}
return 0;
}
