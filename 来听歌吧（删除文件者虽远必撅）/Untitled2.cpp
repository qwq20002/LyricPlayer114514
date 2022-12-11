#include <bits/stdc++.h>
#include <windows.h>
#include <Mmsystem.h>
#include <time.h>
#pragma comment(lib,"WinMM.lib")
using namespace std;

struct lyric
{
	double time;
	string s;
}lyrics[10001];
int p=0;

int main()
{
	freopen("23333.txt","r",stdin);
	string st;
	while(getline(cin,st))
	{
		string T=st.substr(1,st.find(']')-1),S=st.substr(st.find(']')+1,st.length());
		string Tmin=T.substr(0,st.find(':')-1),Tsec=T.substr(st.find(':'),T.length());
		double tmin=atof(Tmin.c_str()),tsec=atof(Tsec.c_str());
		lyrics[p].time=tmin*60+tsec;
		lyrics[p].s=S;
		p++;
	}
	mciSendString(TEXT("play w.wav"),NULL,0,NULL);
	time_t time1,time2;
	time1=time(NULL);
	time2=time(NULL);
	int i=0;
	while(i<=p)
	{
		while(difftime(time2,time1)<lyrics[i].time)
			time2=time(NULL);	
		cout<<lyrics[i].s<<endl;
		i+=1;
	} 
	return 0;
}
