int solution(const string &S) {
    int stack = 0;
    for (int i=0; i<S.size(); i++) {
        if (S.compare(i,1,")")==0) {
            stack--;
        }
        else if (S.compare(i,1,"(")==0) {
            stack++;
        }
        else {
            return 0;
        }
        if (stack<0) {
            return 0;
        }
    }
    return (stack==0)? 1 : 0;
}