#include <stdio.h>

char num[20];

class Node
{
public:
	Node();
	bool exist;
	bool hasChild;
	Node *next[10];
};

Node::Node():exist(false),hasChild(false)
{
	for(int i=0;i<10;i++) next[i] = NULL;
}


bool insert(Node * root,char * str)
{
	int cur = str[0] - '0';
	if( root->next[cur] == NULL )	
	{// 第一次遇到该数字,新建子女
		root->next[cur] = new Node;
		root->hasChild = true;
	}
	else if( root->next[cur]->exist )// 该数字已存在,是当前串前缀,停止插入返回
			return false;

	if( str[1] == '\0' )	// 当前串已经到了最后一个数字
	{
		if( root->next[cur]->hasChild == true )
		{// 当前串成为前缀,停止插入返回
			return false;
		}
		root->next[cur]->exist = true;
		return true;
	}
	else	// 向下一个数字插入串
		return insert(root->next[cur],str+1);
}

void del(Node * root)
{
	if( root == NULL)
		return;
	for(int i=0;i<10;i++)
		del(root->next[i]);
	delete root;
	root = NULL;
}

int main()
{
	int t;
	Node * r = NULL;
	scanf("%d\n",&t);
	for(int i=0;i<t;i++)
	{// for each test case
		int n;
		bool result = true;
		bool final = true;
		scanf("%d\n",&n);
		//del(r);
		r = new Node;
		for(int j=0;j<n;j++)
		{
			scanf("%s",num);
			if(final == false) continue;

			result = insert(r,num);
			if(result == false)
				final = false;
		}
		if( final == true )
			printf("YES\n");
		else
			printf("NO\n");
	}
	//del(r);
	return 0;
}