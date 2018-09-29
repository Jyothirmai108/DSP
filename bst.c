#include<stdio.h>
typedef struct 
{
	int data;
	struct node *left,*right;
}Node;
typedef Node nodeptr;
int search(nodeptr h,int val)
{
	if(h==NULL)
		return 0;
	if(h->data==val)
		return 1;
	if(val<h->data)
		return (search(h->left,val));
	else
		return (search(h->right,val));
}
nodeptr create(int x)
{
	nodeptr temp;
	temp=(nodeptr)malloc(sizeof(nodeptr));
	if(trmp==NULL)
		printf("\n out of memory");
	else
	{
		temp->data=x;
		temp->left=NULL;
		temp->roght=NULL;
	}
	return temp;
}
nodeptr insert(nodeptr proot,nodeptr pnew)
{
	nodeptr parent,cur;
		if(proot==NULL)
				return pnew;
		parent=NULL;
		cur=proot;
		do
		{
			if(pnew->data<cur->data)
			{
				parent=cur;
				cur=cur->left;
			}
			else
			{
				parent=cur;
				cur=cur->right;
			}
		}while(cur!=NULL);
		//insert new node as appropriate leaf
		if(pnew->data<=parent->data)
			parent->left=pnew;
		else
			parent->right=pnew;
		return proot;
}
void delete(nodeptr *r,int key)
{
	nodeptr p,q,f,s,rp;
	p=*r;
	q=NULL;
	while(p!=NULL && p->data!=key)
	{
		q=p;
		p=(key<p->data)?p->left:p->right;
	}
	if(p==NULL)
	{
		printf("\n the key does not exist in the tree");
		return;
	}
	if(p->left==NULL)
		rp=p->left;
	else if(p->right==NULL)
		rp=p->right;
	else
	{
		f=p;
		rp=p->right;
		s=rp->left;
		while(s!=NULL)
		{
			f=rp;
			rp=s;
			s=rp->left;
		}
		if(f!=p)
		{
			f->left=rp->right;
			rp->right=p->right;
		}
		rp->left=p->left;
	}
		if(q==NULL)
			*r=rp;
		else if(p==q->left)
			q->left=rp;
		else
			q->right=rp;
		free(p);
		return;
}
int main()
{
	int x;
	nodeptr node,root=NULL;
	printf("\n enter the sequence of integer to form bst\n Press ctrl+Z and enter key to end\n");
	while(scanf("%d",&x)!=EOF)
	{
		if(search(root,x)==1)
		{
			printf("\n %d is duplicate valude ",x);
			continue;
		}
		node=create(x);
		if(node!=NULL)
			root=insert(root,node);
	}
}
	
}