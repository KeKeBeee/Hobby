#include <stdio.h>
#include <stdlib.h>
int main(){
	int year,month,date,sum,sumy,summ,r,s,t; /*計算用*/
	int i;/*関数用*/
	printf("\n★ 曜日判別アプリ ver1.1 ★\n\n");
	printf("このアプリでは西暦1700年以降の曜日を判別できます\n");
	printf("西暦を入力してください : ");
	scanf("%d",&year);
	
	/*西暦確認*/
	if ( year < 1700 ){
		printf("ERROR : 1700年より前は判別できません\n");
		printf("アプリを終了します\n\n");
		exit(0);
	}
	
	printf("月を入力してください : ");
	scanf("%d",&month);
	/*月確認*/
	if ( month < 1 || month > 12) {
		printf("ERROR : 月は 1 ~ 12 の範囲で入力してください\n");
		printf("アプリを終了します\n\n");
		exit(0);
	}
	printf("日付を入力してください : ");
	scanf("%d",&date);
	
	/*日付確認*/
	if ( date < 1 ) {
		printf("ERROR : 日付は 1 ~ 31 の範囲で入力してください\n");
		printf("アプリを終了します\n\n");
		exit(0);
	}
	
	/*整合性確認*/
	if ( (year%4 == 0 && year%100 != 0) || year%400 == 0 ) {
		switch(month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if ( date > 31 ) {
					printf("ERROR : 月と日付の組み合わせが間違っています\n");
					printf("アプリを終了します\n\n");
					exit(0);
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if ( date > 30 ) {
					printf("ERROR : 月と日付の組み合わせが間違っています\n");
					printf("アプリを終了します\n\n");
					exit(0);
				}
				break;
			case 2:
				if ( date > 29 ) {
					printf("ERROR : 月と日付の組み合わせが間違っています\n");
					printf("アプリを終了します\n\n");
					exit(0);
				}
				break;
		}
	} else {
		switch(month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if ( date > 31 ) {
					printf("ERROR : 月と日付の組み合わせが間違っています\n");
					printf("アプリを終了します\n\n");
					exit(0);
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if ( date > 30 ) {
					printf("ERROR : 月と日付の組み合わせが間違っています\n");
					printf("アプリを終了します\n\n");
					exit(0);
				}
				break;
			case 2:
				if ( date > 28 ) {
					printf("ERROR : 月と日付の組み合わせが間違っています\n");
					printf("アプリを終了します\n\n");
					exit(0);
				}
				break;
		}
	}
	
	/*sum*/
	sumy = ((year - 1) - 1699 ) * 365;
	summ = ((month - 1) * 30);
	sum = sumy + summ + date;
	
	/*閏年補正*/
	for ( i = 1700 ; i < year ; i++ ) {
		if ( (i%4 == 0 && i%100 != 0) || i%400 == 0 ) {
			sum = sum + 1;
		}
	}
	if ( (year%4 == 0 && year%100 != 0) || year%400 == 0 ) {
		if ( month > 3 ){
			sum = sum + 1;
		}
	}
	
	/*月別日数補正*/
	switch(month) {
		case 12:
		case 11: sum = sum +1;
		case 10: 
		case 9: sum = sum + 1;
		case 8: sum = sum + 1;
		case 7:
		case 6: sum = sum + 1;
		case 5:
		case 4: sum = sum + 1;
		case 3: sum = sum - 2;
		case 2: sum = sum + 1;
		case 1: break;
	} 
	
	/*剰余計算*/
	r = sum%7;
	
	/*出力*/
	printf("%d年 %d月 %d日 は",year,month,date);
	
	switch(r) {
		case 0: printf(" 木曜日"); break;
		case 1: printf(" 金曜日"); break;
		case 2: printf(" 土曜日"); break;
		case 3: printf(" 日曜日"); break;
		case 4: printf(" 月曜日"); break;
		case 5: printf(" 火曜日"); break;
		case 6: printf(" 水曜日"); break;
	}
	
	printf(" です\n");
	printf("アプリを終了します\n\n");
	return 0;
}

	