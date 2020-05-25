#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	time_t osTime;
	struct tm *datetime;
	int month;
	int year;
	struct tm userdatetime;
	time_t usertime;
	char userstr[26];

	//OS time
	if(time(&osTime) == -1){
		perror("time()");
	    exit(EXIT_FAILURE);
	}
	printf("OStime: %ld\n", osTime);

	//gm time
	if((datetime = gmtime(&osTime)) > 0){
		month = datetime->tm_mon + 1;
		year = datetime->tm_year + 1900;
		printf("GMT: S:%02d M:%02d H:%02d | D:%02d M:%02d Y:%04d | WD:%d YD:%03d DST:%d\n", datetime->tm_sec, datetime->tm_min, datetime->tm_hour, datetime->tm_mday, month, year, datetime->tm_wday, datetime->tm_yday, datetime->tm_isdst);
	} else {
		perror("gmtime()");
	    exit(EXIT_FAILURE);
	}

	//local time
	if((datetime = localtime(&osTime)) > 0){
		month = datetime->tm_mon + 1;
		year = datetime->tm_year + 1900;
		printf("Localtime: S:%02d M:%02d H:%02d | D:%02d M:%02d Y:%04d | WD:%d YD:%03d DST:%d\n", datetime->tm_sec, datetime->tm_min, datetime->tm_hour, datetime->tm_mday, month, year, datetime->tm_wday, datetime->tm_yday, datetime->tm_isdst);
	} else {
		perror("localtime()");
	    exit(EXIT_FAILURE);
	}

	//mk time
	usertime = mktime(datetime);
	printf("usertime: %ld\n", osTime);

	//c time
	if((ctime_r(&usertime, &userstr)) > 0){
		printf("ctime: %s", userstr);
	} else {
		perror("ctime()");
	    exit(EXIT_FAILURE);
	}

	//asc time
	if((asctime_r(datetime, &userstr)) > 0){
		printf("asctime: %s", userstr);
	} else {
		perror("asctime()");
	    exit(EXIT_FAILURE);
	}

	//strf time
	if((strftime(&userstr, sizeof(userstr), "%c", datetime)) > 0){
		printf("strftime: %s\n", userstr);
	} else {
		perror("strftime()");
		exit(EXIT_FAILURE);
	}

   	exit(EXIT_SUCCESS);
}