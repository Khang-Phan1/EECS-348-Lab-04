#include <stdio.h>

int safety_count(score) {
    int count = 0;
    while (score >= 2) {
        score -= 2;
        count++;
    }
    return count;
}

int main() {
    while(1) {
        int score=0, TD=0, FG=0, S=0, TD2=0, TD1=0;
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }

        int temp=score, count=0;
        while (temp >= 2) {
            temp -= 2;
            count++;
        }
        if (temp == 1) {
            count--;
            FG++;
        }
        S = count;
        printf("%d S, ", S);
        printf("%d FG\n", FG);
        
        while (S >= 3) {
            S -= 3;
            FG += 2;
            printf("%d S, %d FG\n", S, FG);
        }

        if (FG >= 2) {
            temp = score;
            for (int i; i<=FG/2; i++) {
                temp -= 6;
                TD++;

            }
        }
    }
}