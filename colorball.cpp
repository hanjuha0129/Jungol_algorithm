#include <stdio.h>
#include <algorithm>
using namespace std;

vector<pair<int,int>> a[2009];
int cnt[200009];
int ans[200009];

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int color,val;
        scanf("%d %d",&color,&val);
        a[val].push_back({color,i});
    }
    int smaller=0;
    for(i=1;i<=2000;i++){
        for(j=0;j<a[i].size();j++)
        {
            ans[a[i][j].second]=smaller - cnt[a[i][j].first];

        }
        for(j=0;j<a[i].size();j++)
        {
            cnt[a[i][j].first]+=i, smaller+=i;
        }

    }
    for(i=0;i<n;i++) printf("%d\n",ans[i]);
    return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

const int M=(int)2e5+5;

int N;
int colorsum[M];
int sum;

struct Data{
	int c,s,index;// color, size
	bool operator<(const Data&r)const{
	return s>r.s;
	}
};

vector <Data> A;

int main()
{
	int i,j;
	int size,color;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d %d",&color,&size);
		A.push_back({color,size,i});
	}
	sort(A.begin(),A.end());
	for(i=0;i<N;i=j)
	{
		for(j=i;j<N&&A[j].s==A[i].s;j++)
		{
			printf("%d",sum-colorsum[A[j].c]);
			colorsum[A[j].c]+=A[j].s;
		}
		sum+=A[i].s;
	}


	return 0;
}
*/
