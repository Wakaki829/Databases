#include "stdafx.h"
#include "Header.h"

//ファイルを開く
void File_Open(FILE* fp, char *filename) {
	errno_t err; //ファイルが正常に開けたかどうかを確認するための変数
	err = fopen_s(&fp, filename, "r"); //ファイルを開き正常に開けたら0を返す

	if (err != 0) {
		printf("file open error!!\n");	//ファイルが開けなかったらエラーを出力
		exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
	}
}

//ファイルに書かれてる内容を読み取る
void File_read(FILE* fp, char *password) {
	int j;

	while (fgets(password, 256, fp) != NULL) {
		j++;
		// ここではfgets()により１行単位で読み出し
		printf("ファイル内のデータ数: %d\n", j);
	}
}