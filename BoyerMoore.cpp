#include <bits/stdc++.h> 
using namespace std; 
void badChar( string strng, int s, int charbad[256]) 
{ 
	int a;
	for (a= 0; a< 256; a++) 
		charbad[a] = -1; 
	for (a= 0; a< s; a++) 
		charbad[(int) strng[a]] = a; 
} 
void search( string text, string pattren) 
{ 
	int badchar[256]; 
	int n = text.size();
	int m = pattren.size(); 
	badChar(pattren, m, badchar); 
	int ls = 0;
	while(ls <= (n - m)) 
	{ 
		int j = m - 1;
		while(j >= 0 && pattren[j] == text[ls + j]) 
			j--; 
		if (j < 0) 
		{ 
			cout << "pattren at = " << ls << endl; 
			ls += (ls + m < n)? m-badchar[text[ls + m]] : 1; 

		} 

		else
			ls += max(1, j - badchar[text[ls + j]]); 
	} 
} 
int main() 
{ 
	string text= "ABCAAGCCTABTAGABC"; 
	string pattren = "TABTAG"; 
	search(text, pattren); 
	return 0; 
}
