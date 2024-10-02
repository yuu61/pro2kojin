#include <stdio.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

//引数はreadmeを参照
void initRepository(char* command)
{
	char comitDir[256], stageDir[256];
	snprintf(comitDir, sizeof(comitDir), "%s/comitDir", command);
	snprintf(stageDir, sizeof(stageDir), "%s/stageDir", command);

	if (_mkdir(command) == 0)
	{
		if (_mkdir(comitDir) == 0 && _mkdir(stageDir) == 0)
		{
			puts("success!!");
		}
		else
		{
			printf("エラー\n下位フォルダを作成できませんでした\nすでに存在するか、アクセス権がありません\n");
		}
	}
	else
	{
		printf("エラー\nリポジトリを作成できませんでした\nすでに存在するか、アクセス権がありません\n");
	}
}

char hashGen(const char* pass)
{
	char passs[256];
	char hash[41];
	snprintf(passs, sizeof(passs), "certutil -hashfile %s sha1", pass);
	system(passs);
	//certutil -hashfileはプログラム内での使用が推奨されていないのでsha1暗号関数を後で実装
	return hash;
}

int main(void)
{
	char command[256];
	char* input;
	char* option;

	printf("バージョン管理\n");
	while (1)
	{
		printf("> ");
		input = fgets(command, sizeof(command), stdin);
		
		command[strcspn(command, "\n")] = 0;

		(void)hashGen("C:\\Users\\admin\\Downloads\\0G03036_DX01.c");
		
	}
	return 0;
}