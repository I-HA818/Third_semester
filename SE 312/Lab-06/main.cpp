#include <iostream>
#include <cstring>
#define siz 100
using namespace std;

int state_num;
int symbol_num;
int symbols[siz];
string states[siz];
string transition[siz][siz];
string start_state;
string accepting_state;

int s, a;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> state_num;
    for (int i = 0; i < state_num; i++) {
        cin >> states[i];
    }

    cin >> symbol_num;
    for (int j = 0; j < symbol_num; j++) {
        cin >> symbols[j];
    }

    for (int i = 0; i < state_num; i++) {
        for (int j = 0; j < symbol_num; j++) {
            cin >> transition[i][j];
        }
    }

    cin >> start_state;
    for (int k = 0; k < state_num; k++) {
        if (states[k] == start_state) s = k;
    }

    cin >> accepting_state;
    for (int k = 0; k < state_num; k++) {
        if (states[k] == accepting_state) a = k;
    }

    for (int i = 0; i < state_num; i++) {
        for (int j = 0; j < symbol_num; j++) {
            cout << transition[i][j] << " ";
        }
        cout << endl;
    }

    string RE[state_num + 1][state_num][state_num];

    for (int i = 0; i < state_num; i++) {
        for (int j = 0; j < state_num; j++) {
            bool flag = true;
            int d;
            for (d = 0; d < symbol_num; d++) {
                if (transition[i][d] == states[j] && transition[i][d] == states[i]) {
                    flag = false;
                    RE[0][i][j] = to_string(symbols[d]) + "+" + "E";
                } else if (transition[i][d] == states[j]) {
                    RE[0][i][j] = to_string(symbols[d]);
                    flag = false;
                    break;
                }
            }
            if (flag == true) RE[0][i][j] = "NULL";
        }
    }

    for (int k = 1; k < state_num; k++) {
        for (int i = 0; i < state_num; i++) {
            for (int j = 0; j < state_num; j++) {
                RE[k][i][j] = "(" + RE[k - 1][i][j] + ")" + "+" + "(" + RE[k - 1][i][k - 1] + ")" + "(" + RE[k - 1][k - 1][k - 1] + ")" + "*" + "(" + RE[k - 1][k - 1][j] + ")";
            }
        }
    }

    for (int k = 0; k < state_num; k++) {
        cout << "For k = " << k << endl;
        for (int i = 0; i < state_num; i++) {
            for (int j = 0; j < state_num; j++) {
                cout << "R" << i + 1 << j + 1 << " = " << RE[k][i][j] << "   ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    return 0;
}
