#include <dirent.h>
#include <stdio.h>

int main(void)
{
	DIR *dir = opendir(".");;
	struct dirent *entity;
	if (dir != NULL)
	{
		while ((entity = readdir(dir)) != NULL)
		{
			if (entity->d_type == DT_REG)
			{
				printf("%s\n", entity->d_name);
			}
		}
		closedir (dir);
	}
	return (0);
}
