#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	int value;
	node* next;
	public:
	void setvalue(int a){value=a;}
	void setnext(node* b){next=b;}	
	
	int getvalue(){return value;}
	node* getnext(){return next;}
};

class sll
{
	node* head;
	node* cnode;
	node* lastcnode;
	node* newnode;
	node* temp;
	int nov;
	public:
												//PROTOYPES
	//Constructor
	sll();
	//Create List
	void createlist();
	//Find
	sll find();
	//Display
	void display();
	//Inserts
	void insertas();
	void insertae();
	void insertasl();
	//Deletes
	void deleteas();
	void deleteae();
	void deleteasl();
	void deleteel();
	//Updates
	void update_by_value();
	void update_by_location();
	//Copy
	void copy();
	//Swaps
	void swap_by_value();
	void swap_by_location();
	//Checks
	void success();
	void invalid();
	bool listcheck();
	//Menues	
	void menue();
	void insertion_menue();
	void deletion_menue();
	void update_menue();
	void swap_menue();
};

int main()
{
	system("COLOR 0F" );	
	sll list;
	int choice=0;

	while(choice!=9)
{
	list.menue();
	cin>>choice;
	
	switch(choice)
	{
		case 1:
		list.createlist();
		break;
		
		case 2:
		list.insertion_menue();
		break;
		
		case 3:
		list.deletion_menue();
		break;
		
		case 4:
		list.update_menue();
		break;

		case 5:
		list.swap_menue();
		break;
		
		case 6:
		list.copy();
		break;
		
		case 7:
		list.find();
		break;
		
		case 8:
		list.display();
		break;
		
		case 9:
		exit(0);break;
		
		default:
		list.invalid();
		break;
	}		
}	
	return 0;
}

sll::sll()
{
	head=cnode=newnode=lastcnode=temp=NULL;
	nov=0;
}

void sll:: createlist()
{
	system("cls");
	if(!nov==0){cout<<"\nList Already Created";cout<<"\nPress Any Key To Continue";getch();}
	else
	{
		cout<<"\nEnter The Number of nodes You want to Create:";
		cin>>nov;
		for(int i=0;i<nov;i++)
		{	
		if(head==NULL){insertas();nov--;}
		else{insertae();nov--;}	
	}
	success();	
	}
}

void sll:: display()
{
	if(listcheck()){}
	else
	{
		cnode=head;
		while(cnode!=NULL)
		{
			cout<<cnode->getvalue()<<"	";
			cnode=cnode->getnext();
		}
		cout<<"\nNo of Nodes In List Are:"<<nov;
		cout<<"\nPress Any Key To Continue";
		getch();
	}
}

void sll::insertas()
{
		int v;
		newnode=new node;
		nov++;
		cout<<"\nEnter Value:";
		cin>>v;
		newnode->setvalue(v);
		newnode->setnext(head);
		head=newnode;	
}

void sll:: insertae()
{
	int v;
	newnode=new node;
	nov++;
	cout<<"\nEnter Value:";
	cin>>v;
	cnode=head;
	newnode->setnext(NULL);
	newnode->setvalue(v);
	while(cnode->getnext()!=NULL)
	{cnode=cnode->getnext();}
	cnode->setnext(newnode);
}

void sll:: insertasl()
{
	if(listcheck()){}
	else
	{
		int v,nono;
		newnode=new node;
		nov++;
		cnode=head;
		g:
		system("cls");
		cout<<"\nEnter The Node Number where you want to enter a new node:";
		cin>>nono;
		if(nono<1 || nono>nov)
		{
			invalid();
			goto g;
		}
		if(nono==1){insertas();}
		else if(nono==nov){insertae();}
		else
		{
			cout<<"\nEnter"<<"Value:";
			cin>>v;
			newnode->setvalue(v);
			for(int i=1;i<nono-1;i++){cnode=cnode->getnext();}
			newnode->setnext(cnode->getnext());
			cnode->setnext(newnode);
			success();
		}
	}
}

void sll:: deleteas()
{
	if(listcheck()){}
	else
	{
		if(nov==1)
		{
			head==NULL;
		}
		else
		{
			temp=head;
			head=head->getnext();
			delete temp;
		}
		nov--;
		success();
	}
}

