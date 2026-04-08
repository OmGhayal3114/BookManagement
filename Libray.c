#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct node
{
    char name[N],author[N];
    int id,no;            // nook ID and no. of avability
    float price;
    struct node *next;
}node;
typedef struct LL
{
    node *start;
}LL;
void insert(LL *l,int id,char name[N],char auth[N],float price,int no)
{
    node *p,*newrec;
    newrec = (node*)malloc(sizeof(node));
    strcpy(newrec->name,name);
    strcpy(newrec->author,auth);
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
                l->start=p->next;
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
void sort(LL *l) {
    node *i, *j;
    int t_id, t_no;
    float t_pr;
    char t_nm[N], t_au[N];

    if (l->start == NULL) return;

    for (i = l->start; i != NULL; i = i->next) {
        for (j = l->start; j->next != NULL; j = j->next) {
            if (j->id > j->next->id) {
                // Swap only data fields
                t_id = j->id; j->id = j->next->id; j->next->id = t_id;
                t_no = j->no; j->no = j->next->no; j->next->no = t_no;
                t_pr = j->price; j->price = j->next->price; j->next->price = t_pr;
                strcpy(t_nm, j->name); strcpy(j->name, j->next->name); strcpy(j->next->name, t_nm);
                strcpy(t_au, j->author); strcpy(j->author, j->next->author); strcpy(j->next->author, t_au);
            }
        }
    }
}

void borrow(LL *l, char name[N]) {
    node *p = l->start; 
    while (p != NULL) {
        if (strcasecmp(p->name, name) == 0) {
            if (p->no > 0) {
                p->no--;
                printf("\nBook successfully borrowed! Remaining: %d\n", p->no);
            } else {
                printf("\nOut of stock!\n");
            }
            return;
        }
        p = p->next;
    }
    printf("\nBook not found!\n");
}
int search(LL *l, char a[])
{  
    node *p;
    p = l->start;

    while (p != NULL)
    {
        if (strcasecmp(p->name, a) == 0)
        {
            printf("\nBook details:\nBook name: %s\nAuthor Name : %s\nBook id: %d\nNumber of copies: %d\n",p->name,p->author, p->id, p->no);  
            return 1;             // Book found
        }
        else
        {
            p = p->next;
        }
    }

    return 0;             // book not found
}

void returnback(LL *l, char a[])
{
    node *p = l->start;
    while (p != NULL)
    {
        if (strcasecmp(p->name, a) == 0)
        {
            p->no++;             //  increment the book count
            printf("\nBook returned successful");
            return;
        }
        p = p->next;
    }
    printf("\nThis book is not from library");
}
void display(LL *l)
{
    node *p;
    p=l->start;
    printf("------------------------------------------------------------------------\n");
    printf("%-5s %-25s %-25s %-10s %-10s\n", "ID", "Name", "Author", "Price", "Qty");
    while(p!=NULL)
    {
        printf("%-5d %-25s %-25s %-10f %-10d\n",p->id,p->name,p->author,p->price,p->no);
        p=p->next;
    }

    printf("------------------------------------------------------------------------");
}
int main()
{
    int ch,x,q,id;
    float p;
    char n[N],a[N];
    LL l;
    l.start=NULL;
    insert(&l,101,"The Great Gatsby","F. Scott Fitzgerald",15.99,12);
    insert(&l,105,"C Programming","Dennis Ritchie",45.00,6);
    insert(&l,103,"To Kill a Mockingbird","Harper Lee",18.25,3);
    insert(&l,102,"1984","George Orwell",12.50,9);
    insert(&l,104,"The Hobbit","J.R.R. Tolkien",20.00,10);
    display(&l);
    while(1){
        
        printf("\nMenu\n1-Insert a New Book\n2-Remove Book\n3-Barrow a Book\n4-Return Book\n5-search Book\n6-Display Details of Book\n7-Exit\nEnter Choice:");
    
        scanf("%d",&ch);
        // scanf(" %[^\n]",n);
        if(ch==7)
        break;

        switch (ch)
        {
        case 1:
            {
                printf("Enter Details\nEnter Name:");
                scanf(" %[^\n]",n);
                printf("Enter Author Name : ");
                scanf(" %[^\n]",a);
                printf("Enter ID of Book: ");
                scanf("%d",&id);
                printf("Enter Price of Book: ");
                scanf("%f",&p);
                printf("Enter Quantity of Book: ");
                scanf("%d",&q);
                insert(&l,id,n,a,p,q);
                sort(&l);
                printf("Book is Inserted Succefully!");
                
            }
            break;
        case 2:
        {
            delete(&l);
        }
        break;
        case 3:{
            printf("Enter Name of Book you want to Borrow :");
            scanf(" %[^\n]",n);
            if(search(&l,n))
            {
                borrow(&l,n);
            }
        }
        break;
        case 4:
        {
            printf("Enter a Name of Book you want to Return: ");
            scanf(" %[^\n]",n);
            returnback(&l,n);
        }
        break;
        case 5:{
             printf("Enter a Name of Book you want to Search: ");
            scanf(" %[^\n]",n);
            if(search(&l,n))
            {
                printf("\n1-Borrow the Book\n2-Return the book\nEnter Choice : ");
                scanf("%d",&x);
                
                if(x==1)
                borrow(&l,n);
                else
                returnback(&l,n);
            }
        }
        break;
        case 6:display(&l);
        break;
        default:printf("Invalid Choice");
            break;
        }
        
    }
    return 0;
}
