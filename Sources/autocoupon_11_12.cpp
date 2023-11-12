#include <iostream>
#include <string>

using namespace std;

const int MAX_PURCHASES = 100;

// 구매 내역을 저장하는 배열
string customerNames[MAX_PURCHASES];
string items[MAX_PURCHASES];
string themes[MAX_PURCHASES];

// 현재 저장된 구매 내역의 개수
int numPurchases = 0;

// 구매 내역을 저장하는 함수
void addPurchase(const string& customerName, const string& item, const string& theme) {
    if (numPurchases < MAX_PURCHASES) {
        customerNames[numPurchases] = customerName;
        items[numPurchases] = item;
        themes[numPurchases] = theme;
        numPurchases++;
    }
    else {
        cout << "더 이상 구매 내역을 추가할 수 없습니다." << endl;
    }
}

// 특정 테마의 구매 내역을 출력하는 함수
void printThemePurchases(const string& theme) {
    cout << "테마: " << theme << "에 대한 구매 내역" << endl;
    for (int i = 0; i < numPurchases; ++i) {
        if (themes[i] == theme) {
            cout << "고객 이름: " << customerNames[i] << " /  구매했던 상품: " << items[i] << endl;
        }
    }
    cout << endl;  // 테마별로 내역을 구분하기 위해 빈 줄 출력
}

int main() {
    // 구매 내역 추가 예시
    addPurchase("권성준", "후드 티", "의류");
    addPurchase("이현인", "쌀 20kg", "식품");
    addPurchase("황건하", "가디건", "의류");
    addPurchase("최성호", "냉동피자", "식품");
    addPurchase("신명훈", "헤드셋", "전자기기");
    addPurchase("정지수", "4B연필", "생활용품");
    addPurchase("곽범훈", "일렉기타", "전자기기");
    addPurchase("조현진", "신디사이저", "전자기기");
    addPurchase("박채린", "다이나믹 마이크", "전자기기");
    addPurchase("김래경", "만년필", "생활용품");
    addPurchase("박주홍", "베이스", "전자기기");
    addPurchase("서찬영", "패딩", "의류");
    addPurchase("이가은", "수면안대", "생활용품");
    addPurchase("김원범", "마우스패드", "생활용품");
    addPurchase("박점식", "자연산 송이버섯", "음식");

    // 특정 테마의 구매 내역 출력 예시
    printThemePurchases("의류");
    printThemePurchases("식품");
    printThemePurchases("전자기기");
    printThemePurchases("생활용품");


    return 0;
}






