#include "stdafx.h"
#include "Header.h"

//�t�@�C�����J��
void File_Open(FILE* fp, char *filename) {
	errno_t err; //�t�@�C��������ɊJ�������ǂ������m�F���邽�߂̕ϐ�
	err = fopen_s(&fp, filename, "r"); //�t�@�C�����J������ɊJ������0��Ԃ�

	if (err != 0) {
		printf("file open error!!\n");	//�t�@�C�����J���Ȃ�������G���[���o��
		exit(EXIT_FAILURE);	/* (3)�G���[�̏ꍇ�͒ʏ�A�ُ�I������ */
	}
}

//�t�@�C���ɏ�����Ă���e��ǂݎ��
void File_read(FILE* fp, char *password) {
	int j;

	while (fgets(password, 256, fp) != NULL) {
		j++;
		// �����ł�fgets()�ɂ��P�s�P�ʂœǂݏo��
		printf("�t�@�C�����̃f�[�^��: %d\n", j);
	}
}