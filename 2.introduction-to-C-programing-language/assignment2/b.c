//Abu and Babu are close friends. Recently they both got admitted into the same university.
//Now they want to live in the university halls.
//They want to live in the same room. There are n rooms in the hall. At the moment the i-th room has pi people living in it and the room can accommodate qi people in total.
//Your task is to count how many rooms has free place for both Abu and Babu.

#include<stdio.h>

int main(){
    int n, room=0;
    scanf("%d", &n);

    for(int i=0; i<n;i++){
        int pi, qi;
        scanf("%d %d", &pi, &qi);
        if(pi<qi && (qi-pi) >1){
            room++;
        }
    }
    printf("%d", room);
    return 0;
}
