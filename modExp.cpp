int modExp(int base,int exp,int MOD){
	int res=1;

	while(exp){
		if(exp&1){
			res=(res*base)%MOD;
		}
		base = (base*base)%MOD;
		exp=exp>>1;
	}

	return res;
}
