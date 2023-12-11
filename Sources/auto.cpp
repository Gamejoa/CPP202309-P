#include <iostream>
#include <string>
#include "purchaseData.h"

using namespace std;

const int MAX_PURCHASES = 100;

// 구매 내역을 저장하는 배열
string customerNames[MAX_PURCHASES];
string items[MAX_PURCHASES];
string themes[MAX_PURCHASES];

// 현재 저장된 구매 내역의 개수
int numPurchases = 0;


// 현재 보유 중인 쿠폰 개수 저장 배열
int couponCounts[MAX_PURCHASES];



// 구매 내역을 저장하는 함수

void addPurchase(const string& customerName, const string& item, const string& theme) {
    if (numPurchases < MAX_PURCHASES) {
        customerNames[numPurchases] = customerName;
        items[numPurchases] = item;
        themes[numPurchases] = theme;
        couponCounts[numPurchases] = 0;
        numPurchases++;
    }
    else {
        cout << "더 이상 구매 내역을 추가할 수 없습니다." << endl;
    }
}

// 대소문자 구별없이 출력해주는 함수 
bool caseInsensitiveCompare(const string& str1, const string& str2) {
    return equal(str1.begin(), str1.end(), str2.begin(), str2.end(), [](char a, char b) {
        return tolower(a) == tolower(b);
        });
}

// 특정 테마의 구매 내역을 출력하는 함수
void printCustomerPurchases(const string& customerName) {
    cout << customerName << "님의 구매 내역" << endl;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName)) {
            cout << "구매했던 상품: " << items[i] << " / 테마: " << themes[i] << endl;

          }
    }
    cout << endl;  // 구매 내역 출력 종료 후 빈 줄 출력
}


int main() {
    // 구매 내역 추가 예시
    initializeData();



    cout << "권성준을 입력해보세요" << endl;

    // 사용자에게 입력받아 구매내역 확인
    string targetCustomer;
    cout << "고객 이름을 입력하세요: ";
    cin >> targetCustomer;

    printCustomerPurchases(targetCustomer);

    


    return 0;
}




