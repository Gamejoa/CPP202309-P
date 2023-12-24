#include <iostream>
#include <string>
#include "purchaseData.h"

using namespace std;

const int MAX_PURCHASES = 100;

string customerNames[MAX_PURCHASES];
string items[MAX_PURCHASES];
string themes[MAX_PURCHASES];
int couponCounts[MAX_PURCHASES];
int numPurchases = 0;

// 대소문자 구분 없이 두 문자열을 비교하는 함수
bool caseInsensitiveCompare(const string& str1, const string& str2) {
    return equal(str1.begin(), str1.end(), str2.begin(), str2.end(), [](char a, char b) {
        return tolower(a) == tolower(b);
        });
}

// 특정 테마와 고객에 대한 구매 횟수를 세는 함수
int countTheme(const string& customerName, const string& theme) {
    int count = 0;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName) && caseInsensitiveCompare(themes[i], theme)) {
            count++;
        }
    }
    return count;
}

// 구매 내역을 데이터 배열에 추가하는 함수
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

// 특정 고객의 구매 내역을 출력하는 함수
void printCustomerPurchases(const string& customerName) {
    cout << customerName << "님의 구매 내역" << endl;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName)) {
            cout << "구매했던 상품: " << items[i] << " / 테마: " << themes[i];
            if (couponCounts[i] > 0) {
                cout << " / 할인 쿠폰 지급: " << couponCounts[i] << "장";
            }
            cout << endl;
        }
    }
    cout << endl;
}


// 모든 고객에게 특정 테마에 대한 할인 쿠폰을 지급하는 함수
void grantCouponForThemeToAllCustomers(const string& theme, int couponCount) {
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(themes[i], theme)) {
            couponCounts[i] += couponCount;
            cout << customerNames[i] << "님에게 " << theme << " 테마에 대한 할인 쿠폰 " << couponCount << "장을 지급했습니다." << endl;
        }
    }
}

// 특정 고객에 대한 할인 쿠폰을 지급하는 함수
void grantCouponForCustomer(const string& customerName, int couponCount) {
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName)) {
            couponCounts[i] += couponCount;
            cout << customerName << "님에게 할인 쿠폰 " << couponCount << "장을 지급했습니다." << endl;
        }
    }
}



int main() {

    initializeData();
    // "권성준", "이현인", " 황건하" 를 대표적으로 입력해보세요.
    string targetCustomer;
    cout << "고객 이름을 입력하세요: ";
    cin >> targetCustomer;

    // 특정 고객의 구매 내역 출력
    printCustomerPurchases(targetCustomer);

    // 특정 고객의 주요 테마 확인
    string majorTheme = "";
    int maxThemeCount = 0;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], targetCustomer)) {
            // 해당 고객의 테마별 구매 개수 확인
            int themeCount = countTheme(targetCustomer, themes[i]);
            if (themeCount > maxThemeCount) {
                maxThemeCount = themeCount;
                majorTheme = themes[i];
            }
        }
    }

    // 주요 테마에 대한 할인 쿠폰 지급
    if (!majorTheme.empty()) {
        grantCouponForCustomer(targetCustomer, 1);
        cout << "주요 테마 '" << majorTheme << "'에 대한 할인 쿠폰을 지급했습니다." << endl;
    }

   // 재확인
    printCustomerPurchases(targetCustomer);

    return 0;
}