#include <iostream>
#include <cstddef>
using namespace std;

/* Structure for Creading node*/
struct node
{
	int ch;
	node *ptr;
};

/* class for linked list */
class list{
	private:
		node *s, *c, *n;
	public:
		/* constructure of class list */
		list()
		{
		  s=c=n=NULL;	
		}
		/* Funcation for creak list */
		void create_List(int val)
		{
			if(s==NULL)
			{
				s=new node;
				s-> ch=val;
				s-> ptr=NULL;
				c=s;
			}
			else
			{
				n=new node;
				n-> ch=val;
				n-> ptr=NULL;
				c-> ptr=n;
				c=n;
			}
		}
		/* Funcation for insert at end */
		void insert_at_end()
		{
			int num;
			cout<<"enter element in the list"<<endl;
			cin>>num;
			c=s;
			while(c!=NULL)
			{
				if(c->ptr==NULL)
				{
				n=new node;
				n-> ch=num;
				n-> ptr=NULL;
				c-> ptr=n;
				c=n;
				break;
			    }
			    c=c->ptr;
			}
			    
		}
		/* Funcation for insert element at starting */
		void insertStart(){
		int val;
		cout<<"Enter the element which you to insert at start Posdition"<<endl;
		cin>>val;
        n = new node;
        n->ch = val;
        n -> ptr = NULL;
        n-> ptr = s;
        s=n;
        }
		/* Funcation for display linked list */
		void display_list()
        {
	        c=s;
	        cout<<"linked list element are : "<<endl;
 	        while(c!=NULL)
	         {
	    	  cout<<c->ch<<"\t"<<endl;
		      c=c->ptr;
	         }
        }
        
        /* Funcation for Search element in the list */
        void  search()
        {
	     int f=0;
	     int val;
	     cout<<"Enter the element you want to search"<<endl;
	     cin>>val;
	     c=s;
	     while(c!=NULL)
	     {
		  if(c->ch==val)
		   {
			  f=1;
			  break;
		   }
		
		  c=c->ptr;
	     }
	     
	     if(f==1)
	     {
	     	cout<<c->ch<<" is found in the list"<<endl;
		 }
		 else{
		 	cout<<"Element is not found"<<endl;
		 }
	      
	
       }
       
       /* Funcation for Update element in the list */  
       void  update()
        {
	     int f=0;
	     int new_num,val;
	     cout<<"Enter the element you want to Update"<<endl;
	     cin>>val;
	     c=s;
	     while(c!=NULL)
	     {
		  if(c->ch==val)
		   {
			  f=1;
			  break;
		   }
		
		  c=c->ptr;
	     }
	     
	     if(f==1)
	     {
	     	cout<<"Enter the new element"<<endl;
	     	cin>>new_num;
	     	c->ch=new_num;
		 }
		 else{
		 	cout<<"Element is not found"<<endl;
		 }
	      
	
       }
       
       
	    /* Delete the last element in the linked list */     
        void delete_end_node()
        {
          if(s==NULL)
		  {
           cout<<"list is empty"<<endl;
          }
          else
	      {
            c = s;
            while(c->ptr->ptr != NULL)
	         {
          
              c = c->ptr;
             }
         cout<<c->ptr->ch<<" Deleted"<<endl;
         c->ptr=NULL;       
         }
    
        }

        /* Delete the start Element in the linked list */
        void delete_start_node()
        {
         if(s==NULL){
         cout<<"list is empty"<<endl;
        }
	    else{
	    cout<<s->ch<<" Deleted"<<endl;
        s=s->ptr;
        
        }
        }

