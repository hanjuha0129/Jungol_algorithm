#include <bits/stdc++.h>

using namespace std;

const int MN=105;

int M,N,H;
int Map[MN][MN][MN];
int fr,re;
int dr[6]={1,-1,0,0,0,0};
int dc[6]={0,0,1,-1,0,0};
int dh[6]={0,0,0,0,1,-1};
int cnt;

struct que{
	int r,c,h,lev;
}A[MN*MN*MN];

void view()
{
	int i,j,k;
	puts("");
	for(k=1;k<=H;k++)
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                printf("%d ",Map[i][j][k]);
            }
            printf("\n");
        }
    }
	puts("");
	getchar();
}

void push(int row,int col,int high,int level)
{
	A[re++]={row,col,high,level};
}

int BFS()
{
	int row,col,high,level;
	while(fr<re)
	{
//		view();
		row=A[fr].r; col=A[fr].c;high=A[fr].h; level=A[fr++].lev;
		for(int j=0;j<6;j++)
		{
			int nr=row+dr[j],nc=col+dc[j],nh=high+dh[j];
			if(nr<1||nc<1||nh<1||nr>N||nc>M||nh>H||Map[nr][nc][nh]) continue;
			Map[nr][nc][nh]=level+1;
			push(nr,nc,nh,level+1);
			cnt--;
		}
	}
	if(cnt!=0) return -1;
	return level;
}

int main() {
	int i,j,k;
	scanf("%d %d %d",&M,&N,&H);
	cnt=M*N*H;
	for(k=1;k<=H;k++)
	{
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				scanf("%d",&Map[i][j][k]);
				if(Map[i][j][k]==1)
				{
					push(i,j,k,0);
					cnt--;
				}
				else if(Map[i][j][k]==-1)
				{
					cnt--;
				}
			}
		}
	}

	printf("%d",BFS());

	return 0;
}
