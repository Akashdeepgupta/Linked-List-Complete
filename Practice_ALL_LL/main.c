#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first = NULL,*second = NULL,*third = NULL;

struct cnode
{
    int data;
    struct cnode *next;
}*head =NULL;

struct dnode
{
    struct dnode *prev;
    int data;
    struct dnode *next;
}*firstd = NULL;



void create(int a[], int n) // creating global linked list using array.
{
    int i;
    struct node *p,*last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        p = (struct node *)malloc(sizeof(struct node *));
        p->data=a[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }

}

void creat2(int a[], int n) // creating global linked list using array.
{
    int i;
    struct node *p,*last;
    second = (struct node*)malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        p = (struct node *)malloc(sizeof(struct node *));
        p->data=a[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }

}

void display(struct node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void Rdisplay(struct node *p)
{
    if(p==NULL)
        return ;
    else
    {
        printf("%d ",p->data);
        return(Rdisplay(p->next));
    }
}

void Rdisplay2(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Rdisplay2(p->next);
    }
}

void Revese_display(struct node *p)
{
    if(p!=NULL)
    {
        Revese_display(p->next);
        printf("%d ",p->data);
    }
}

int count(struct node *p)
{
    int c = 0;
    while(p)
    {
        p=p->next;
        c++;
    }
    return c;
}

int Rcount(struct node *p)
{
    if(p!=NULL)
        return(Rcount(p->next)+1);
}

int sum(struct node *p)
{
    int s = 0;
    while(p)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}

int Rsum(struct node *p)
{
    if(p)
        return((Rsum(p->next))+p->data);
}

int max(struct node*p)
{
    int m = -32768;
    while(p)
    {
        if(p->data > m)
        {
            m = p->data;
            p=p->next;
        }
        else{
            p=p->next;
        }
    }
    return m;
}

int Rmax(struct node *p)
{
    int m;
    if(p==NULL)
    {
        return -32768;
    }
    else{
        m = Rmax(p->next);
        if(m>p->data)
            return m;
        else
            return p->data;
    }
}

int Rmax2(struct node *p)
{
    int m;
    if(p==NULL)
        return -32768;
    m = Rmax2(p->next);
    return m>p->data?m:p->data;
}

