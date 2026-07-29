class Solution {
public:
    int i = 0;

    map<string, int> solve(string &formula) {
        map<string, int> mp;

        while (i < formula.size() && formula[i] != ')') {

            if (formula[i] == '(') {
                i++; // skip '('

                map<string, int> temp = solve(formula);

                i++; // skip ')'

                int num = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }

                if (num == 0) num = 1;

                for (auto &x : temp)
                    mp[x.first] += x.second * num;
            }
            else {
                // Parse atom name
                string atom;
                atom += formula[i++];
                while (i < formula.size() && islower(formula[i]))
                    atom += formula[i++];

                // Parse count
                int num = 0;
                while (i < formula.size() && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }

                if (num == 0) num = 1;

                mp[atom] += num;
            }
        }

        return mp;
    }

    string countOfAtoms(string formula) {
        i = 0;

        map<string, int> ans = solve(formula);

        string res;

        for (auto &x : ans) {
            res += x.first;
            if (x.second > 1)
                res += to_string(x.second);
        }

        return res;
    }
};