void sll:: deleteae()
{
	if(listcheck()){}
	else
	{
		if(nov==1){head==NULL;}
		else
		{
			temp=head;
			while(temp->getnext()!=NULL)
			{
				lastcnode=temp;
				temp=temp->getnext();
			}
			lastcnode->setnext(NULL);
			delete temp;
		}
		nov--;
		success();
	}
}

void sll:: deleteasl()
{
	int nono,ch;
	h:
	system("cls");
	if(nov==1)
	{
		cout<<"\nThere is only One Node In List";
		deleteas();
	}
	else
{
	cout<<"\nEnter The Node Number you want to Delete:";
	cin>>nono;
	if(nono<1 || nono>nov)
	{
		invalid();
		goto h;
	}
	if(nono==1){deleteas();}
	else if(nono==nov){deleteae();}
	else
	{
		cnode=head;
		for(int i=1;i<nono;i++)
		{
			lastcnode=cnode;
			cnode=cnode->getnext();
		}
		temp=cnode;
		lastcnode->setnext(cnode->getnext());
		delete temp;
		nov--;
	}	
}
}

void sll::deleteel()
{
	temp=head;
	for(int i=0;i<nov;i++)
	{
		cnode=temp->getnext();
		delete temp;
		temp=cnode;
	}
	nov=0;
	head=NULL;
	success();
}

void sll::update_by_value()
{
	int fvalue,l,nvalue,count=0,check=0;
	int locations[nov];
	temp=head;
	cout<<"\nEnter The value you want to update:";cin>>fvalue;
	while(temp!=NULL)
	{
		check++;
		if(fvalue==temp->getvalue())
		{
			cout<<"\nValue is found at location:"<<check;
			locations[count]=check;
			count++;
		}
		temp=temp->getnext();
	}
	if(count==0){invalid();}
	else if(count==1)
	{
		cout<<"\nEnter the updated value for this location:";cin>>nvalue;
		temp=head;
		for(int i=1;i<locations[0];i++)
		{
			temp=temp->getnext();
		}
		temp->setvalue(nvalue);
		success();
	}
	else
	{
		temp=head;
		cout<<"\nEnter The Loaction on which you want to update:";cin>>l;
		for(int i=0;i<l;i++)
		{
			if(l==locations[i])
			{
				for(int i=1;i<l;i++)
				{
					temp=temp->getnext();
				}
				cout<<"\nEnter the updated value for this location:";cin>>nvalue;
				temp->setvalue(nvalue);
				success();
			}
			else
			invalid();
		}
	}
}

void sll::update_by_location()
{
	int loc,nvalue;
	temp=head;
	cout<<"\nEnter The Location where you want to update the value:";cin>>loc;
	if(loc>nov || loc<1){invalid();}
	else
	{
		for(int i=1;i<loc;i++){temp=temp->getnext();}
		cout<<"\nEnter The Updated Value:";cin>>nvalue;
		temp->setvalue(nvalue);
		success();
	}
}

void sll:: copy()
{
	int loc1,loc2;
	node* temp2;
	temp=head;
	temp2 =head;
	cout<<"\nEnter The Location from where you want to copy the value:";cin>>loc1;
	if(loc1>nov || loc1<1){invalid();}
	else
	{
		cout<<"\nEnter The Location from where you want to copy the value:";cin>>loc2;
		if(loc2>nov || loc2<1){invalid();}
		else
		{
			for(int i=1;i<loc1;i++){temp=temp->getnext();}
			for(int i=1;i<loc2;i++){temp2=temp2->getnext();}
			temp2->setvalue(temp->getvalue());
		}
		success();
	}
}

