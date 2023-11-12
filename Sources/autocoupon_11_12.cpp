#include <iostream>
#include <string>

using namespace std;

const int MAX_PURCHASES = 100;

// ���� ������ �����ϴ� �迭
string customerNames[MAX_PURCHASES];
string items[MAX_PURCHASES];
string themes[MAX_PURCHASES];

// ���� ����� ���� ������ ����
int numPurchases = 0;

// ���� ������ �����ϴ� �Լ�
void addPurchase(const string& customerName, const string& item, const string& theme) {
    if (numPurchases < MAX_PURCHASES) {
        customerNames[numPurchases] = customerName;
        items[numPurchases] = item;
        themes[numPurchases] = theme;
        numPurchases++;
    }
    else {
        cout << "�� �̻� ���� ������ �߰��� �� �����ϴ�." << endl;
    }
}

// Ư�� �׸��� ���� ������ ����ϴ� �Լ�
void printThemePurchases(const string& theme) {
    cout << "�׸�: " << theme << "�� ���� ���� ����" << endl;
    for (int i = 0; i < numPurchases; ++i) {
        if (themes[i] == theme) {
            cout << "�� �̸�: " << customerNames[i] << " /  �����ߴ� ��ǰ: " << items[i] << endl;
        }
    }
    cout << endl;  // �׸����� ������ �����ϱ� ���� �� �� ���
}

int main() {
    // ���� ���� �߰� ����
    addPurchase("�Ǽ���", "�ĵ� Ƽ", "�Ƿ�");
    addPurchase("������", "�� 20kg", "��ǰ");
    addPurchase("Ȳ����", "�����", "�Ƿ�");
    addPurchase("�ּ�ȣ", "�õ�����", "��ǰ");
    addPurchase("�Ÿ���", "����", "���ڱ��");
    addPurchase("������", "4B����", "��Ȱ��ǰ");
    addPurchase("������", "�Ϸ���Ÿ", "���ڱ��");
    addPurchase("������", "�ŵ������", "���ڱ��");
    addPurchase("��ä��", "���̳��� ����ũ", "���ڱ��");
    addPurchase("�跡��", "������", "��Ȱ��ǰ");
    addPurchase("����ȫ", "���̽�", "���ڱ��");
    addPurchase("������", "�е�", "�Ƿ�");
    addPurchase("�̰���", "����ȴ�", "��Ȱ��ǰ");
    addPurchase("�����", "���콺�е�", "��Ȱ��ǰ");
    addPurchase("������", "�ڿ��� ���̹���", "����");

    // Ư�� �׸��� ���� ���� ��� ����
    printThemePurchases("�Ƿ�");
    printThemePurchases("��ǰ");
    printThemePurchases("���ڱ��");
    printThemePurchases("��Ȱ��ǰ");


    return 0;
}






