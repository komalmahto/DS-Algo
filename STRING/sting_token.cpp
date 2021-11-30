#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
// Declaration of string 
	char gfg[100] = "Geeks - for - geeks - Contribute"; 

	// Declaration of delimiter 'G','f','g','C'
	const char s[4] = {'G','f','g','C'}; 
	char* tok; 

	// Use of strtok 
	// get first token 
	tok = strtok(gfg, s); 

	// Checks for delimeter 
	while (tok != 0) { 
		cout<<tok<<endl; 

		// Use of strtok 
		// go through other tokens 
		tok = strtok(0, s); 
	} 
    return 0;
}
