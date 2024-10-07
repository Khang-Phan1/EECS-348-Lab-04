#include <stdio.h>

int safety_count(int score) {
    //calculates highest number of safeties scored possible given a score
    int count = 0;
    while (score >= 2) {
        score -= 2;
        count++;
    }
    return count;
}

int convert(int TD2, int TD1, int TD, int FG, int S) {
    //prints every variation of FG/S where 3 safeties converts to 2 FGs
    printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d S\n", TD2, TD1, TD, FG, S);
    while (S >= 3) {
        S -= 3;
        FG += 2;
        printf("%d TD+2pt, %d TD+FG, %d TD, %d FG, %d S\n", TD2, TD1, TD, FG, S);
    }
}

int main() {
    while(1) {
        int score=0, TD=0, FG=0, S=0, TD2=0, TD1=0, temp1=0, temp2=0, temp3=0;
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        //breaks loop if user input is 1 or below
        if (score <= 1) {
            break;
        }

        S = safety_count(score);
        //checks for odd input, will convert one safety to a FG
        if (score%2 == 1) {
            S--;
            FG++;
        }
        convert(TD2, TD1, TD, FG, S);

        //calculates highest number of FGs
        while (S >= 3) {
            S -= 3;
            FG += 2;
        }

        //for every 2 FGs, 1 TD is possible
        if (FG >= 2) {
            temp1 = score;
            temp2 = FG;
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

        //checks for possible combinations with increments of TD+1
        temp1 = score;
        while (temp1-7 >= 2 || temp1-7 == 0) {
            FG = 0;
            TD = 0;
            temp1 -= 7;
            TD1++;
            S = safety_count(temp1);
            if (temp1%2 == 1) {
                S--;
                FG++;
            }
            convert(TD2, TD1, TD, FG, S);

            //checks for possible combinations of TD within TD+1
            temp2 = temp1;
            while (temp2-6 >= 2 || temp2-6 == 0) {
                FG = 0;
                temp2 -= 6;
                TD++;
                S = safety_count(temp2);
                if (temp2%2 == 1) {
                    S--;
                    FG++;
                }
                convert(TD2, TD1, TD, FG, S);
            }
        }

        //checks for possible combinations with increments of TD+2
        temp1 = score;
        while (temp1-8 >= 2 || temp1-8 == 0) {
            FG = 0;
            TD = 0;
            TD1 = 0;
            temp1 -= 8;
            TD2++;
            S = safety_count(temp1);
            if (temp1%2 == 1) {
                S--;
                FG++;
            }
            convert(TD2, TD1, TD, FG, S);

            //checks for possible combinations with TD within TD+2
            temp2 = temp1;
            while (temp2-6 >= 2 || temp2-6 == 0) {
                FG = 0;
                temp2 -= 6;
                TD++;
                S = safety_count(temp2);
                if (temp2%2 == 1) {
                    S--;
                    FG++;
                }
                convert(TD2, TD1, TD, FG, S);
            }

            //checks for possible combinations with TD+1 within TD+2
            temp2 = temp1;
            while (temp2-7 >= 2 || temp2-7 == 0) {
                FG = 0;
                TD = 0;
                temp2 -= 7;
                TD1++;
                S = safety_count(temp2);
                if (temp2%2 == 1) {
                    S--;
                    FG++;
                }
                convert(TD2, TD1, TD, FG, S);

                temp3 = temp2;
                while (temp3-6 >= 2 || temp3-6 == 0) {
                    FG = 0;
                    temp3 -= 6;
                    TD++;
                    S = safety_count(temp3);
                    if (temp3%2 == 1) {
                        S--;
                        FG++;
                    }
                    convert(TD2, TD1, TD, FG, S);
                }
            }
        }
    }
}