

int power(int a, int b){
	int ans=1;
	while(b){
		if(b&1)
			ans=ans*a;
		b/=2;
		a=a*a;
	}
	return ans;
}

int power(int a, int b, int m){
	int ans=1;
	while(b){
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}