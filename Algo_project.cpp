#include<iostream>
#include<stdlib.h>
using namespace std;
//creating adjacency list  for courses
struct node{
	int course,color;
	struct node *downlink;
	struct node *rlink;
};

void graphcoloring(struct node *head);

int main(){
	int c;
	char ch;
	struct node *header,*ptr2;
	header=(struct node*)malloc(sizeof(struct node));
	ptr2=header;
	ptr2->downlink=NULL;
	ptr2->rlink=NULL;
	ptr2->course=0;
	ptr2->color=0;
	while(1){														//Taking input of courses
		cout<<"Enter the course number\n";
		cin>>c;
		struct node *ptr=(struct node*)malloc(sizeof(struct node));
		ptr->course=c;
		ptr->color=0;
		ptr->downlink=NULL;
		ptr->rlink=NULL;
		ptr2->downlink=ptr;
		ptr2=ptr;
		cout<<"Do you want to enter any course??Y/N";
		cin>>ch;
		if(ch=='N')
			break;
	}

	int c1,c2,n;
	while(1){																		//Creating adjacency list
		cout<<"Enter the courses and number of students common (don't enter if two courses have 0 common)";
		cin>>c1>>c2>>n;
		ptr2=header;
		while(ptr2->course!=c1){													//Linking c1 with c2
			ptr2=ptr2->downlink;
			if(ptr2==NULL){
				cout<<"You have entered wrong course\n";
				exit(0);
			}
		}
		while(ptr2->rlink!=NULL)
			ptr2=ptr2->rlink;
		struct node* ptr=(struct node*)malloc(sizeof(struct node));
		ptr->downlink=NULL;
		ptr->rlink=NULL;
		ptr->course=c2;
		ptr2->rlink=ptr;
		ptr2=header;
		
		while(ptr2->course!=c2){													//Linking c2 with c1
			ptr2=ptr2->downlink;
			if(ptr2==NULL){
				cout<<"You have entered wrong course\n";
				exit(0);
			}
		}
		while(ptr2->rlink!=NULL)
			ptr2=ptr2->rlink;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->downlink=NULL;
		ptr->rlink=NULL;
		ptr->course=c1;
		ptr2->rlink=ptr;
		cout<<"Do you want to enter anymore??Y/N\n";
		cin>>ch;
		if(ch=='N')
			break;
		}
	
	graphcoloring(header);														//calling function
	
	struct node *ptr3;															//Printing
	ptr2=header;
	while(ptr2->downlink!=NULL){
		ptr2=ptr2->downlink;
		cout<<"course No."<<ptr2->course<<" ";
		cout<<"color : "<<ptr2->color<<" ";
		ptr3=ptr2;
		cout<<"Edges linked with this course:"<<ptr2->course<<"->";
		while(ptr3->rlink!=NULL){
			ptr3=ptr3->rlink;
			cout<<ptr3->course<<" ";
		}
		cout<<"\n";
	}
	return 1;
}

void graphcoloring(struct node *head)
{											//Coloring graph
	struct node *ptr,*ptr1,*ptr2,*ptr3,*ptr4,*ptr5;
	int i=1,k=0,l;
	ptr=head->downlink;
	ptr1=head->downlink;
	ptr2=ptr1->rlink;
	ptr->color = i;							//assigning color 1 to 1st course
	while(ptr!=NULL)
	{
		l=0;
		ptr1=head->downlink;
		ptr5=head->downlink;
		while(ptr1!=ptr)					//checks whether course i is linked with course 1 to i-1 or not
		{
			ptr2=ptr1->rlink;
			while(ptr2!=NULL&&ptr2->course!=ptr->course)
			{
				ptr2=ptr2->rlink;
			}
			if(ptr2==NULL)
			{
				ptr->color=ptr1->color;
				
			}
			else l++;
			ptr3=head->downlink;
			while(ptr3!=ptr){				// checks whether 2 courses are linked indirectly
				ptr4=ptr3->rlink;
				while(ptr4!=NULL&&ptr4->course!=ptr->course)
				{
					ptr4=ptr4->rlink;
				}
				if(ptr4!=NULL && ptr3->color==ptr->color){
					k=1;
					break;
				}
				else k=0;
				ptr3=ptr3->downlink;
			}
			if(k==1){
				ptr5=ptr5->downlink;
				ptr1=ptr5;
			} 
			else 
				ptr1=ptr1->downlink;
			
		}
		if(k==1 || l==((ptr->course)-1))
		{
			ptr->color=i++;
			printf("%d\n",ptr->course);
		}
		
		ptr=ptr->downlink;
	}
}
