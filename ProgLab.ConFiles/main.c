#include <stdbool.h>
#include <conio.h>
#include "../ProgLab/strings.h"
#include "io.h"

const char DEFAULT_PATH[] = "D:\\Desktop\\proglab.xml";
const char DEFAULT_PATH2[] = "C:\\Windows\\WinSxS\\amd64_microsoft-windows-servicingstack_31bf3856ad364e35_10.0.10586.168_none_76587b40265ca57e\\GlobalInstallOrder.xml";

int main()
{
	char *data = fileReadLine(DEFAULT_PATH2);
	while (data != NULL)
	{
		printf(data);
		free(data);
		data = fileReadLine(NULL);
	}

	_getch();
	return 0;
}