#include <iostream>

using namespace std;

int a[100001];
int d[100001];
int rec[100001];
int n;
struct S{
	int max;
	int rec;
	int val;
}s;
S ans(int a[])
{
	d[n]=a[n];
	rec[n]=n;
	for(int i=n-1;i>=1;i++)
	{
		if(d[i+1]>0)
		{
			d[i]=a[i]+d[i+1];
			rec[i]=rec[i+1];
		}
		else
		{
			d[i]=a[i];
			rec[i]=i;
		}	
	}
	for(int j=2;j<=n;j++)
	{
		if(d[j-1]<d[j])
		{
			s.max=j;
		}		
	}
	s.rec=rec[s.max];
	s.val=d[s.max];
	return s;
}
int main()
{
	int T;
	while(~scanf("%d",&T))
	{
		for(int i=1;i<=T;i++)
		{
			scanf("%d",&n);
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&a[j]);
			}
			printf("%d %d %d",ans(a).rec,ans(a).val,ans(a).max);
		}
	}
	return 0;
}
