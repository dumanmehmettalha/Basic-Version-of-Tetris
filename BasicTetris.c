#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void returnPart(int part[][3], int randomNum) {
    int part1[3][3] = {{1, 1, 1}, {0, 0, 0}, {0, 0, 0}};
    int part2[3][3] = {{1, 1, 0}, {1, 1, 0}, {0, 0, 0}};
    int part3[3][3] = {{1, 0, 0}, {1, 0, 0}, {0, 0, 0}};
    int part4[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int part5[3][3] = {{1, 0, 0}, {1, 0, 0}, {1, 1, 0}};
    int part6[3][3] = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
    int part7[3][3] = {{1, 1, 0}, {0, 1, 1}, {0, 0, 0}};

    int i, j;
    switch (randomNum) {
        case 1:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    part[i][j] = part1[i][j];
                }
            }
            break;
        case 2:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    part[i][j] = part2[i][j];
                }
            }
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    part[i][j] = part3[i][j];
                }
            }
            break;
        case 4:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    part[i][j] = part4[i][j];
                }
            }
            break;
        case 5:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    part[i][j] = part5[i][j];
                }
            }
            break;
        case 6:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    part[i][j] = part6[i][j];
                }
            }
            break;
        case 7:
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    part[i][j] = part7[i][j];
                }
            }
            break;
    }
}

void printMatrix(int matrix[][MAX], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printPart(int part[][3]) {
    //printf("boyut1: %d, boyut2: %d\n", boyut1, boyut2);
    printf("Siradaki gelecek olan sekil: \n");
    int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (part[i][j] == 1) {
                printf("X");
            }else{
            	printf(" ");
			}
        }
        printf("\n");
    }
}

void rotatePart(int part[][3]) {
    int i, j;
    int temp[3][3];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            temp[i][j] = part[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            part[j][i] = temp[i][j];
        }
    }
    printPart(part);
}

int controlMatrix(int board[][MAX], int boyut,int score) {
	int i;
    for (i = 0; i < boyut; i++) {
        if (board[0][i] == 1) {
        	printf("\nKaybettiniz.\n");
            return 0; // oyun bitti
        }
    }
    return 1; // oyuna devam edilebilir.
}

int findFullLine(int board[][MAX], int boyut) {
    int i, j, counter = 0;
    for (i = 0; i < boyut; i++) {
        for (j = 0; j < boyut; j++) {
            if (board[i][j] == 1) {
                counter++;
            }
        }
        if (counter == boyut) {
			return i;
        }else{
		counter=0;}
    }
    return 0;
}
int deleteLine(int board[][MAX], int boyut, int lineInd) {
    int i, j;
    for (i = lineInd; i > 0; i--) {
        for (j = 0; j < boyut; j++) {
            board[i][j] = board[i - 1][j];
        }
    }
    for (j = 0; j < boyut; j++) {
        board[0][j] = 0;
    }
    return boyut;
}
int findBottom(int board[][MAX],int boyut,int koordinat){
	int i;
	for(i=boyut-1;i>0;i--){
		if(board[i][koordinat]==0 && board[i-1][koordinat]!=1){
			return i;
		}
		else{ 
			//
		}
	}
	return boyut-1;
}
void putPart(int board[][MAX], int part[][3], int koordinat, int boyut) {
    int i, j, bottom;
		bottom=findBottom(board,boyut,koordinat);
		//printf("Bottom: %d\n",bottom);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
				if (part[i][j] == 1 && board[bottom-i][koordinat + j] == 0) {
                    board[bottom-i][koordinat + j] = 1;
                } else if (koordinat + j >= boyut && part[i][j]!=0) {
                    printf("Girdiginiz koordinata yerlestirme yapilamadi\n");
                }
            }
        }
}
void zeroMatrix(int board[][MAX],int boyut){
	int i,j;
	for(i=0;i<boyut;i++){
		for(j=0;j<boyut;j++){
			board[i][j]=0;
		}
	}
}
int main() {
    //int boyutlar[7][2] = {{1, 3}, {2, 2}, {2, 1}, {1, 1}, {3, 2}, {3, 1}, {2, 3}};
    int boyut, i, j;
    int board[MAX][MAX] = {{0}}; // her bir elemaný sýfýr olan bir oyun tahtasý oluþtur
    int koordinat,lineInd,score=0;
    int oyunSonu = 1;
    int rotate = 0;
    int part[3][3];
    int topScore=0;

    printf("Tetris'e Hosgeldiniz.\n");
    printf("Lutfen oyun tahtasinin boyutunu giriniz.");
    scanf("%d", &boyut);

    do {
        srand(time(NULL));
        int a = rand() % 7 + 1;
       // printf("Random: %d\n", a);
        returnPart(part, a);
        printPart(part);
        printf("\nParcayi dondurmek istiyorsaniz 1'e basin, aksi taktirde 0. ");
        scanf("%d", &rotate);
        if(rotate==1){
        	rotatePart(part);
		}
		printf("\n\tOyun Tahtasi\n");
        printMatrix(board, boyut);
        printf("Lutfen parcayi yerlestirmek icin bir koordinat giriniz: ");
        scanf("%d", &koordinat);
        if (koordinat >= boyut) {
            printf("\nTekrar giriniz.");
            scanf("%d", &koordinat);
        }
        putPart(board,part,koordinat,boyut);
        score+=1;
        oyunSonu=controlMatrix(board,boyut,score);
        if(oyunSonu==0){
        	printf("Tekrar oynamak icin 1, cikmak icin 0'a basin.");
        	scanf("%d",&oyunSonu);
        	if(oyunSonu==1){
        		if(score>topScore){
        			topScore=score;
				}
				printf("\nEn yuksek skor: %d\n",topScore);
        		printf("Lutfen oyun tahtasinin boyutunu giriniz.");
    			scanf("%d", &boyut);
    			zeroMatrix(board,boyut);
    			score=0;
			}
		}
        printMatrix(board,boyut);
        printf("\n Oyunu sonlandirmak icin 0'a basin, devam etmek icin 1. ");
        scanf("%d",&oyunSonu);
		lineInd=findFullLine(board,boyut);
		if(lineInd!=0){
			score+=deleteLine(board,boyut,lineInd);
			printMatrix(board,boyut);
		}
		printf("\n\nSkorunuz: %d\n\n",score);
    } while (oyunSonu == 1);
    return 0;
}

