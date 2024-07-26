#include"VietNamese.h"

int mp[10000];

void setChar() {
	int idx = 0;
	for (int x : vietnamese_chars) mp[x] = idx++;
}