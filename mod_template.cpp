int modmulti(int a, int b){
   return ((a%mod)*1LL*(b%mod))%mod;
}
int modadd(int a, int b){
   int _tmpA =  ((a%mod)+(b%mod)+mod+mod)%mod;
   _tmpA = (_tmpA+mod)%mod;
   return _tmpA;
}
int modpower(int a, int n){
   if(n==0) return 1;
   if(n==1) return a%mod;
   int b = modpower(a,n/2);
   b = modmulti(b,b);
   if(n%2==0) return b;
   return modmulti(a,b);
}
int modinv(int a){
    return modpower(a,mod-2);
}   