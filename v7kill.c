/* Copyright (c) 2022 calmsacibis995. All rights reserved. */
/* v7kill is licensed under the 3-clause BSD license. */

/*
 * kill - send signal to process
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int register signo, pid, res;
	int errlev;
	extern errno;

	errlev = 0;
	if (argc <= 1) {
	usage:
		printf("usage: kill [ -signo ] pid ...\n");
		exit(2);
	}
	if (*argv[1] == '-') {
		signo = atoi(argv[1]+1);
		argc--;
		argv++;
	} else
		signo = SIGTERM;
	argv++;
	while (argc > 1) {
		if (**argv<'0' || **argv>'9')
			goto usage;
		res = kill(pid = atoi(*argv), signo);
		if (res<0) {
			printf("%u: %s\n", pid, strerror(errno));
			errlev = 1;
		}
		argc--;
		argv++;
	}
	return(errlev);
}
