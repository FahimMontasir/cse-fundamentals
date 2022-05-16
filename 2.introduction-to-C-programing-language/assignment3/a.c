//You are provided with the username of the profile that Mahir encounters.
//You have to find if it is the profile of a girl or a boy. The way to distinguish between the account of boy and girl depends on the number of distinct characters in the username.
//If this number is odd, the profile is of a boy otherwise it is of a girl.
#include<stdio.h>
#include<string.h>

int main(){
    char username[101];
    scanf("%s", username);
    int hash[128] = { 0 };
	int i, c = 0;

	// reading each character of username[]
	for (i = 0; i < strlen(username); ++i) {
		// set the position corresponding
		// to the ASCII value of username[i] in hash[] to 1
		hash[username[i]] = 1;
	}

	// counting number of unique characters
	// repeated elements are only counted once
	for (i = 0; i < 128; ++i) {
		c += hash[i];
	}

    if(c%2 == 0){
        printf("CHAT WITH HER!");
    }
    else {
        printf("IGNORE HIM!");
    }
}