void sll::swap_by_location()
{
	int loc1,loc2,tempvalue;
	node* temp2;
	temp=head;
	temp2 =head;
	cout<<"\nEnter The Location#1 from where you want to swap value:";cin>>loc1;
	if(loc1>nov || loc1<1){invalid();}
	else
	{
		cout<<"\nEnter The Location#2 from where you want to swap value:";cin>>loc2;
		if(loc2>nov || loc2<1){invalid();}
		else
		{
			for(int i=1;i<loc1;i++){temp=temp->getnext();}
			for(int i=1;i<loc2;i++){temp2=temp2->getnext();}
			tempvalue=temp->getvalue();
			temp->setvalue(temp2->getvalue());
			temp2->setvalue(tempvalue);
		}
		success();
}
}

void sll::swap_by_value()
{
	int fvalue,l,l2,svalue,count1=0,check1=0,count2=0,check2=0,tempvalue;
	int locations1[nov];
	int locations2[nov];
	node* temp2=new node;
	fv:
	temp=head;
	cout<<"\nEnter The first value you want to swap:";cin>>fvalue;
	while(temp!=NULL)
	{
		check1++;
		if(fvalue==temp->getvalue())
		{
			cout<<"\nValue is found at location:"<<check1;
			locations1[count1]=check1;
			count1++;
		}
		temp=temp->getnext();
	}
	if(count1==0)
	{
		invalid();
		check1=0;
		system("cls");
		goto fv;;
	}
	else if(count1==1)
	{
		sv:
		temp2=head;
		cout<<"\n\nEnter The second value you want to swap:";cin>>svalue;
		while(temp2!=NULL)
		{
			check2++;
			if(svalue==temp2->getvalue())
			{
				cout<<"\nValue is found at location:"<<check2<<endl;
				locations2[count2]=check2;
				count2++;
			}	
			temp2=temp2->getnext();
		}
		if(count2==0)
		{
			invalid();
			check2=0;
			system("cls");
			goto sv;
		}
		else if(count2==1)
		{
			temp=head;
			temp2=head;
			for(int i=1;i<locations1[0];i++){temp=temp->getnext();}
			for(int j=1;j<locations2[0];j++){temp2=temp2->getnext();}
			
			tempvalue=temp->getvalue();
			temp->setvalue(temp2->getvalue());
			temp2->setvalue(tempvalue);
			success();
		}
		else
		{
			temp=head;
			for(int i=1;i<locations1[0];i++){temp=temp->getnext();}
			c:
			cout<<"\n\nEnter The Loaction On which you want to update:";cin>>l;
			for(int i=0;i<l;i++)
			{
				if(l==locations2[i])
				{
					temp2=head;
					for(int i=1;i<l;i++){temp2=temp2->getnext();}
					tempvalue=temp->getvalue();
					temp->setvalue(temp2->getvalue());
					temp2->setvalue(tempvalue);
					success();
				}
			}
			{
				invalid();
				system("cls");
				goto c;
			}
		}
	}
	else
	{
		cout<<"\n\nEnter The Loaction On which you want to update:";cin>>l;
		sv2:
		temp2=head;
		cout<<"\n\nEnter The second value you want to swap:";cin>>svalue;
		while(temp2!=NULL)
		{
			check2++;
			if(svalue==temp2->getvalue())
			{
				cout<<"\nValue is found at location:"<<check2;
				locations2[count2]=check2;
				count2++;
			}	
			temp2=temp2->getnext();
		}
		if(count2==0)
		{
			invalid();
			check2=0;
			system("cls");
			goto sv;
		}
		else if(count2==1)
		{
			temp=head;
			for(int i=1;i<l;i++){temp=temp->getnext();}
			temp2=head;
			for(int j=1;j<locations2[0];j++){temp2=temp2->getnext();}
			tempvalue=temp->getvalue();
			temp->setvalue(temp2->getvalue());
			temp2->setvalue(tempvalue);
			success();
		}
		else
		{
			cout<<"\n\nEnter The Loaction On which you want to update:";cin>>l2;
			
			for(int i=0;i<l2;i++)
			{
				if(l2==locations2[i])
				{
					temp=head;
					temp2=head;
					for(int i=1;i<l;i++){temp=temp->getnext();}
					for(int j=1;j<l;j++){temp2=temp2->getnext();}
					tempvalue=temp->getvalue();
					temp->setvalue(temp2->getvalue());
					temp2->setvalue(tempvalue);
					success();
				}
			}
		}
	}
}