struct node* search(struct node *p, int key)
{
    while(p)
    {
        if(key==p->data){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return NULL;
}

struct node * Rsearch(struct node *p,int key)
{
    if(p!=NULL)
    {
        if(key==p->data)
        return p;
    else
        Rsearch(p->next,key);
    }
    return NULL;
}

int min(struct node *p)
{
    int mn = 32768;
    while(p)
    {
        if(p->data<mn)
        {
            mn = p->data;
            p = p->next;
        }

        else
            p=p->next;
    }
    return mn;
}

void Insert(struct node *p,int index ,int data)
{
    int i;
    struct node *t;
    if(index < 0 && index > count(p))
    {
        printf("Invalid Index\n");
        return;
    }
    t = (struct node *)malloc(sizeof(struct node));
    t->data=data;
    if(index==0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i=1;i<=index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}

void Insert_sorted(struct node *p,int value)
{
    struct node *temp,*prev;
    prev=NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next= NULL;
    if(p == NULL)
    {
        first = temp;
    }
    else
    {
         while(p && p->data < value)
           {
                    prev = p;
                    p=p->next;
           }
           if(p==first)
           {
               temp->next = first;
               first=temp;
           }
           else
           {
                temp->next = prev->next;
                prev->next = temp;
           }
    }

}

int Delete(struct node *p, int pos)
{
    int x=-1,i;
    struct node *prev=NULL;
    if(pos<1 || pos > count(p))
        return -1;
    if(pos==1)
    {
        x = p->data;
        p = first;
        first = first->next;
        free(p);
        return x;
    }
    else
    {
        for(i = 0 ;i< pos-1 && p; i++)
        {
            prev = p;
            p = p->next;
        }
        if(p)
        {
            x = p->data;
            prev->next = p->next;
            free(p);
            return x;
        }
    }
}

int isLLSorted(struct node *p) //output is correct but not tested all cases
{
    int x=-32768;
    while(p)
    {
        if(x < p->data) // checking for success condition is not that good
            {
                p=p->next;
                return 1;
            }
            else{
                return -1;
            }
    }
}

int isLLSorted2(struct node *p)
{
    int x =-32768;
    while(p)
    {
        if(x > p->data){  // checking for failure condition will be better as done here
            return-1;
        }
        else{
            x = p->data;
            p=p->next;
        }
    }
    return 1;
}

void remove_duplicates(struct node *p)
{
    struct node *q = p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse_LL_usingArray(struct node *p)
{
    int size = count(p);
    int A[size];
    int i = 0;
    while(p)
    {
        A[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while(p)
    {
        p->data = A[i--];
        p = p->next;
    }
}

void reverse_LL_usingSlidingPointers(struct node *p)
{
    struct node *q  = NULL,*r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Recursive_Reverse(struct node *q,struct node *p)
{
    if(p)
    {
        Recursive_Reverse(p,p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

void Concate_LL(struct node *p,struct node *q)
{
    third = p;
    while(p->next!=NULL)
    {
        p= p->next;
    }
    p->next = q;
    q = NULL;
}

void merge_LL(struct node *p,struct node *q)
{
    struct node *last;
    if(p->data < q->data)
    {
       third = last = p;
       p = p->next;
       last->next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last =p;
            p = p->next;
            last->next=NULL;
        }
        else{
            last->next = q;
            last =q;
            q = q->next;
            last->next=NULL;
        }
    }
    if(p)last->next = p;
    if(q)last->next = q;
}

int isLoop(struct node *f)
{
    struct node *p,*q;
    p=q=f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q ->next:q;
    }while(p && q && p!=q);

    return p==q ? 1:0;
}

//------------ CIRCULAR LINKED LIST------------------------//

void create_cnode(int A[], int n)
{
    struct cnode *p,*last;
    int i;
    head = (struct cnode *)malloc(sizeof(struct cnode));
    head->data = A[0];
    head->next = head;
    last = head;
    for(i=1;i<n;i++)
    {
        p = (struct cnode *)malloc(sizeof(struct cnode));
        p->data = A[i];
        //last->next = p;
        //p->next = head;
        //last = p;
        p->next = last->next;
        last->next = p;
        last = p;
    }
}

void c_display(struct cnode *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}

void R_c_display(struct cnode *h)
{
    static int flag = 0;
    if(h!=head || flag==0)
    {
        flag = 1;
        printf("%d ",h->data);
        R_c_display(h=h->next);
    }
    flag = 0;
}

int c_length(struct node *h)
{
    int c =0;
    if(h==NULL)
    {
        return c;
    }
    do{
        c++;
        h = h->next;
    }while(h!=head);
    return c;
}

void c_Insert(struct cnode *h,int index,int value)
{
    int i;
    struct cnode *t;
    if(index < 0 || index > c_length(h))
    {
        printf("Invalid Index");
        return;
    }
    if(index == 0)
    {
        t = (struct cnode *)malloc(sizeof(struct cnode));
        t->data = value;
        if(head == NULL)
        {
           head=t;
           head->next=head;
        }
        else
        {

          while(h->next!=head)
            {
            h = h->next;
            }
        h->next = t;
        t->next=head;
        head = t;
        }
    }
    else
    {
       for(i=1;i<index;i++)
        h=h->next;
       t = (struct cnode *)malloc(sizeof(struct cnode));
       t->data = value;
       t->next = h->next;
       h->next = t;
    }
}

int c_delete(struct cnode *h,int pos)
{
    int i,x;
    struct node *p;
    if(pos < 1 || pos > c_length(h))
    {
        printf("Invalid Index");
        return -1;
    }
     if(pos==1)
     {
         while(h->next!=head) h = h->next;
         x = head->data;
         if(head == p)
         {
             free(head);
             head = NULL;
         }
         else
         {
            h->next = head->next;
            free(head);
            head = h->next;
         }
     }
     else
     {
         for(i=1;i<pos-1;i++)
         {
             h = h->next;
         }
         p = h->next;
         h->next = p->next;
         x = p->data;
         free(p);
     }
     return x;
}
//-------------------  Doubly Linked List-------------------------//

void create_dnode(int A[], int n)
{
    struct dnode *t,*last;
    int i;
    firstd = (struct dnode *)malloc(sizeof(struct dnode));
    firstd->data = A[0];
    firstd->prev = firstd->next = NULL;
    last = firstd;
    for(i=1;i<n;i++)
    {
        t = (struct dnode *)malloc(sizeof(struct dnode));
        t->data = A[i];
        t->prev = last;
        last->next = t;
        last = t;
        last->next =NULL;
        /*
        this will also work
        t = (struct dnode *)malloc(sizeof(struct dnode));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
        */
    }
}

void display_dnode(struct dnode *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int length_dnode(struct dnode *p)
{
    int len = 0;
    if(p == NULL)
    {
        return len;
    }
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert_dnode(struct dnode *p,int value, int index)
{
    struct dnode *t;
    int i;
    if(index < 0 || index > length_dnode(p))
    {
        printf("Invalid Index\n");
        return;
    }
    t = (struct dnode *)malloc(sizeof(struct dnode));
    t->data = value;
    if(index == 0)
    {
        if(p == NULL)
        {
            firstd = (struct dnode *)malloc(sizeof(struct dnode));
            firstd->data = value;
            firstd->prev = firstd->next = NULL;
        }
        else
        {
            t->prev = NULL;
            t->next = firstd;
            firstd->prev = t;
            firstd = t;
        }
    }
    else
    {
        for(i = 1; i<index;i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int delete_dnode(struct dnode *p, int index)
{
    struct dnode *t;
    int i,x;
    if(index < 1 || index > length_dnode(p))
    {
        printf("invalid Index \n");
        return -1;
    }
    if(index == 1)
    {
        x = p->data;
        firstd = p->next;
        free(p);
        if(first)
        {
            firstd->prev = NULL;
        }
    }
    else
    {
        for(i=1;i<index;i++)
        {
            p = p->next;

        }
        p->prev->next = p->next;
        if(p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}



void Reverse_dnode(struct dnode *p)
{
    struct node *temp;
    while(p)
    {
       temp = p->next;
       p->next = p->prev;
       p->prev = temp;
       p = p->prev;
       if(p!=NULL && p->next == NULL){
        firstd = p;
       }
    }
}

int main()
{
    int A[] = {10,30,20,40,50};
    create_dnode(A,5);
    display_dnode(firstd);
    printf("Length is: %d\n",length_dnode(firstd));
    Insert_dnode(firstd,21,0);
    display_dnode(firstd);
    printf("deleted: %d\n",delete_dnode(firstd,3));
    display_dnode(firstd);
    Reverse_dnode(firstd);
    display_dnode(firstd);
    //create_cnode(A,5);
    //c_display(head);
    //printf("length of linked list is %d\n",c_length(head));
    /*c_Insert(head,0,33);
    c_Insert(head,0,333);
    c_display(head);
    printf("deleted: %d\n",c_delete(head,1));*/

    /*
    int arr_size;
    struct node *temp;
    int a []={50,40,10,30,20};
    int b [] = {5,15,25,35,45};
    //printf("%d",(sizeof(a)/sizeof(int)));
    arr_size = (sizeof(a)/sizeof(int));
    create(a,arr_size);
    creat2(b,5);
    printf("Elements of Linked List: ");
    Rdisplay2(first);
    printf("\n");
    printf("The number of nodes are: %d\n",Rcount(first));
    printf("The sum of all nodes are: %d\n",Rsum(first));
    printf("The maximum element is: %d\n",Rmax2(first));
    printf("The minimum Element is: %d\n",min(first));
    temp = search(first,13);
    if(temp)
        printf("Key is Found: %d\n",temp->data);
    else
        printf("Key is not Found\n");
    Insert(first,3,1000);
    display(first);
    Insert_sorted(first,10);
    printf("Display after inserting in sorted: \n");
    display(first);
    printf("After Deleting Element: \n");
    printf("Deleted Element is: %d\n",Delete(first,5));
    display(first);
    printf("checking Whether Linked List is sorted: %d\n",isLLSorted2(first));
    remove_duplicates(first);
    printf("After Deleting duplicates: \n");
    display(first);
    printf("Reversing Linked List\n");
    reverse_LL_usingArray(first);
    display(first);
    printf("Reversing the Linked List Again\n");
    reverse_LL_usingSlidingPointers(first);
    display(first);
    printf("Reversing Use recursion\n");
    Recursive_Reverse(NULL,first);
    display(first);
    printf("Second List linked list\n");
    display(second);
    printf("Third linked list after concatenating\n");
    //Concate_LL(first,second);
    display(third);
    printf("third linked list after merging \n");
    merge_LL(first,second);
    display(third);
    struct node *t1,*t2;
    //t1 = first->next->next;
    //t2 = first->next->next->next->next;
    //t2->next = t1;
    printf("%d\n",isLoop(first));
    */
    return 0;
}
