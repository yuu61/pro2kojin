#include <stdio.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

// 引数はreadmeを参照
void initRepository(char *command)
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

void hashGen(const char *filepath)
{
	FILE *fp = fopen(filepath, "rb");
	if (!fp)
	{
		perror("ファイルオープンエラー");
		return;
	}

	SHA_CTX shaContext;
	unsigned char hash[SHA_DIGEST_LENGTH];
	unsigned char buffer[BUFFER_SIZE];
	int bytesRead = 0;

	while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
	{
		SHA1_Update(&shaContext, buffer, bytesRead);
	}

	SHA1_Final(hash, &shaContext);

	printf("SHA1 hash of file %s: ", fp);
	for (int i = 0; i < SHA_DIGEST_LENGTH; i++)
	{
		printf("%02x", hash[i]);
	}
	printf("\n");

	fclose(fp);
}

int main(void)
{
	char command[256];
	char *input;
	char *option;

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
