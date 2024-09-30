#include <stdio.h>
#include <direct.h>
#include <string.h>
#include <stdlib.h>

//コンパイルしてコマンドラインから実行してください
//引数はreadmeを参照
void initRepository()
{
	if (_mkdir("./test") == 0)
	{
		puts("success!!");
	}
	else
	{
		printf("エラー\nリポジトリを作成できませんでした\nすでに存在するか、アクセス権がありません");
	}
}

void addFile()
{
	
}

int main(void)
{
	char command[256];
	char* input;

	printf("なんちゃってバージョン管理\n");
	while (1)
	{
		printf("> ");
		input = fgets(command, sizeof(command), stdin);
		
		command[strcspn(command, "\n")] = 0;

		if (strcmp(command, "init") == 0);
		{
			initRepository();
		}
	
	
	}



	

	initRepository();
	
}