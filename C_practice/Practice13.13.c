#include <stdio.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url);

int main(int argc, char *argv[]) {
	char domain[100] = "forever.info", index_url[100];
	build_index_url(domain, index_url);
	printf("%s", index_url);
	
}

void build_index_url(const char *domain, char *index_url){
	char full_url[100] = "http://www.";
	strcat(full_url, domain);
	strcat(full_url, "/index.html");
	strcpy(index_url, full_url);
}