        /* Delete the element at any position in the list */
        void deleteSpecific(){
	    int pos;
        if(s==NULL){
        cout<<"list is empty"<<endl;
         }
        else{
   	    lebel:
	     cout<<"enter the postiion where you want to del"<<endl;
	     cin>>pos;
	  	if(pos <0 || pos > list::size())
	           {
			cout<<"invalid position"<<endl;
			goto lebel;
			
	 	       }
	   else
	   {
	   	    node *temp;
	   	    c=s;
			for(int i =1; i<pos-1; i++)
			{
				c= c->ptr;
			}
			cout<<c->ptr->ch<<" Deleted"<<endl;
			temp=c->ptr->ptr;
			c->ptr->ptr=NULL;
			c->ptr=temp;
			
	   }
	   
	   
  
    
}
}
void insertSpecific()
{
	int val;
	cout<<"enter the value you want to insert"<<endl;
	cin>>val;
	n=new node;
	n->ch=val;
	n->ptr=NULL;
	
	int p;
	cout<<"Enter the position where you insert node"<<endl;
	cin>>p;
	if(p<0 || p> list::size())
	{
		cout<<"enter valid number"<<endl;
	}
	else
	{
	c=s;
	for(int i=1;i<p-1;i++)
	{
		c=c->ptr;
	}
	n->ptr=c->ptr;
	c->ptr=n;
    cout<<"\n";
	cout<<val<<" inserted at position "<<p<<".."<<endl;
    }
	
}
/* Funcation for size of the linked list */
int size()
{   int count=0;
	c=s;
	while(c!=NULL)
	{
		count++;
		c=c->ptr;
	}
   
     return count;
}
/* Maximum number in the list */
void Max_num()
	{
		int max;
		c=s;
	    max=c->ch;
	    while(c!=NULL)
	    {
		
			if(c->ch>max)
			{
				max=c->ch;
			}
			c=c->ptr;
	    }
			
		
		cout<<"Maximum = "<<max<<endl;
	}
	
/* Minimum number in the list */
void Min_num()
	{
		int min;
		c=s;
	    min=c->ch;
	    while(c!=NULL)
	    {
		
			if(c->ch<min)
			{
				min=c->ch;
			}
			c=c->ptr;
	    }
			
		
		cout<<"Minimum = "<<min<<endl;
	}
};
		

int main()
{
	list obj;
	int val,x;
	cout<<"enter 5 element"<<endl;
	for(int i = 0; i<5; i++)
	{
		cin>>val;
		obj.create_List(val);
		
	}
	
	do{
	
	cout<<"Choice any operation"<<endl;
	cout<<"1 Insertion at start"<<endl;
	cout<<"2 Insertion at end"<<endl;
	cout<<"3 Insertion at Specific Position"<<endl;
	cout<<"4 Delete at start"<<endl;
	cout<<"5 Delete at end"<<endl;
	cout<<"6 delete at Specific Position"<<endl;
	cout<<"7 Display"<<endl;
	cout<<"8 Search"<<endl;
	cout<<"9 Update"<<endl;
	cout<<"10 Size of array"<<endl;
	cout<<"11 Maximum"<<endl;
	cout<<"12 Minimum"<<endl;
	cout<<"13 Exit"<<endl;
	cin>>x;
	if(x==1)
	{
		obj.insertStart();
		
	}
	else if(x==2)
	{
		obj.insert_at_end();
		
	}
	else if(x==3)
	{
		obj.insertSpecific();
	}
	else if(x==4)
	{
		obj.delete_start_node();
	}
	else if(x==5)
	{
		obj.delete_end_node();
	}
	else if(x==6)
	{
		obj.deleteSpecific();
	}
	else if(x==7)
	{
		obj.display_list();
	}
	else if(x==8)
	{
		obj.search();
	}
	else if(x==9)
	{
		obj.update();
	}
	else if(x==10)
	{
		int val=obj.size();
		cout<<"Size : "<<val<<endl;
	}
	else if(x==11)
	{
		obj.Max_num();
	}
	else if(x==12)
	{
		
		obj.Min_num();
	}
	
	else if(x==13)
	{
		cout<<"Thanks for coming"<<endl;
	}
	else{
		cout<<"INvalid Input"<<endl;
	}
	system("pause");
	system("cls");
}while(x!=13);

	
	
	
	return 0;
}
