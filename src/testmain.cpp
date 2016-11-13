#include "CSHandle.h"
struct tag {};
typedef cs::CSHandle<tag> HTag;
int main(void)
{
	HTag x;
	return 1;
}