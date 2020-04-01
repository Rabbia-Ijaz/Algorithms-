#include <stdio.h> 
#include <string.h>
void search(char pattern[], char textt[], int q) 
{ 
	int N = strlen(pattern); 
	int K = strlen(textt); 
	int i, j; 
	int p = 0;
	int t = 0;
	int h = 1; 
	for (i = 0; i < N - 1; i++) 
		h = (h * 256) % q; 
	for (i = 0; i < N; i++) { 
		p = (256 * p + pattern[i]) % q; 
		t = (256 * t + textt[i]) % q; 
	}  
	for (i = 0; i <= K - N; i++) { 
		if (p == t) 
		{
			for (j = 0; j < N; j++) 
			{ 
				if (textt[i + j] != pattern[j]) 
					break; 
			} 
			if (j == N) 
				printf("at index %d \n", i); 
		}  
		if (i < K - N) { 
			t = (256 * (t - textt[i] * h) + textt[i + N]) % q; 
			if (t < 0) 
				t = (t + q); 
		} 
	} 
} 

int main() 
{ 
	char text[] = "3141592653589793"; 
	char P[] = "26"; 
	int Q = 11;
	search(P, text, Q); 
	return 0; 
} 
