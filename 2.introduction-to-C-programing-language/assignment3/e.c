#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    int n,c = 0;
    scanf("%d", &n);

    char word[n+1];
    scanf("%s", word);

    for(int i=0; i<n; ++i){
        word[i]= tolower(word[i]);
    }

    int hash[128] = { 0 };

	// reading each character of word[]
	for (int i = 0; i < n; ++i) {
		// set the position corresponding
		// to the ASCII value of word[i] in hash[] to 1
		hash[word[i]] = 1;
	}

	// counting number of unique characters
	// repeated elements are only counted once
	for (int i = 0; i < 128; ++i) {
		c += hash[i];
	}

	if(c == 26){
        printf("YES");
	}
	else {
        printf("NO");
	}
    return 0;
}
