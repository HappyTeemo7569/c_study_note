void qsort_dj(void* array, size_t n, size_t w, int(*cmp)(const void*,const void*))
{
	if(n<=1) return;

	int l = 0;
	int r = n-1;
	void* pivot = malloc(w); 
	memcpy(pivot,array,w);

	while(l < r)
	{
		while(l < r && cmp(pivot,(char*)array+r*w)<=0)
			r--;
		memcpy((char*)array+l*w,(char*)array+r*w,w);

		while(l < r && cmp(pivot,(char*)array+l*w)>=0)
			l++;
		memcpy((char*)array+r*w,(char*)array+l*w,w);
	}

	memcpy((char*)array+l*w,pivot,w);

	free(pivot);

	qsort_dj(array,l,w,cmp);
	qsort_dj((char*)array+l*w+w,n-l-1,w,cmp);                    
}
