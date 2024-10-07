#include <stdio.h>

int safety_count(int score) {
    int count = 0;
    while (score >= 2) {
        score -= 2;
        count++;
    }
    return count;
}

int convert(int TD2, int TD1, int TD, int FG, int S) {
    printf("%d TD+2, %d TD+1, %d TD, %d FG, %d S\n", TD2, TD1, TD, FG, S);
    while (S >= 3) {
        S -= 3;
        FG += 2;
        printf("%d TD+2, %d TD+1, %d TD, %d FG, %d S\n", TD2, TD1, TD, FG, S);
    }
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

        S = safety_count(score);
        if (score%2 == 1) {
            S--;
            FG++;
        }
        convert(TD2, TD1, TD, FG, S);

        while (S >= 3) {
            S -= 3;
            FG += 2;
        }

        if (FG >= 2) {
            int temp1 = score;
            int temp2 = FG;
            for (int i=0; i<temp2/2; i++) {
                FG = 0;
                temp1 -= 6;
                TD++;
                S = safety_count(temp1);
                if (temp1%2 == 1) {
                    S--;
                    FG++;
                }
                convert(TD2, TD1, TD, FG, S);
            }
        }

        int temp = score;
        while (temp >= 7) {
            FG = 0;
            TD = 0;
            temp -= 7;
            TD1++;
            S = safety_count(temp);
            if (temp%2 == 1) {
                S--;
                FG++;
            }
            convert(TD2, TD1, TD, FG, S);
        }
    }
}