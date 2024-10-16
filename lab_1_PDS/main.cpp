#include <iostream>
#include <string>
#include <limits> 
using namespace std;

bool implication(bool p, bool q) {
    return !p || q;
}

bool equivalence(bool p, bool q) {
    return implication(p, q) && implication(q, p);
}

void bitwise_operations(const string& a, const string& b, string& or_result, string& and_result, string& xor_result) {
    if (a.length() != 8 || b.length() != 8) {
        throw invalid_argument("Both strings must be exactly 8 characters long.");
    }

    or_result = "";
    and_result = "";
    xor_result = "";

    for (int i = 0; i < 8; ++i) { 
        if (a[i] == '1' || b[i] == '1') {
            or_result += '1';
        }
        else {
            or_result += '0';
        }

        if (a[i] == '1' && b[i] == '1') {
            and_result += '1';
        }
        else {
            and_result += '0';
        }

        if (a[i] != b[i]) {
            xor_result += '1';
        }
        else {
            xor_result += '0';
        }
    }
}



bool get_input(const string& prompt) {
    bool value;
    while (true) {
        cout << prompt;
        if (cin >> value && (value == 0 || value == 1)) {
            break; 
        }
        else {
            cout << "�������: ����i�� 0 ��� 1!" << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
    return value;
}

string get_bit_string(const string& prompt) {
    string bit_string;
    while (true) {
        cout << prompt;
        cin >> bit_string;
        bool is_valid = true;

        
        for (char c : bit_string) {
            if (c != '0' && c != '1') {
                is_valid = false;
                break;
            }
        }

        if (is_valid && bit_string.length() == 8) {
            break;
        }
        else {
            cout << "�������: ����� ������� �i����� �i���� 0 �� 1, i ���� �i��� 8 ������i�." << endl;
        }
    }
    return bit_string;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    bool p = get_input("����i�� �������� i��������i ��� p (0 ��� 1): ");
    bool q = get_input("����i�� �������� i��������i ��� q (0 ��� 1): ");

    bool conjunction = p && q;
    cout << "���'����i� (p i q): " << conjunction << endl;

    bool disjunction = p || q;
    cout << "���'����i� (p ��� q): " << disjunction << endl;

    bool exclusiveOr = p != q;
    cout << "������������� \"���\" (p xor q): " << exclusiveOr << endl;

    bool impl_pq = implication(p, q);
    cout << "I���i���I� (p -> q): " << impl_pq << endl;

    bool impl_qp = implication(q, p);
    cout << "I���i���i� (q -> p): " << impl_qp << endl;

    bool equiv = equivalence(p, q);
    cout << "���i�������i��� (p ~ q): " << equiv << endl;

    string a = get_bit_string("\n����i�� 1-� �i����� ����� (8 �I�): ");
    string b = get_bit_string("����i�� 2-� �i����� ����� (8 �I�): ");

    string or_result, and_result, xor_result;
    bitwise_operations(a, b, or_result, and_result, xor_result);

    cout << "��������� OR:  " << or_result << endl;
    cout << "��������� AND: " << and_result << endl;
    cout << "��������� XOR: " << xor_result << endl;

    return 0;
}