sll sll::find()
{
	int x,n=0,d=0;
	sll a;
	if(listcheck()){}
	else
{
	cout<<"\nEnter The Value you want to find:";
	cin>>x;
	cnode=head;
	while(cnode!=NULL)
	{	n++;
		if(cnode->getvalue()==x)
		{
			d++;
			cout<<"\nValue is on:'"<<n<<"'Node"<<endl;
		}
			cnode=cnode->getnext();
	}
	success();
}
return a;
}
void sll::success()
{
	cout<<"\nProcess Successful!!!";
	cout<<"\nPress Any Key To Continue";
	getch();system("cls");
}
void sll::invalid()
{
	cout<<"\nInavlid Input!!!";
	cout<<"\nEnter Again!!!";
	cout<<"\nPress Any key to enter again";getch();
}

bool sll::listcheck()
{
	if(nov==0){cout<<"\nList Doest Not Exist";
	cout<<"\nPress Any key to Contiinue";getch();return 1;}
	else{return 0;}
}

void sll::menue()
{
	system("cls");
	cout<<"\n\n\t\t\t\t\t\t\t****ASSIGNMENT # 2****"<<endl;
	cout<<"\t\t\t\t\t\t\t     Shayan Akhtar \n  \t\t\t\t\t\t\t         210907"<<endl;
	cout<<"\nEnter 1 To Create List";
	cout<<"\nEnter 2 for Insertion";
	cout<<"\nEnter 3 for Deletion";
	cout<<"\nEnter 4 for Update";
	cout<<"\nEnter 5 for Swapping";
	cout<<"\nEnter 6 for Copy";
	cout<<"\nEnter 7 for Find";
	cout<<"\nEnter 8 To Display";
	cout<<"\nEnter 9 To EXIT ";
	cout<<"\nEnter:";
}

void sll::insertion_menue()
{
	int a;
	if(listcheck()){}
	else
	{
	system("cls");
	cout<<"\nEnter 1 for Insertion at start";
	cout<<"\nEnter 2 for Insertion at end";
	cout<<"\nEnter 3 for Insertion at specifix Location";
	cout<<"\nEnter:";cin>>a;
	switch(a)
	{
		case 1:
		system("cls");insertas();
		success();
		break;
		
		case 2:
		system("cls");insertae();
		success();
		break;
		
		case 3:
		system("cls");insertasl();
		break;
		
		default:invalid();
		break;	
	}
}
}

void sll::deletion_menue()
{
	if(listcheck()){}
	else
	{
	int a;
	system("cls");
	cout<<"\nEnter 1 for Deletion at start";
	cout<<"\nEnter 2 for Deletion at end";
	cout<<"\nEnter 3 for Deletion of specifix Node";
	cout<<"\nEnter 4 for Deletion of Entire List";
	cout<<"\nEnter:";cin>>a;
	switch(a)
	{
		case 1:
		deleteas();
		break;
		
		case 2:
		deleteae();
		break;
		
		case 3:
		system("cls");deleteasl();
		break;
		
		case 4:
		deleteel();
		break;
		
		default:invalid();
		break;	
	}
}
}

void sll::update_menue()
{
	if(listcheck()){}
	else
	{
	int a;
	system("cls");
	cout<<"\nEnter 1 for Update By Value";
	cout<<"\nEnter 2 for Update By Location";
	cout<<"\nEnter:";cin>>a;
	switch(a)
	{
		case 1:
		system("cls");update_by_value();
		break;
		
		case 2:
		system("cls");update_by_location();
		break;

		default:invalid();
		break;	
	}
	}
}

void sll::swap_menue()
{
	if(listcheck()){}
	else
	{
	int a;
	system("cls");
	cout<<"\nEnter 1 for Swap By Value";
	cout<<"\nEnter 2 for Swap By Location";
	cout<<"\nEnter:";cin>>a;
	switch(a)
	{
		case 1:
		system("cls");swap_by_value();
		break;
		
		case 2:
		system("cls");swap_by_location();
		break;

		default:invalid();
		break;	
	}
	}
}

