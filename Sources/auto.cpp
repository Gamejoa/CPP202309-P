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

// ��ҹ��� ���� ���� �� ���ڿ��� ���ϴ� �Լ�
bool caseInsensitiveCompare(const string& str1, const string& str2) {
    return equal(str1.begin(), str1.end(), str2.begin(), str2.end(), [](char a, char b) {
        return tolower(a) == tolower(b);
        });
}

// Ư�� �׸��� ���� ���� ���� Ƚ���� ���� �Լ�
int countTheme(const string& customerName, const string& theme) {
    int count = 0;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName) && caseInsensitiveCompare(themes[i], theme)) {
            count++;
        }
    }
    return count;
}

// ���� ������ ������ �迭�� �߰��ϴ� �Լ�
void addPurchase(const string& customerName, const string& item, const string& theme) {
    if (numPurchases < MAX_PURCHASES) {
        customerNames[numPurchases] = customerName;
        items[numPurchases] = item;
        themes[numPurchases] = theme;
        couponCounts[numPurchases] = 0;
        numPurchases++;
    }
    else {
        cout << "�� �̻� ���� ������ �߰��� �� �����ϴ�." << endl;
    }
}

// Ư�� ���� ���� ������ ����ϴ� �Լ�
void printCustomerPurchases(const string& customerName) {
    cout << customerName << "���� ���� ����" << endl;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName)) {
            cout << "�����ߴ� ��ǰ: " << items[i] << " / �׸�: " << themes[i];
            if (couponCounts[i] > 0) {
                cout << " / ���� ���� ����: " << couponCounts[i] << "��";
            }
            cout << endl;
        }
    }
    cout << endl;
}


// ��� ������ Ư�� �׸��� ���� ���� ������ �����ϴ� �Լ�
void grantCouponForThemeToAllCustomers(const string& theme, int couponCount) {
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(themes[i], theme)) {
            couponCounts[i] += couponCount;
            cout << customerNames[i] << "�Կ��� " << theme << " �׸��� ���� ���� ���� " << couponCount << "���� �����߽��ϴ�." << endl;
        }
    }
}

// Ư�� ���� ���� ���� ������ �����ϴ� �Լ�
void grantCouponForCustomer(const string& customerName, int couponCount) {
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName)) {
            couponCounts[i] += couponCount;
            cout << customerName << "�Կ��� ���� ���� " << couponCount << "���� �����߽��ϴ�." << endl;
        }
    }
}



int main() {

    initializeData();
    // "�Ǽ���", "������", " Ȳ����" �� ��ǥ������ �Է��غ�����.
    string targetCustomer;
    cout << "�� �̸��� �Է��ϼ���: ";
    cin >> targetCustomer;

    // Ư�� ���� ���� ���� ���
    printCustomerPurchases(targetCustomer);

    // Ư�� ���� �ֿ� �׸� Ȯ��
    string majorTheme = "";
    int maxThemeCount = 0;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], targetCustomer)) {
            // �ش� ���� �׸��� ���� ���� Ȯ��
            int themeCount = countTheme(targetCustomer, themes[i]);
            if (themeCount > maxThemeCount) {
                maxThemeCount = themeCount;
                majorTheme = themes[i];
            }
        }
    }

    // �ֿ� �׸��� ���� ���� ���� ����
    if (!majorTheme.empty()) {
        grantCouponForCustomer(targetCustomer, 1);
        cout << "�ֿ� �׸� '" << majorTheme << "'�� ���� ���� ������ �����߽��ϴ�." << endl;
    }

   // ��Ȯ��
    printCustomerPurchases(targetCustomer);

    return 0;
}