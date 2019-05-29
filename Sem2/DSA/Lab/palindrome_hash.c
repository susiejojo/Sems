#include<stdio.h>
#include<string.h>
#include<math.h>
char str[100000];
long long int arr1[1000000];
long long int arr2[1000000];
long long int hash_f1(long long int hash1,long long int i)
{
		hash1=hash1*29+(long long int)(str[i] - 'a') + 1;
		arr1[i]=hash1;
		return hash1;
}
long long int hash_f2(long long int hash2,long long int i)
{
		hash2=hash2*29+(long long int)(str[i] - 'a') + 1;
		arr2[strlen(str)-i-1]=hash2;
		return hash2;
}
long long int palindrome_checker(long long int l,long long int r){
	long long int flag=0;
	long long int fval=arr1[r]-(arr1[l-1]*(long long int)(pow(29,r-l+1)));
	long long int rval=arr2[strlen(str)-l-1]-(arr2[strlen(str)-r-2]*(long long int)(pow(29,r-l+1)));
	printf("%lld %lld\n",fval,rval);
	if (fval==rval)
		flag=1;
	else
		flag=0; 
	return flag;
}
long long int main(){
	scanf("%s",str);
	long long int q;
	scanf("%lld",&q);
	while (q--)
	{
	    long long int hash1=(long long int)(str[0] - 'a') + 1;
	    arr1[0]=hash1;
	for (int i=1;i<strlen(str);i++)
	{
		hash1=hash_f1(hash1,i);
	}
	    long long int hash2=(long long int)(str[strlen(str)-1] - 'a')+ 1;
	    //printf("%Ld\n", hash2);
	    arr2[0]=hash2;
	    //printf("%Ld\n", arr2[0]);
	for (int i=strlen(str)-2;i>=0;i--)
	{
	    //printf("%Ld\n", arr2[0]);
		hash2=hash_f2(hash2,i);
	}
		    //printf("%Ld\n", arr2[0]);

	for (int i=0;i<strlen(str);i++)
	{
		printf("%lld ",arr1[i]);
	}
	printf("\n");
	for (int i=0;i<strlen(str);i++)
	{
		printf("%lld ",arr2[i]);
	}
		long long int l,r;
		scanf("%lld %lld",&l,&r);
		long long int ans=palindrome_checker(l,r);
		if (ans==1)
			printf("YES\n");
		else
			printf("NO\n");
	}

}