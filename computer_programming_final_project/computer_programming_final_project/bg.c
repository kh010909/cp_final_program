#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int game_over(int[]);
void play(int[], int, struct GamePlayer* player1, struct GamePlayer* player2, struct GamePlayer* player3, struct GamePlayer* player4, struct GamePlayer* player5);
void reset(int[]);
struct GamePlayer{
	char* name;
	int current_gem;
	int stored_gem;
	int gamestatus;
};
int main(void) {
	int card[35] = { 0 };
	int i = 0;
	struct GamePlayer p1 = { "player1" , 0, 0, 1 };
	struct GamePlayer p2 = { "player2" , 0, 0, 1 };
	struct GamePlayer p3 = { "player3" , 0, 0, 1 };
	struct GamePlayer p4 = { "player4" , 0, 0, 1 };
	struct GamePlayer p5 = { "player5" , 0, 0, 1 };
	for (i = 0;i < 5; i++) {
		play(card, 5, &p1, &p2, &p3, &p4, &p5);
		reset(card);
		p1.gamestatus = 1;
		p2.gamestatus = 1;
		p3.gamestatus = 1;
		p4.gamestatus = 1;
		p5.gamestatus = 1;
		p1.current_gem = 0;
		p2.current_gem = 0;
		p3.current_gem = 0;
		p4.current_gem = 0;
		p5.current_gem = 0;
		printf("%d %d %d %d %d\n", (p1.stored_gem), (p2.stored_gem), (p3.stored_gem), (p4.stored_gem), (p5.stored_gem));
	}
	printf("%d %d %d %d %d\n", (p1.stored_gem), (p2.stored_gem), (p3.stored_gem), (p4.stored_gem), (p5.stored_gem));
	printf("Game over.");
}
int game_over(int a[]) {
	int i = 0;
	for (i = 0;i <= 4; i++) {
		if (a[20 + 3 * i] + a[21 + 3 * i] + a[22 + 3 * i] >= 2) {
			printf("Round over.");
			return 1;
		}
	}

	return 0;
}
void play(int a[], int b, struct GamePlayer* p1, struct GamePlayer* p2, struct GamePlayer* p3, struct GamePlayer* p4, struct GamePlayer* p5) {
	srand(rand() % 1000);
	int i = 0;
	int x = 0;
	int current_player = b;
	int leaving_player = 0;
	int remain = 0;
	int current = 0;
	int split1 = 0;
	int split2 = 0;
	int artifact = 0;
	while (1){
		if (!current_player) {
			printf("Round over.");
			break;
		}
		x = rand() % 35;
		if (a[x] == 1) {
			continue;
		}
		else {
			printf("%d ", x);
			if (0 <= x && 14 >= x) {
				a[x]++;
				printf("找到了%d顆寶石", x + 1);
				current = x + 1;
			}
			else if (15 <= x && 19 >= x) {
				a[x]++;
				printf("找到了1個神器");
				artifact += 1;
			}
			else if (20 <= x && 22 >= x) {
				a[x]++;
				printf("發生詛咒:落石");
			}
			else if (23 <= x && 25 >= x) {
				a[x]++;
				printf("發生詛咒:蜘蛛");
			}
			else if (26 <= x && 28 >= x) {
				a[x]++;
				printf("發生詛咒:木乃伊");
			}
			else if (29 <= x && 31 >= x) {
				a[x]++;
				printf("發生詛咒:隨便啦");
			}
			else if (32 <= x && 34 >= x) {
				a[x]++;
				printf("發生詛咒:我忘了");
			}
			printf("\n");
		}
		if (game_over(a)) {
			break;
		}
		split1 = 0;
		if (current != 0) {
			split1 = current / current_player;
			if (current < current_player) {
				remain += current;
				current = 0;
			}
			else {
				remain += current - (split1 * current_player);
				current = 0;
			}
			printf("由於有%d個人，每個人分到%d個寶石\n", current_player, split1);
		}
		if (p1->gamestatus == 1) {
			p1->current_gem += split1;
			int i = 0;
			printf("%s: you have %d gems right now.\n", p1->name,p1->current_gem);
			printf("%s: if you want to leave,please enter 0.\n", p1->name);
			scanf_s("%d", &i);
			if (i == 0) {
				(p1->gamestatus) = 0;
				current_player -= 1;
				leaving_player += 1;
			}
		}
		if (p2->gamestatus == 1) {
			int i = 0;
			p2->current_gem += split1;
			printf("%s: you have %d gems right now.\n", p2->name, p2->current_gem);
			printf("%s: if you want to leave,please enter 0.\n", p2->name);
			scanf_s("%d", &i);
			if (i == 0) {
				(p2->gamestatus) = 0;
				current_player -= 1;
				leaving_player += 1;
			}
		}
		if (p3->gamestatus == 1) {
			int i = 0;
			p3->current_gem += split1;
			printf("%s: you have %d gems right now.\n", p3->name, p3->current_gem);
			printf("%s: if you want to leave,please enter 0.\n", p3->name);
			scanf_s("%d", &i);
			if (i == 0) {
				(p3->gamestatus) = 0;
				current_player -= 1;
				leaving_player += 1;
			}
		}
		if (p4->gamestatus == 1) {
			int i = 0;
			p4->current_gem += split1;
			printf("%s: you have %d gems right now.\n", p4->name, p4->current_gem);
			printf("%s: if you want to leave,please enter 0.\n", p4->name);
			scanf_s("%d", &i);
			if (i == 0) {
				(p4->gamestatus) = 0;
				current_player -= 1;
				leaving_player += 1;
			}
		}
		if (p5->gamestatus == 1) {
			int i = 0;
			p5->current_gem += split1;
			printf("%s: you have %d gems right now.\n", p5->name, p5->current_gem);
			printf("%s: if you want to leave,please enter 0.\n", p5->name);
			scanf_s("%d", &i);
			if (i == 0) {
				(p5->gamestatus) = 0;
				current_player -= 1;
				leaving_player += 1;
			}
		}
		if (leaving_player > 0) {
			printf("有%d個人選擇離開，", leaving_player);
			if (leaving_player == 1) {
				split2 = remain;
				if (artifact) {
					printf("由於只有1個人離開，因此他獲得了%d個神器(價值5個寶石)", artifact);
				}
				if (p1->gamestatus == 0) {
					p1->current_gem += remain + 5 * artifact;
					artifact = 0;
					p1->stored_gem += (p1->current_gem);
					p1->gamestatus = -1;
				}
				else if (p2->gamestatus == 0) {
					p2->current_gem += remain + 5 * artifact;
					artifact = 0;
					p2->stored_gem += (p2->current_gem);
					p2->gamestatus = -1;
				}
				else if (p3->gamestatus == 0) {
					p3->current_gem += remain + 5 * artifact;
					artifact = 0;
					p3->stored_gem += (p3->current_gem);
					p3->gamestatus = -1;
				}
				else if (p4->gamestatus == 0) {
					p4->current_gem += remain + 5 * artifact;
					artifact = 0;
					p4->stored_gem += (p4->current_gem);
					p4->gamestatus = -1;
				}
				else if (p5->gamestatus == 0) {
					p5->current_gem += remain + 5 * artifact;
					artifact = 0;
					p5->stored_gem += (p5->current_gem);
					p5->gamestatus = -1;
				}
				remain = 0;
			}
			else if (remain < leaving_player &&leaving_player > 1) {
				split2 = 0;
				if (p1->gamestatus == 0) {
					p1->stored_gem += (p1->current_gem);
					p1->gamestatus = -1;
				}
				if (p2->gamestatus == 0) {
					p2->stored_gem += (p2->current_gem);
					p2->gamestatus = -1;
				}
				if (p3->gamestatus == 0) {
					p3->stored_gem += (p3->current_gem);
					p3->gamestatus = -1;
				}
				if (p4->gamestatus == 0) {
					p4->stored_gem += (p4->current_gem);
					p4->gamestatus = -1;
				}
				if (p5->gamestatus == 0) {
					p5->stored_gem += (p5->current_gem);
					p5->gamestatus = -1;
				}

			}
			else {
				split2 = remain / leaving_player;
				remain = remain - (split2 * leaving_player);

				if (p1->gamestatus == 0) {
					p1->stored_gem += (p1->current_gem) + split2;
					p1->gamestatus = -1;
				}
				if (p2->gamestatus == 0) {
					p2->stored_gem += (p2->current_gem) + split2;
					p2->gamestatus = -1;
				}
				if (p3->gamestatus == 0) {
					p3->stored_gem += (p3->current_gem) + split2;
					p3->gamestatus = -1;
				}
				if (p4->gamestatus == 0) {
					p4->stored_gem += (p4->current_gem) + split2;
					p4->gamestatus = -1;
				}
				if (p5->gamestatus == 0) {
					p5->stored_gem += (p5->current_gem) + split2;
					p5->gamestatus = -1;
				}
			}
			printf("每個離開的人獲得了路上的%d個寶石\n", split2);
			leaving_player = 0;
		}
		printf("目前路上有%d個寶石\n", remain);
	}
	printf("\n");
}
void reset(int a[]) {
	int i = 0;
	for (i = 0;i < 35;i++) {
		a[i] = 0;
	}
}
