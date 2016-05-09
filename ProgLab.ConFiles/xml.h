#pragma once
#include <stdbool.h>

enum XmlObjectType
{
	OpenTagBegin = 0,
	CloseTagBegin = 1,
	TagEnd = 2,
	TagName = 3,
	AttributeName = 4,
	AttributeValue = 5,
	ElementValue = 6
};

struct XmlAttribute
{
	char *name;
	char *value;
};

struct XmlNode
{
	char *name;
	char *value;
	struct XmlAttribute *attributes;
	struct XmlNode *childrens;
	struct XmlNode *parent;
};

bool xmlValidate(char xml[]);