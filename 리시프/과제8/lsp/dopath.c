static int dopath(function *func)
{
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;
	int ret;
	char *ptr;

	if(lstat(fullpath, &statbuf) < 0)
		return(func(fullpath, &statbuf, FTW_NS));
	if(S_ISDIR(statbuf.st_mode) == 0)
		return(func(fullpath, &statbuf, FTW_F));
	if((ret = func(fullpath, &statbuf, FTW_D))!=0)
		return(ret);

	ptr = fullpath + strlen(fullpath);
	*ptr++ = '/';
	*ptr = 0;

	if((dp = opendir(fullpath)) == NULL)
		return(func(fullpath, &statbuf, FTW_DNR));

	while((dirp = readdir(dp))!= NULL)
	{
		if(strcmp(dirp->d_name, ".")==0 || strcmp(dirp->d_name, "..")==0)
			continue;

		strcpy(ptr, dirp->d_name);
		
		if((ret = dopath(func))!= 0)
			break;
	}

	ptr[-1] = 0;

	if(closdir(dp)<0)
	{
		printf("can't close directory [%s]\n", fullpath);
		exit(0);
	}

	return(ret);
}


int main(int argc, char *argv[])
{
	int i,fd;
	struct stat stat_buf;
	struct utimebuf time_buf;

	for()
	{
		if(stat(argv[i], &stat_buf)<0)
		{
			print err;
			continue;
		}
		if(fd = open(argv[i], O_RDWR| O_TRUNC) <0)
			err, continue;
		close(fd);

		time_buf.actime = stat_buf.st_atime;
		time_buf.modtime = stat_buf.st_mtime;

		if(utime(argv[i], &time_buf)<0)
			print, continue;



		
	}
}



int main(void)
{
	if(chdir("/etc")<0)
		print err, exit(1);

	printf("chdir to /etc succeeded\n");
	exit(0);
}




int main(void)
{
	char *path;

	if(chdir("")<0)
		err;

	path = malloc(PATH_MAX);
	if(getcwd(path, PATH_MAX) == NULL)
		err;

	printf(path);


}


if(lstat(fullpath, &statbuf)<0)
	return(func(fullpath &statbuf, FTW_NS));
if(S_ISDIR(stat_buf.st_mode) == 0)
	return(func(fullpath, &statbuf, FTW_F));
if(ret = func(fullpath, &statbuf, FTW_D)!=0)
	return(ret);

	ptr = fullpath + strlen(ptr);
	*ptr++  = '/';
	*ptr = 0;

	if(dp = opendir(fullpath) == NULL)
		return(func(fullpath, &statbuf, FTW_DNR));
	
	while(dirp = readdir(fullpath) ! = NULL)
	{
		if(. , ..)
			continue;

		strcpy(ptr, dirp->d_name);

		if(ret = dopath(func)!= 0)
			break;
	}

	ptr[-1] = 0;
	if(closedir(dp) < 0)
{
	err, exit(0);
}

return(ret);

