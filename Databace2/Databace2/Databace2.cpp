// Databace2.cpp : アプリケーションのエントリ ポイントを定義します。
//
#include "stdafx.h"
#include "Header.h"

int main() {
	//データベース情報
	const char host[] = "localhost";                 //接続先
	const char user[] = "root";                      //ユーザ名
	char password[256];                              //パスワード
	const char dbname[] = "sample_data";             //データベース名
	const char sql[] = "SELECT * FROM sample_data";  //参照sql

	//mysql用の構造体
	MYSQL*       mysql; //接続情報
	MYSQL_RES*   res;   //クエリの返信データ
	MYSQL_FIELD* field; //フィールド（カラム）情報
	MYSQL_ROW    row;   //ロウ（レコード）情報

	//その他の変数宣言
	int    num_fields;     //フィールド数
	my_ulonglong num_rows; //ロウ数
	int    i,j=0;            //ループカウンタ
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, "password.txt", "r");
	// ファイルのオープン 
	if (err != 0) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
	}

	// ファイルの読み（書き）
	while (fgets(password, 256, fp) != NULL) {
		j++;
		// ここではfgets()により１行単位で読み出し
		printf("ファイル内のデータ数: %d\n", j);
	}
	fclose(fp);	/* ファイルのクローズ */

	//初期処理
	mysql = mysql_init(0);

	//mysqlに接続
	if (mysql_real_connect(mysql, host, user, password, dbname, MYSQL_PORT, NULL, 0) == NULL) {
		printf("%s\n", mysql_error(mysql));
		return -1;
	}

	//sqlの発行
	if (mysql_query(mysql, sql) != 0) {
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
		return -1;
	}

	//mysqlからデータを取得
	res = mysql_store_result(mysql);
	if (res == NULL) {
		printf("%s\n", mysql_error(mysql));
		mysql_close(mysql);
		return -1;
	}

	//ロウ数取得
	num_rows = mysql_num_rows(res);
	printf("データ件数: %d\n", num_rows);

	//フィールド数取得
	num_fields = mysql_num_fields(res);

	//フィールド情報取得
	field = mysql_fetch_fields(res);

	//データを読み取って表示
	while (row = mysql_fetch_row(res)) {
		for (i = 0; i < num_fields; i++) {
			printf("%s=%s/", field[i].name, row[i]);
		}
		printf("\n");
	}
	getchar();
	getchar();
	//mysqlと切断
	mysql_close(mysql);

	return 0;
}

