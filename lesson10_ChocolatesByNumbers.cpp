// you can also use includes, for example:
// #include <algorithm>
int gcd(int a, int b);

int solution(int N, int M) {
    
    int mygcd = gcd(N,M);
    
    return N/mygcd;
}

int gcd(int a, int b) {
    if (a<b) {
        return (b%a==0)? a : gcd(a, b%a);
    } else {
        return (a%b==0)? b : gcd(b, a%b);
    }
}