#include <unistd.h>
#include <stdio.h>
#include <dirent.h>

int main(void)
{
	DIR *dir_info;
	struct dirent *dir_entry;

	dir_info = opendir(".");
	if(NULL != dir_info)
	{
		while(dir_entry = readdir(dir_info))
		{
			printf("%s\n", dir_entry->d_name);
		}

		closedir(dir_info);
	}
}
