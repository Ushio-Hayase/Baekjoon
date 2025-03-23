#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;

int T, N;
string strp, strn;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
    
	cin >> T;
    
	while (T--)
	{
		cin >> strp;
		cin >> N;
		cin >> strn;
        
		deque<int> dq;
        
		bool err = true;
		bool dir = true;
       
		string temp = "";
		for (int i = 1; i < strn.size(); i++)
		{
			if (strn[i] == ',' || strn[i] == ']')
			{
				if (temp != "")
				{
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
			else
			{
				temp += strn[i];
			}
		}
		for (int i = 0; i < strp.size(); i++)
		{
			if (strp[i] == 'R')
			{
				dir = !dir;
			}
			else if (strp[i] == 'D')
			{
				if (dq.empty())
				{
					err = false;
					break;
				}
				else
				{
					if (dir) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (!err) cout << "error\n";
		else
		{
			if (!dir) reverse(dq.begin(), dq.end());
			cout << "[";
			for (int i = 0; i < dq.size(); i++)
			{
				if (i == dq.size() - 1) 
					cout << dq[i];
				else
					cout << dq[i] << ",";
			}
			cout << "]\n";
		}
	}
}