#include<iostream>
#include <algorithm> 
#include<vector>
using namespace std;

int ans,m,n;
vector<int> col;
vector<char> sq;
bool isValid(int,int,vector<vector<char> >&);

void solve(int i,vector<vector<char> >&table)
{
	if(i==m+n) ans++;
	else
	{
		for(int j=0;j<(m+n);j++)
		{	
			if(isValid(i,j,table))
			{
				col.at(j)=1;
				if(sq.at(i)=='q')
					table[i][j]='q';
				else
					table[i][j]='k';	
				solve(i+1,table);
				table[i][j] = '0';
				col.at(j)=0;				
			}
		}
	}
}
bool isValid(int i,int j,vector<vector<char> >&table)
{
	if(col[j]==1) return false;
	for (int row = i , col = j ; row >= 0 && col >= 0; row--, col--)
	{
		if (sq.at(i) == 'k' && table[row][col] == 'q') return false;
		else if ( sq.at(i) == 'q' && table[row][col] != '0') return false;
	}
	for(int row=i,col=j; row>=0 && col<(m+n) ;row--,col++)
	{
		if (sq.at(i) == 'k' && table[row][col] == 'q') return false;
		else if (sq.at(i) == 'q' && table[row][col] != '0') return false;
	}

	return true;	
} 
int main()
{
	while(cin >> m >> n)
	{
		vector<vector<char> >table(m+n, vector<char>(m+n));
		for(int i=0; i<(m+n); i++)
			for(int j=0;j<(m+n);j++)
				table[i][j]='0';//init table
		ans=0;
		col.assign(m+n,0);
	
		sq.assign(n,'k');
		sq.insert(sq.begin()+n,m,'q');
	
		do{
			solve(0,table);
			col.assign(m+n,0);
		}while(next_permutation(sq.begin(),sq.end()));			
		cout << ans << endl;
	}
}
