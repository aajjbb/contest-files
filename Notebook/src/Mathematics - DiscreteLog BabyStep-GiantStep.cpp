//mpow(b, e, mod) -> base^exp % mod
//modInverse(r,p) -> inverse modular of r mod p

//find x such that "r ^ x = S mod p", p is prime.
long long discreteLog(long long r, long long S, long long p){
    long long ans = -1;
    if(r == 1){
        return S;
    }else{
        long long sqrtP = sqrt(p) + 1;
        unordered_map<long long, long long> baby;
        for(long long i = 0; i < sqrtP; i++){
            long long value = mpow(r, i, p);
            baby[value] = i;
        }
        long long m = mpow(modInverse(r,p), sqrtP, p);
        //n = m * i + baby[value]
        for(int i = 0; i < sqrtP; i++){
            long long value = (S * (mpow(m, i, p))) % p;
            if(baby.find(value) != baby.end()){
		ans = (i * sqrtP + baby[value]);
		break;
            }
        }
    }
    return ans;
}
