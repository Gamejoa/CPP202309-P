#include <iostream>
#include <string>
#include "purchaseData.h"

using namespace std;

const int MAX_PURCHASES = 100;

// ���� ������ �����ϴ� �迭
string customerNames[MAX_PURCHASES];
string items[MAX_PURCHASES];
string themes[MAX_PURCHASES];

// ���� ����� ���� ������ ����
int numPurchases = 0;


// ���� ���� ���� ���� ���� ���� �迭
int couponCounts[MAX_PURCHASES];



// ���� ������ �����ϴ� �Լ�

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

// ��ҹ��� �������� ������ִ� �Լ� 
bool caseInsensitiveCompare(const string& str1, const string& str2) {
    return equal(str1.begin(), str1.end(), str2.begin(), str2.end(), [](char a, char b) {
        return tolower(a) == tolower(b);
        });
}

// Ư�� �׸��� ���� ������ ����ϴ� �Լ�
void printCustomerPurchases(const string& customerName) {
    cout << customerName << "���� ���� ����" << endl;
    for (int i = 0; i < numPurchases; ++i) {
        if (caseInsensitiveCompare(customerNames[i], customerName)) {
            cout << "�����ߴ� ��ǰ: " << items[i] << " / �׸�: " << themes[i] << endl;

          }
    }
    cout << endl;  // ���� ���� ��� ���� �� �� �� ���
}


int main() {
    // ���� ���� �߰� ����
    initializeData();



    cout << "�Ǽ����� �Է��غ�����" << endl;

    // ����ڿ��� �Է¹޾� ���ų��� Ȯ��
    string targetCustomer;
    cout << "�� �̸��� �Է��ϼ���: ";
    cin >> targetCustomer;

    printCustomerPurchases(targetCustomer);

    


    return 0;
}




