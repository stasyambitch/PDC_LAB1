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
            cout << "Помилка: введiть 0 або 1!" << endl;
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
            cout << "Помилка: рядок повинен мiстити тiльки 0 та 1, i мати рiвно 8 символiв." << endl;
        }
    }
    return bit_string;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    bool p = get_input("Введiть значення iстинностi для p (0 або 1): ");
    bool q = get_input("Введiть значення iстинностi для q (0 або 1): ");

    bool conjunction = p && q;
    cout << "Кон'юнкцiя (p i q): " << conjunction << endl;

    bool disjunction = p || q;
    cout << "Диз'юнкцiя (p або q): " << disjunction << endl;

    bool exclusiveOr = p != q;
    cout << "Альтернативне \"або\" (p xor q): " << exclusiveOr << endl;

    bool impl_pq = implication(p, q);
    cout << "IмплiкацIя (p -> q): " << impl_pq << endl;

    bool impl_qp = implication(q, p);
    cout << "Iмплiкацiя (q -> p): " << impl_qp << endl;

    bool equiv = equivalence(p, q);
    cout << "Еквiвалентнiсть (p ~ q): " << equiv << endl;

    string a = get_bit_string("\nВведiть 1-й бiтовий рядок (8 бIт): ");
    string b = get_bit_string("Введiть 2-й бiтовий рядок (8 бIт): ");

    string or_result, and_result, xor_result;
    bitwise_operations(a, b, or_result, and_result, xor_result);

    cout << "Результат OR:  " << or_result << endl;
    cout << "Результат AND: " << and_result << endl;
    cout << "Результат XOR: " << xor_result << endl;

    return 0;
}
