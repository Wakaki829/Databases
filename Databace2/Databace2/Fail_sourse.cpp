#include "stdafx.h"
#include "Header.h"

void File_Open(FILE* fp, char *filename) {
	errno_t err;
	err = fopen_s(&fp, filename, "r");

	if (err != 0) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	/* (3)�G���[�̏ꍇ�͒ʏ�A�ُ�I������ */
	}
}