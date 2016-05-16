#include <stdio.h>
#include "xml.h"
#include "..\ProgLab\strings.h"

#define MAX_CHILDRENS_COUNT 10;
#define MAX_ATTRIBUTES_COUNT 10;

void xmlProcessObject(struct XmlNode *parent, char xml[]);
void xmlProcessAttributes(struct XmlNode *parentNode, char xml[]);

bool xmlValidate(char xml[])
{
	struct XmlNode root;
	xmlProcessObject(&root, xml);

	return false;
}

void xmlProcessObject(struct XmlNode *parent, char xml[])
{
	int pos = 0;
	char *block = stringToken(&(xml[pos]), " \t\n");
	while (block != NULL)
	{
		if (block == '\0')
		{
			pos++;
			continue;
		}
		
		pos += stringLength(block);

		if (block[0] == '<')
		{
			(*parent).name = &(block[1]);
		}

		block = stringToken(NULL, " \t\n");
	}
}
