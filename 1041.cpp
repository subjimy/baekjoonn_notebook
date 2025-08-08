/*
정육면체 전개도
d
abfe
c
이러한 주사위를 가지고 n^3의 정육면체를 만든다.
밖에 보이는 주사위 눈의 최소값.
예로 n이 2고 abcdef가 123456이라면 최소값은 36이다.

n : 1,000,000 이하 자연수
눈 값 : 50 이하 자연수
입력은 첫줄에 n, 둘째 줄에 abcdef값이 순차적으로 온다.

n=1 -> 바닥 제외
n=2 -> 아래 2면, 위 3면
n>=3 -> 아래 2면(4개), 1면(n*4-8)
        중간 2면(4개), 1면(n*4-8)  * (n-2)
        위 3면(4개), 2면(n*4-8), 1면((n-2)^2)

n이 3이상 이라면
    3면 4개
    2면 n*8개
    1면 4*(n-2)^4개

면 위치에 따른 최소값 조합
1면 가장 작은 숫자(가장 앞에 있는 걸로)
(불가 조합 - 2면) -> af, be, cd
3면 조합 -> abc, abd, aec, aed, fbc, fbd, fec, fed

*/

#include <iostream>

using namespace std;

int main(){
    int n;
    int sum = 0;

    cin >> n;
    if(n==1){
        int max = 0;
        int temp;
        for(int i=0;i<6;i++){
            cin>>temp;
            if(temp>max){
                max = temp;
            }
            sum += temp;
        }
        cout<<sum-temp<<endl;
        return 0;
    }

    int dice[6] = {};
    int one, two, three;
    int p1=0;
    int p2=0;
    one = 50;
    two = 50;
    three = 50;
    for(int i=0;i<6;i++){
        cin>>dice[i];
        if(dice[i] < one){
            one = dice[i];
            p1=i;
        }
    }
    //0a 1b 2c 3d 4e 5f  2side / 05, 23, 14
    //가장 작은 면을 구함(one). 인접 면중 가장 작은 거 더함. - two
    for(int i=0;i<6;i++){
        if(p1==i || p1+i==5) continue;
        else if(dice[i] < two){
            two = dice[i];
            p2=i;
        }
    }
    two += one;
    //two에 인접면 2개 중 작은 거 구함. - three
    for(int i=0;i<6;i++){
        if(p1==i || p1+i==5 || p2==i || p2+i==5) continue;
        else if(dice[i] < three){
            three = dice[i];
        }
    }
    three += two;

    if(n==2){
        cout<<4*(two+three)<<endl;
    }else if(n>2){
        cout<<4*(three+2*n*two+one*(n-2)*(n-2)*(n-2)*(n-2))<<endl;
    }else{
        return 1;
    }

    return 0;
}