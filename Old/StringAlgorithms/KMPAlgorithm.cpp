 //KMP ALgorithm- Sabuj Jana-@greenindia-Jadavpur University
#include <bits/stdc++.h> 
using namespace std;

void computeLPSArray(string pat, int M, int* lps); 

 
void KMPSearch( std::string pat,  std::string txt) 
{ 
	int M =  pat.length(); 
	int N =  txt.length(); 

	 
	int lps[M]; 

 
	computeLPSArray(   pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
// 			printf("Found pattern at index %d ", i - j); 
            std::cout << "Found pattern at index " << i-j <<std::endl;
			j = lps[j - 1]; 
		} 

	 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

 
void computeLPSArray( std::string pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0;  
	 
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			 
			if (len != 0) { 
				len = lps[len - 1]; 

			 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program   
int main() 
{   
    string txt,pat;
         txt  = "ABACABAB"; 
	     pat  = "AB"; 
	KMPSearch(pat, txt); // 0 4 6
	return 0; 
} 

/**Resources-
1.https://www.youtube.com/watch?v=GTJr8OvyEVQ&t=691s
2.https://www.youtube.com/watch?v=GTJr8OvyEVQ&t=691s
3.https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
4.https://www.youtube.com/watch?v=V5-7GzOfADQ
